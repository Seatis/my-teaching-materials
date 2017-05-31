# The Calorie Counter Project (Java Version)

## Description

Basic web page of your own fashion that tracks the calories consumed per meal in a persistent way. This runs in a browser and routes with links that route to particular pages, but it also provides an API to be able to communicate with other services.
Uploading your project to Heroku should be optional, you can work on your local server with your local MySQL database.

### Main Page
There should be a page that is sent as a response to starting up (`index`).  It shows the title, perhaps a background image and then lists the meals in a table.

The table columns shown are:
- meal date
- type
- description
- calories
- functions 
  - edit
  - delete

Right below the title you can see a short statistic that shows the:
- number of meals
- total calories

Above the table you find the `Add new meal` button that navigates to the Add or Edit meal page

The type of meal comes from a database table:
- Breakfast
- Elevenses
- Lunch
- Snack
- Dinner
- Midnight Snack


### Add or Edit meal page
This is a simple page that either adds a new meal definition or edits one.


The page shows the following form:
- Date: [date field]
- Type: [select with the values of the possible meal types]
- Description: [text field]
- Calories: [numeric entry]
- Save button
- Cancel button

Functionality:
- In case of editing the values of the form elements are automatically filled with its current values.
- The description field is optional, the others are mandatory.
- By clicking on the save button:
	- if all mandatory fields are filled, the data gets saved to your database and the page redirects to the Main page
	- if one or more mandatory fields are empty, an error message appears listing the empty required field names
- The user should be able to cancel: returning to the Main page

### Delete a meal 
It deletes the meal from your database and removes it from your table.
  
### Create a REST API to your service
#### `GET` /getmeals
- returns the meals list (the same that appears on your Main page) in JSON format

#### `GET` /getstats
- returns the number of meals and the total calories value in JSON format

#### `POST` /meal
- receives meal data in JSON format (e.g. `{date : "2017-05-16", type : "Breakfast", description : "ham and eggs", calories : 250}`)
- saves the meal as a new meal in the database
- in case of successfull create, the response is `{status : "ok"}` JSON

#### `UPDATE` /meal
- receives meal data extended the meal ID in JSON format (e.g. `{id : 12, date : "2017-05-16", type : "Breakfast", description : "ham and eggs", calories : 250}`)
- updates the meal with the given ID in your database
- in case of successfull update, the response is `{status : "ok"}` JSON

#### `DELETE` /meal
- recieves a meal ID in JSON format (e.g. `id : 12`)
- deletes the meal with the given ID from your database
- in case of successfull delete, the response is `{status : "ok"}` JSON

### Endpoint tests
- create tests for all your REST endpoints using Mock MVC
