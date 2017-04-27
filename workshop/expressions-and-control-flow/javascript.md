# Expressions and Control flow
Learn your second programming language, get used to the new syntax of JavaScript

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [JavaScript Tutorial For Beginners 01 - Introduction](https://www.youtube.com/watch?v=qoSksQ4s_hg) | 3:40 |
| [JavaScript for Beginners 02 - What is JavaScript?](https://www.youtube.com/watch?v=VB7y0yxZjro) | 4:03 |
| [JavaScript Tutorial For Beginners 03 - Hello World! in JavaScript](https://www.youtube.com/watch?v=ranSYb-EhrU) | 3:17 |
| [JavaScript Tutorial For Beginners #4 - Where to put your JS](https://www.youtube.com/watch?v=czlwRUeTCgw) | 5:13 |
| [JavaScript Tutorial For Beginners #5 - Google Chrome Developer Tools](https://www.youtube.com/watch?v=JzZFccCEgGA) | 4:51 |
| [JavaScript Tutorial For Beginners #6 - Basic JavaScript Syntax & Rules](https://www.youtube.com/watch?v=QLatPwsbDrQ) | 7:49 |
| [JavaScript Tutorial For Beginners #7 - JavaScript Variables](https://www.youtube.com/watch?v=u0Mq3FzpsmI) | 8:59 |
| [JavaScript Tutorial For Beginners #8 - Basic Mathematical Operators](https://www.youtube.com/watch?v=_MC0Gw07w8M) | 6:16 |
| [JavaScript Tutorial For Beginners #9 - Math Operator Short-hand](https://www.youtube.com/watch?v=Z1eV0RBRam0) | 4:55 |
| [JavaScript Tutorial For Beginners #10 - Logging to the Console](https://www.youtube.com/watch?v=tH-q9QFNUdA) | 3:38 |
| [JavaScript Tutorial For Beginners #11 - Booleans in JavaScript](https://www.youtube.com/watch?v=B4ZCFdrBmbE) | 6:13 |
| [JavaScript Tutorial For Beginners #12 - If Statements](https://www.youtube.com/watch?v=Lp-Du2fKoug) | 8:45 |
| [JavaScript Tutorial For Beginners #13 - Else If Statements](https://www.youtube.com/watch?v=1v1Bk3Q02Sc) | 4:03 |
| [JavaScript Tutorial For Beginners #14 - Comparison Operators](https://www.youtube.com/watch?v=LjGaaWX_NbE) | 5:25 |
| [JavaScript Tutorial For Beginners #15 - Logical Operators](https://www.youtube.com/watch?v=mbT7sSmVUS8) | 6:01 |
| [JavaScript Tutorial For Beginners #16 - While Loops](https://www.youtube.com/watch?v=PpbFyLTtpWI) | 4:09 |
| [JavaScript Tutorial For Beginners #17 - For Loops](https://www.youtube.com/watch?v=U87UmD-5h4o) | 7:49 |
| [JavaScript Tutorial For Beginners 19 - Practical Example using Loops](https://www.youtube.com/watch?v=eZBTLsv2ktM) | 4:02 |
| [JavaScript Tutorial For Beginners #22 - Numbers](https://www.youtube.com/watch?v=TD3Pfuxgnuc) | 6:09 |
| [JavaScript Tutorial For Beginners - NaN (Not a Number)](https://www.youtube.com/watch?v=0ZiltZDg9Gg) | 6:34 |
| [JavaScript Tutorial For Beginners #24 - Strings](https://www.youtube.com/watch?v=k8MIbEVXhE0) | 9:37 |

### Optional
| Material | Time |
|:---------|-----:|
| [All the rest of The Net Ninja JavaScript Tutorials](https://www.youtube.com/playlist?list=PL4cUxeGkcC9i9Ae2D9Ee1RvylH38dKuET) | |

### Environment
 -  Please install Node.js Latest LTS Version from
    [nodejs.org/en/download](https://nodejs.org/en/download/)

## Material Review
 - Node.js
 - Comments
 - `console`
 - Types
   - number
   - string
   - boolean
   - null
   - undefined
 - Operators
   - arithmetric
   - logical
   - comparison
   - assignment
   - typeof
 - Control structures
   - `if`
   - `while`
   - `for`
   - `break`
   - `continue`

## Workshop

Your best friend in the next few weeks will be Mozilla's JavaScript reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript

### Printing to the terminal window

#### Hello World

```javascript
'use strict';

console.log('Hello world');
```

#### Exercises
 - [01](hello-me/hello-me.py)
 - [02](hello-others/hello-others.py)
 - [03](humpty-dumpty/humpty-dumpty.py)

### Comments
```javascript
'use strict';

// single line comment

/*
 multi line
 comment block
*/
```

### Types

#### Print values with different types

```javascript
'use strict';
// Prints a string to the terminal window.
console.log('Hello, World!');

// Prints an integer to the terminal window.
console.log(42);

// Prints a floating point number to the terminal window.
console.log(3.141592);
```

#### Integers

```javascript
'use strict';

// Positive, negative and zero
console.log(42); // Prints 42
console.log(-1); // Prints -1
console.log(0); // Prints 0
```

#### Floats

```javascript
'use strict';

// Positive, negative and zero
console.log(3.1415); // Prints 3.1415
console.log(-1.5); // Prints -1.5
console.log(0.0); // Prints 0

// Leading and closing zero is not mandatory
console.log(.5) // Prints 0.5
console.log(5.) // Prints 5.0
```

#### Number Operations

```javascript
'use strict';

// Arithmetic operations
console.log(1 + 1); // Prints 2
console.log(5 - 2); // Prints 3
console.log(3 * 4); // Prints 12
console.log(6 / 2); // Prints 3
console.log(5 / 2); // Prints 2.5
console.log(5 % 2); // Prints 1
```

#### Booleans

```javascript
'use strict';

// true, false
console.log(true); // Prints true
console.log(false); // Prints false

// Boolean Operators
// Negation
console.log(!true); // Prints false
console.log(!false); // Prints true

// And
console.log(true && true); // Prints true
console.log(true && false); // Prints false
console.log(false && true); // Prints false
console.log(false && false); // Prints false

// Or
console.log(true || true); // Prints true
console.log(true || false); // Prints true
console.log(false || true); // Prints true
console.log(false || false); // Prints false
```

#### Strings

```javascript
'use strict';

// String and special characters
console.log('apple'); // Prints apple
console.log('don\'t'); // Prints don't
console.log('"Everything you can imagine is real." - Picasso'); // Prints "Everything you can imagine is real." - Picasso

// String Operators
// Concatenation
console.log('tooth' + 'brush'); // Prints toothbrush

// Concat string with number
console.log('My favorite number is: ' + 8); // Prints My favorite number is: 8
```

#### Exercises
 -  [04](introduce-yourself/introduce-yourself.py)
 -  [05](two-numbers/two-numbers.py)
 -  [06](coding-hours/coding-hours.py)

### Variables

#### Creating different variables for each type

```javascript
'use strict';

// String
var welcome = 'Hello, World';
console.log(welcome);

// Boolean
var isAwesome = true;
console.log(is_awesome);

// Integer
var theMeaningOfLifeAndTheUniverseAndEverything = 42;
console.log(theMeaningOfLifeAndTheUniverseAndEverything);

// Floating point number
var pi = 3.141592;
console.log(pi);

// Assigning and creating a variable, (define its value)
var number = 12;

// Mutate a variable, (redefine its value)
number = 23;
```

#### Arithmetic Assignment Operators

```javascript
'use strict';

var a = 12;
a += 4;
console.log(a); // Prints 16

var b = 12;
b -= 4;
console.log(b); // Prints 8

var c = 12;
c *= 3;
console.log(c); // Prints 36

var d = 12;
d /= 3;
console.log(d); // Prints 4

var e = 12;
e %= 7;
console.log(e); // Prints 5

var f = 12;
f++;
console.log(f); // Prints 13

var g = 12;
g--;
console.log(g); // Prints 13

var h = 10;
console.log(h); // Prints 10
console.log(h++); // Prints 10
console.log(h); // Prints 11

var i = 10;
console.log(i); // Prints 10
console.log(++i); // Prints 11
console.log(i); // Prints 11
```

#### Exercises
 -  [07](favorite-number/favorite-number.py)
 -  [08](define-basic-info/define-basic-info.py)
 -  [09](bmi/bmi.py)
 -  [10](cuboid/cuboid.py)
 -  [11](seconds-in-a-day/seconds-in-a-day.py)
 -  [12](swap/swap.py)
 -  [13](variable-mutation/variable-mutation.py)


### Nothings
```javascript
'use strict';

undefined;
null;
NaN;

null !== undefined;
NaN !== undefined;
null !== NaN;

null == undefined;

typeof undefined; // 'undefined'
typeof null; // 'object'
typeof NaN; // 'number'

var alma;
alma; // undefined
alma + 1; // NaN
alma = null; // null
```


### Conditionals

```javascript
'use strict';

var a = 13;

if (a === 13) {  
  console.log('Yaaay! The value of the \'a\' variable is 13'); // This block will run
}

if (a === 8) {
  console.log('Yaaay! The value of the \'a\' variable is 8'); // This block will NOT run
}


var b = 20;

if (b < 10) {
  console.log('Yaaay! The value of the \'b\' variable is lower than 10') // This block will NOT run
} else {
  console.log('Yaaay! The value of the \'b\' variable is higher than 10') // This block will run
}


var c = 15;

if (c < 10) {
  console.log('Yaaay! The value of the \'b\' variable is lower than 10'); // This block will NOT run
} else if (c < 20) {
  console.log('Yaaay! The value of the \'b\' variable is higher than 10'); // This block will run
} else {
  console.log('Yaaay! The value of the \'b\' variable is higher than 10'); // This block will NOT run
}


var thirsty = true;
var hungry = false;

if (thirsty && hungry) {
  console.log('Lunch time!');
} else if (thirsty || hungry) {
  console.log('Snack time!');
} else {
  console.log('No food for you.');
}
```

#### Exercises
 -  [18](odd-even/odd-even.py)
 -  [19](one-two-a-lot/one-two-a-lot.py)
 -  [20](print-bigger/print-bigger.py)
 -  [21](party-indicator/party-indicator.py)
 -  [22](conditional-variable-mutation/conditional-variable-mutation.py)

### Loops

```javascript
'use strict';

var a = 0;
while (a < 10) {
  console.log(a); // Prints the numbers from 0 to 9
  a++;
}

for (var j = 0; j < 100; j++) {
  console.log(i); // Prints the numbers from 0 to 99
}
```

#### Exercises
 -  [23](i-wont-cheat-on-the-exams/i-wont-cheat-on-the-exams.py)
 -  [24](print-even/print-even.py)
 -  [25](count-from-to/count-from-to.py)
 -  [26](multiplication-table/multiplication-table.py)
 -  [27](draw-triangle/draw-triangle.py)
 -  [28](draw-pyramid/draw-pyramid.py)
 -  [29](draw-diamond/draw-diamond.py)
 -  [30](draw-square/draw-square.py)
 -  [31](draw-diagonal/draw-diagonal.py)
 -  [32](fizz-buzz/fizz-buzz.py)
 -  [33](guess-the-number/guess-the-number.py)
 -  [34](parametric-average/parametric-average.py)
 -  [35](draw-chess-table/draw-chess-table.py)


## Individual Workshop Review
Please follow the styleguide: [Our Python styleguide](../../styleguide/python.md)

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
