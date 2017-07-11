# Currency and Payment Backend Service

## Description

A microservice inside the hotel booking project. This service is responsible for
payments. It is connected to a payment gateway like stripe. It stores all the
transactions and balances for both the hotels and the end users.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements a simple API for trigger notifications, that is called by other
services. For transactions it has to integrate with a 3rd party service
(like Stripe or Paypal). It saves the transactions to Postgre SQL using JPA.

## Main Features
 -  Payment with bankcard
 -  Tracking transactions and balances
 -  Retry payment using message queue
 -  Multiple currerncy support

## [Repository](https://github.com/greenfox-academy/hotel-booking-currency-service)

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
  When the '/heartbeat' endpoint is requested with 'GET' method
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
  When the '/heartbeat' endpoint is requested with 'GET' method
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

### Payment page for 50 Eur

Create a simple page for payments that is includable by frontend services.

```gherkin
Feature: Payment form

Scenario: Open form
 Given the application running
  When the '/checkout' page is requested
  Then it should render the checkout form for 50 'Euro'
```

#### Technical Requirements

The checkout for should use the [Stripe checkout](https://stripe.com/checkout).
 - The currency should be Euros
 - The amount should be 50
 - The form should get the Stripe public key from an environment variable.

### Charge

The checkout form should send the payment to the server

```gherkin
Feature: Charge

Scenario: Charge
 Given the application running
  When the checkout for is submitted to '/charge'
  Then it should submit the transaction to Stripe
   And save the transaction to the database
   And render a page with a success message
```

#### Technical Requirements

Use the stripe Java API to submit the charge to Stripe.

### Checkout tracking

Track transactions in the database

```gherkin
Feature: Checkout

Scenario: Create checkout
 Given the application running
   And 0 checkouts in the 
  When the '/api/checkouts' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "checkout",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR"
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/checkout/1"
     }
     "data": {
       "type": "checkout",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }
   }
   """

Feature: Missing field
 Given the application running
   And 0 hotels in the database
  When the '/hotels' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "checkout",
       "attributes": {
         "user_id": "1",
         "currency": "EUR"
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
       "detail": "The attribute fields: \"booking_id\", \"amount\" are missingo"
     }]
   }
   """
```

### Checkout tracking payment page

```gherkin
Feature: Payment page tracking

Scenario: Paymanet page with checkout id
 Given a checkout in the database:
  | id | user_id | booking_id | amount | currency |  status |
  |  1 |       1 |          1 |   8000 |      EUR | pending |
  When the '/checkout?checkout_id=1' page is requested
  Then it should render the checkout form for 80 'Euro'
```

### Checkout tracking charge

The checkout form should send the payment to the server

```gherkin
Feature: Charge tracking

Scenario: Charge with checkout_id
 Given a checkout in the database:
  | id | user_id | booking_id | amount | currency |
  |  1 |       1 |          1 |   8000 |      EUR | 
  When the checkout for is submitted to '/charge'
  Then it should send the checkout_id as a parameter
   And it should submit the transaction to Stripe
   And save the transaction to the database
   And render a page with a success message
   And it should update the checkout status to success
```

### Checkout CRUD

Create anendpoint for listing, creating, removing updating and deleting checkout entities.

```gherkin
Feature: List checkouts

Scenario: Good request
 Given the application running
  When the '/api/checkouts' endpoint is requested with a 'GET' request
  Then it should return a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts"
     }
     "data": [{
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }]
   } 
   """
```


```gherkin
Feature: Checkouts pagination

Scenario: More than 20
 Given the application running
   And 200 xheckouts in the database
  When the '/api/checkouts' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts",
       "next": "https://your-hostname.com/api/checkouts?page=2",
       "last": "https://your-hostname.com/api/checkouts?page=10",
     }
     "data": [{
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }, {
       ...
     } ...]
   }
   """
```

```gherkin
Feature: Checkouts pagination

Scenario: Second page
 Given the application running
   And 200 checkouts in the database
  When the '/api/checkouts?page=2' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts?page=2",
       "next": "https://your-hostname.com/api/checkouts?page=3",
       "prev": "https://your-hostname.com/api/checkouts",
       "last": "https://your-hostname.com/api/checkouts?page=10",
     }
     "data": [{
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }, {
       ...
     } ...]
   }
   """
```

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Pageviews filtering

The checkout endpoint should be able to filter on the attributes.

```gherkin
Feature: filter by currency

Scenario: by currency
 Given the application running
   And 10 checkouts in the database
  When the '/checkouts?currency=EUR' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/checkouts?currency=EUR"
     }
     "data": [{
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }]
   }
   """

```

#### Technical requirements

It should accept all the attributes as filter paramters.


### Get Single Checkout 

Create an endpoint for a single checkout

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 200 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts/1"
     }
     "data": {
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "EUR",
         "status": "pending"
       }
     }
   }
   """
```

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 0 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'GET' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No checkouts found by id: 1"
     }]
   }
   """
```


### Delete Single Checkout 

Create an endpoint for a single checkout

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 200 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'DELETE' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts/1"
     }
   }
   """
   And delete the checkout with id 1
```

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 0 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'DELETE' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No checkouts found by id: 1"
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
   And 200 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'PATCH' request
   """
   {
     "data": {
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "currency": "USD"
       }
     }
   }
   """
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/checkouts/1"
     }
     "data": {
       "type": "checkouts",
       "id": "1",
       "attributes": {
         "user_id": "1",
         "booking_id": "1",
         "amount": "50",
         "currency": "USD",
         "status": "pending"
       }
     }
   }
   """
   And update the attributes of the checkout entity

```

```gherkin
Feature: Single Checkout

Scenario: Single Checkout
 Given the application running
   And 0 checkouts in the database
  When the '/api/checkouts/1' endpoint is requested with a 'PATCH' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No checkouts found by id: 1"
     }]
   }
   """
```

### Transactions

Create an endpoint for requesting transactions.

The path should look like this: `/api/hotel/1/transactions`.
It should store the transactions for the hotel with 1 as id. 
Each transaction should store the following values:

 - **id**: number
 - **currency**: string
 - **amount**: number
 - **created_at**: timestamp

The endpoint should list the transactions, and it should be filterable by query parameters.
Also it should handle adding a new transaction.

Implement an endpoint for single transactions as well like: `/api/hotel/1/transactions/1`.
The endpoint should handle reading, updating and deleting.

Please handle all the errors that could occure, and use the corresponding http status.

### Save transactions on checkout

On each successful checkout, save a transaction entity to the database.

### Balance

Create and endpoint for aggregated balances from transactions.
The path of the endpoint: `/api/hotels/1/balances/`

```gherkin
Feature: Balance

Scenario: balance
 Given the application running
   And 4 transactions in the database for the hotet with 1 as id:
    | id | currency | amount |                created_at |
    |  1 |     eur  |   5000 | 2017-06-28T15:10:33+00:00 |
    |  2 |     huf  |  50000 | 2017-06-28T15:10:33+00:00 |
    |  3 |     eur  |   4000 | 2017-06-28T15:10:33+00:00 |
    |  4 |     usd  |   3000 | 2017-06-28T15:10:33+00:00 |
  When the '/api/hotel/1/balance' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1/balances"
     }
     "data": {
       "type": "balances",
       "attributes": {
         "eur": 9000,
         "huf": 50000,
         "usd": 3000
       }
     }
   }
   """

```

### Balance filtering

The `/api/hotels/1/balances/` endpiont should be configurable by dates.
A `from` and `to` query parameter could be provided, then it should only consider
transactions between these dates. Both parameters are optional.

### Exchange

The `/api/hotels/1/balances/` endpoint should have a possible `currency` parameter.
If it is provided it should give back the whole balance in only that currency.
Use [fixer](http://fixer.io/) for the exchange rate. The current exchange rate is sufficient.

### Exchange on real date

When the `/api/hotels/1/balances/` endpoint exchanges the balances, it should convert
the currencies based on the date of the transactions. The program should cache the
exchange rates to the database to not initiate the http request on each transaction
exchange.
