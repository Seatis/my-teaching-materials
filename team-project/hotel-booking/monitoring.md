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


