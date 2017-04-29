# Document object model – DOM

You'll learn how the browser builds HTML documents.

### Training

| Material | Time |
|:---------|-----:|
| [JavaScript Tutorial For Beginners #32 - What is the DOM in JavaScript?](https://youtu.be/H63dVFDuJDM) | 4:31 |
| [JavaScript Tutorial For Beginners #33 - Traversing the DOM](https://youtu.be/SowaJlX1uKA) | 7:43 |
| [JavaScript Tutorial For Beginners #34 - Changing Page Content](https://youtu.be/FQuwArzGPYo) | 5:38 |
| [JavaScript Tutorial For Beginners #35 - Changing Element Attributes](https://youtu.be/V0S0LXvnW-o) | 6:02 |
| [JavaScript Tutorial For Beginners #36 - Changing CSS Styles](https://youtu.be/97agDBCyxAE) | 4:49 |
| [JavaScript Tutorial For Beginners #37 - Adding Elements to the DOM](https://youtu.be/TrGI9Yki-24) | 7:43 |
| [JavaScript Tutorial For Beginners #38 - Removing Elements from the DOM](https://youtu.be/rBGgguNnutE) | 4:12 |
| [JavaScript Tutorial For Beginners # 39 - Introduction to JavaScript Events](https://youtu.be/bf_9IeihQ0M) | 8:29 |
| [JavaScript Tutorial For Beginners #40 - The onClick Event](https://youtu.be/XQEfWd1lh4Q) | 8:04 |
| [JavaScript Tutorial For Beginners #41 - Window onLoad Event](https://youtu.be/RVA4HoEE_q8) | 5:06 |
| [Introduction to the DOM](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Introduction) |
| [Document Object Model (DOM)](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model) |
| [What is the DOM?](https://css-tricks.com/dom/) |
| [How to Create a JavaScript Bookmarklet](http://www.dev-hq.net/posts/1--create-javascript-bookmarklet) |

#### Digging deeper

Read more about the DOM in the Eloquent Javascript book's relevant chapter:

http://eloquentjavascript.net/13_dom.html

Examples of how to use the bookmarklets:

http://www.hongkiat.com/blog/100-useful-bookmarklets-for-better-productivity-ultimate-list/

## Material Review
- data types
  - window
  - document
  - node
  - element
- accessing elements
  - getElementById
  - getElementsByTagName
  - querySelector
  - querySelectorAll
- creating, inserting & removing elements
  - createElement
  - appendChild
  - removeChild
- an element's contents
  - innerHTML
  - textContent
- element attributes
  - getAttribute
  - setAttribute
- element styles
- classes
  - classList
- events
  - addEventListener
- bookmarklets
  - javascript protocol


## Workshop

### Including JavaScript in an HTML page
```HTML
<script>
  console.log('Hello World!');
</script>

<script src="something.js"></script>
```

### Selecting elements
```javascript
var king = document.getElementById('b325');
var lamplighter = document.querySelector('.b329');

var asteroids = document.querySelectorAll('div.asteroid');
for (var i = 0; i < asteroids.length; i++) {
  console.log(asteroids[i]);
}
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [accessing-elements.html](examples/accessing-elements.html)

#### Exercises
- [queryselector-1.html](workshop/queryselector-1.html)

### An element's contents
```javascript
var asteroid = document.querySelector('.asteroid');
console.log(asteroid.innerHTML);
console.log(asteroid.textContent);
asteroid.innerHTML = 'This is your <strong>new content!</strong>';
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [element-contents.html](examples/element-contents.html)

#### Exercises
- [content-1.html](workshop/content-1.html)
- [content-2.html](workshop/content-2.html)
- [content-3.html](workshop/content-3.html)
- [content-4.html](workshop/content-4.html)

### Element attributes
```javascript
var littlePrince = document.querySelector('img');
console.log(littlePrince.getAttribute('src'));
littlePrince.setAttribute('src', 'http://deji.chez.com/dessins/pp1.gif');
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [element-attributes.html](examples/element-attributes.html)

#### Exercises
- [attribute-1.html](workshop/attribute-1.html)

### Classes
```javascript
  var asteroid = document.querySelector('div');

  console.log(asteroid.classList.value);

  console.log('asteroid?', asteroid.classList.contains('asteroid'));
  console.log('planet?', asteroid.classList.contains('planet'));

  asteroid.classList.add('new-class');
  asteroid.classList.remove('asteroid');
  console.log('still asteroid?', asteroid.classList.contains('asteroid'));
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [classlist.html](examples/classlist.html)

#### Exercises
- [classlist-1.html](workshop/classlist-1.html)

### Creating, inserting & removing elements
```javascript
var asteroidList = document.querySelector('ul.asteroids');

var newAsteroid = document.createElement('li');
newAsteroid.id = 'b555';
newAsteroid.textContent = 'The Green Fox';
asteroidList.appendChild(newAsteroid);

var businessAsteroid = document.querySelector('.b328');
asteroidList.removeChild(businessAsteroid);
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [create-insert-remove.html](examples/create-insert-remove.html)

#### Exercises
- [createelement-1.html](workshop/createelement-1.html)
- [createelement-2.html](workshop/createelement-2.html)
- [createelement-3.html](workshop/createelement-3.html)
- [createelement-4.html](workshop/createelement-4.html)

### Events
```javascript
  var button = document.querySelector('button');
  function alertGreenFox () {
    alert('Green Fox!');
  }
  button.addEventListener('click', alertGreenFox);
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [events.html](examples/create-insert-remove.html)

#### Exercises
- [events-1.html](workshop/events-1.html)
- [events-2.html](workshop/events-2.html)

### Bookmarklets
```HTML
  <a href="javascript:alert('Hello!');">Drag me in the bookmarks bar!</a>
```

#### Example
You can find the inserted Javascript code into an HTML page:
- [bookmarklet.html](examples/bookmarklet.html)

#### Exercises
- [bookmarklet-1.html](workshop/bookmarklet-1.html)
- [bookmarklet-2.html](workshop/bookmarklet-2.html)

## Individual Workshop Review
Please follow the styleguide: [Our JavaScript styleguide](../../styleguide/javascript.md)

- Is the directory structure and the name of the files correct?
- Is every file in strict mode?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Are the names of things following the styleguide?
- Are all of the brackets in the perfect place?
- Are whitespaces where they should be?
