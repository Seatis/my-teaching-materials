# The Bean Factory Pattern
Having started to look at Spring, lets take a little bit of time to understand better what is going on inside.  The Spring framework uses a pattern commonly referred to as a *Factory* (or specifically a Bean Factory).  The Factory is a *container* that references *blueprints* to build object (instances commonly referred to as *beans*) as required by a calling application.  These *beans* live inside the factory which manages them.  As they are based upon *blueprints* defined in a configuration file, their internals can be changed without altering the calling objects.  We say *internals* as changing their *interfaces* could however affect the callers.  The Factory manages the life of the bean, simply returns *references* to the caller to use and when the Beans are no longer references, the Factory destroys them.

A major benefit to this approach is that there can be just ONE copy of the instance which can be used repeatedly in the code.  However, this requires that instance be *stateless*.  Stateless means the Bean only retains _final_ data between calls; it must not have anything that varies (e.g. a counter).  This way, if 2 different threads call the same Bean, the values it holds will not be corrupted.

As explained earlier in the Module, Beans are defined in a variety of combinable ways:-
- xml configuration (mentioned earlier)
- during execution of the object (flexible but not always recommended)
- annotations in caller and definitional code - which is prescanned to generate the configuration that drives Spring.
Here, we focus on the annotation method.

The Bean Factory has several facets.  For today will focus on the core and practice, namely by:
- reviewing the concept Dependency Injection (DI) / Inversion of Control (IoC)
- explore the the bean factory model
- look at the core elements of beans, and using annotation how 
  - configure the code so that beans are found and wired together
  - the different ways that bean can interact
  - specifying what to do when a bean is created and destroyed


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

Read this through closely.  It says that *When TextEditor is created, it will have a dependency on a creation of an instance of a SpellChecker*.  In this way we can say that the *TextEditor is dependent upon SpellChecker*.

Inversion of Control (IoC) says we can change that.  Instead we could pass an instance of the SpellChecker as we would a parameter:-

```java
public class TextEditor {
   private SpellChecker spellChecker;
   
   public TextEditor(SpellChecker spellChecker) {
      this.spellChecker spellChecker();
   }
}
```

This is the fundamental basis of IoC.  It's how we inject a dependency (DI).

The Bean Factory enables this sort of *passing* to occur in a simple, clean way.

| Material | Time |
|:---------|-----:|
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how the need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) - a simple illustration of annotation using `@bean()`.|1:58|
|[Overview of DI (tutorialspoint)](https://www.tutorialspoint.com/spring/constructor_based_dependency_injection.htm)|reading|
|[Using Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_annotation_based_configuration.htm)|reading|
|[Autowire Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_autowired_annotation.htm)|reading|
|[Useful reference on using Annotation(spring.io)](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html) - peruse this, I think you'll find it handy later.|reading|

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
- `@Bean(name="*override the name of the bean here if you so wish*")`
- `@Configuration`
- `@Component`
- `@ComponentScan`
- `@Autowired`
  - on a setter method (that is `setX(int x) {this.x = x});`) -  will make required (unless told otherwise); byType wiring
  - on a property (that is `private AProperty aProperty;`) - will remove the need for a setter method; Spring automatically assigns the property with the values passed
  - on a constructor (that is `public class AClass { public AClass(){}; ...`) - will bean and connect in the subordinate class(es) !!AZE?
  - `@Autowired(required=false)` - will turn off the default behaviour so that the bean will be construct even if the value(s) to instantiate it are missing.
- Libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation 
  - `org.springframework.beans.factory.*` (note also has annotation support)
- Different ways of instantiating the Factory, but as we are using annotation:-
  - `AnnotationConfigApplicationContext()` 
- the naming convention for beans; start off lowercase (as opposed to a Class)

### Optional Items
- `@Resource` - similar to `@Autowired` 
- `@Required` - similiar to `@Autowired`
- `@Service` - as opposed to `@Component`
- `@Scope` - prototype, singleton

## Workshops
- [Hello World](./workshop/Workshop01.md) - in this exercise, you will get acquainted with the IntelliJ support for Spring
- [Work through an example of DI](./workshop/Workshop02.md) - run the code and understand how it's working
- [Create a couple of beans that are autowired](./workshop/Workshop03.md) - try to do it yourself referring to earlier examples
- [More on Autowiring](./workshop/Workshop04.md) - play with where the @Autowire is set
- [Bean Dependency and adding initialization and destruction methods](./workshop/Workshop05.md) 

#Links
- [Parent - Java Spring](../README.md)
- [Prior - Thymeleaf](../thymeleaf/README.md)
- [Next - Database Integration](../database-integration/README.md)
