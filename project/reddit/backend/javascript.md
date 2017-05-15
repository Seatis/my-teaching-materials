# The Reddit Javascript REST backend

We'll create a simple reddit clone application, where the users can create posts and upvote / downvote existing posts. Later on you can extend this functionality.

This page focuses on the RESTful backend written in Javascript. If you follow the [API Specification](../apispec.md), then you'll be able to connect the backend with the frontend.

## User stories

### Initialize a new npm project

 -  use `npm init`
 -  you'll need `express`, `body-parser` and `mysql` as dependencies
 -  do not forget to use `--save` command line flag to automatically add the packages to your package.json
 -  exclude node_modules in your .gitignore

### Check out the API Specification

 -  [API Specification](../apispec.md)
 -  think about how many endpoints will be needed
 -  *ignore the (Optional) parts at first, those are parts of the optional tasks at the end*


### The Post

 -  setup a new local MySQL database called `reddit`
 -  think about and create the tables you'll need

### Wiring in

 -  connect your application to your database
 -  create the first endpoint for [listing the posts](../apispec.md#get-posts)
 -  make sure that it returns the same type of JSON object as specified

### Adding

 -  create the endpoint as specified for [adding a new post](../apispec.md#post-posts)
 -  make sure that you receive the proper object
 -  and return the proper object as a response
 -  and also save the Post to your database

### Vote

 -  create the endpoints if you haven't already (for [upvote](../apispec.md#put-postsidupvote) and [downvote](../apispec.md#put-postsiddownvote) separately)
 -  the voting urls should look like this: `/posts/5/upvote` for upvoting the post with the id 5
 -  increment or decrement the score
 -  save it and respond with the proper object

### Connect to your frontend

 -  create a `public` folder in your project directory
 -  put your frontend files into that directory
 -  modify that your frontend use the api you've just written
 -  [Serving static files in Express](https://expressjs.com/en/starter/static-files.html)

### Extending functionality

 -  add users
    -  user model will be needed
    -  post model will be updated
    -  extend every request
    -  save the user with the post
 -  a little hint for headers

```javascript
app.get('/', function(request, response) => {
  console.log(request.headers);
  res.send();
});
```

 -  add [Delete](../apispec.md#delete-postsid) / [Update](../apispec.md#put-postsid) functionality enabled for the users own posts
    -  when updating update the timestamp as well
