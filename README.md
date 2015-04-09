# function-origin

Get origin of a function in io.js and node.js

# Usage

```
npm install function-origin
```

and then:

```javascript
var FunctionOrigin = require('function-origin');
var origin = FunctionOrigin(someFn);
```
`origin` has the following properties:

 - `file` — source file name;
 - `line` — line number (0-based);
 - `column` — column number (0-based);
 - `inferredName`.

# License

MIT
