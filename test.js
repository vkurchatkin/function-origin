var FunctionOrigin = require('./index.js');
var assert = require('assert');

function TestFn() {}

var info = new FunctionOrigin(TestFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 4);
assert.equal(info.column, 15);
