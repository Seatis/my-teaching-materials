# App frontend

![Todo mockup](todo-mockup.png)

### Give the above design, create the UI:
- HTML
- CSS
- Find cool icons at: http://iconfinder.com/ 
	- prefer SVG-s since they are resolution independent

*You can create your own design!*

#### Text styles:

```css
.heading {
	font-family: Lato-Light, sans-serif;
	font-size: 64px;
	color: #ffffff;
}

.todo-item {
	font-family: Lato-Regular, sans-serif;
	font-size: 26px;
	line-height: 2.2;
	color: #cecece;
}

.button-text {
	font-family: Lato-Regular, sans-serif;
	font-size: 26px;
	color: #ffffff;
}
```

### Check out the API docs

Now is a good time to read the API specification

- [Endpoints](todo-endpoints.md)
- Check all the resources
- Examine what parameters they should accept and what should they return

### Create the frontend JS code
- on page load, retrieve all todos from the API
- the app is a single page application, *do not reload the page* to refresh the state
- when adding a new todo:
	- the todo's title needs to be at least 3 charachter long, otherwise the app should display an error (you decide how)
    - `post` the todo to the appropriate API
    - and also render it in the todo list (when the response is success)
- when deleting a todo:
    - send the `delete` request to the API
    - and also remove the todo item for the UI (when the response is success)
- when completing a todo:
    - send the `put` request to the API
    - and also update the todo item's checkmark icon (when the response is success)

### Tips & Tricks
- all API calls should be separated
- write a function to reuse the `XMLHttpRequest`
- you can disable a button while your code is communicating with the server
- the API's host should be easily modified
- avoid code duplication
- avoid code duplication
- avoid code duplication
