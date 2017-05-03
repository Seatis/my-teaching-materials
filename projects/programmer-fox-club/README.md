# Programmer Fox Club

> At Programmer Fox Club you can have your very own fox. It's like a virtual tamagochi, you can feed and train your lil' one.

## Introduction

 - create a new Spring Boot project with Gradle
     - Dependencies: Web, Thymeleaf
     - Optional dependencies: Lombok, DevTools
 - create an `index.html` file in the `src/main/resources/static/` folder
 - reproduce [this](assets/views/information-00.png) static view
     - [here](assets/greenfox.png) you can download the fox
 - start your application, navigate to `localhost:8080`
 - if it works then you are good to go
 - create a `MainController.class` file where you will store all your navigation routes
 - move your html file to `src/main/resources/templates` folder
 - create a `/` route
     - fix the html file so that it works
     - restart your application, navigate to `localhost:8080`
     - if it works then you are good to go

## Information Page

 - create a `Fox.class`
     - it should represent a virtual fox
     - it should have at least the followings: name, list of tricks, food and drink
     - consider using more classes or enums
 - make this class a bean
 - add the fox to the template model
 - use Thymeleaf to replace the data
 - if the fox does not know any tricks yet, display a message instead of an empty list
 - if the fox's name is *Mr. Green*, eats *salad*, drinks *water* and knows *0* trick, it should look something like [this](assets/views/information-01.png)

## Nutrition Store

 - create a `/nutritionStore` route
 - create your template file based on [this](assets/views/nutrition_store.png) image
     - do not forget to add this to the menu on the other views
 - here you should be able to change the fox's food and drink
     - feel free to add your own foods and drinks
     - you might need additional routes to achieve this
     - create an other controller for those (eg. `FoxController.class`)
 - when the button is pressed it should redirect to the information page
 - optional: the current food and drink are selected by default

## Trick Center

 - create a `/trickCenter` route
 - create your template file based on [this](assets/views/trick_center.png) image
 - it should list the tricks
     - feel free to add your own tricks
 - one trick could be learned only once
 - optional: do not list the tricks that have been learned already
 - optional: if all the tricks have been learned display a message instead of the dropdown

### Optional

## Action History

 - create a `/actionHistory` route
 - here you should display all the actions that have been made *(eg. food change)*
 - if no actions were made yet display a message else list all the actions
 - should look like [this](assets/views/action_history.png)
 - display the five latest actions to the information page
     - should look like [this](assets/views/information-02.png)

## Other ideas

 - add amount to food and drink that decreases over time
 - be able to play the tricks
     - display different image based on the trick
 - add a little design
 - add anything else if you have time 😉
