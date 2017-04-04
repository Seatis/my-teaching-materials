# Testing
*Trust, but verify.* - Ronald Reagan in speaking to Mikhail Gorbachev about an arms control treaty.

When coding, we start with the best intentions of covering all the eventualities.  But sometimes we miss things or our code evolves and no longer does what it was intended.

Several languages have a concept of automated testing.  These are separate collections from the code base which can be called (and stored with the project).

Testing generally involves running a method to see that such returns expected results.  As the testing grows in complexity, the testing system also has to have the means to impose logic.  For example, pre-fill some data, reset something, handle "exceptions" as the code is expected to complain/refuse to operate.

## Materials & Resources

### Material
| Material | Time |
|:-------- |-----:|
|[JUnit 4 Intro with IntelliJ (DrBee.01)](https://www.youtube.com/watch?v=Bld3644bIAo)|11:05|
|[Additional annotative directives for testing (In28Minutes)](https://www.youtube.com/watch?v=5lRetx3Gv-w) - shows the "Before", "Before Class", assertTrue()|9:42|


### Optional
| Material | Time |
|:-------- |-----:|
|[Thinking about what to test (QAShahin)](https://www.youtube.com/watch?v=M_6z8L8qK8o)|13:04|
|[Reinforcement on using IntelliJ for testing (IntelliJ)](https://www.youtube.com/watch?v=AsHZWTjJYmg)|3:02|
|[Refresher on JUnit from a different perspective (In28Minutes)](https://www.youtube.com/watch?v=AN4NCnc4eZg)|12:54|
|[Summary of JUnit constructs](https://www.tutorialspoint.com/junit)||

## Material Review
- Persistent data
- `@Test`
  - Expectation
- `@Before`, `@BeforeClass`
- `@After`, `@AfterClass`
- `@AssertEqual`, `@AssertTrue`, `@AssertFalse`
- Coverage
- `@Ignore`
- `@Exception`

## Workshop

### Class
```java
public class MessageUtil {
   private String message;
	
   public MessageUtil(String message) {
      this.message = message;
   }
      
   public String printMessage() {
      System.out.println(message);
      return message;
   }   
}  
```

### Test Case Class
```java
public class TestJunit {	
   String message = "Hello World";	
   MessageUtil messageUtil = new MessageUtil(message);

   @Test
   public void testPrintMessage() {
      assertEquals(message, messageUtil.printMessage());
   }
}
```

### Test Runner Class
```java
public class TestRunner {
   public static void main(String[] args) {
      Result result = JUnitCore.runClasses(TestJunit.class);
		
      for (Failure failure : result.getFailures()) {
         System.out.println(failure.toString());
      }
		
      System.out.println(result.wasSuccessful());
   }
}  	
```

## Exercises
- [Apples](apples/apples-java.md)
- [Sum](sum/sum-java.md)
- [Anagram](anagram/anagram.md)
- [Count Letters](count-letters/count-letters.md)
- [Fibonacci](fibonacci/fibonacci.md)
- [Cows and Bulls](cows-and-bulls/cows-and-bulls.md)