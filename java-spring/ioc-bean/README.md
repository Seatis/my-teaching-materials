# The Bean Factory Pattern

!!WORK IN PROGRESS 
The Spring framework uses a pattern commonly referred to as a *Factory* (or specifically a Bean Factory).  The Factory is a *container* that references *blueprints* to build object (instances commonly referred to as *beans*) as required by an calling application.  These *beans* live inside the factory which manages them.  As they are based upon *blueprints* defined in a configuration file, their composition can be changed without altering the calling objects.  The Factory in effect manages all communications between the callers and its beans and simply returns *references* that the caller can use.

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

### Training
In selecting materials, the introduction to this topic starts with the XML approach and then explains the annotation method.  Annotation is quicker to code than annotation and preferred.  XML's advantage is that you see all there is to know about a bean in a single place.  As you need to understand what you're doing, we start by showing the XML - but, as in many cases as you are turning out beans that are closely related to their classes, you'll more likely use the annotation approach.  

Please bear with the explanation in XML; we'll expect you to use the simpler, annotation method in general; the xml will only be there to get your program to start.


| Material | Time |
|:---------|-----:|
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how the  need for the Bean Factory arose.|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - XML (JavaBrains.04)](https://www.youtube.com/watch?v=7c6ZTF6cF88&s=10) - starts off doing this the way we know and then repeats using the Bean Factory pattern.|11:21|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) - shows how easy it is to do the same thing with annotation using just `@bean()`.|1:58|
|[@Component annotation (Telusko)](https://www.youtube.com/watch?v=4fZJfqpnyWg) - this is fairly clear and quick |6:35|
|[@Component(&lt;name&gt;) and @scope(@quot;singleton(@quot;|(@quot;prototype(@quot;)](https://www.youtube.com/watch?v=ELKrfHIvvPI&s=240) - watch this just for the `@Component(<name>)` and `@scope()`|7:21|
|[ApplicationContext - XML (JavaBrains.05)](https://www.youtube.com/watch?v=ZxLaEovze3M)|7:36|
|[Constructor - XML (JavaBrains.06)](https://www.youtube.com/watch?v=IOZzxmJVus0) - once you get the principle, speed through the rest|13:59|
|[Creation &amp; Destruction methods - annotation &amp; xml (gontuseries.13)](https://www.youtube.com/watch?v=CZzmmP2Soy4)|10:40|
|[Injecting subordinate objects - XML (JavaBrains.07)](https://www.youtube.com/watch?v=g15RcFyEcrk)|15:18|
|[Autowiring - XML (JavaBrains.10)](https://www.youtube.com/watch?v=suiEGbKf21g)|7:26|

Once through the above, consider rewatching the first video (JavaBrains.01) to reinforce your understanding.


### Optional
| Material | Time |
|:---------|-----:|
|[Inner Beans, Aliasing and Enforcing completeness (idref) - XML (JavaBrains.08)](https://www.youtube.com/watch?v=TW51XsixMqA)|9:50|
|[Enforcing completeness `@required` annotation (JavaBrains.18)](https://www.youtube.com/watch?v=Fs_IoEGSP-A)|9:53|

### Reference Only
|[Using @Resource and @Service (Nurkiewicz)](http://www.nurkiewicz.com/2011/01/spring-framework-without-xml-at-all.html)||
|[Easy Tutorials](https://www.tutorialspoint.com/spring/spring_ioc_containers.htm) - great resource for quick checking||
|[Spring's detailed discussion on Beans](http://docs.spring.io/spring/docs/current/spring-framework-reference/html/beans.html) - this is the defacto, *go to* site for Spring and Beans.|170 pages|
|[Spring support enable in IntelliJ](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html#plugin)||


## Review
- Container (creates the objects needed; instantiates from *blueprint*)
- Object lifecycle
  - instantiation
  - properties injected
  - .setBeanName() - method of BeanNameAware
  - preDestroy
- Bean
- Object Factory
  - gets a request
  - reads a configuration (blueprint / meta-data)
    - `<!DOCTYPE beans PUBLIC "-//SPRING//DTD// BEAN 2.0//EN" "http://www.springframework.org/dtd/spring-beans-2.0.dtd">`
    - `<context:component-scan/>` (see [github: nurkiewicz/spring-no-xml](https://github.com/nurkiewicz/spring-no-xml/commit/69b0a64b23bdb1a913a5dce81abb4c775d98db7d))
  - does the *new* 
- `<beans>`
  - xmlns, xmlns:xsi, xsi:schemaLocation
  - `<bean>` 
    - id - the unique name
    - autowire
      - byName - if name matches in the list
      - byType - (matches on the `class`); only works if there is only one of the type 
      - constructor 
        - [if multiple, then must have a `<constructor-arg ref="*the <bean id= value>*/>`](https://www.youtube.com/watch?v=yH-QiznQJpI)
    - class - the package &amp; class (e.g. "com.greenfox.beans.ObjectExample")
    - `<constructor-arg>` - calls the constructor for the object, passing the value, index parameters
      - value
      - matching up
        - index
        - type - to determine which constructor signature; *java.lang.String if a string as this is an object*
    - `<property>`
      - name - describing the property
      - setting
        - ref - links to another property defined (see https://www.youtube.com/watch?v=yH-QiznQJpI&t=306) *wiring manual*
        - value - initial value
- wiring
- constructor injection
- `@bean(name=<>)`
- `@configuration`
- `@required`
- `@autowired`
- `@component`
- `@scope` - prototype, singleton

- libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation 
  - `org.springframework.beans.factory.*`

- Different ways of instantiating the Factory
  - BeanFactory fac = new XmlBeanFactory (new FileSystemResource ("beans.xml")
    - `.getBean(String nameOfTheBean)`  has to be classed e.g. `Account a = (Account)fac.getBean("accObj");`
  - ApplicationContext fac = FileSystemXmlApplicationContext("c:\\TestAC\\beans.xml") //whereever located
    - or ClassPathXmlApplicationContext(); \\will search down the classpath
    - or AnnotationConfigApplicationContext();  \\when using @bean() - having a Java class instead of an XML file (described earlier in [Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=P0m1dW0LJeE) )
- the naming convention for beans; start off lowercase (as opposed to a Class)


### Optional Items
- idref
- inner bean
- aliasing
- `@Resource` - similar to `@Autowire` 
- `@Service` - as opposed to `@Component`




## Workshops
In today's workshops you'll be creating a few simple beans.  The beans are critical for later stuff we'll do.  So right now it's just getting a basic feel for how to write.

- [Do the Traditional, "Hello World"](./workshop/Workshop01.md) - Create a simple, single bean and ensure that Spring is working on your machine
- [Adding an initialization and destruction method](./workshop/Workshop02.md) - 
- [Bean dependencies](./workshop/Workshop03.md)  
- 
- [Injecting bean d
  - id attrib specifying the name, class the fully qualified name - https://www.youtube.com/watch?v=gy4I_jmwu9k
  http://www.java2novice.com/spring/spring-java-based-configuration/
  
  other ideas
  http://www.java2novice.com/spring/inject-list-into-spring-bean/
  
  - redo with annotation
- Lifecycle
  - on create
  - teardown
- Change container
- sub items 
  - directly entered
  - using autowire byName
  - using autowire byClass

- Challenge/Real World application -
  - Point Of Sales card reader call to the backend.  


#Links
- [Parent - Java Spring](../README.md)
- [Next - Database Integration](../database-integration/README.md)
