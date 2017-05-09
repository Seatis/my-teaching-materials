# Callbacks
Getting to know callbacks inside-out.

## Objectives
 - You'll understand what callbacks are
 - See callbacks from multiple angles

### Training
| Material | Time |
|:---------|-----:|
| [Higher-order functions - Part 1 of Functional Programming in JavaScript](https://www.youtube.com/watch?v=BMUiFMZr7vk) | 10:48 |
| [Map - Part 2 of Functional Programming in JavaScript](https://www.youtube.com/watch?v=bCqtb-Z5YGQ) | 9:07 |
| [[JavaScript Tutorial] 014 Function Statements and Function Expressions](https://www.youtube.com/watch?v=oB5rH_9bqAI) | 28:03 |
| [Asynchronous JavaScript #1 - What is Asynchronous JavaScript?](https://www.youtube.com/watch?v=YxWMxJONp7E) | 5:46 |
| [Asynchronous JavaScript #3 - Callback Functions](https://www.youtube.com/watch?v=QRq2zMHlBz4) | 13:49 |
| [BGTSD - Part 24: Basic Asynchronous Programming](https://www.youtube.com/watch?v=1V7rpblmruw) | 12:58 |
| [Mastering JavaScript Callbacks](https://www.youtube.com/watch?v=qN0dkXj7jc0) | 14:07 |
| [Episode #42 - JavaScript Timers](https://www.youtube.com/watch?v=Az5J_EkhYCY) | 12:11 |
| [Closures - Part 5 of Functional Programming in JavaScript](https://www.youtube.com/watch?v=CQqwU2Ixu-U) | 7:03 |

## Material Review
 -  First class function
     -  function as variable / value
     -  function as object
 -  function statement / function expression
 -  Higher order function
 -  `.map()`
 -  `.filter()`
 -  what is async
 -  callbacks
 -  setTimeout
 -  setInterval
 -  clearTimeout
 -  clearInterval
 -  blocking / non blocking
 -  closure

## Workshop

### First class functions
```javascript
function add(a, b) {
  return a + b;
}

var apple = add;
console.log(apple(5, 6)); // 11
```

```javascript
function substract(a, b) {
  return a - b;
}

substract.pear = 45;
console.log(substract.pear);
```

### Function as argument
```javascript
function provideName(callback) {
  callback('John Doe');
}

function printName(name) {
  console.log(name);
}

provideName(printName); // prints John Doe
```

### Higher order functions
```javascript
var numbers = [1, 2, 3, 4, 5];

function doubler(num) {
  return num * 2;
}

var doubles = numbers.map(doubler);

console.log(doubles); // prints [2, 4, 6, 8, 10]
```
 - [01 - Call](call/call.js)
 - [02 - Map](map/map.js)
 - [03 - Caller](caller/caller.js)

### SetTimeout
```javascript
setTimeout(function() {
  console.log('apple'); // prints after one second
}, 1000);
console.log('pear'); // prints first
```

```javascript
var timeoutId = setTimeout(function() {
  console.log('Yeeey!'); // not going to run
}, 1000);

clearTimeout(timeoutId);

```

 - [04 - Simple Timeout](simple-timeout/simple-timeout.js)
 - [05 - Multiple Timeout](multiple-timeout/multiple-timeout.js)
 - [06 - Delayed Click](delayed-click/delayed-click.md)
 - [07 - Click Three Times](click-three-times/click-three-times.md)
 

#### Candy shop

Find the HTML skeleton of the game in the [candy game](candy-game) folder.

 - Gather 10.000 candies!
 - Clicking the ‘Create candies’ button gives you 1 candy.
 - You can buy a lollipop for 100 candies by clicking the ‘Buy lollipop’ button.
 - 10 lollipops generate 1 candy per second.
   - Use the 🍭 emoji to display the lollipops you have
 - Display the candy producton rate in the `Candies / Second` row
 - If you press the "make candy rain" button, the candy generation should speed up 10x
