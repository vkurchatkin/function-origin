# function-origin

Get origin of a function

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

 - `file`;
 - `line`;
 - `column`
 - `scriptId` (`>=v0l.12` only).

# License

MIT
