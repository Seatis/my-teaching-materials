# Spring MVC

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[Creating a Srping Project to use Gradle](https://www.youtube.com/watch?v=RtbWEKMWp7A)|6:51|
|[Or this is basically the same](https://www.youtube.com/watch?v=oBqTpe5ciMo)|4:10|
|[Building a CRUD Web Application with Spring Boot](https://www.youtube.com/watch?v=TcP5kFPq354)|29:38|

### Optional
| Material | Time |
|:---------|-----:|
|[MVC started with a Bean, also configuring to use Tomcat](https://www.youtube.com/watch?v=_SOXs4xdurE)|4:57|
|[Getting Started with Spring MVC and IntelliJ, JSP, taglib](https://www.youtube.com/watch?v=JKaalSS76vk#t=200) - note, also talks about Homebrew which is a command line installer for Mac.|22:52|
|[MVC CRUD Setup (Vega.01)](https://www.youtube.com/watch?v=Ys0UiIIIDlQ) - Start of walking through an example; CRUD setup.|8:30|
|[MVC CRUD Read (Vega.02)](https://www.youtube.com/watch?v=HHWepKpJtmk)|15:29|
|[MVC CRUD Create (Vega.03)](https://www.youtube.com/watch?v=fozoSKHNXJg)|12:39|
|[MVC CRUD Validate(Vega.04)](https://www.youtube.com/watch?v=WiVHC7fNJa8)|12:80|
|[MVC CRUD Update (Vega.05)](https://www.youtube.com/watch?v=q2DMt_XEfq0)|4:00|
|[MVC CRUD Delete (Vega.06)](https://www.youtube.com/watch?v=bdVKdMZNjOY)|5:23|

## Review

## Workshops - The Reddit
We'll create a simple reddit clone application, where the users can create posts and upvote / downvote existing posts. Later on you can extend this functionality.

### Create a new Project
- Set up a new project
- You'll need these dependencies:
```
compile('org.springframework.boot:spring-boot-starter-data-jpa')
compile('org.springframework.boot:spring-boot-starter-thymeleaf')
runtime('org.springframework.boot:spring-boot-devtools')
runtime('mysql:mysql-connector-java')
```
- Create a package to work in (eg. `com.greenfox.aze.reddit`)
- Create a `RedditApp` class containing the `main` method to start SpringBoot.

### The Home Controller
- Create a package for controllers
- Create a Controller with one endpoint for the entry point of our website
    - the first and default root endpoint: `"/"`
    - add `@ResponseBody` to the method for now
    - return a Hello World
- Check it out!

### The Posts Controller, templates
- Think about how many endpoints will be needed:
    - Each different display (which needs different data) needs one `RequestMethod.GET` type of endpoint
    - Every action will also need one (the method may vary, go with the default GET for now)
- In an ideal architecture everything in the posts controller should be available under the `/posts` endpoint (eg. `/posts/add`...)
- Also listing the posts should be done here
    - this action usually called `index`, it's always a `GET` and the endpoint is `"/"`
    - create an HTML template for this, a simple `Hello World` in the body will do for now
    - hence our home controller will only redirect to here (you'll need to remove the requestbody annotation to do that)
- If you haven't thought about adding a new post as a separate display
- Check your index page out (even the redirect)

### The Post
- Setup a new database called `reddit`
- Setup your database connection with the `application.properties` file
- It should look like this
```
spring.datasource.url=jdbc:mysql://localhost/reddit
spring.datasource.username=aze
spring.datasource.password=asd
spring.datasource.driver-class-name=com.mysql.jdbc.Driver
spring.jpa.hibernate.ddl-auto=create-drop
```
- Later you can change the last line to your liking, but we will develop this incrementally, so spring will need to recreate the db if our Post class is changed
- Create a package for our models
- Create a `Post` class, with a necessary `id`, `content` and `score` fields
    - You can add anything else if you'd like to
    - Add setters and getters for these fields

### Wiring in
- Create a package for our services
- Create a PostRepository based on the CRUDRepository
- Wire it in the PostsController
- In your index method pass all the posts to the template
```java
model.addAttribute("posts", repository.findAll());
```
...

#Links
- [Parent - Java Spring](../README.md)
- [Prior ](../xxx/README.md)
- [Next ](../xxxx/README.md)
