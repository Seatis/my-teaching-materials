# Admin Frontend

A frontend single page application for administating hotels in the hotel booking project.
It provides different user interfaces for hotel owners to manage their resources and
bookings.

## Technology

The application is implemented using Angular 4. The application is deployed 
to a separate hosting service from the backend applications. It uses Ajax calls
for retriving or sending any data to the microservices.
It has to handle the session using JWT tokens.

## Main features

 -  User management
 -  User session using JWT tokens
 -  Hotel room management and availability
 -  Booking management
 -  Payment and transaction management

## [Repository](https://github.com/greenfox-academy/hotel-booking-admin-frontend)

## Stories

### Front page

The front page should display a title: "Hotel Booking Admin"

```gherkin
Feature: Front page and title

Scenario: Front page is accesable form '/' path
 Given the browser path set to '/'
  When the page is loaded
  Then it should display 'Hotel Booking Admin'
```

#### Techincal Requirements

You can use the Angular CLI for initialize the project.
The title on the front page should be a component.
Please cover the component with unit tests.

### Continuous Integration

Set up a Continuous Integration server for continuous deployment and testing,
using [Codeship](https://codeship.com/).

#### Technical Requirements

Codeship should detect each change on the master branch of your repository on Github.
When the change is detected Codeship should run all the unit tests, if none the tests
failed it should deploy the latest version of the application to Heroku.
The application should run by Heroku using the Angular CLI serve feature.

### Login Page

The application should have a separate login page for logging in users.

```gherkin
Feature: Login page route

Scenario: Load login route
 Given the browser path set to '/login'
  When the page is loaded
  Then it should display 'Login'
```

#### Technical Requirements

Please create a separate component for the login page, also cover it with unit
tests. Use the Angular Router module for handling the routes.

### Mock login backend

Create a simple backend application for simulating authentication.

```gherkin
Feature: Login endpoint

Scenario: Post valid data
 Given the running mock backend application
  When the '/api/login/' is requested with a 'POST' request
   And the body is: '{"email": "test@example.com", "password": "1234"}'
  Then it should response:
  """
  {
    "data": {
      "type": "auth",
      "attributes": {
        "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IlRlc3RBZG1pbiIsImFkbWluIjp0cnVlfQ.nhC1EDI5xLGM4yZL2VMZyvHcbcWiXM2RVS7Y8Pt0Zuk"
      }
    }
  }
  """


Scenario: Post invalid data
 Given the running mock backend application
  When the '/api/login/' is requested with a 'POST' request
   And the body is: '{"email": "test@example.com", "password": "123"}'
  Then it should response:
   """
   {
     "errors": [{
       "status": "400",
       "title": "Bad Request",
       "detail": "Mismatched email and password"
     }]
   }
   """

```

#### Technical Requirements

You should deploy the application to [Glitch](https://glitch.com/).

### Login form

Create a login form based on [this](https://app.moqups.com/tamas.kokeny@lab.coop/6PDcDVJ2ne/view) mockup.

#### Technical Requirements

 - The form should not send any http request if any of the fields are missing
 - The form should validate on the email field if the given input is a valid email address
 - Use angular form validation

### Session

```gherkin
Feature: Required login

Scenario: Logged out user
 Given a user logged out
  When the '/' page is visited
  Then it should redirect to '/login'

Scenario: Login
 Given a user logged out
  When the '/login' page is visited
   And the form is submitted correctly
  Then it should redirect to '/'

Scenario: Logged in user
 Given a user logged in
  When the '/login' page is visited
  Then it should redirect to '/'
```

#### Technical Requirements

The session should be solved by saving the JWT token in sessionStorage

### Logout

Add a logout link to the header, that only shows when the user is logged in

```gherkin
Scenario: Logout user
 Given a user logged in
  When the '/' page is visited
   And the logout link is clicked
  Then it should redirect to '/login'
```

### Mock register backend

Create a simple backend endpoint for simulating registration.

```gherkin
Feature: Register endpoint

Scenario: Post valid data
 Given the running mock backend application
  When the '/api/register/' is requested with a 'POST' request
   And the body is:
   """
   {
     "data": {
       "type": "user",
       "attributes": {
         "email": "john.doe@example.org",
         "password": "suchsecret"
       }
     }
   }
   """
  Then it should response:
   """
   {
     "data": {
       "type": "user",
       "attributes": {
         "id": "1",
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }
   }
   """
```

### Register form

Create a register form based on [this](https://app.moqups.com/tamas.kokeny@lab.coop/6PDcDVJ2ne/view) mockup.

### Add hotel

Create a page for adding hotels based on [this](https://app.moqups.com/tamas.kokeny@lab.coop/6PDcDVJ2ne/view) mockup.

```
Feature: Add hotel endpoint

Scenario: Mock endpoint
 Given the application running
   And 0 hotels in the database
  When the '/hotels' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "hotels",
       "attributes": {
         "location": "Budapest",
         "name": "Hotel Ipoly utca",
         "has_wifi": true,
         "has_parking": true,
         "has_pets": true,
         "has_restaurant": true,
         "has_bar": true,
         "has_swimming_pool": true,
         "has_air_conditioning": true,
         "has_gym": true,
         "meal_plan": "american-plan",
         "stars": 5
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels/1"
     }
     "data": {
       "type": "hotels",
       "id": "1",
       "attributes": {
         "location": "Budapest",
         "name": "Hotel Ipoly utca",
         "has_wifi": true,
         "has_parking": true,
         "has_pets": true,
         "has_restaurant": true,
         "has_bar": true,
         "has_swimming_pool": true,
         "has_air_conditioning": true,
         "has_gym": true,
         "meal_plan": "american-plan",
         "stars": 5
       }
     }
   }
   """
```

The form should submit a hotel to this endpoint

### Mock single hotel endpoint 

Create an endpoint for a single checkout

```gherkin
Feature: Single Hotel

Scenario: Single Hotel
 Given the application running
   And 200 hotels in the database
  When the '/api/hotels/1' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1"
     }
     "data": {
       "type": "hotels",
       "id": "1",
       "attributes": {
         "location": "Budapest",
         "name": "Hotel Ipoly utca",
         "main_image_src: "https://path-to-your-image/",
         "has_wifi": true,
         "has_parking": true,
         "has_pets": true,
         "has_restaurant": true,
         "has_bar": true,
         "has_swimming_pool": true,
         "has_air_conditioning": true,
         "eal_plan": "american-plan"
       }
     }
   }
   """
```

```gherkin
Feature: Single Hotel

Scenario: Single Hotel
 Given the application running
   And 0 hotels in the database
  When the '/hotels/1' endpoint is requested with a 'GET' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No hotels found by id: 1"
     }]
   }
   """
```


### Delete Single Checkout 

Create an endpoint for a single checkout

```gherkin
Feature: Single Hotel

Scenario: Single Hotel
 Given the application running
   And 200 hotels in the database
  When the '/hotels/1' endpoint is requested with a 'DELETE' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1"
     }
   }
   """
   And delete the hotel with id 1
```

```gherkin
Feature: Single Hotel

Scenario: Single Hotel
 Given the application running
   And 0 hotels in the database
  When the '/hotels/1' endpoint is requested with a 'DELETE' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No hotels found by id: 1"
     }]
   }
   """
```

### Update Single

Create an endpoint for a single checkout

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 200 hotels in the database
  When the '/hotels/1' endpoint is requested with a 'PATCH' request
   """
   {
     "data": {
       "type": "hotels",
       "id": "1",
       "attributes": {
         "name": "Apartment Molnar utca"
       }
     }
   }
   """
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1"
     }
     "data": {
       "type": "hotels",
       "id": "1",
       "attributes": {
         "location": "Budapest",
         "name": "Apartment Molnar utca",
         "main_image_src: "https://path-to-your-image/",
         "has_wifi": true,
         "has_parking": true,
         "has_pets": true,
         "has_restaurant": true,
         "has_bar": true,
         "has_swimming_pool": true,
         "has_air_conditioning": true,
         "eal_plan": "american-plan"
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "USD",
         "status": "pending"
       }
     }
   }
   """
   And update the attributes of the hotel entity

```

```gherkin
Feature: Single Hotel

Scenario: Single Hotel
 Given the application running
   And 0 checkouts in the database
  When the '/hotels/1' endpoint is requested with a 'PATCH' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No hotels found by id: 1"
     }]
   }
   """
```

### Hotel page

The list of the hotels should consist a toggle-able add form under the '/hotels' path.
The list of the hotels shoud be requested like: `https://domain.com/api/hotels?user_id=1`
Create a page for listing hotels based on [this](https://app.moqups.com/tamas.kokeny@lab.coop/6PDcDVJ2ne/view) mockup.

### Delete button

The delete button should remove the hotel, and it should send the request to the server.

### Single hotel page

Create a page for single hotels based on [this](https://app.moqups.com/tamas.kokeny@lab.coop/6PDcDVJ2ne/view) mockup.
The single hotel page url is: `/hotels/1`.

### Autosave

It saves on every blur event (click on other element, tab, etc) and if nothing happens after 2 seconds.
