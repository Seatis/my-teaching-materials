# Introduction To Spring

Inversion of Control (IoC) offers an alternative way to construct applications such that developers can:
- work independently to test items without depending upon others and 
- swap out internals without needing to refactor (aka recode) objects.

Typically objects are built upon other, subordinate objects.  The objects at the top of the heap know who they use.  We can say that they are *in control*.  But those at the bottom are blind.  Now this would be okay in a static universe.  But imagine the chagrin when something deep in the heap needs changing.  

*Inversion of Control* takes that philosophy and flips it.  In simple terms, it says that those at the bottom retain control of themselves (and some would argue, those that use them).  By using this approach, they can be decoupled (that is, unlinked) such that they can retain their existing interfaces, be recompiled with new features, swapped out and/or repaired, and those that depend upon them are unaffected.  Instead of their class definitions being "baked in" to their callers, the Spring Framework acts like a dispensary, fabricating the objects for the callers (which might include wiring them together with other objects) and then handing the *instances* over as required.

This is useful, for example, when one might need to swap the way data is retrieved from a database (say you remove one service in favour of another provider).  The *surgery* (aka changing the service) happens outside of your calling object.  And when needed, Spring serves your calling object the _right_ subordinate based upon the latest configuration.  This way the caller does not need to be recompiled.  This approach offers a stronger, more stable means of polymorphism.  

Core to Spring itself are its *beans*.  Beans are objects based upon class definitions.  They are the same as what you've already built in Java.  Only, they are managed by Spring.  In this first day, we'll look at getting a simple "Hello World" application to fire up.  This will require understanding a little about the Spring universe and informing IntelliJ of what you want to build.

But wait! Beans are not the only Spring feature.  Spring came along at a critical point simplifying many other challenges such as a cleaner way to interact with requests for web-pages, build webservices, consume data services and use databases.

*One last introductory point related to beans ...*

Spring has evolved over the years.  Early on it was controlled through configuration files and/or programming.  The configuring was (and still can be) achieved by writing XML which is hierarchical in nature and centralised.  As Java improved, new features came along - specifically annotation.  Annotation simplifies the way developers interact with Spring.  

Nonetheless, there's a lot of documents of there explaining Spring using XML.  It's just a fact of time, there are just more of those videos and answers out there.  And, XML has an advantange: you can see the overall definition of all of the beans in one (or more dedicated) file(s).

However, we are focusing on applying Spring through annotation as this technique extends the actual code that Spring reads.  By annotating the specific code fragment that relates to the bean there's no distance between the code and what Spring will employ.  By annotating the code when such gets defined for Spring, you reduce the risk of omitting something.


## Materials & Resources

### Training

| Material | Time |
|:---------|-----:|
|[Best Practices for Designing a Pragmatic RESTful API](http://www.vinaysahni.com/best-practices-for-a-pragmatic-restful-api)| reading |
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0) - explains how the  need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Serving Web Content with Spring MVC](http://spring.io/guides/gs/serving-web-content/)| reading |
|[Understanding View Templates](http://spring.io/understanding/view-templates)| reading |

Once through the above, consider rewatching the first video (JavaBrains.01) to reinforce your understanding.


### Optional
| Material | Time |
|:---------|-----:|
|[Creating beans - XML (JavaBrains.04)](https://www.youtube.com/watch?v=7c6ZTF6cF88&s=10) - starts off doing this the way we know and then repeats using the Bean Factory pattern.|11:21|
|[Clear, concise tutorials related to Spring](https://www.tutorialspoint.com/spring/spring_ioc_containers.htm) - great resource for quick checking||

|[Spring's detailed discussion on Beans](http://docs.spring.io/spring/docs/current/spring-framework-reference/html/beans.html) - _Reference Only_ this is the defacto, *go to* site for Spring.|170 pages|



## Review
- Dependency Injection/Inversion of Control
- Bean
- Component
- Autowired
- `@bean(name=<>)`
- `@configuration`
- `@required`
- `@autowired`
- `@component`
- libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation 
  - `org.springframework.beans.factory.*`


## Workshops
In today's workshops you'll be creating a few simple beans.  The beans are critical for later stuff we'll do.  So right now it's just getting a basic feel for how to write.

### Create our first Spring Boot Application
- [Open Start Spring IO site](http://start.spring.io/)
- Use following settings: 
  - Generate a Gradle with Spring Boot 1.4.2.
  - Group: com.greenfoxacademy
  - Artifact: springstart
  - Name: springstart
  - Package Name: com.greenfoxacademy.springstart
  - Packaging: jar
  - Java Version: 1.7
  - Language: java
  - Selected Dependencies: Lombok, Web, Thymeleaf, DevTools
- Generate Project
- Extract the downloaded zip

- IntelliJ: Import project
- Use Gradle external model
- Use Auto import, Create directories for empty..., uncheck: Create separate modules per source set >> Finish
- Open build.grdle and remove line: "apply plugin: 'eclipse'"
- Open terminal from bottom of the IDE and start Spring boot app container with: "gradlew bootRun" command
- Open [localhost:8080](http://localhost:8080) in your webbrowse
- If you get "Whitelabel Error Page" it means your application is running.

### Hello World REST App
- Add "controllers" package to your Spring project.
- Create "Greeting" class with "long id" and "String content" fields. Getter and AllArgsConstructor. (Use Lombok)
- Add "HelloRESTController" class to controllers package and add @RestController annotation to this class.
- Add greeting method and use @RequestMapping annotation.
- Create and pass a Greeting object when it is called.
- Recompile app
- Open [http://localhost:8080/greeting](http://localhost:8080/greeting) in your webbrowser
- Your output should looks like: {"id":1,"content":"Hello, World!"}

### Hello User REST App
- Please improve your previous app to greet you and get the name from url query parameter.
- You should use @RequestParam annotation 
- Recompile app
- Open [http://localhost:8080/greeting?name=Your%20name](http://localhost:8080/greeting?name=Your%20name) in your webbrowser
- Your output should looks like: {"id":1,"content":"Hello, Your name!"}

### REST Greet counter app
- Lets improve your previous app to able to count the greet number. (count api calls)
- You should use AtomicLong class.
- Recompile app
- Open [http://localhost:8080/greeting?name=Your%20name](http://localhost:8080/greeting?name=Your%20name) in your webbrowser
- Your output should looks like: {"id":1,"content":"Hello, Your name!"}
- Then at next call your output should looks like: {"id":2,"content":"Hello, Your name!"} and so on...

### Hello World Web App
- Lets create another controller "HelloWebController" to controllers package.
- Add greeting method like:
```java
@RequestMapping("/web/greeting")
    public String greeting(Model model) {
        model.addAttribute("name", " World!");
        return "greeting";
    }
```
- Add following HTML template file to "resources/templates/greeting.html"
```html
<!DOCTYPE HTML>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title>Getting Started: Serving Web Content</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
</head>
<body>
<p th:text="'Hello, ' + ${name} + '!'"/>
</body>
</html>
```

#Links
- [Parent - Java Spring](../README.md)
- [Next - Thymeleaf](../thymeleaf/README.md)
