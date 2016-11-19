# Workshop01 - Create something to test
This method has to sit in a class that we'll extend in this lesson for testing.  At the end of the day, it will support your various tests.  Implement the following interface in 

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
  System.out.println ("countHowMany(\"a\")=", wSource.countHowMany("a")); \\ countHowMany("a")=2
  System.out.println ("countHowMany(\"T\")=", wSource.countHowMany("T")); \\ countHowMany("T")=2
  System.out.println ("countHowMany(\"t\")=", wSource.countHowMany("t")); \\ countHowMany("t")=2
  System.out.println ("countHowMany(\"x\")=", wSource.countHowMany("x")); \\ countHowMany("x")=0
  System.out.println ("countHowMany(\"\")=", wSource.countHowMany("")); \\ countHowMany("")=0
  System.out.println ("countHowMany(\" \")=", wSource.countHowMany(" ")); \\ countHowMany(" ")=1
```
