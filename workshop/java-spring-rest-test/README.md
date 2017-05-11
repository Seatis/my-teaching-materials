# Testing REST Service endpoints
For testing HTTP endpoints Spring MVC provides a great support. It provides very nice middle solution between unit-testing and integration-testing where it lets you stand up the entire Spring MVC DispatcherServlet-send request to the specific Spring MVC controller, it is including validators, HttpMessageConverters, and more - and then run tests against them without actually starting up a real HTTP service.

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[Testing a REST Service](https://spring.io/guides/tutorials/bookmarks/)|"Testing a REST Service" part|
|[Deeper concept of JSONPath](http://www.baeldung.com/guide-to-jayway-jsonpath)|reading|
|[Spring Boot Controller Integration Test Example](https://www.youtube.com/watch?v=gNUm14kL7sI)|14:18|


### Optional
More aspects, techniques of testing Spring Boot REST Web Services

| Material | Time |
|:---------|-----:|
|[Spring Boot Integration Testing](https://www.youtube.com/watch?v=Psei7F7KsDw)|17:59|
|[Spring Boot Unit Testing](https://www.youtube.com/watch?v=RbZvXCAtMus)|17:42|
|[Data JPA Tests](https://docs.spring.io/spring-boot/docs/current/reference/html/boot-features-testing.html#boot-features-testing-spring-boot-applications-testing-autoconfigured-jpa-test)|reading|

## Material Review
- Integration Test
- Unit Test
- Business Service
- DispatcherServlet
- @WebAppConfiguration
- MockMvc
- contentType()
- andExpect()
- andDo()
- JSONPath

## Workshops
