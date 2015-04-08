var FunctionOrigin = require('./index.js');
var assert = require('assert');

function TestFn() {}

var info = new FunctionOrigin(TestFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 3);
assert.equal(info.column, 15);
assert.equal(TestFn.name, 'TestFn');
assert.equal(info.inferredName, '');

info = FunctionOrigin(TestFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 3);
assert.equal(info.column, 15);
assert.equal(TestFn.name, 'TestFn');
assert.equal(info.inferredName, '');

var assignedFn = function () { }

info = FunctionOrigin(assignedFn);

assert(/test.js$/.exec(info.file));
assert.equal(info.line, 21);
assert.equal(info.column, 26);
assert.equal(assignedFn.name, '');
assert.equal(info.inferredName, 'assignedFn');
