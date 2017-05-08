# Advanced JavaScript part 1.

## Objectives
 - Get an understanding of how variables work in JavaScript
 - Get an understanding what scope is and how it works in Javascript
 - Get some routine in Object Creation in JavaScript

## Materials & Resources

### Variables, Scopes, Hoisting
| Material | Time |
|:---------|-----:|
| [JavaScript The Global Environment and The Global Object](https://www.youtube.com/watch?v=byiUGKVeJuY) | 10:58 |
| [The Basics of Scope in JavaScript](https://www.youtube.com/watch?v=ZoFlcv2ByBo) | 8:19 |
| [JavaScript Conceptual Aside Javascript and undefined](https://www.youtube.com/watch?v=J7QkYbxfMxo) | 8:04 |
| [JavaScript The Execution Context Code Execution](https://www.youtube.com/watch?v=FdW0WbvmS3k) | 2:54 |
| [JavaScript Functions, Context, and Variable Environments](https://www.youtube.com/watch?v=F9o4CPcDq18) | 7:56 |
| [var, let and const - What, why and how - ES6 JavaScript Features](https://www.youtube.com/watch?v=sjyJBL5fkp8) | 19:18 |
| Reading: |  |
| [Understanding Hoisting in JavaScript](https://scotch.io/tutorials/understanding-hoisting-in-javascript) | |

### Object Creation
| Material | Time |
|:---------|-----:|
| [JavaScript Functions, Context, and Variable Environments](https://www.youtube.com/watch?v=F9o4CPcDq18) | 7:56 |
| [Function Statements and Function Expressions](https://www.youtube.com/watch?v=oB5rH_9bqAI) | 28:30 |
| [bind and this - Object Creation in JavaScript P1](https://www.youtube.com/watch?v=GhbhD1HR5vk) | 15:38 |
| [Examples of this and bind - Object Creation in JavaScript P2](https://www.youtube.com/watch?v=PIkA60I0dKU) | 16:33 |
| [Beginner JavaScript Tutorial - 25 - Creating Our Own Objects](https://www.youtube.com/watch?v=6xLcSTDeB7A) | 9:22 |
| [Beginner JavaScript Tutorial - 27 - Adding Methods to Our Objects](https://www.youtube.com/watch?v=6lQEtgFnZTY) | 8:53 |
| Reading: |  |
| [This, Bind method](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this) |  |
| [Gentle explanation of 'this' keyword in JavaScript](https://rainsoft.io/gentle-explanation-of-this-in-javascript) |  |
| [Working with Objects](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_Objects) |  |

## Material Review
 - execution context
  - global
  - this
  - outer environment
 - hoisting
 - scope
 - undefined
 - var, let, const
 - `this`
 - `bind()`
 - `new`
 - constructor

## Workshop

### variables, scope, hoisting

```js
const numbers = [1, 2];
var number = 100;

  if (cond) {
    let sum = numbers[0] + numbers[1];
    number += sum;
  }

console.log(number); // prints 103
```

 - [neighbours01](neighbours/neighbours01.js)
 - [neighbours02](neighbours/neighbours02.js)
 - [neighbours03](neighbours/neighbours03.js)

### methods and this

```js
var student = {
  name: "John Doe",
  greet: function() {
    console.log(this.name);
  }
};

student.greet(); // prints greet
```

 - [Cars](cars/cars.js)
 - [Petrol Station](petrol-station/petrol-station.js)

### objects

```js
function Aircraft(type){
  this.type = type;
  this.ammo = 0;
  this.maxAmmo = 8;
  this.baseDamage = 30;
  this.printMaxAmmo = function() {
    console.log(this.maxAmmo);
  };
}

var plane = new Aircraft('F16');
console.log(plane.type); // prints 'F16'
plane.printMaxAmmo(); // prints 8
```
 - [Elevator](elevator/js.md)
