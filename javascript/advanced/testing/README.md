# Testing JavaScript Applications with Tape

## Objectives
 - Set up a node module and try out testing with tape

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [15.2: What is NPM? - Twitter Bot Tutorial](https://www.youtube.com/watch?v=s70-Vsud9Vk) | 3:32 |
| [JavaScript Tutorial: Unit Testing with Tape pt1](https://www.youtube.com/watch?v=5JXx0QrYUXo) | 3:32 |
| [Writing unit tests for personal projects? - FunFunFunction #29](https://www.youtube.com/watch?v=ib2Pt9_zciA) | 4:26 |
| [Unit testing: How to get your team started - FunFunFunction #2](https://www.youtube.com/watch?v=TWBDa5dqrl8&t=297s) | 17:24 |


## Material Review
 - npm
 - tape
 - units

## Workshop
initialize an npm project in today's working directory,   
install tape for testing
- [tape](https://github.com/substack/tape)

```
npm init
npm install tape --save-dev
```

#### Exercise
```javascript
var test = require('tape');

var add = function (a, b) {
  return a + b;
}

test('add 2 numbers', function (t) {
    var actual = add(1, 2);
    var expected = 3;

    t.equal(actual, expected);
    t.end();
});
```

write tests for all your function exercise solutions from the basics module:
- [39.js](../../basics/expressions-control-flow/workshop/39.js)
- [40.js](../../basics/expressions-control-flow/workshop/40.js)
- [41.js](../../basics/expressions-control-flow/workshop/41.js)
- [42.js](../../basics/expressions-control-flow/workshop/42.js)
- [43.js](../../basics/expressions-control-flow/workshop/43.js)
- [44.js](../../basics/expressions-control-flow/workshop/44.js)
- [45.js](../../basics/expressions-control-flow/workshop/45.js)
