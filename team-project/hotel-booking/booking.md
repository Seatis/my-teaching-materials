# Booking and Resource Backend Service

## Description

A microservice inside the hotel booking project. This microservice is responsible for
tracking all the available resources and bookings.

## Technology

This service is a Spring Boot application deployed to Heroku.
It implements a REST API for manage hotels, rooms and bookings.
The database layer is using Postgre SQL and JPA. This project is quite database
and data heavy, you can expect quite a few different queries, filterings and 
multiple joint tables.

## Main features

 -  Manage hotels
 -  Manage bookings
 -  Manage rooms
 -  Rate hotels and rooms
 -  Availability management
 -  Search based on
     -  Date
     -  Location
     -  Price
     -  Rating

