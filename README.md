node-buffer-indexof-fast
========================

This is a native implementation of [`.indexOf`](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/String/indexOf) for the [`Buffer`](http://nodejs.org/api/buffer.html) data type. Exports a function which can be applied to a buffer like so:

    Buffer.prototype.indexOf = require('buffer-indexof-fast');
    
    new Buffer("hello").indexOf("llo", 1);
