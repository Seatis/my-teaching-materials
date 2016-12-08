# Introduction To Spring

Inversion of Control (IoC) offers an alternative way to construct applications such that developers can:
- work independently to test items without depending upon others and 
- swap out internals without needing to refactor (aka recode) objects.

*Inversion* means that the rather the subordinates (aka objects) being unaware of who calls them and therefore causing heartache if they themselves need amending, they are now decoupled (unlinked) in a way and are made available to those who need them in a way that is similar to a dispensary.  Through a medium, Spring takes care of providing access to subordinate Objects constructed from your (or others') definitions and fill in all the linkages as required.

This is useful, for example, when one might need to swap the way data is retrieved from a database (say you remove one service in favour of another provider).  The *surgery* (aka changing the service happens outside) and your calling object(s) serve up the *right* Object based upon the current configuration without needing to be recompiled.  This is offers a richer, more stable means of polymorphism.  It allows a caller to be ignorant of the specific functionality that will run to do the low-level thing(s) needed; it need only concern itself with interfacing with the object(s).  And Spring will resolve all the necessary connections (referred to as *wiring* and *resources*).

Core to Spring itself are *beans*.  Beans are objects based upon class definitions.  They are the same as what you've already built in Java.  Only, they are managed by Spring.  In this first day, we'll look at getting a simple "Hello World" application to fire up.  This will require understanding a litttle about the Spring universe and adding in features in IntelliJ.

Very important to note.  Spring has evolved over the years.  Early on it was controlled mainly through configuration files.  These are XML in nature.  As Java itself has improved, new features in Java - specifically annotations - have been used to simplify the way developers interact with the framework.  We bring this up because a) many times, you'll see features of Java explained using XML as there are just much more of these videos and answers out there and b) in the xml, you can see the overall definition of the beans.

However, we are using Spring with annotation.

## Materials & Resources

### Training

| Material | Time |
|:---------|-----:|
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how the  need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) - shows how easy it is to do the same thing with annotation using just `@bean()`.|1:58|
|[@Component annotation (Telusko)](https://www.youtube.com/watch?v=4fZJfqpnyWg) - this is fairly clear and quick |6:35|
|[Autowire - annotation (JavaBrains.19)](https://www.youtube.com/watch?v=IVIhVJJGo68)|14:19|
|[Spring support enable in IntelliJ](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html#plugin)||

Once through the above, consider rewatching the first video (JavaBrains.01) to reinforce your understanding.


### Optional
| Material | Time |
|:---------|-----:|
|[Creating beans - XML (JavaBrains.04)](https://www.youtube.com/watch?v=7c6ZTF6cF88&s=10) - starts off doing this the way we know and then repeats using the Bean Factory pattern.|11:21|
|[Clear, concise tutorials related to Spring](https://www.tutorialspoint.com/spring/spring_ioc_containers.htm) - great resource for quick checking||

### Reference Only
|[Spring's detailed discussion on Beans](http://docs.spring.io/spring/docs/current/spring-framework-reference/html/beans.html) - this is the defacto, *go to* site for Spring and Beans.|170 pages|


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
