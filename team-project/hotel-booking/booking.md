# Booking and Resource Backend Service

## Description

A microservice inside the hotel booking project. This microservice is responsible for
tracking all the available resources and bookings.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements a REST API for manage hotels, rooms and bookings.
The database layer is using Postgre SQL and JPA. This project is quite database
and data heavy, you can expect quite a few different queries, filterings and 
multiple joint tables.

## Main features

 -  Manage hotels
 -  Manage bookings
 -  Manage rooms
 -  Rate hotels and rooms
 -  Availability management
 -  Search based on
     -  Date
     -  Location
     -  Price
     -  Rating


## [Repository](https://github.com/greenfox-academy/hotel-booking-resource-service)

## Stories

### Hearthbeat

Create an endpoint for monitoring the availibilty of this service, and check
each connected tool if it is working.

```gherkin
Feature: A simple JSON endpoint that could be called periodically to ensure,
if the application is running or not.

Scenario: Monitor availability
 Given the application running
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should return a JSON like: '{"status": "ok"}'
```

```gherkin
Feature: Hearthbeat endpoint should check database availability.

Scenario: Monitor database that has one record
 Given the application running
   And connected to the database
   And the database is has 1 record in the 'hearthbeat' table
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should return a JSON like: '{"status": "ok", "database": "ok"}'

Scenario: Monitor database that has no records
 Given the application running
   And connected to the database
   And the database is has 0 record in the 'hearthbeat' table
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should return a JSON like: '{"status": "ok", "database": "error"}'
```

#### Technical Requirements

Create a database table called 'hearthbeat' that only has one column with
boolean type called 'status'.

The application should be deployed to Heroku as a production environment,
and the database should be set up on each developer and production environments.

The endpoint should be tested using MockMvc

### Continuous Integration

Set up a Continuous Integration server for continuous deployment and testing,
using [Codeship](https://codeship.com/).

#### Technical Requirements

Codeship should detect each change on the master branch of your repository on Github.
When the change is detected Codeship should run all the unit tests, if none the tests
failed it should deploy the latest version of the application to Heroku.

### Database Migration On Production Environment

Create a database migration using [flyway](https://flywaydb.org/getstarted/)

#### Technical Requirements

Add flyway as a dependency to your project. Alter your heartbeat table by adding
a new autoincrement id column to it,
alter it in a way that all the stored records are remaining in the table on 
the production environment. Use the flywaydb to proceed with the migration.

### Logging

Create a simple unit that is able to log any message to the standatd out.
The application should have 4 different log levels, in the following increasing priority:

 -  **debug**: Logging any debugging related information, that is only
    informative for the current temporary debugging situation. Typically not
    logged in production environment.
 -  **info**: Generally useful information to log (service start/stop,
    configuration assumptions, etc). Info I want to always have available but
    usually don't care about under normal circumstances. This is my
    out-of-the-box config level.
 -  **warn**: Anything that can potentially cause application oddities, but for
    which I am automatically recovering. (Such as switching from a primary to
    backup server, retrying an operation, missing secondary data, etc.)
 -  **error**: Any error which is fatal to the operation, but not the service
    or application (can't open a required file, missing data, etc.).
    These errors will force user (administrator, or direct user) intervention.
    These are usually reserved (in my apps) for incorrect connection strings,
    missing services, etc.

#### Technical Requirements

The unit should have a method for each log level and it should take the log message
as a prameter. It should print the level, the hostname, and the message.
in a format like:

```
INFO some-service.herokuapp.com message
```

The debug and info levels should log to the standard out and the warn and error
levels should log to the standard error.

### Logging time

The logging unit should log the current date in standard format.
It should use the ISO 8601 standard with combined date and time in UTC.
Each log message should look like something similar:

```
INFO 2017-06-12T17:39:29Z some-service.herokuapp.com message
```

### Configurable logging levels

The log levels should be configurable by an environment variable.
If the called methods priority is the same or higher than the stored log level,
then it should log the message otherwise it should not.
So it for example it should log a `warn` level message if the environment variable is
set to `info`, but it should not log anything if the message level is `info` and
the variable is set to `error`.
The default log level should be `info` if the environment variable is not present.

### RabbitMQ in hearthbeat

The hearthbeat endpoint should check the RabbitMQ connection and push and consume a message.

```gherkin
Feature: Hearthbeat endpoint should check message queue availability.

Scenario: Monitor queue that has no items
 Given the application running
   And connected to RabbitMQ
   And the 'heartbeat' queue is empty
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should send a message to the 'heartbeat' queue and consume that message right after
   And it should return a JSON like: '{"status": "ok", "database": "ok", "queue": "ok"}'

Scenario: Monitor queue that has items
 Given the application running
   And connected to RabbitMQ
   And the 'heartbeat' queue is not empty
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should return a JSON like: '{"status": "ok", "database": "ok", "queue": "error"}'

Scenario: Monitor queue that is not connected
 Given the application running
   And not connected to RabbitMQ
  When the '/hearthbeat' endpoint is requested with 'GET' method
  Then it should return a JSON like: '{"status": "ok", "database": "ok", "queue": "error"}'
```

### Send Event

Create a unit that is able to send an event to the 'events' message queue, to track events
for further analytics.

#### Technical Requirements

If the dispach method is called on the unit it should send an event to a message queue
thats configuration is saved in environment variables. The message should be in JSON
format and it should consist these information:

 - time
 - hostname
 - message

### Endpoint logging

Each http endpoint should be logged by the application

```gherkin
Feature: Logging on endpoints

Scenario: Good request
 Given the application running
  When any of the endpoints is requested
  Then it should log 'HTTP-REQUEST /path' in 'info' level

Scenario: Bad request
 Given the application running
  When any of the endpoints is requested
   And the response has any error
  Then it should log 'HTTP-ERROR /path' in 'error' level
```

### Hotel list

Create a REST endpoint for managing hotels

```gherkin
Feature: List hotels

Scenario: Good request
 Given the application running
  When the '/hotels' endpoint is requested with a 'GET' request
  Then it should return a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels"
     }
     "data": [{
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
         "has_gym": true,
         "meal_plan": "american-plan",
         "stars": 5
       }
     }]
   } 
   """
```

#### Technical Requirements

The API should follow the [JSON-API](http://jsonapi.org/) specification guidelines.
The hotels should be stored in the database.

### Hotel pagination

The rest endpoint should have pagination if there are more than 20 hotels

```gherkin
Feature: Hotel pagination

Scenario: More than 20
 Given the application running
   And 200 hotels in the database
  When the '/hotels' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels",
       "next": "https://your-hostname.com/hotels?page=2",
       "last": "https://your-hostname.com/hotels?page=10",
     }
     "data": [{
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
         "has_gym": true,
         "meal_plan": "american-plan",
         "stars": 5
       }
     }, {
       ...
     } ...]
   }
   """
```

```gherkin
Feature: Hotel pagination

Scenario: Second page
 Given the application running
   And 200 hotels in the database
  When the '/hotels?page=2' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels?page=2",
       "next": "https://your-hostname.com/hotels?page=3",
       "prev": "https://your-hostname.com/hotels",
       "last": "https://your-hostname.com/hotels?page=10",
     }
     "data": [{
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
         "has_gym": true,
         "meal_plan": "american-plan",
         "stars": 5
       }
     }, {
       ...
     } ...]
   }
   """
```

### Add Hotel

Create a rest endpoint for creating new hotels

```gherkin
Feature: Add hotel
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
         "main_image_src: "https://path-to-your-image/",
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
         "main_image_src: "https://path-to-your-image/",
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

Feature: Add hotel
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
  Then it should send a 400 response with a JSON:
   """
   {
     "errors": [{
       "status": "400",
       "title": "Bad Request",
       "detail": "The attribute fields: \"stars\", \"has_gym\" are missing"
     }]
   }
   """
```

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Hotel filtering

The hotel endpoint should be able to filter on the attributes.

```gherkin
Feature: filter by wifi

Scenario: by wifi
 Given the application running
   And 10 hotels in the database
  When the '/hotels?has_wifi=true' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels?has_wifi=true"
     }
     "data": [{
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
     }]
   }
   """

```

#### Technical requirements

It should accept all the attributes as filter paramters.

### Get Single Hotel

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

### Reviews

Create an endpoint for reviews.

The needed attributes for reviews:

 - **id**: number, unique referencce
 - **rating**: number, a number between 0-5
 - **created_at**: timestamp, the creation date
 - **description**: text, the description of the review

The endpoint path: `hotels/1/reviews`, where the 1 is the id of the hotel.

Please follow the JSON-api guidelines and create a full CRUD functionallity.
The api should be able to:
 
 - Create a new review
 - List all reviews
 - Paginate in listing
 - Filter in listing by attributes
 - Get a review by id
 - Delete a review by id
 - Update a review by id
 - Hande errors and provide error responses

All the reviews should store a reference to the hotel and the user.

### Review as relation in Hotel

A hotel object should consist its lates reviews

```gherkin
Feature: Single Hotel with reviews

Scenario: Single Hotel with reviews
 Given the application running
   And 200 hotels in the database
   And 2 reviews for hotel_id: 1 in the database
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
     },
     "relationships": {
       "reviews": {
         "links": {
           "self": "https://your-hostname/api/hotels/1/relationships/reviews",
           "related": "https://your-hostname/api/hotels/1/reviews"
         }
       },
       "data": [
         { "type": "reviews", "id": "1" }
         { "type": "reviews", "id": "2" }
       ]
     },
     "included": [{
       "type": "reviews",
       "id": "1",
       "attributes": {
         "rating": 5,
         "description": "Cool place, cool people",
         "created_at": "2017-06-26T14:05:10+0000"
       }
     }, {
       "type": "reviews",
       "id": "2",
       "attributes": {
         "rating": 5,
         "description": "Awesomesauce! Best place ever!",
         "created_at": "2017-06-26T14:05:10+0000"
       }
     }]
   }
   """
```

#### Technical requirements

Both the self and related links should work for the relationships objects.

### Average rating

Every hotel should have an attribute called `average_rating` that represents
the aggregated average of all the reviews about the hotel.

### Rooms

Create a new relationship under hotels.
It should be accessable from the `/api/hotels/{id}/relationships/rooms`.

The needed attributes for rooms:

 - **id**: number, unique referencce
 - **price**: number, the price of the room
 - **currency**: string: the currency of the price
 - **description**: text, the description of the review
 - **max_occupancy**: number, the maximum occupancy of the team


### Booking

Create an endpoint for bookings.

The needed attributes for reviews:

 - **id**: number, unique reference
 - **guests**: number, the number of guests
 - **start_date**: timestamp, the start date
 - **end_date**: timestamp, the end date
 - **created_at**: timestamp, the creation date
 - **description**: text, the description of the review

The endpoint path: `hotels/1/bookings`, where the 1 is the id of the hotel.
It should be accessable form `users/1/bookings` and `/bookings` as well.

Please follow the JSON-api guidelines and create a full CRUD functionallity.
The api should be able to:
 
 - Create a new bookings
 - List all bookings by hotel and user
 - Paginate in listing
 - Filter in listing by attributes
 - Get a booking by id
 - Delete a booking by id
 - Update a booking by id
 - Hande errors and provide error responses

All the booking should store a reference to the hotel and the user.


