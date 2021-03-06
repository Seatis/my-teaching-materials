# Image resize and Geo Location Service

A microservice inside the hotel booking project. This service is responsible for
resizing and storing the uploaded images and retriving geo location based on
city names. 

## Technology

This service is a Spring Boot application deployed to Heroku.
It saves the images to a 3rd party file hosting service, then creates the desired
resized versions, to the same service. It uses RabbitMQ to schedule the resizing
tasks. It also uses 3rd party APIs to retirve geo location based on given city
names. Also calculating distances between cities.

## Main features
 -  Receive and upload files to hosting service
 -  Resize image
 -  Schedule jobs using message queue
 -  Retrive geolocation
 -  Calculate distances


## [Repository](https://github.com/greenfox-academy/hotel-booking-resize-service)

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

### Save image

Create an enpoint for saving images

```gherkin
Feature: Add image

Scenario: Upload request
 Given the application running
   And 0 images in the database
  When the '/images' endpoint is requested with a 'POST' request with a jpg file
  Then it should send a 201 response with a JSON:
   """
   {
     "data": {
       "type": "images",
       "attributes": {
         "id": "1"
       }
     }
   }
   """
```

### Upload image to S3

The /images endpoint should upload the image to S3

```gherkin
Feature: Upload image

Scenario: Upload request
 Given the application running
   And 0 images in the database
  When the '/images' endpoint is requested with a 'POST' request with a jpg file
  Then it should upload the given image to S3
   And it should send a 201 response with a JSON:
   """
   {
     "data": {
       "type": "images",
       "attributes": {
         "id": "1",
         "url": "s3-eu-west-1.amazonaws.com/somebucket/filename.jpg"
       }
     }
   }
   """
```

#### Technical Requirements

Use the official [AWS java API](http://docs.aws.amazon.com/AmazonS3/latest/dev/UploadObjSingleOpJava.html)
for uploading images to S3. Store the Amazon credentials in environment variables, do not commit them.

### Rename image

The `/images` endpoint should give the image a uniq name

```gherkin
Feature: Rename image

Scenario: Generate name
 Given the application running
   And 0 images in the database
  When the '/images' endpoint is requested with a 'POST' request with a jpg file
  Then it should generate a uniq 12 character name for the file.
   And it should upload the given image to S3
   And it should send a 201 response with a JSON:
   """
   {
     "data": {
       "type": "images",
       "attributes": {
         "id": "1",
         "url": "s3-eu-west-1.amazonaws.com/somebucket/hj2rtk4ds7pl.jpg"
       }
     }
   }
   """
```

### Refactor Logging 

Refactor the logging of enpoints using Aspect Oriented Programming.
Learn about Spect Oriented Programming in Spring [here](https://www.youtube.com/playlist?list=PLE37064DE302862F8).
Refactor your code to use aspects for logging on each endpoint.

### Add Thumbnail

Create a rest endpoint for creating new thumbnails

```gherkin
Feature: Add thumbnail
 Given the application running
   And 0 thumbnails in the database
  When the '/hotels/1/thumbnails' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "thumbnails",
       "attributes": {
         "is_main": true
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels/1/thumbnails/1"
     }
     "data": {
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": true,
         "uploaded": false,
         "created_at": "2017-06-26T14:05:10+0000",
         "content_url": "https://your-hostname.com/media/images/1/content
       }
     }
   }
   """

Feature: Add thumbnail
 Given the application running
   And 0 thumbnails in the database
  When the '/hotels/1/thumbnails' endpoint is requested with a 'POST' request with data like:
   """
   {
     "data": {
       "type": "thumbnails",
       "attributes": {
       }
     }
   }
   """
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels/1/thumbnails/1"
     }
     "data": {
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": false,
         "uploaded": false,
         "created_at": "2017-06-26T14:05:10+0000",
         "content_url": "https://your-hostname.com/media/images/1/content
       }
     }
   }
   """
```

### Thumbnail Listing`

Create a rest endpoint for listing thumbnails

```gherkin
Feature: Add thumbnail
 Given the application running
   And 2 thumbnails in the database
  When the '/hotels/1/thumbnails' endpoint is requested with a 'GET' request
  Then it should send a 201 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels/1/thumbnails"
     }
     "data": [
       {
         "type": "thumbnails",
         "id": "1",
         "attributes": {
           "is_main": true,
           "uploaded": false,
           "created_at": "2017-06-26T14:05:10+0000",
           "content_url": "https://your-hostname.com/media/images/1/content
         }
       },
       {
         "type": "thumbnails",
         "id": "2",
         "attributes": {
           "is_main": false,
           "uploaded": false,
           "created_at": "2017-06-26T14:05:10+0000",
           "content_url": "https://your-hostname.com/media/images/2/content
         }
       }
     ]
   }
   """
```


### Thumbnail filtering

The thumbnail endpoint should be able to filter on the attributes.

```gherkin
Feature: filter by is_main

Scenario: by is_main
 Given the application running
   And 10 hotels in the database
  When the '/hotels/1/thumbnails?is_main=true' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/hotels/1/thumbnails?is_main=true"
     }
     "data": [{
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": true,
         "uploaded": false,
         "created_at": "2017-06-26T14:05:10+0000",
         "content_url": "https://your-hostname.com/media/images/1/content
       }
     }]
   }
   """
```

#### Technical requirements

It should accept all the attributes as filter paramters.

### Get Single Thumbnail

Create an endpoint for a single Thumbnail

```gherkin
Feature: Single Thumbnail

Scenario: Single Thumbnail
 Given the application running
   And 200 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'GET' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1/thumbnails/1"
     }
     "data": {
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": true,
         "uploaded": false,
         "created_at": "2017-06-26T14:05:10+0000",
         "content_url": "https://your-hostname.com/media/images/1/content
       }
     }
   }
   """
```

```gherkin
Feature: Single Thumbnail

Scenario: Single Thumbnail
 Given the application running
   And 0 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'GET' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No thumbnails found by id: 1"
     }]
   }
   """
```


### Delete Single Thumbnail 

Create an endpoint for a single thumbnail

```gherkin
Feature: Single Thumbnail

Scenario: Single thumbnail
 Given the application running
   And 200 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'DELETE' request
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1/thumbnails/1"
     }
   }
   """
   And delete the thumbnail with id 1
```

```gherkin
Feature: Single Thumbnail

Scenario: Single thumbnail
 Given the application running
   And 0 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'DELETE' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No thumbnails found by id: 1"
     }]
   }
   """
```

### Update Single Thumbnails

Create an endpoint for a single thumbnails

```gherkin
Feature: Single Thumbnails

Scenario: Single Thumbnails
 Given the application running
   And 200 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'PATCH' request
   """
   {
     "data": {
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": false
       }
     }
   }
   """
  Then it should send a 200 response with a JSON:
   """
   {
     "links": {
       "self": "https://your-hostname.com/api/hotels/1/thumbnails/1"
     }
     "data": {
       "type": "thumbnails",
       "id": "1",
       "attributes": {
         "is_main": false,
         "uploaded": false,
         "created_at": "2017-06-26T14:05:10+0000",
         "content_url": "https://your-hostname.com/media/images/1/content
       }
     }
   }
   """
   And update the attributes of the thumbnail entity

```

```gherkin
Feature: Single Thumbnail

Scenario: Single Thumbnail
 Given the application running
   And 0 thumbnails in the database
  When the '/hotels/1/thumbnails/1' endpoint is requested with a 'PATCH' request
  Then it should send a 404 response with a JSON:
   """
   {
     "errors": [{
       "status": "404",
       "title": "Not Found",
       "detail": "No thumbnails found by id: 1"
     }]
   }
   """
```

### Refactor add image

Remove the old `/images` endpoint and replace it with: `/media/images/{id}`.
A POST request on the new endpoint should upload the posted image to S3 and
give it a unique name like in the old endpoint. A GET request on the new endpoint
should redirect to the uploaded image.

### Error on image size

If the uploaded image is bigger than 1MB the endpoint should not upload it to S#
and it should response a 413 response like:
```
{
  "errors": [{
    "status": "413",
    "title": "Payload Too Large",
    "detail": "The image cannot be bigger than 1MB"
  }]
}
```

### Resize image

When an image is uploaded to S3, the service should upload a resized version as well,
beside the original version. First it should crop the image to 4:3 portait ratio, from
the middle of the image. Then it should resize it to 200x150 pixels. Then it should upload the image
to S3, with a `_200x150` postfix. (if the image name is `hj2rtk4ds7pl.jpg` then
the resized image should be: `hj2rtk4ds7pl_200x150.jpg`)

### Image validation

If the uploaded image type is not supported or it is smaller than 200x150 in any
dimension it should response a 406 response.

The rsponse on unsupported type:
```
{
  "errors": [{
    "status": "406",
    "title": "Not Acceptable",
    "detail": "The image type should be one of the following: jpeg, gif, png"
  }]
}
```

The resonse on not sufficient size:
```
{
  "errors": [{
    "status": "413",
    "title": "Not Acceptable",
    "detail": "The image cannot be smaller than 200x150"
  }]
}
```

### Reach images

The `/media/iamges/{id}` endpoint should response the original image.
The `/media/images/{id}/resize/200/150` should response the resized image.
Any other size parameter should be handeled as an error and response 400 like:
```
{
  "errors": [{
    "status": "400",
    "title": "Bad Request",
    "detail": "Unsupported image size. Supported sizes: 200x150"
  }]
}
```

### Thumbnail ready

If the images are both uploaded it should set `uploaded` flag on the corresponding
thumbnail to true.

### Reliable image resize

If an image is uploaded to S3 the microservice should not start the resize right away.
It should put a resize event into a message queue, and a consumer should read the
events from the queue and resize and upload them 1 by 1. If anything fails during
the process it should push back the event to the message queue.


