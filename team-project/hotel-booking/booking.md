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
