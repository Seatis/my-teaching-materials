# The Calorie Counter Project (Java Version)
As part of our learning about Spring and simulating the world of a programmer, this project - done over the week and in teams, is about pooling knowledge, skill and parcelling out tasks, to develop an app that tracks for a user, the calories consumed in a day.

## Materials & Resources

| Material | Time |
|:---------|-----:|


| Material | Time |
|:---------|-----:|
|[Motivation (FunFunFunction.25)](https://www.youtube.com/watch?v=RQg_Q4HYYpg) - what keeps people going? PMJ is a consummate developer with a following, and these are his musings from Gotenborg|11:53|
Working in teams?
JSON


## Review
To do this project, you should leverage the following lessons:-
- Thymeleaf
- Beans
- Project Lombok
- ORMLite and/or JPA
- SQL - basics
- JSON
- MVC

## Specification/Stories

Basic web page of your own fashion that tracks the calories consumed per meal in a persistent way.  This runs in a browser and routes with links that route to particular pages.

### Main Page
There should be a page that is sent as a response to starting up (`index`).  It shows the title, perhaps an image, and one can click a button that calls the `/meals` GET endpoint.

### Add meal backend

#### Create a database scheme for meals.
Each meal should have:
- name (string),
- count total calories (integer),
- a date (date)
- type of meal (breakfast, lunch, dinner, snack, midnight snack, elevenses (for Hobbits and Welsh users) 

#### Create an endpoint: "/meals"
When receiving the meal in the post data in a `POST` request, the server should add a new meal to the database.
Use the `body-parser` module for decoding the post data.
You can try your application with the following command:
`curl --data '{"name": "something", "calories": 200, "date": "2016-01-26:12:03:10"}' -H 'content-type:application/json'  http://localhost:8080/meals`
It should reply with the newly created meal object plus status ok if the request was successful. Example response:
```JavaScript
{
  "status": "ok",
  "meal": {
    "id": 123,
    "name": "something",
    "calories": 200,
	"type": "midnight snack"
    "date": "2016-01-04T23:00:00.000Z"
  }
}
```


### Add meal frontend
#### Create a form for adding a new meal
- Create an input field for the name of the meal
- Create an input field for the calories
- Create an input field for the date
- Create a button that sends an `POST` http request to the server, to the
`/meals` endpoint with the fields from the inputs.

### List meals backend
#### Create an endpoint: "/meals"
When receiving a `GET` request, the server should respond with the list of meals.
like:
```json
{
  "meals": [
    {"id": 1, "name": "steak", "calories": 890, type: "dinner", "date": "2016-01-04T23:00:00.000Z"},
    {"id": 2, "name": "carrot", "calories": 200,type: "snack",  "date": "2016-01-04T23:00:00.000Z"}
  ]
}
```
You can try your application with the following command:
`curl -H 'content-type:application/json'  http://localhost:8080/meals`

### List meals frontend
The fronted should list all the added meals below the form.
It should show the name, calories and date for each.

### Delete meals backend
#### Create an endpoint: "/meals/:id"
When receiving a `DELETE` request, the backend should delete the meal with the given id.
If the delete was successful, it should respond

```json
{
  "status": "ok",
  "meal": {
    "id": 123
  }
}
```
, otherwise it should respond
`{"status": "not exists"}`

You can try your application with the following command:
`curl -H 'content-type:application/json' -X 'DELETE' http://localhost:8080/meals/3`

### Delete meals frontend
Add a delete button to each row in the meals list. Clicking a button should send a `DELETE` http request to the server, to the
`/meals/:id` endpoint with the id of the corresponding meal, after a user confirmation asking "Are you sure you want to delete this meal?".

### Filter meals frontend
Add a form for filtering the meal list for days. The form should have a date input, a button called 'filter', and one called 'all'.
If the 'filter' button is clicked, it should only show meals for the given day.
If the 'all' button is clicked, it should show all meals.

### Sum calories
Add a field that always shows the sum of calories.

### Object Model 
These are the minimum elements, of course you can add your own.

- Meal
  - date/time
  - type (breakfast, lunch, snack, dinner, other)
  - food description
  - total calories


#Links
- [Parent - Java Spring](../README.md)
