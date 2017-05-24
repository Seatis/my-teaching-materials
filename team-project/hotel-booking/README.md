# Hotel Booking

## Description

A management system for booking hotels, and managing its resourses.
The project is separated to 6 microservices and 2 frontend repository.
The main goal of the project is to simulate a microservce architecture,
where each of the teams has to collaborate, to create a working application,
by implementing APIs between the services.

## Technology

The backend microservices are Spring Boot applications deployed to Heroku.
The communication os mostly solved by HTTP calls on REST APIs between the services,
in some cases the channel is offloaded by RabbitMQ message queues.
The database layer is using Postgre SQL and JPA.
The frontends are separate single page applications, implemented using
Angular 4, none of the pages are rendered on the backend side.
The deploy is solved by codeship on the backend and the frontend side as well.
Each of the applications (both frontend and backend) are deployed in a separate
pipeline. All the tests and stylecheck runs before the deploys.

## Main features

 - List possible bookings
 - Filtering
 - Rating
 - Availability management
 - Monitoring
 - Trafic analytics
 - User profile and authentication
 - Booking history
 - Image handling
 - Payment and Currency

## Project Teams
 
 - [Booking and Listing Backend Service]()
 - [Availability and Resource Backend Service]()
 - [Currency and Payment Backend Service]()
 - [Monitoring and Analytics Backend Service]()
 - [User Profile and Authentication Backend Service]()
 - [Image resize and Geo Location Backend Services]()
 - [Booking Frontend]()
 - [Administration Frontend]()