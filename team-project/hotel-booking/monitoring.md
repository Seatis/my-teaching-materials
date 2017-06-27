# Monitoring and Analytics Service

A microservice inside the hotel booking project. This service is responsible for
monitoring all the other services. It defines an API for the ather services, and
all the other services are able to send events. It aggregates data about user
behaviur provides an API to query it. 

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements a simple API for registering events, that is called by other
services. For persistent event storing it uses RabbitMQ as a message queue.
It saves the events and the aggregations to Postgre SQL using JPA.

## Main features
 -  Receive and save events
 -  Save events persistently using message queues
 -  Aggregation jobs
 -  Alerting


## [Repository](https://github.com/greenfox-academy/hotel-booking-monitoring-service)

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

### Monitoring services

Create a monitor endpoint that checks all the microservices.

```gherkin
Feature: Monitoring

Scenario: Monitor
 Given the application running
   And a config file "monitoring-services.json":
   """
   {
     "services": [{
       "host": "service1.herokuapp.com",
       "contact": "dev1@hotel-booking.com"
     }]
   }
   """
  When the '/monitor' endpoint is requested with a 'GET' request
  Then it should call the '/heartbeat' endpoint on 'service1.herokuapp.com'
   And if the service responses "ok" response:
   """
   {
     "statuses": [{
       "name": "service1.herokuapp.com",
       "status": "ok"
     }]
   }
   """
```

#### Technical Requirements

The endpoint should check each of the services that are saved in the config file.

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Page view

Create an endpoint that returns the aggregated page view events.

```gherkin
Feature: Page view tracking

Scenario: Aggregating page view
 Given the application running
  When a page view event is received in the queue
  Then it should save and aggregate it into the database

Scenario: Page view endpoint
 Given the application running
  When the '/pageviews' endpoint is requested with a "GET" request
  Then it should response:
   """
   {
     "links": {
       "self": "https://your-hostname.com/pageviews"
     },
     "data": [{
       "type": "pageviews",
       "id": 1,
       "attributes": {
         "path": "/search",
         "count: 123
       }
     }, {  
       "type": "pageviews",
       "id": 2,
       "attributes": {
         "path": "/checkout",
         "count: 12
       }
     }]
   }
   """
```

### Technical requirements

Each event should be stored as JSON in the message queue. Each event should have
a `type` key.
A typical page view event:
```json
{
  "type": "page-view",
  "path": "/search",
  "trackingId": "5431325134"
}
```

### Pageview pagination

The rest endpoint should have pagination if there are more than 20 pageview

```gherkin
Feature: Pageview pagination

Scenario: More than 20
 Given the application running
   And 200 pageviews in the database
  When the '/pageviews' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/pageviews",
       "next": "https://your-hostname.com/pageviews?page=2",
       "last": "https://your-hostname.com/pageviews?page=10",
     }
     "data": [{
       "type": "pageviews",
       "id": "1",
       "attributes": {
         "path": "/search",
         "count: 123
       }
     }, {
       ...
     } ...]
   }
   """
```

```gherkin
Feature: Pageviews pagination

Scenario: Second page
 Given the application running
   And 200 pageviews in the database
  When the '/pageviews?page=2' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/pageviews?page=2",
       "next": "https://your-hostname.com/pageviews?page=3",
       "prev": "https://your-hostname.com/pageviews",
       "last": "https://your-hostname.com/pageviews?page=10",
     }
     "data": [{
       "type": "pageviews",
       "id": "1",
       "attributes": {
         "path": "/search",
         "count: 123
       }
     }, {
       ...
     } ...]
   }
   """
```

### Pageviews filtering

The pageview endpoint should be able to filter on path.

```gherkin
Feature: filter by path

Scenario: by path
 Given the application running
   And 10 pageviews in the database
   And one of them is '/search'
  When the '/pageviews?path=%2fsearch' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/pageviews?path=%2fsearch"
     }
     "data": [{
       "type": "pageviews",
       "id": "1",
       "attributes": {
         "path": "/search",
         "count: 123
       }
     }]
   }
   """

```

### Pageview min max

The pageview endpoint should have a `min` and a `max` filter parameter, both holding
a number value. If the `min` parameter is present, it should only show page views that
have a higher count than the given parameter. The `max` parameter should work the same
way just showing the events with the lower counts.

### Daily Aggregation
