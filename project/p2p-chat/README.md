# Peer to Peer Chat application

*Write a chat application that connects to other peer applications and chat your
fellow Green Foxers*

## Tasks

### Main page

Create a main page containing a heading that is accessable from the `/` route.

![heading](assets/heading.png)

The application should conenct to a local SQL database.

### Production environment

Deploy your application to heroku, and set up the database using the heroku postgre addon.

The application should be accesable by its heroku hostname.

![heading with heroku](assets/heroku.png)

### Logging

Each http request should be logged to the standard out, also if any error has happened in the routes
it should log the error to the standard error.
The log message should have the following fields:

 - **Path**: The path of the endpoint like: `/`
 - **Method**: The method of the endpoint like: `GET`
 - **Date and Time**: It should print the date in a format like this: `2017-05-16 21:47:19.040`
 - **Log Level**: `INFO` on http requests and `ERROR` on any occured error
 - **Request Data**: It should log all the request params from the endpoint

The log should look like this:
`2017-05-16 21:47:19.040 INFO Request /message POST text=apple`

The logs should be configurable by an environment variable called `CHAT_APP_LOGLLEVEL`

About environment variables: [Windows](https://www.youtube.com/watch?v=bEroNNzqlF4), [Linux + Mac](https://www.youtube.com/watch?v=pjh9rU9h22Q)

Reading environment variables in java: [This article](https://docs.oracle.com/javase/tutorial/essential/environment/env.html)

If the environment is set to `ERROR` it should only print the error messages, any other cases it should print both error and info level mesages.

Try your environment variables on heroku as well: [This article](https://devcenter.heroku.com/articles/config-vars)

### Save new message

### Client id and peer address

### Receive new message

### Broadcast new message

### Receive own message

### Try it with your fellowa

### Better looking frontend

### Auto refresh
