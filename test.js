var FunctionOrigin = require('./index.js');
var assert = require('assert');

function TestFn() {}

var info = new FunctionOrigin(TestFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 3);
assert.equal(info.column, 15);

info = FunctionOrigin(TestFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 3);
assert.equal(info.column, 15);
