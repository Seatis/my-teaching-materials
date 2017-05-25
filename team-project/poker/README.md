# Online Poker site

## Description

An online poker website where multiple users can play simultaniously in multiple game rooms.
1 back end and 1 front end team works on this project.
The main goal is to
- create a working application where several developers collaborate in Scrum metodology
- clearly separate back end and front end functionality
- implement proper APIs and web sockets for back end - front end communication

## Technology

The backend microservices are Spring Boot applications deployed to Heroku.
The communication is mostly solved by HTTP calls on REST APIs that invoke web sockets,
in some cases the channel is offloaded by RabbitMQ message queues.
The database layer is using Postgre SQL and JPA.
The frontend is a multi page application, implemented using
Angular 4, none of the pages are rendered on the backend side.
The deploy is solved by codeship on the back end and the front end side as well.
Each of the applications (both front end and back end) are deployed in a separate
pipeline. All the tests and stylecheck runs before the deploys.
During the continous developement process we use test and producation environments.

## Main features

 - View ongoing games without login
 - Login with OAuth 2 autentication (allows Google and Github autentication)
 - Profile page with personal statistics
 - Main screen with running poker tables
 - Join to an existing table and play poker with others
 - Create a new poker table and wait for others to join the game
 - Fake money payment system

## Project Teams
 
 - [Poker frontend team]()
 - [Poker backend team]()
