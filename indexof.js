var i = require('./build/Release/indexof');

module.exports = function (needle, position) {

  if (!Buffer.isBuffer(this)) {
    throw new TypeError("This is not a buffer");
  }

  if (!Buffer.isBuffer(needle)) {
    needle = new Buffer(needle);
  }

  return i.indexOf.call(this, needle, position);

};
