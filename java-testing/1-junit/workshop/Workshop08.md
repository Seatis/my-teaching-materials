# Workshop08 - Let's cause an exception

What happens if you do the following?

```java
            System.out.printf("is %s an anagram of %s = %s\n", null, w.getS(), w.isAnAnagram(null));
```

Let's have a test to catch this failure.  

Then let's modify the code to both catch the failure (in the class), and still test for it cleanly.
