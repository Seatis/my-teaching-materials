# Project: Todo app frontend

![Todo mockup](todo-mockup.png)

### Check out the API docs
- https://todo-docs.herokuapp.com/docs/#!/default
- See all the paths
- Examine the parameters and responses
- Try all endpoints

### Try to access the API
- https://mysterious-dusk-8248.herokuapp.com/todos

### Create the form
- HTML
- CSS
- Style guide: https://zpl.io/scene/Z2u9aJ0
- Text styles:
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
- if you want more info on the mockup,
send your email address to Aniko for a Zeplin invite!

### Create the JS
- on page load, get all todos from the API
- when adding a new todo
    - send the todo to the API
    - and also display it in the list for the client (when the response is success)
- when deleting a todo
    - send the delete request to the API
    - and also update the list for the client (when the response is success)
- when completing a todo
    - send the update request to the API
    - and also update the list for the client (when the response is success)

### Tips & Tricks
- all API calls should be separated
- you can disable a button for the time being
- the API's host should be easily modified
- avoid code duplication
