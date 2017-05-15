#I am groot!

- First create a new spring project
- Add dependencies: web, devtools
- Create a GuardianController
- Create a `GET /groot` endpoint
- That receives a query parameter: `message=somemessage`
- And responds with a json object with a translated text like below:
```json
{
  "received": "somemessage",
  "translated": "I am Groot!"
}
```
- if no input is provided:
```json
{
  "error": "I am Groot!"
}
```
- Create the GuardianControllerTest class
- Add the necessary annotations:
  - `@RunWith(SpringRunner.class)`
  - `@SpringBootTest(classes = YourApplication.class)`
  - `@WebAppConfiguration`
  - `@EnableWebMvc`
- Set up the outline like in the example below:
```java
  private MockMvc mockMvc;

  @Autowired
  private WebApplicationContext webApplicationContext;

  @Before
  public void setup() throws Exception {
    this.mockMvc = webAppContextSetup(webApplicationContext).build();
  }

  @Test
  public void yourFirstTest(){
      ...
  }
```
- Write a test where you check:
  - With giving a parameter the status is ok,
  - and the given respone is the same as expected
  - Without giving a parameter the status is not ok,
  - and the given error respone is the same as expected

  [![](assets/groot.jpg)](https://www.youtube.com/watch?v=HplYmXMo4Jc)