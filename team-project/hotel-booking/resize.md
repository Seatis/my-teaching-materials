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


