# User Profile and Authentication Service

A microservice inside the hotel booking project. This service is responsible for
handling users, user profiles and authentication. It distinguishes between diffetent
user roles like end user and admin. It allows registration and login with Facebook
authentication.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements an API for registering ang logging in users. It stores all the user
data in a Postre SQL database using JPA. It has to integrate with the Facebook
API using OAuth.

## Main features

 -  Register
 -  Login
 -  User profile
 -  Session handling
 -  Facebook authentication


## [Repository](https://github.com/greenfox-academy/hotel-booking-user-service)

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

