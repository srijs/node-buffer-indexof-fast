#include <node.h>
#include <nan.h>

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using v8::Number;

NAN_METHOD(IndexOf) {
  NanScope();

  char *S = node::Buffer::Data(args.This());
  int len = node::Buffer::Length(args.This());

  char *searchStr = node::Buffer::Data(args[0]);
  int searchLen = node::Buffer::Length(args[0]);

  int pos = args[1]->Int32Value();

  int start = std::min(std::max(pos, 0), len);

  if (searchLen == 0) {
    NanReturnValue(NanNew<Number>(start));
  }

  while (searchLen <= len - start) {
    // Search for the first byte of the needle.
    char *chr = (char *)memchr(&S[start], searchStr[0], len - start);
    if (chr == NULL) {
      // First byte not found, short circuit.
      NanReturnValue(NanNew<Number>(-1));
    }
    if (searchLen == 1) {
      // Nothing more to compare, we found it.
      NanReturnValue(NanNew<Number>((intptr_t)chr - (intptr_t)S));
    }
    if (searchLen > len - ((intptr_t)chr - (intptr_t)S)) {
      // Needle is longer than the rest of the haystack,
      // no way it is contained in there.
      NanReturnValue(NanNew<Number>(-1));
    }
    int cmp = memcmp(&chr[1], &searchStr[1], searchLen - 1);
    if (cmp == 0) {
      // All bytes are equal, we found it.
      NanReturnValue(NanNew<Number>((intptr_t)chr - (intptr_t)S));
    }
    // Advance start position for next iteration.
    start = (intptr_t)chr - (intptr_t)S + 1;
  }

  NanReturnValue(NanNew<Number>(-1));

}

void Init(Handle<Object> exports) {
  exports->Set(NanNew<String>("indexOf"),
    NanNew<FunctionTemplate>(IndexOf)->GetFunction());
}

NODE_MODULE(indexof, Init)
