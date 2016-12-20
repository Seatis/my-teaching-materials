# The Calorie Counter Project (Java Version)
As part of our learning about Spring and simulating the world of a programmer, this project - done over the week and in teams, is about pooling knowledge, skill and parcelling out tasks, to develop an app that tracks for a user, the calories consumed in a day.

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[Building a CRUD Web App Using Thymeleaf, JPA and H2 (Marinho)](https://www.youtube.com/watch?v=TcP5kFPq354)|29:38|


| Material | Time |
|:---------|-----:|
|[Dev Tools &amp; Docker](https://spring.io/blog/2015/06/17/devtools-in-spring-boot-1-3) - article and video explaining dev tools and docker| reading + 11:26|
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
- DevTools (Optional above)

## Specification/Stories

Basic web page of your own fashion that tracks the calories consumed per meal in a persistent way.  This runs in a browser and routes with links that route to particular pages.

### Main Page
There should be a page that is sent as a response to starting up (`index`).  It shows the title, perhaps a background image and then lists the meals.

The columns shown are:-
- meal date
- type
- description
- total calories
- functions 
  - edit
  - delete

At the bottom of the page, it shows the:-
- total calories.
- number of meals
- summary table
  - type (of meal)
  - count
  - total calories
- functions
  - add a meal
  - view next, previous page
  - view first, last page
  - set number of lines to view on a page
  
There are selectors for:-
- a date range
- types of meals
- functions 
  - reselect

The type of meal comes from a table:-
- Breakfast
- Elevenses
- Lunch
- Snack
- Dinner
- Midnight Snack


### Add &amp; Edit a meal
This is a simple page that either adds a new meal definition, or edits such.

As a columnar (right justified around a ":") set, one can enter the details, for example
```
     Date: [date field]
	 Type: [pull down list]v
	 Desc: [text block]
	 Cals: [numeric entry]
	 
	 <Add/Return> <Add/Another> <Cancel> <Delete>
	 
```
The user should be able to cancel, returning to the main screen.

### Delete a meal 
For the various situations where deleting.  The user should reconfirm the delete.

### Object Model 
These are the minimum elements, of course you can add your own.

- Meal
  - date/time
  - type (breakfast, lunch, snack, dinner, other)
  - food description
  - total calories

- Type
  - code
  - description
  - sequence in a day
  
### Extra credit ideas
- Add line item details to the meal, for each part of the meal, to break up the calories
- Call a WebService to get calories for particular serving
  - this will require portion size
  - learning about how to call a webservice  
- Create a calendar view that shows, day by day meals eaten, total calories  

#Links
- [Parent - Java Spring](../README.md)
