# The Bean Factory Pattern
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
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE&t=9) - a simple illustration of annotation using `@bean()`.|1:58|
|[Overview of DI (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_dependency_injection.htm) - there are 2 sub-links, consider these too.  They use XML (rather than Annotation), so read them to understand the concept only.|reading|
|[Using Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_annotation_based_configuration.htm)|reading|
|[Autowire Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_autowired_annotation.htm)|reading|
|[Useful reference on using Annotation(spring.io)](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html) - peruse this, I think you'll find it handy later.|reading|

Once through the above, consider rewatching the first video (JavaBrains.01) to reinforce your understanding.

|[Autowiring examples (in28min)](https://www.youtube.com/watch?v=xTGkWSZkyNg)|18:20|
|[Autowired Annotation example (Telusko.9)](https://www.youtube.com/watch?v=HFt_q0wYYLU&t=70) - not the most "direct" example, but he gets there in the end.  You'll see how a bean is annotated to pick up another class through @Autowire|5:43|

## Review
- Dependency Injection via either: constructor or setter (for fine-tuning beans)

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
- `@Bean(name="*override the name of the bean here if you so wish, otherwise it's derived from the bean's name*")` - method-level annotation
- `@Configuration` - indicates that the class will be used as a source of Bean definition
- `@Component`
- `@ComponentScan`
- `@Autowired`
  - on a setter method (that is `setX(Integer x) {this.x = x});`) -  will make required (unless told otherwise); byType wiring
  - on a property (that is `private AProperty aProperty;`) - will remove the need for a setter method; Spring automatically assigns the property with the values passed
  - on a constructor (that is `public class AClass { public AClass(){}; ...`) - will bean and connect in the subordinate class(es) !!AZE?
  - `@Autowired(required=false)` - will turn off the default behaviour so that the bean will be construct even if the value(s) to instantiate it are missing.
- Libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation
  - `org.springframework.beans.factory.*` (note also has annotation support)
- Different ways of instantiating the Factory, but as we are using annotation:-
  - `AnnotationConfigApplicationContext(&lt;name of the class to use&gt;.class)`  - e.g. `newAnnotationConfigApplicationContext(AppConfig.class)`
- working with beans
  - .getBean(&lt;name of bean&gt;)  - ``` Service service = (Service) context.getBean("ServiceA");```

- the naming convention for beans; start off lowercase (as opposed to a Class)

### Optional Items
- `@Resource` - similar to `@Autowired`
- `@Required` - similiar to `@Autowired`
- `@Service` - as opposed to `@Component`
- `@Scope` - prototype, singleton

## Workshops
- [Hello World With Fries](./workshop/Workshop01.md) - in this exercise, you will get acquainted with the IntelliJ and basic Bean Annotation (replacing "new" object)
- [Switching Configurations](./workshop/Workshop02.md) - run the code and understand how it's working; get an insight into how, with Spring one would swap services
- [Create a couple of beans that are autowired](./workshop/Workshop03.md) - try to do it yourself referring to earlier examples
- [More on Autowiring](./workshop/Workshop04.md) - play with where the @Autowire is set
- [Bean Dependency and adding initialization and destruction methods](./workshop/Workshop05.md)

#Links
- [Parent - Java Spring](../README.md)
- [Prior - Thymeleaf](../thymeleaf/README.md)
- [Next - Database Integration](../database-integration/README.md)
