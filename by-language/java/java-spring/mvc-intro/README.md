# Spring MVC

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[IntelliJ - Spring Initializr (CodeTaming)](https://www.youtube.com/watch?v=oBqTpe5ciMo) - these are the key steps for generating a project using IntelliJ's Spring Initializr facility.|4:10|
|[Creating a Spring Project using Gradle &amp; migrating from Maven (LynAs)](https://www.youtube.com/watch?v=RtbWEKMWp7A) - this gives an overview of moving from Maven to Gradle; what's happening behind the scenes.|6:51|
|[Building a CRUD Web Application with Spring Boot (Marinho)](https://www.youtube.com/watch?v=TcP5kFPq354)|29:38|
|[Handling a Form (spring.io)](https://spring.io/guides/gs/handling-form-submission/) | reading 10:00|

__Note__ while there are explanations talking about DELETE and PUT methods, as we have not studied JavaScript/Ajax, we will not use these in our current assignments.  For these situations we can get by with our simpler understanding of HTML and use GET and POST (which supports retrieving a page and POSTing values from a form).  Thus for situations such as say DELETE, we would use a modified endpoint (e.g /students/delete/1).

### Optional
| Material | Time |
|:---------|-----:|
|[MVC started with a Bean, also configuring to use Tomcat](https://www.youtube.com/watch?v=_SOXs4xdurE)|4:57|
|[Getting Started with Spring MVC and IntelliJ, JSP, taglib](https://www.youtube.com/watch?v=JKaalSS76vk#t=200) - note, also talks about Homebrew which is a command line installer for Mac.|22:52|
|[Spring MVC Framework](https://www.tutorialspoint.com/spring/spring_web_mvc_framework.htm) - while using xml and jsp, this gives you an overview of MVC. Be sure to dive into the examples, especially the first 3.|reading 45:00|
|[Using IntelliJ, the basics of MVC (Djalas)](https://www.youtube.com/watch?v=Ke7Tr4RgRTs) - while he uses DAO, he also shows how to 1) make an installable version to run on another machine 2) use a Chrome add-in to send different RequestMethods 3) refactor to create an Interface after the fact to then build an alternative Data Access layer 4) uses  `@Qualifier` and reinforces how SpringBoot, `@Bean` and `@Autowired` work. _Note_ this is the basis of a workshop.|56:53|
|[What's the difference between @Component, @Service, @Controller and @Repository? (Stackoverflow)](http://stackoverflow.com/questions/6827752/whats-the-difference-between-component-repository-service-annotations-in)| reading 10:00|

### Optional : Vega Tutorial
The Vega MVC CRUD videos cover a more involved example.  It's well-worked, covering much of what are core to this course: Thymeleaf, CrudRepository and Dependency Injection; and it also works in Security and Interceptor.  As a later review, stepping through his code would reinforce a lot.  But it's too involved as a starter tutorial.  The projet is a blog site.  It lists articles and also features lists of articles by author as well as restricting which users can admin blog articles.

| Material | Time |
|:---------|-----:|
|[MVC CRUD Setup (Vega.01)](https://www.youtube.com/watch?v=Ys0UiIIIDlQ) - Start of walking through an example; CRUD setup.  |8:30|
|[MVC CRUD Read (Vega.02)](https://www.youtube.com/watch?v=HHWepKpJtmk)|15:29|
|[MVC CRUD Create (Vega.03)](https://www.youtube.com/watch?v=fozoSKHNXJg)|12:39|
|[MVC CRUD Validate(Vega.04)](https://www.youtube.com/watch?v=WiVHC7fNJa8)|12:80|
|[MVC CRUD Update (Vega.05)](https://www.youtube.com/watch?v=q2DMt_XEfq0)|4:00|
|[MVC CRUD Delete (Vega.06)](https://www.youtube.com/watch?v=bdVKdMZNjOY)|5:23|

## Review
The Vega MVC CRUD videos cover a more involved example.  It's well-worked, covering much of what are core to the course: Thymeleaf, CrudRepository and Dependency Injection; and it also works in Security and Interceptor.  As a later review, stepping through his code would reinforce much.  But it's not a starting point.

If you want to explore this later, using Gradle and SpringInitialzr, set:-
- gradle
- group-id: com.therealdanvega
- artifact-id: crud-start
- dependencies
  - security
  - web
  - thymeleaf
  - jpa
  - h2

## Review
- `@Controller` and `@RestController` - identifies the code/class that will fire in response to fielding a request for an endpoint; determines who to call to get data and return views; enables `@RequestMapping`
  -  `@RestController` adds `@ResponseBody` to `@Controller` see [Difference between @Controller and @RestController](http://stackoverflow.com/questions/25242321/difference-between-spring-controller-and-restcontroller-annotation)
- `@RequestMapping` - available if Class is marked `@Controller`
  - `...("/url")`
  - `(method=RequestMethod.GET POST PUT DELETE)` - __note__ that we are only using GET and POST
  - `(consumes=MediaType.APPLICATION_JSON_VALUE)`
  - `(value="/{id}")` - /{id} being an example, and would be bound with `@PathVariable`
  - can set at either class level or method; if at class, then can have different RequestMethods for each method
  - `@GetMapping("/url")` and `@PostMapping("/url")` - shorthands for `@RequestMapping("/url", method=RequestMethod.GET)` and `@RequestMapping("/url", method=RequestMethod.POST)`
- `@PathVariable("id")` - annotation to connect RequestMapping value to a procedure call
- `@RequestBody`, `@ResponseBody` -used in the method associated with an end-point, means to access fields in a response see [@RequestBody and @ResponseBody annotations in Spring](http://stackoverflow.com/questions/11291933/requestbody-and-responsebody-annotations-in-spring)
- Return
  - ModelAndView, AddObject
  - String and AddAttribute(s)
- A Controller returns either ModelAndView or a String; ModelAndView is the older version. (see [returning a ModelAndView or String? (StackOverflow)](http://stackoverflow.com/questions/7175509/which-is-better-return-modelandview-or-string-on-spring3-controller) for more info)
  - ModelAndView, addObject
  - String and addAttribute(s)
- `@Service` - for Service layer; extension of `@Component` - identifies where the business logic goes  

Illustration of `@PathVariable` to the way it is used in an endpoint.
```java
...
@RequestMapping(value = "/{id}", method=RequestMethod.GET)
public Student getStudentById(@PathVarible("id") int id {
  return studentService.getStudentById(id);
  }
...
```

vs.

```java
...
@RequestMapping(method=RequestMethod.PUT)
public Student getStudentById(@RequestBody Student student {
  return studentService.updateStudent(student);
  }
...
```

The layers of Components:-

|Type|Provides|
|:---|:-------|
|Component|Base Annotation/Stereotype; identifies a class for Spring to *bean* |
|Controller|Extends Component; identifies the layer that will interact with calls from internet, returns to a Servlet that either sends back pages or data.  Methods are marked with RequestMapping (or GetRequest, PostRequest); data from Servlet can be wired into your routines using @PathVariable and @ModelAndView returns ModelAndView (with addAttributes) or String and additional objects|
|Service|Extends Component; where the business logic should occur; no special additional handling in Spring yet; its elements can be wired in|
|Repository|Extends Component; where the communication to the persistence (database) store resides.  Also offers database Exception handling|

<img src="./README01.jpg" >



## Workshops
- [The Reddit](./workshop/reddit.md)

### Optional
- [WS1 Reproduce Djalas tutorial](./workshop/Workshop01.md)
- [WS2 Refactor the Database](./workshop/Workshop02.md)

#Links
- [Parent - Java Spring](../README.md)
