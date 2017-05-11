# Exception Handling and Testing JavaScript Applications with Tape

## Objectives
 - Set up a node module and try out testing with tape

## Materials & Resources

### Exception Handling

Material | Time |
|:---------|-----:|
| [Javascript Tutorial 23 - Try, Catch, Finally](https://www.youtube.com/watch?v=Vv1CLj4vLjE&t=35s) | 9:44 |
| [Reading |  |
| [Exceptional Exception Handling in JavaScrip](https://www.sitepoint.com/exceptional-exception-handling-in-javascript/) |  |
| [try...catch](https://developer.mozilla.org/hu/docs/Web/JavaScript/Reference/Statements/try...catch) |  |
| [throw](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/throw) |  |


### NPM Package Manager

Material | Time |
|:---------|-----:|
| [15.2: What is NPM? - Twitter Bot Tutorial](https://www.youtube.com/watch?v=s70-Vsud9Vk) | 13:26 |
| [Reading |  |
| [NPM Documentation](https://docs.npmjs.com/) |  |

### Unit Testing

| Material | Time |
|:---------|-----:|
| [JavaScript Tutorial: Unit Testing with Tape pt1](https://www.youtube.com/watch?v=5JXx0QrYUXo) | 3:32 |
| [Writing unit tests for personal projects? - FunFunFunction #29](https://www.youtube.com/watch?v=ib2Pt9_zciA) | 4:26 |
| [Unit testing: How to get your team started - FunFunFunction #2](https://www.youtube.com/watch?v=TWBDa5dqrl8&t=297s) | 17:24 |
| [Reading |  |
| [Writing javascript tests with tape](http://www.catonmat.net/blog/writing-javascript-tests-with-tape/) |  |
| [Tape Documentation](https://github.com/substack/tape) | Reading |

## Material Review
- exception, Error
  - `try`, `catch`, `finally`
  - `throw`
- NPM package manager
  - `npm init`
  - `npm install`
  - dependencies, devDependencies
- unit test
- `module.exports`
- tape
  - methods
    - `t.ok(value, msg)`
    - `t.notOk(value, msg)`
    - `t.error(err, msg)`
    - `t.equal(actual, expected, msg)`
    - `t.notEqual(actual, expected, msg)`
    - `t.deepEqual(actual, expected, msg)`
    - `t.notDeepEqual(actual, expected, msg)`
    - `t.throws(fn, expected, msg)`
    - `t.doesNotThrow(fn, expected, msg)`
    - etc.

## Workshop

### Exception Handling

```javascript
function add(a, b){
  if (typeof a !== 'number'){
    throw new Error('"a" is not a number');
  } else if (typeof b !== 'number'){
    throw new Error('"b" is not a number');
  }
  console.log(a + b);
}

add('string', 'string');
add(1, 'string');
add(1, 2);
```
```javascript
function add(a, b){
  if (typeof a !== 'number'){
    throw new Error('"a" is not a number');
  } else if (typeof b !== 'number'){
    throw new Error('"b" is not a number');
  }
  console.log(a + b);
}

try {
	add('string', 'string');
} catch (err) {
	console.log('catching error:');
	console.log(err.message);
}
```

- [Exception](exception/exception.js)

### NPM

Initialize an npm project in today's working directory.

Install ESLint. It's a linter for JavaScript. Install the Atom ESLint package.

[ESLint](http://eslint.org/)

```
npm init
npm install eslint --save-dev
eslint --init
```

Install tape for testing.

[tape](https://github.com/substack/tape)

```
npm install tape --save-dev
```

### Testing

```javascript
'use strict';

var add = function (a, b) {
  return a + b;
}

module.exports = add;
```
```javascript
'use strict';

var test = require('tape');
var add = require('./add.js');

test('add 2 numbers', function (t) {
  var actual = add(1, 2);
  var expected = 3;

  t.equal(actual, expected);
  t.end();
});
```

## Exercises

Test and handle the exceptions too.

- [Apples](apples/java.md)
- [Sum](sum/java.md)
- [Anagram](anagram/anagram.md)
- [Count Letters](count-letters/count-letters.md)
- [Fibonacci](fibonacci/fibonacci.md)
- [Extension](extension/java.md)
- [Sharpie](sharpie/java.md)
- [Animal](animal/animal.md)
- [Cows and Bulls](cows-and-bulls/cows-and-bulls.md)
