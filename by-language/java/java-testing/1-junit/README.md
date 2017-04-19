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

## Workshops

## The beginning
- [01) Workshop01](workshop/Workshop01.md)
- [02) Workshop02](workshop/Workshop02.md)
- [03) Workshop03](workshop/Workshop03.md)


## Lets play a game - The testing Competition
With our basic testing Knowledge we shall figure out who's the best in writing solution and writing tests. So we've created a relatively simple task (which will be implemented as the Solution) and you also asked to create tests for checking that solution. Since the problem is the same for everyone, if we pay attention to the details we can run everyone's test on your solution to see how well it is doing on things others' tested.
- [Testing Competition](workshop/TestingCompetition.md)

#Links
- [Parent - Java OO Module](../README.md)
- [Prev - Project: Todo App](../4-project-todo-app/README.md)
- [Next - not defined](../XYZ/README.md)
