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
 - `column`.

# License

MIT
