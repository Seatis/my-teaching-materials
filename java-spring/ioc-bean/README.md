# The Bean Factory Pattern
Having started to look at Spring, lets take a little bit of time to understand better what is going on inside.  The Spring framework uses a pattern commonly referred to as a *Factory* (or specifically a Bean Factory).  The Factory is a *container* that references *blueprints* to build object (instances commonly referred to as *beans*) as required by an calling application.  These *beans* live inside the factory which manages them.  As they are based upon *blueprints* defined in a configuration file, their composition can be changed without altering the calling objects.  The Factory in effect manages all communications between the callers and its beans and simply returns *references* that the caller can use.

A major benefit to this approach is that there can be just ONE copy of the instance which can be used repeatedly in the code.  However, this requires that instance be *stateless*.  That is, it does not retain any data between calls.  This way, if 2 different threads or parts of the code call the same instance, the values inside of it do not get over-written or impact the other call.  

As explained earlier in the Module, Beans are defined in a variety of combinable ways:-
- xml configuration (mentioned earlier)
- during execution of the object (flexible but not always recommended)
- annotations in caller and definitional code - which is prescanned to generate the configuration that drives Spring.

As with other aspects of Spring, the Bean Factory too is a large topic and we will cover the basics used most frequently; this will serve you later in learning more about the Factory approach.  In the Materials & Resources for this unit we:-
- introduce the concept of IoC
- review the bean factory model
- look at the core elements of beans
  - creating
  - integrating beans into code and with each other
  - identifying methods to run when creating and destroying
- practice defining beans, with special emphasis on annotation (as that's the most common way developers employ the Bean Factory Pattern).


## Materials & Resources

Consider the following situation:

```java
public class TextEditor {
   private SpellChecker spellChecker;
   
   public TextEditor() {
      spellChecker = new SpellChecker();
   }
}
```

When TextEditor runs, it has a dependency on the creation of an instance of SpellChecker.  In this way, TextEditor is dependent upon SpellChecker.

Inversion of Control says instead that the instance of the SpellChecker would be passed like a parameter:-

```java
public class TextEditor {
   private SpellChecker spellChecker;
   
   public TextEditor(SpellChecker spellChecker) {
      this.spellChecker spellChecker();
   }
}
```

This is the fundamental basis of IoC / DI.

The Bean Factory enables this sort of *passing* to occur in a simple, clean way.

| Material | Time |
|:---------|-----:|
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how the need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) - shows how easy it is to do the same thing with annotation using just `@bean()`.|1:58|
|[Overview of DI (tutorialspoint)](https://www.tutorialspoint.com/spring/constructor_based_dependency_injection.htm)|reading|
|[Using Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_annotation_based_configuration.htm)|reading|
|Useful reference on using Annotation(spring.io)|(http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html) - peruse this, I think you'll find it handy later.|reading|

Once through the above, consider rewatching the first video (JavaBrains.01) to reinforce your understanding.

## Review
- Container (creates the objects needed; instantiates from *blueprint*)
  - Object Factory
    - gets a request
    - reads a configuration (blueprint / meta-data)
     - does the *new* 
- Bean
  - Handle to an object that is made by the factory (repository)
  - Object lifecycle
    - instantiation
    - properties injected
    - .setBeanName() - method of BeanNameAware
    - preDestroy
- wiring
- `@Bean(name=<>)`
- `@Configuration`
- `@Required`
- `@Autowired`
- `@Component`
- `@ComponentScan`
- `@Scope` - prototype, singleton

- Libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation 
  - `org.springframework.beans.factory.*` (note also has annotation support)

- Different ways of instantiating the Factory, but as we are using annotation:-
  - or AnnotationConfigApplicationContext();  \\when using @bean() - having a Java class instead of an XML file (described earlier in [Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) )
- the naming convention for beans; start off lowercase (as opposed to a Class)


### Optional Items
- idref
- inner bean
- aliasing
- `@Resource` - similar to `@Autowire` 
- `@Service` - as opposed to `@Component`




## Workshops
- [Hello World](./workshop/Workshop01.md) - in this exercise, you will get acquainted with the IntelliJ support for Spring
- [Work through an example of DI](./workshop/Workshop02.md) - run the code and understand how it's working
- [Create a couple of beans that are autowired](./workshop/Workshop03.md) - try to do it yourself referring to earlier examples
- [Adding an initialization and destruction method](./workshop/Workshop04.md) - 
- [Bean dependencies](./workshop/Workshop05.md)  
- [Web service call](.workshop/Workshop06.md) - get some experience calling a service and managing such with a bean

#Links
- [Parent - Java Spring](../README.md)
- [Prior - Thymeleaf](../thymeleaf/README.md)
- [Next - Database Integration](../database-integration/README.md)
