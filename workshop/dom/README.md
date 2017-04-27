# Document object model – DOM

You'll learn how the broser builds HTML documents

### Training

| Material | Time |
|:---------|-----:|
| [What is the DOM in JavaScript? Watch from 32 - 41](https://www.youtube.com/watch?v=H63dVFDuJDM&index=32&list=PL4cUxeGkcC9i9Ae2D9Ee1RvylH38dKuET) | ~60min |
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
