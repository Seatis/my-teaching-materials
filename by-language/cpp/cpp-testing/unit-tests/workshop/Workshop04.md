# The Testing


So,
- create a clean new project
- Create
  - A class called `WordToolbox` with the following fields and methods
    - `string stringHeld` this is going to be the string that is the base for your tests
    - a getter and setter to manipulate this string
    - constructor `WordToolbox(string stringHeld)`
    - `bool isAnAnagram(string stringToCheck)`
    - `int countHowMany(char charToFind)`
  - a new directory called `tests` and inside your unit tests

## C01) Create something to test
So create the `WordToolbox` class declaration.

Now add to this class the following methods `getS()` and `countHowMany(char c)`.  Here are some samples to give you an idea

```cpp
  WordToolbox wSource("Tarzan's toenails");
  cout << "countHowMany(\"a\")=" + wSource.countHowMany('a') << endl; // countHowMany("a")=3
  cout << "countHowMany(\"T\")=" + wSource.countHowMany('T') << endl; // countHowMany("T")=2
  cout << "countHowMany(\"t\")=" + wSource.countHowMany('t') << endl; // countHowMany("t")=2
  cout << "countHowMany(\"x\")=" + wSource.countHowMany('x') << endl; // countHowMany("x")=0
  cout << "countHowMany(\" \")=" + wSource.countHowMany(' ') << endl; // countHowMany(" ")=1
```

## C02) First Assert
Set up a test for "Tarzan's toenails, check for "a" and other letters both in and out of the string.

## C03) Multiple tests
Extend from Tarzan and his toenails. Add another string, specifically "Me Tarzan, You Jane" to the mix.

## C04) Develop the `isAnagram()` method.

### C05) Now the isAnagram method

By *anagram* we want to test if one word uses the same characters as the other.  We are case *insensitive* and only care about the standard English letters. Here are some samples from which you can derive a solution:-

```cpp
	WordToolbox WordToolbox("folate");
  w.setS("folate");
  string alternatives[6] = {"falsetto", "latest", "foetal","aloft","float","flota"};
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " <<< w.isAnAnagram(s) << endl;
  }
  cout << endl << "New test" << endl;
  w.setS("aloft");
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " <<< w.isAnAnagram(s) << endl;
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

## C06) Try out `REQUIRE()` and `REQUIRE_FALSE()`

Now that the Anagram program *works*, let's put it through its paces.

Do various asserts based on what we tested earlier, with
- "aloft", try a true and a false.
- what if one string is blank and the other isn't
- vice versa

## C07) Test all cases and methods
- If you're finished with these, you can come up with special cases, test them.
- Ensure that all `public` methods are tested
