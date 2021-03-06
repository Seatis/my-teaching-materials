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

### Register

Create an endpoint that is able to add a new user to the database

```gherkin
Feature: Register

Scenario: Register
 Given the application running
   And 0 users in the database
  When the '/register' endpoint ir requested with a 'POST' request:
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
  Then it should send a 201 response with a JSON:
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

#### Technical Requirements

The token should be generated by the service using the [JWT](https://jwt.io/) method.

### Password store

The register endpoint should save the given user. The password should not be stored as plain text,
rather it should be stored in an encrypted form. Use the [bcrypt](https://en.wikipedia.org/wiki/Bcrypt)
algorithm to encrypt the passwords. All the necessary keys should be stored as environment variables for
the encryption. You can use the official bcrypt java library.

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Guarded endpoint

The `/user/{id}` endpoint should be guarded by required authentication.

```gherkin
Feature: Required auth

Scenario: No auth token
 Given the application running
   And a valid token: "apple"
  When the '/user/1' endpoint is requested with a 'GET' request
   And no Authorization header is provided
  Then it should send a 401 response with a JSON:
   """
   {
     "errors": [{
       "status": "401",
       "title": "Unauthorized",
       "detail": "No token is provided"
     }]
   }
   """
```

```gherkin
Feature: Required auth

Scenario: Auth token
 Given the application running
   And a valid token: "apple"
  When the '/user/1' endpoint is requested with a 'GET' request
   And with a header: Authorization: Bearer apple
  Then it should send a 201 response with a JSON:
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

```gherkin
Feature: Required auth

Scenario: Auth token
 Given the application running
   And a valid token: "apple"
  When the '/user/1' endpoint is requested with a 'GET' request
   And with a header: Authorization: Bearer pear
  Then it should send a 401 response with a JSON:
   """
   {
     "errors": [{
       "status": "401",
       "title": "Unauthorized",
       "detail": "No token is provided"
     }]
   }
   """
```

### Login

Create a simple endpoint for logging the user in

```gherkin
Feature: Register

Scenario: Register
 Given the application running
   And 0 users in the database
  When the '/login' endpoint is requested with a 'POST' request:
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
  Then it should send a 200 response with a JSON:
   """
   {
     "data": {
       "type": "user",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }
   }
   """
```

### Users CRUD

Create anendpoint for listing, creating, removing updating and deleting user entities.

```gherkin
Feature: List users

Scenario: Good request
 Given the application running
  When the '/api/users' endpoint is requested with a 'GET' request
  Then it should return a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/users"
     }
     "data": [{
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }]
   } 
   """
```


```gherkin
Feature: Users pagination

Scenario: More than 20
 Given the application running
   And 200 users in the database
  When the '/api/users' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/users",
       "next": "https://your-hostname.com/api/users?page=2",
       "last": "https://your-hostname.com/api/users?page=10",
     }
     "data": [{
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }, {
       ...
     } ...]
   }
   """
```

```gherkin
Feature: users pagination

Scenario: Second page
 Given the application running
   And 200 users in the database
  When the '/api/users?page=2' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/users?page=2",
       "next": "https://your-hostname.com/api/users?page=3",
       "prev": "https://your-hostname.com/api/users",
       "last": "https://your-hostname.com/api/users?page=10",
     }
     "data": [{
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }, {
       ...
     } ...]
   }
   """
```

### User filtering

The user endpoint should be able to filter on the attributes.

```gherkin
Feature: filter by admin

Scenario: by admin
 Given the application running
   And 10 users in the database
  When the '/api/users?admin=true' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/users?currency=EUR"
     }
     "data": [{
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }]
   }
   """

```

#### Technical requirements

It should accept all the attributes as filter paramters.


### Get Single User 

Create an endpoint for a single user 

```gherkin
Feature: Single User

Scenario: Single user
 Given the application running
   And 200 users in the database
  When the '/api/users/1' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/users/1"
     }
     "data": {
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": false,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }
   }
   """
```

```gherkin
Feature: Single user

Scenario: Single user
 Given the application running
   And 0 users in the database
  When the '/api/users/1' endpoint is requested with a 'GET' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No users found by id: 1"
     }]
   }
   """
```


### Delete Single user 

Create an endpoint for a single user

```gherkin
Feature: Single user

Scenario: Single user
 Given the application running
   And 200 users in the database
  When the '/api/users/1' endpoint is requested with a 'DELETE' request
  Then it should send a 200 response with a JSON:
   """
   {
   }
   """
   And delete the user with id 1
```

```gherkin
Feature: Single user

Scenario: Single user
 Given the application running
   And 0 users in the database
  When the '/api/users/1' endpoint is requested with a 'DELETE' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No users found by id: 1"
     }]
   }
   """
```

### Update Single

Create an endpoint for a single user

```gherkin
Feature: Single user

Scenario: Single user
 Given the application running
   And 200 users in the database
  When the '/api/users/1' endpoint is requested with a 'PATCH' request
   """
   {
     "data": {
       "type": "users",
       "id": "1",
       "attributes": {
         "admin": "true"
       }
     }
   }
   """
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/users/1"
     }
     "data": {
       "type": "users",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "admin": true,
         "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjEiLCJlbWFpbCI6ImpvaG4uZG9lQGV4YW1wbGUub3JnIiwiYWRtaW4iOmZhbHNlfQ.UK8Z1BNeHWvaFElWrrSxhO6oxTRaMW_66DO5yjkqOhM"
       }
     }
   }
   """
   And update the attributes of the user entity

```

```gherkin
Feature: Single user

Scenario: Single user
 Given the application running
   And 0 users in the database
  When the '/api/users/1' endpoint is requested with a 'PATCH' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No users found by id: 1"
     }]
   }
   """
```

### Authentication microserrvice

Create a separate microservice for handling authentication, and refactor the
current microservice to only focus on user storage.

The new microservice should have the `/login` and `/register` endpoints, 
the old should have the full CRUD operation for users. The authentication service
should call the user microservice for reading the user properties or creating a new user.

The authentication microservice should proxy the user CRUD endpoint, by guarding
the read of users by tokens.

Any admin role user should be able to:
 - Create a new user
 - List any user
 - Update any user
 - Delete any user

Any normal role user shoud be able to:
 - List any user
 - Update itself
 - Delete itself

### Logging package

Create a separate package that is include-able from gradle. The package should
contain the logging unit and both microservices should use this package for logging.
Try to avoid almost all possible code duplication between the services.

Implement the package in a separate github repository, with full continous integration
pipeline. The package should be independent from any hotel booking related feature.

The package should be obtainable from maven central.
