# Functions and Arrays
Get to know JavaScript's function, array syntax and its behaviors. 

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [JavaScript Tutorial For Beginners #20 - Functions](https://www.youtube.com/watch?v=KH57lIgwe2g) | 9:18 |
| [Node JS Tutorial for Beginners #5 - Function Expressions](https://www.youtube.com/watch?v=lK42xIMcA0Y) | 4:18 |
| [JavaScript Tutorial For Beginners #21 - Variable Scope](https://www.youtube.com/watch?v=kjdZ1h3CIs4) | 6:05 |
| [JavaScript Tutorial For Beginners #26 - Arrays](https://www.youtube.com/watch?v=EUnV-fCY0Pc) | 6:47 |

### Functions

 - http://bonsaiden.github.io/JavaScript-Garden/#function

### Arrays

 - http://bonsaiden.github.io/JavaScript-Garden/#array
 - http://colintoh.com/blog/5-array-methods-that-you-should-use-today (expect Demethodizing chapter)
 - https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array (till the properties chapter)

#### Study these methods:

 - [Splice](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice)
 - [ForEach](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/foreach)
 - [Map](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
 - [Filter](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/filter)


## Material Review
- function expressions
  - function as variable
  - function as parameter
  - anonymus function
- global functions:
  - `alert`
  - `console.log`
  - `parseInt`
  - `parseFloat`
- return statement
- arguments
- variable scope
- array methods:
  - `push`
  - `pop`
  - `shift`
  - `unshift`
  - `indexOf`
  - `slice`
  - `splice`
  - `concat`
  - `forEach`
  - `filter`
  - `map`
  - `every`
  - `some`


## Workshop

### Functions

```javascript
function greet_fox_alert() {
  alert("Hello Green Fox!")
}

greet_fox_alert()

function greet_fox_log() {
  console.log("Hello Green Fox!")
}

greet_fox_log()
```

#### Function arguments

```javascript
function greet_by_name(name) {
  console.log(arguments)
  console.log("Well hi there,", name)
}

greet_by_name("Tojas")
greet_by_name("Barbi", "CEO")
```

#### Default values for function arguments

```javascript
function greet(greet="Hi", name="pal") {
  console.log(greet, name)
}

greet("Hey")
greet("Hello", "Tojas")
```

#### Function return values

```javascript
function make_green(name) {
  var newName = "Green " + name
  return newName
}

name = make_green("Tojas")
greet_by_name("Whazzup", name)
```

#### Excercises
-  [Doubling](exercises/functions/doubling/doubling.js)
-  [Greeter function](exercises/functions/greet/greet.js)
-  [Append a](exercises/functions/append-a/append-a.js)
-  [Summing](exercises/functions/sum/sum.js)
-  [Factorial](exercises/functions/factorio/factorio.js)
-  [Print arguments](exercises/functions/printer/printer.js)

### Data structures

#### Array methods

```javascript
console.log(['apple', 'pear', 'melon'].indexOf('pear')); // 1

['apple', 'pear', 'melon'].forEach(function(e, i) {
  console.log(e, i);
});


var triples = [1, 2, 3, 4, 5].map(function(e) {
  return e * 3;
});
console.log(triples); // [3, 6, 9, 12, 15]


var evens = [1, 2, 3, 4, 5].filter(function(e) {
  return e % 2 === 0;
});
console.log(evens); // [2, 4]


var isAllEven = [2, 6, 14, 5, 4].every(function(e) {
  return e % 2 === 0;
});
console.log(isAllEven); // false


var isAnyEven = [2, 6, 14, 5, 4].some(function(e) {
  return e % 2 === 0;
});
console.log(isAnyEven); // true


var letters = 'apple'.split('');
console.log(letters); // ['a', 'p', 'p', 'l', 'e']
console.log(letters.join('@')); // Worms in the apple!
```

#### Excercises
-  [Third](exercises/arrays/third/third.js)
-  [Compare Length](exercises/arrays/compare-length/compare-length.js)
-  [Sum elements](exercises/arrays/sum-elements/sum-elements.js)
-  [Swap elements](exercises/arrays/swap-elements/swap-elements.js)
-  [Print elements](exercises/arrays/print-all/print-all.js)
-  [Change element](exercises/arrays/change-element/change-element.js)
-  [Increment element](exercises/arrays/increment-element/increment-element.js)
-  [Append a](exercises/arrays/append-a/append-a.js)
-  [Double items](exercises/arrays/double-items/double-items.js)
-  [Colors](exercises/arrays/colors/colors.js)
-  [Sum all elements](exercises/arrays/sum-all/sum-all.js)
-  [Matrix](exercises/arrays/diagonal-matrix/diagonal-matrix.js)
-  [Reverse list](exercises/arrays/reverse/reverse.js)


## Individual Workshop Review
Please follow the styleguide: [Our JavaScript styleguide](../../styleguide/javascript.md)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Are the names of things following the styleguide?
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
