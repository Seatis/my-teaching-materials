# User Profile and Authentication Service

A microservice inside the hotel booking project. This service is responsible for
handling users, user profiles and authentication. It distinguishes between diffetent
user roles like end user and admin. It allows registration and login with Facebook
authentication.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements an API for registering ang logging in users. It stores all the user
data in a Postre SQL database using JPA. It has to integrate with the Facebook
API using OAuth.

## Main features

 -  Register
 -  Login
 -  User profile
 -  Session handling
 -  Facebook authentication


