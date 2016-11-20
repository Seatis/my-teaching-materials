# The Testing Competition


## Rules
We're going to try something that spans not just your own git, but will involve the rest of the class.  To learn about testing, we're going to construct code to meet a specification.  This means that we have to use the same names and store our sample code in a way that we can easily retrieve programs to run the test.

So,
- create a clean new project
- in the `src` folder
  - you can have your standard `App` Class, with `public static void Main(String[] args){}` to test manually
  - A class called `WordToolbox` with the following fields and methods
    - `private String stringHeld` this is going to be the String that is the base for your tests
    - the usual getters and setters
    - constructor `WordToolbox(String stringHeld)`
    - boolean `isAnAnagram(String stringToCheck)`
    - int `countHowMany(char charToFind)`
-  a new directory (as per Dr.Bee Video #1) called `tests` and inside
   - `TestYourName` class that will contain the tests you will build

## Create something to test
This method has to sit in a class that we'll extend in this lesson for testing.  At the end of the day, it will support your various tests. Implement the following interface in

The basis of the class is as follow

```java
package com.greenfox.lesson.junit;

interface IWordToolbox {

    public int countHowMany(char c);
    public void setS(String s);
    public String getS();
    public boolean isAnAnagram(String stringToCheck) throws Exception ;
    public void WaitingItOut();
    }
```


Now add to this class the following methods `getS()` and `countHowMany(char c)`.  Here are some samples to give you an idea

```java

  WordToolbox wSource = new WordToolbox ("Tarzan's toenails");
  System.out.println ("countHowMany(\"a\")=", wSource.countHowMany("a")); \\ countHowMany("a")=3
  System.out.println ("countHowMany(\"T\")=", wSource.countHowMany("T")); \\ countHowMany("T")=2
  System.out.println ("countHowMany(\"t\")=", wSource.countHowMany("t")); \\ countHowMany("t")=2
  System.out.println ("countHowMany(\"x\")=", wSource.countHowMany("x")); \\ countHowMany("x")=0
  System.out.println ("countHowMany(\"\")=", wSource.countHowMany("")); \\ countHowMany("")=0
  System.out.println ("countHowMany(\" \")=", wSource.countHowMany(" ")); \\ countHowMany(" ")=1
```

Hint: `String` variables have `length()` and `charAt(int)`

## First Assert
You are tasked with creating the first assertion; you've probably already tested these anyway in your `main()` however this is a weak way to test programs. Let's move these to a Test section which we can re-visit later if we change the code.

Set up a test for "Tarzan's toenails, check for "a" and other letters both in and out of the string.

## Multiple tests
Extend from Tarzan and his toenails. Add another string, specifically "Me Tarzan, You Jane" to the mix. These should show up as a *2nd test*.

## Test for coverage.
Look at which methods are not being tested.

## Test for coverage.
Ignore `isAnagram()` and recheck the coverage.

## Develop the `isAnagram()` method.

### Helper method
For checking the Anagram its probably helpful to create another method which counts all letters in the word given as paramater.
For that you can use the `HashMap` class.
The `HashMap<Key, Value>` class, what you can use like the `ArrayList<Value>` with not just integer as the index. So you can create a list, where calling the `get()` method you dont put an int as the parameter, but you can use a char instead. It even has a `containsKey(Object)`.
So the helper method should look like this:
```java
private HashMap<Character, Integer> countAllLetters(String word) {
  // Here create the HashMap and go through the word letters, count them if the letter is not already counted
}
```
Hint: You can user your `countHowMany(char)` method.

### Now the isAnagram method

By *anagram* we want to test if one word uses the same characters as the other.  We are case *insensitive* and only care about the standard English letters. Here are some samples from which you can derive a solution:-

```java
	//WordToolbox w = new WordToolbox ("folate");
        w.setS("folate");
        String [] alternatives = {"falsetto", "latest", "foetal","aloft","float","flota"};
        for (String s : alternatives) {
            System.out.printf("is %s an anagram of %s = %s\n", s, w.getS(), w.isAnAnagram(s));
        }
        System.out.println("\nNew test");
        w.setS("aloft");
        for (String s : alternatives) {
            System.out.printf("is %s an anagram of %s = %s\n", s, w.getS(), w.isAnAnagram(s));
        }
```

The results should be
```
is falsetto an anagram of folate = false
is latest an anagram of folate = false
is foetal an anagram of folate = true
is aloft an anagram of folate = false
is float an anagram of folate = false
is flota an anagram of folate = false

New test
is falsetto an anagram of aloft = false
is latest an anagram of aloft = false
is foetal an anagram of aloft = false
is aloft an anagram of aloft = true
is float an anagram of aloft = true
is flota an anagram of aloft = true
```

## Try out `AssertTrue()` and `AssertFalse()`

Now that the Anagram program *works*, let's put it through its paces.

Do various asserts based on what we tested earlier, with
- "aloft", try a true and a false.
- what if one string is blank and the other isn't
- vice versa

## Let's cause an exception

What happens if you do the following?

```java
            System.out.printf("is %s an anagram of %s = %s\n", null, w.getS(), w.isAnAnagram(null));
```

Let's have a test to catch this failure.  

Then let's modify the code to both catch the failure (in the class), and still test for it cleanly.
Infinite loop

## Complete the method() `WaitingItOut()` as follows
```java
void WaitingItOut() {
  for (int i = 0; i = 0; ) {};
}

```

Let's have a test to catch this failure.  

## Using @Before and @After

Add to your test the following methods and ensure that they execute accordingly in your testing

```java
        WordToolbox wordToolbox;

		    public static void onceExecutedBeforeAll() {
		        System.out.println("@BeforeClass: onceExecutedBeforeAll");
		    }

		    public void executedBeforeEach() {
		        wordToolbox = new WordToolbox("Muppets");
		        System.out.println("@Before: executedBeforeEach");
		    }

		    public static void onceExecutedAfterAll() {
		        System.out.println("@AfterClass: onceAfterAll");
		    }

		    public void executedAfterEach() {
						wordToolbox = null;
		        System.out.println("@After: executedAfterEach");
		    }

```

Expectations are something like this (not tested yet).

```	 
@BeforeClass: onceExecutedBeforeAll
@Before: executedBeforeEach
@Test: testwhatever
@After: executedAfterEach
@Before: executedBeforeEach
@Test: testwhatever
@After: executedAfterEach
@AfterClass: onceAfterAll
```

## Test all cases and methods
- If you're finished with these, you can come up with special cases, test them.
- Ensure that all `public` methods are tested
- Try to make others' solution fail, while yours passes everything
