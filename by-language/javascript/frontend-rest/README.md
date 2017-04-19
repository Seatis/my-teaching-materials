# Functional Programming and Object Orientation in JavaScript

## Objectives
 - Have an idea about functional programming in JavaScript
 - Get an understanding of how variables work in JavaScript
 - Get some routine in Object Creation in JavaScript

## Materials & Resources

### Functional Programming
| Material | Time |
|:---------|-----:|
| [Javascript this keyword: Explained](https://www.youtube.com/watch?v=IGqGqlyIcg8) | 15:51 |
| [Higher-order functions - Part 1 of Functional Programming in JavaScript](https://www.youtube.com/watch?v=BMUiFMZr7vk) | 10:48 |
| [Closures - Part 5 of Functional Programming in JavaScript](https://www.youtube.com/watch?v=CQqwU2Ixu-U) | 7:03 |

### Variables, Scopes, Hoisting
| Material | Time |
|:---------|-----:|
| [first 8:29 of var, let and const - What, why and how - ES6 JavaScript Features](https://www.youtube.com/watch?v=sjyJBL5fkp8) | 19:18 |

### Object Creation
| Material | Time |
|:---------|-----:|
| [bind and this - Object Creation in JavaScript P1 - FunFunFunction #43](https://www.youtube.com/watch?v=GhbhD1HR5vk) | 15:38 |
| [Prototype basics - Object Creation in JavaScript P3 - FunFunFunction #46](https://www.youtube.com/watch?v=YkoelSTUy7A) | 19:19 |
| [The 'new' keyword - Object Creation in JavaScript P4 - FunFunFunction #50](https://www.youtube.com/watch?v=Y3zzCY62NYc) | 24:33 |


### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [The rest of the Functional Programming in JavaScript series](https://www.youtube.com/playlist?list=PL0zVEGEvSaeEd9hlmCXrk5yUyqUag-n84) | lot |
| [rest of var, let and const - What, why and how - ES6 JavaScript Features](https://www.youtube.com/watch?v=sjyJBL5fkp8) | 8:29 |
| [The rest of the Object Creation in JavaScript series](https://www.youtube.com/playlist?list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub) | lot |


## Material Review
 - functional Programming
 - higher order functions
 - closures
 - scope
 - hoisting
 - `this`
 - prototype
 - `new`

## Workshop

### Prototype
```javascript
function Car(km) {
 this.km = km;
}

Car.prototype.ride = function(km) {
 this.km += km;
}

var volvo = new Car(80000);
volvo.ride(120);
console.log(volvo.km); // 80120
```

#### Exercises
- [01.js](workshop/01.js)
- [02.js](workshop/02.js)
- [03.js](workshop/03.js)
- [04.js](workshop/04.js)
