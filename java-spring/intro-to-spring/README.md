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
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how the  need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) - getting started with annotation using `@bean()`.|1:58|
|[@Component annotation (Telusko)](https://www.youtube.com/watch?v=4fZJfqpnyWg) - this is fairly clear and quick |6:35|
|[Autowire - annotation (JavaBrains.19)](https://www.youtube.com/watch?v=IVIhVJJGo68)|14:19|
|[Spring support enable in IntelliJ](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html#plugin)||

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

- [Do the Traditional, "Hello World"](./workshop/Workshop01.md) - Create a simple, single bean and ensure that Spring is working on your machine
- multiple beans
- autowire example
- Start Calorie Counter Project


#Links
- [Parent - Java Spring](../README.md)
- [Next - Thymeleaf](../thymeleaf/README.md)
