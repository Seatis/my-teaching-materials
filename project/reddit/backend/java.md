# The Reddit Java REST backend
We'll create a simple reddit clone application, where the users can create posts and upvote / downvote existing posts. Later on you can extend this functionality.

This page focuses on the RESTful backend written in Java.
There will be RESTful frontend created by other classes. If everybody follows the [API Specification](../apispec.md), then you'll be able to connect the frontends with the backends.

### Create a new Project
- Set up a new project
- You'll need these dependencies: web, devtools, data-jpa, mysql
- Create a package to work in (eg. `com.greenfox.aze.reddit`)
- Create a `RedditApp` class containing the `main` method to start SpringBoot.

### Check out the Api Spec
- [API Specification](../apispec.md)
- Think about how many endpoints will be needed
- Think what type of model will you need, with what fields and methods
- You don't need to worry about Headers and status codes, that will be set by Spring automatically if you do everything right
- *Ignore the (Optional) parts at first, those are parts of the optional tasks at the end*

### The Post
- Setup a new database called `reddit`
- Setup your database connection with the `application.properties` file
- It should look like this
```
spring.datasource.url=jdbc:mysql://localhost:3306/reddit
spring.datasource.username=aze
spring.datasource.password=asd
spring.datasource.driver-class-name=com.mysql.jdbc.Driver
spring.jpa.hibernate.ddl-auto=create-drop
```
- Later you can change the last line to your liking, but we will develop this incrementally, so spring will need to recreate the db if our Post class is changed
- Create a package for our models
- Create a `Post` class, with a necessary fields (based on the API spec)
    - You can add anything else if you'd like to
    - Add setters and getters for these fields

### Wiring in
- Create a package for our services
- Create a PostRepository based on the CRUDRepository
- Wire it in the PostsController
- Create the first endpoint for [listing the posts](../apispec.md#get-posts)
- Make sure that it returns the same type of JSON object as specified

### Adding
- Create the endpoint as specified for [adding a new post](../apispec.md#post-posts)
- Make sure that you expect the proper object as parameter
- And return the proper object as a response
- And also save the Post to your database

### Vote
- Create the endpoints if you haven't already (for [upvote](../apispec.md#put-postsidupvote) and [downvote](../apispec.md#put-postsiddownvote) separately)
- The voting urls should look like this: `/posts/5/upvote` for upvoting the post with the id 5
- Then you'll have this id as a parameter in your controller's method, so you can find the actual Post object
- Increment or decrement the score
- Save it and respond with the proper object

## Find a Frontend partner
- Add this to your Posts controller
```java
@CrossOrigin("*")
```
- Make sure that every endpoint works according to the api spec with Postman
- At this point go to the slack channel #reddit
- Find someone who is developing the frontend part
- Make sure that you're on the same network
- Find out your local ip address
- Get together to test out each other's work
- You can create another controller with an `/` endpoint to render the html and load the JavaScript your partner wrote
  - set up the server address locally (http://localhost:8080 should work)

## Extending functionality
- Add users
  - User model will be needed
  - Post model will be updated
  - Extend every request but getting posts to receive a required HTTP header parameter (marked as optional in the apispec):
```java
@RequestMapping("/some-endpoint")
public Response someEndpoint(@RequestHeader("header-name") String headerValue) {
  // do something with your header
}
```
  - Save the user with the post
- Add [Delete](../apispec.md#delete-postsid) / [Update](../apispec.md#put-postsid) functionality enabled for the users own posts
  - When updating update the timestamp as well
- Replace score with vote model
  - connect it to a post and the user
  - calculate the score of a post by using this model
  - make sure that every user gets to vote only once on a post
  - and when listing the posts you return the vote of the user for each post (marked as optional in the apispec)
