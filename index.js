var binding = require('bindings')('function_origin');

function FunctionOrigin(fn) {
  if (!(this instanceof FunctionOrigin))
    return new FunctionOrigin(fn);

  if (typeof fn !== 'function')
    throw new TypeError('Argument is not a function');

  this.file = null;
  this.line = null;
  this.column = null;
  this.inferredName = null;

  binding.SetOrigin(fn, this);
}

module.exports = FunctionOrigin;
