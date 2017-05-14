# Testing REST Service endpoints
For testing HTTP endpoints Spring MVC provides a great support. It provides very nice middle solution between unit-testing and integration-testing where it lets you stand up the entire Spring MVC DispatcherServlet-send request to the specific Spring MVC controller, it is including validators, HttpMessageConverters, and more - and then run tests against them without actually starting up a real HTTP service.

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[Testing a REST Service](https://spring.io/guides/tutorials/bookmarks/)|"Testing a REST Service" part|
|[Deeper concept of JSONPath](http://www.baeldung.com/guide-to-jayway-jsonpath)|reading|
|[Spring Boot Controller Integration Test Example](https://www.youtube.com/watch?v=gNUm14kL7sI)|14:18|
|[Spring MVC Controllers other example](https://www.petrikainulainen.net/programming/spring-framework/unit-testing-of-spring-mvc-controllers-rest-api/)|reading|


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
- Business Layer
- DispatcherServlet
- @WebAppConfiguration
- MockMvc
- contentType()
- andExpect()
- andDo()
- JSONPath

```java
package com.greenfox.enpointtesting.controller;

import ...

@RunWith(SpringRunner.class)
@SpringBootTest(classes = EndpointTestingApplication.class)
@WebAppConfiguration
@EnableWebMvc
public class UserControllerTest {

    private MediaType contentType = new MediaType(MediaType.APPLICATION_JSON.getType(),
            MediaType.APPLICATION_JSON.getSubtype(),
            Charset.forName("utf8"));

    private MockMvc mockMvc;

    @Autowired
    private WebApplicationContext webApplicationContext;

    @Before
    public void setup() throws Exception {
        this.mockMvc = webAppContextSetup(webApplicationContext).build();
    }   

   @Test
   public void testUnsuccessfulSignUp() throws Exception {
       mockMvc.perform(post("/user/signup")
               .contentType(MediaType.APPLICATION_JSON)
               .content("{\"email\": \"name@example.com\", \"password\": \"12345\"}"))
               .andExpect(status().isOk())
               .andExpect(content().contentType(contentType))
               .andExpect(jsonPath("$.result", is("fail")))
               .andExpect(jsonPath("$.message", is("email address already exists")));
   }

```

## Workshops
