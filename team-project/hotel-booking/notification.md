# Notification Backend Service

## Description

A microservice inside the hotel booking project. This service is responsible for
notifying the users and admins about the the states of the bookings.
It is also responsible for time management of the bookings, so this service deletes
the obsolete bookings for example.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements a simple API for trigger notifications, that is called by other
services. For sending email notifications it has to integrate with 3rd party
services (like Amazon SES or Sendgrid). For the time management and for reliable notification sending it uses
RabbitMQ as a message queue.

## Main features
 -  Send emails
 -  Email templating
 -  Reliable message sending using message queue
 -  Change the state of the bookings based on time
 -  Time and job management using message queues


## [Repository](https://github.com/greenfox-academy/hotel-booking-notification-service)

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

### Registration email

Create an endpoint that sends a registration email

```gherkin
Feature: Registration email

Scenario: Send registration email
 Given the application running
  When the '/email/registration' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "email",
       "attributes": {
         "email": "john.doe@example.org",
         "name": "john.doe",
         "url": "https://hotel-booking.com/confirm/sdfkksdfa"
       }
     }
   }
   """
  Then it should send a registration email to 'john.doe@example.org':
   """
   Dear john.doe,

   Please confirm your email address here: https://hotel-booking.com/confirm/sdfkksdfa !

   Regards,
   The Hotel Booking site
   """
 
```

#### Technical Requirements

Use the SendGrid heroku addon for sending emails.

### Reliable Message sending

Use a message queue for sending messages

#### Technical requirements

Each of the emails that the service has to send, should be stored in a message
queue, for reliable sending. The queue should store the already formatted
emails with all the necessary information for sending it. A separate message sender
service should send the emails from the queue. If there was any error with sending the email,
it should push back the email to the queue.

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Exponential retry of emails

If the service failed to send an email it should retry it with a delay.
The delay time should be stored in an environment variable. On each retry
the delay time of the current email sending should increase by its double.
It should retry it till a certain amount that is stored in a environment variable.

### Ticking queue

Create a RabbitMQ consumer and a corresponding queue. The consumer should
consume an event in every 5 minutes and push it back to the queue. The event should
store a simple number, that is incremented by one on each read. The consumer should
log this value in debug level.

### Unsubscribe

Create a rest endpoint for creating new unsubscriptions

```gherkin
Feature: Add unsubscription
 Given the application running
   And 0 unsubscription in the database
  When the '/unsubscribtions' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "unsubscribtions",
       "attributes": {
         "email": "john.doe@example.org",
         "created_at": 2017-06-26T14:05:10+0000
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/unsubscriptions/1"
     }
     "data": {
       "type": "unsubscriptions",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "created_at": 2017-06-26T14:05:10+0000
       }
     }
   }
   """

Feature: Add unsubscription
 Given the application running
   And 0 unsubscriptions in the database
  When the '/unsubscriptions' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "unsubscriptions",
       "attributes": {
         "email": "john.doe@example.org",
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/unsubscriptions/1"
     }
     "data": {
       "type": "unsubscriptions",
       "id": "1",
       "attributes": {
         "email": "john.doe@example.org",
         "created_at": 2017-06-26T14:05:10+0000
       }
     }
   }
   """

Feature: Add unsubscription
 Given the application running
   And 0 unsubscriptions in the database
  When the '/unsubscriptions' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "unsubscriptions",
       "attributes": {
         "created_at": 2017-06-26T14:05:10+0000
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
       "detail": "The attribute field: \"email\" is missing"
     }]
   }
   """
```




