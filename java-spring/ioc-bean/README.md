# The Bean Factory Pattern
Inversion of Control (IoC) offers an alternative way to construct applications such that developers can:
- work independently to test items without depending upon others and 
- swap out internals without needing to refactor (aka recode) objects.

*Inversion* means that the rather the subordinates (aka objects) being unaware of who calls them and therefore unable to be amended or replaced and therefore not in control, instead they are flexible and can be altered.  For example, one could swap the data access object without having to touch the objects that call it.  This is an aspect of polymorphism.  It allows a caller to be ignorant of the specific functionality that will run and only concern itself with calling a specific function.  The object itself resolves what to actually do.

The Spring framework uses the Bean Factory pattern in order to offer IoC.  The Factory is a *container* that references *blueprints* to build object (instances commonly referred to as *beans*) as required by an calling application.  These *beans* live inside the factory which manages them.  As they are based upon *blueprints* defined in a configuration file, their composition can be changed without altering the calling objects.  The Factory in effect manages all communications between the callers and its beans and simply returns *references* that the caller can use.

Beans are defined in a variety of combinable ways:-
- xml configuration
- during execution of the object (not recommended)
- annotations to the caller code - which is prescanned to generate the xml configuration.

Most of the materials use the xml approach, however, the annotation method is easier.

This is a large topic and we will only cover the basics as it's both used by many and we will revisit these concepts later.  In the Materials & Resources for this unit we:-
- introduce the concept of IoC
- review the bean factory model
- look at the core elements of beans
  - creating
  - integrating beans into code and with each other
  - identifying methods to run when creating and destroying
- practice defining beans, with special emphasis on annotation (as that's the most common way people 

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[Inversion of Control/Dependency Injection (JavaBrains.01)](https://www.youtube.com/watch?v=GB8k2-Egfv0&t=714s) - explains how we get to needing a Bean Factory|14:51|
|[Understanding Beans &amp; Factory Design Pattern (JavaBrains.03)](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Creating beans - XML (JavaBrains.04)](https://www.youtube.com/watch?v=7c6ZTF6cF88&s=10) - starts off doing this the way we know and then repeats using the Bean Factory pattern.|11:21|
|[Creating beans - annotation (InterviewDot)](https://www.youtube.com/watch?v=Oft0a5IUalQ)|2:22|
|[ApplicationContext - XML (JavaBrains.05)](https://www.youtube.com/watch?v=ZxLaEovze3M)|7:36|
|[Constructor - XML (JavaBrains.06)](https://www.youtube.com/watch?v=IOZzxmJVus0) - once you get the principle, speed through the rest|13:59|
|[Creation &amp; Destruction methods (gontuseries.14)](https://www.youtube.com/watch?v=CZzmmP2Soy4)|10:40|
|[Injecting subordinate objects - XML (JavaBrains.07)](https://www.youtube.com/watch?v=g15RcFyEcrk)|15:18|
|[Autowiring - XML (JavaBrains.10)](https://www.youtube.com/watch?v=suiEGbKf21g)|7:26|
|
Once you understand the Bean Factory, consider rewatching JavaBrains.01.

### Optional
| Material | Time |
|:---------|-----:|
|[Autowire - annotation](https://www.youtube.com/watch?v=IVIhVJJGo68)|14:19|
|[Inner Beans, Aliasing and Enforcing completeness (idref) - XML (JavaBrains.08)](https://www.youtube.com/watch?v=TW51XsixMqA)|9:50|
|[Spring's detailed discussion on Beans](http://docs.spring.io/spring/docs/current/spring-framework-reference/html/beans.html) - this is the defacto, *go to* site for Spring and Beans.|170 pages|

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

- libraries
  - `org.springframework.context.annotation.CommonAnnotationBeanPostProcessor` - to reach additional annotation directives such as `@PostConstruct` &amp; `@PreDestroy`
  - `org.springframework.beans.factory.DisposableBean`
  - `org.springframework.beans.factory.InitializingBean`
- Different ways of instantiating the Factory
  - BeanFactory fac = new XmlBeanFactory (new FileSystemResource ("beans.xml")
    - `.getBean(String nameOfTheBean)`  has to be classed e.g. `Account a = (Account)fac.getBean("accObj");`
  - ApplicationContext fac = FileSystemXmlApplicationContext("c:\\TestAC\\beans.xml") //whereever located
    - or ClassPathXmlApplicationContext(); \\will search down the classpath

### Optional Items
- idref
- inner bean
- aliasing




## Workshops
In today's workshops you'll be 

- Simple bean creation
  - hello world - https://www.youtube.com/watch?v=OQIsKgfkYcE&t=1000
  - id attrib specifying the name, class the fully qualified name - https://www.youtube.com/watch?v=gy4I_jmwu9k
  - redo with annotation
- Lifecycle
  - on create
  - teardown
- Change container
- sub items 
  - directly entered
  - using autowire byName
  - using autowire byClass

- Challenges  

#Links
- [Parent - Java Spring](../README.md)
- [Next - Database Integration](../database-integration/README.md)
