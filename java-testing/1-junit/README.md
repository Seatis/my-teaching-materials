# JUnit
*Trust, but verify.* - Ronald Reagan in speaking to Mikhail Gorbachev about an arms control treaty.

When coding, we start with the best intentions of covering all the eventualities.  But sometimes we miss things or our code evolves and no longer does what it was intended.

Several languages have a concept of automated testing.  These are separate collections from the code base which can be called (and stored with the project).

Testing generally involves running a method to see that such returns expected results.  As the testing grows in complexity, the testing system also has to have the means to impose logic.  For example, pre-fill some data, reset something, handle "exceptions" as the code is expected to complain/refuse to operate.

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[JUnit 4 Intro with IntelliJ (DrBee.01)](https://www.youtube.com/watch?v=Bld3644bIAo)|11:05|
|[JUnit 4 Continued (DrBee.02)](https://youtu.be/xHk9yGZ1z3k) - ends prematurely|17:55|
|[Review of IntelliJ Facilities for Unit Testing (IntelliJ)](https://www.youtube.com/watch?v=jolXBU-_Yyo) - review, gives some additional insights|2:47|
|[Additional annotative directives for testing (In28Minutes)](https://www.youtube.com/watch?v=5lRetx3Gv-w) - shows the "Before", "Before Class", assertTrue()|9:42|


### Optional
| Material | Time |
|:-------- |-----:|
|[Thinking about what to test (QAShahin)](https://www.youtube.com/watch?v=M_6z8L8qK8o)|13:04|
|[Reinforcement on using IntelliJ for testing (IntelliJ)](https://www.youtube.com/watch?v=AsHZWTjJYmg)|3:02|
|[Refresher on JUnit from a different perspective (In28Minutes)](https://www.youtube.com/watch?v=AN4NCnc4eZg)|12:54|
|[Summary of JUnit constructs](https://www.tutorialspoint.com/juni)||

## Material Review
- Persistent data
- @Test
  - Expectation
- `@Before`, `@BeforeClass`
- `@After`, `@AfterClass`
- `@AssertEqual`, `@AssertTrue`, `@AssertFalse`
- Coverage
- `@Ignore`
- `@Exception`

## Workshops

### Rules
We're going to try something that spans not just your own git, but will involve the rest of the class.  To learn about testing, we're going to construct code to meet a specification.  This means that we have to use the same names and store our sample code in a way that we can easily retrieve programs to run the test.

So,
- your project must be stored in your repository (e.g. `greenfox-zerda-raptor` / your name / `JUnit` / `D1`), there you'll 
- create a `src` folder
  - your standard `App` Class, with `public static void Main(String[] args){}`
  - inside of `src` a package directory `package.com.greenfox.junit` and that in turn will contain
    - A class called `WordToolbox` with the following fields and methods
      - `stringHeld` this is going to be the String that is the base for your tests
      - the usual getters and setters
      - constructor `WordToolbox(String stringHeld)` 
      - boolean `isAnAnagram(String stringToCheck)`
      - int `countHowMany(char charToFind)`
-  a new directory (as per Dr.Bee Video #1) called `tests` and inside
   - `WordToolboxTest` class that will contain the tests you will build

### Exercises
- [01) Create something to test](workshop/Workshop01.md) - build `WordToolbox` class which implements an Interface (`IWordToolbox`) and specifically fill out the method `countHowMany()` (the other methods do nothing for the moment).
- [02) The first use of JUnit](workshop/Workshop02.md) - Test `AssertEquals()`
- [03) Multiple tests](workshop/Workshop03.md) - Add a 2nd test to the `AssertEquals()`
- [04) Test for *Coverage*](workshop/Workshop04.md) - See which methods have been missed by testing
- [05) Ignore a test](workshop/Workshop05.md) - For `isAnagram()` tell the test suite it's not necessary to test
- [06) Create a 2nd item to test](workshop/Workshop06.md) - Complete `isAnagram()` method
- [07) Work with a 2nd type of *assertion*](workshop/Workshop07.md) - Test `AssertsTrue()` and `AssertsFalse()` on `isAnagram()`
- [08) Add exception handling](workshop/Workshop08.md) - in this workshop we're going to throw an exception
- [09) Time out test](workshop/Workshop09.md) - create an infinite loop and cause the testing to catch and report
- [10) Learn about the `@Before` and `@After` annotations](workshop/Workshop10.md) 
- [11) Construct test to challenge others](workshop/Workshop11.md) - create your master test script to challenge the rest of the class.

#Links
- [Parent - Java OO Module](../README.md)
- [Prev - Project: Todo App](../4-project-todo-app/README.md)
- [Next - not defined](../XYZ/README.md)


