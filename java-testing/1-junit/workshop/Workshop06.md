# Workshop06 - Develop the `isAnagram()` method.

By *anagram* we want to test if one word uses the sme characters as the other.  We are case *insensitive* and only care about the standard English letters.  Here are some samples from which you can derive a solution:-

```java
	//WordToolbox w = new WordToolbox ("folate"); 
        w.setS("folate");
        String [] testlist = {"falsetto", "latest", "foetal","aloft","float","flota"};
        for (String s : testlist) {
            System.out.printf("is %s an anagram of %s = %s\n", s, w.getS(), w.isAnAnagram(s));
        }
        System.out.println("\nNew test");
        w.setS("aloft");
        for (String s : testlist) {
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
