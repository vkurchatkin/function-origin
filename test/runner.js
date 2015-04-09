var assert = require('assert');
var path = require('path');
var FunctionOrigin = require('../index.js');
var fixtures = require('./fixtures.js');

var info = new FunctionOrigin(fixtures.TestFn);

var fixturesPath = path.join(__dirname, 'fixtures.js');

assert.equal(info.file, fixturesPath);
assert.equal(info.line, 2);
assert.equal(info.column, 15);
assert.equal(fixtures.TestFn.name, 'TestFn');
assert.equal(info.inferredName, '');

info = FunctionOrigin(fixtures.TestFn);

assert.equal(info.file, fixturesPath);
assert.equal(info.line, 2);
assert.equal(info.column, 15);
assert.equal(fixtures.TestFn.name, 'TestFn');
assert.equal(info.inferredName, '');

var assignedFn = function () { }

info = FunctionOrigin(fixtures.assignedFn);

assert.equal(info.file, fixturesPath);
assert.equal(info.line, 5);
assert.equal(info.column, 26);
assert.equal(fixtures.assignedFn.name, '');
assert.equal(info.inferredName, 'assignedFn');
