var assert = require('assert');
var crypto = require('crypto');

bIndexOf = require('./indexof');
sIndexOf = String.prototype.indexOf;

var compare = function (haystack, needle, position) {
  console.log(haystack, needle, position); 
  assert.equal(bIndexOf.call(new Buffer(haystack), needle, position),
               sIndexOf.call(haystack, needle, position));
};

var i;
for (i = 0; i < 1000; i++) {
  var haystack = crypto.pseudoRandomBytes(Math.floor(Math.random() * 10)).toString('hex');
  var needle;
  if (i % 2 == 0) {
    needle = crypto.pseudoRandomBytes(Math.floor(Math.random() * 10)).toString('hex');
  } else {
    needle = haystack.slice(Math.floor(Math.random() * haystack.length / 2), Math.floor(Math.random() * haystack.length));
  }
  var position = Math.floor(Math.random() * 30 - 15);
  compare(haystack, needle, position);
}
