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
