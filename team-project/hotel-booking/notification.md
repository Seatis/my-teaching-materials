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

