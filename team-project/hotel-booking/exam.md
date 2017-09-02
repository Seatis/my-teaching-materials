# Exam applivation

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

### Create an endpoint that stores geolocations

Create a REST endpoint for managing locations

```gherkin
Feature: List locations

Scenario: Good request
 Given the application running
  When the '/api/locations' endpoint is requested with a 'GET' request
  Then it should return a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/locations"
     }
     "data": [{
       "type": "locations",
       "id": "1",
       "attributes": {
         "name": "Budapest, Ipoly utca",
         "lat": 47.5145641,
         "long": 19.051597
       }
     }]
   } 
   """
```

#### Technical Requirements

The API should follow the [JSON-API](http://jsonapi.org/) specification guidelines.
The locations should be stored in the database.

### Location pagination

The rest endpoint should have pagination if there are more than 20 locations

```gherkin
Feature: Location pagination

Scenario: More than 20
 Given the application running
   And 200 locations in the database
  When the '/api/locations' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/locations",
       "next": "https://your-hostname.com/api/locations?page=2",
       "last": "https://your-hostname.com/api/locations?page=10",
     }
     "data": [{
       "type": "locations",
       "id": "1",
       "attributes": {
         "name": "Budapest, Ipoly utca",
         "lat": 47.5145641,
         "long": 19.051597
       }
     }, {
       ...
     } ...]
   }
   """
```

```gherkin
Feature: Locations pagination

Scenario: Second page
 Given the application running
   And 200 locations in the database
  When the /api'/locations?page=2' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/locations?page=2",
       "next": "https://your-hostname.com/api/locations?page=3",
       "prev": "https://your-hostname.com/api/locations",
       "last": "https://your-hostname.com/api/locations?page=10",
     }
     "data": [{
       "type": "locations",
       "id": "1",
       "attributes": {
         "name": "Budapest, Ipoly utca",
         "lat": 47.5145641,
         "long": 19.051597
       }
     }, {
       ...
     } ...]
   }
   """
```

### Add location

Create a rest endpoint for creating new locations

```gherkin
Feature: Add location
 Given the application running
   And 0 locations in the database
  When the '/api/locations' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "locations",
       "attributes": {
         "name": "Budapest, Ipoly utca",
         "lat": 47.5145641,
         "long": 19.051597
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/locations/1"
     }
     "data": {
       "type": "locations",
       "id": "1",
       "attributes": {
         "name": "Budapest, Ipoly utca",
         "lat": 47.5145641,
         "long": 19.051597
       }
     }
   }
   """

Feature: Add location
 Given the application running
   And 0 locations in the database
  When the '/api/locations' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "locations",
       "attributes": {
         "name": "Budapest, Ipoly utca"
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
       "detail": "The attribute fields: \"lat\", \"long\" are missing"
     }]
   }
   """
```





