# Strings and ArrayLists

Get familiar with Java String functions and a new data structure: Arraylist.

Make sure you finish the sorting assignment, rewatch the video if needed.

## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[String Methods](https://www.youtube.com/watch?v=Hb_IVskG_Ck)|11:39|
|[ArrayLists with types (Fudge.14)](https://www.youtube.com/watch?v=FhqdMFJbsxs) __until 11:42 only!!!__|11:42|
|[Java HashMap Example](https://www.youtube.com/watch?v=J-klDVEtwkM)|3:21|
|[Hash Tables](https://www.youtube.com/watch?v=h2d9b_nEzoA) | 7:41 |


## Material Review
- ArrayLists
  - Object
  - means to *add* and *remove*
  - initialize
    - what are the situation? empty, with values
    - how does one use such; loops
  - `.add()` (to the next position, at an index)
  - `.addAll()`
  - `.remove()` (by index, by value)
  - `.set()`
  - `.size()`
  - `.isEmpty()`
  - `.clear()`
  - searching: `.contains()`, `.containsAll()`
  - assigning between arrays (*copying* `.toArray()`, `.addAll()`)
  - casting as string `.toString()`
- String
  - `.length()`
  - `.subString()`
  - `.replace()`
  - `.charAt()`
  - `.equals()`
  - `.compare()`
  - `.toLowerCase()`
  - `.contains()`
  - `.endsWith()`
  - `.startsWith()`
  - `.indexOf()`
  - `.lastIndexOf()`
  - `.split()`
- HashMap
  - key
  - value
  - `.put()`
  - `.get()`

## Workshop

### Strings

Strings are basic data structures, they can be treated like a list or array of characters.

- [01](strings/simplereplace/SimpleReplace.java)
- [02](strings/urlfixer/UrlFixer.java)
- [03](strings/takeslonger/TakesLonger.java)
- [04](strings/todoprint/TodoPrint.java)
- [05](strings/reverse/Reverse.java)


### Lists

Let's play more with list manipulation

- [01](lists/solarsystem/SolarSystem.java)
- [02](lists/matchmaking/Matchmaking.java)
- [03](lists/appendletter/AppendLetter.java)
- [04](lists/candyshop/Candyshop.java)
- [05](lists/elementfinder/ElementFinder.java)
- [06](lists/isinlist/IsInList.java)
- [07](lists/quoteswap/QuoteSwap.java)

*Okay, you've made it this far. Awesome. If you feel you can get back to any remaining tasks you're unsure of from the previous days. If list is still not your friend, redo all (or some of) the* [tasks for arrays](../functions-and-arrays/java.md#excercises-1) *just with arraylists instead*
```java
// You can simply convert the examples from this
int[] example = {1, 2, 3};
// To this
ArrayList<Integer> converted = Arrays.asList(1, 2, 3);
```

Only proceed to these if you're confident using arraylists, functions, loops, conditions
- [08](lists/calculator/Calculator.java)

### Map

Maps are key-value pairs. If you think of it, the list or array is also a map, just with specifically integers as keys.

- [01](strings/hewillnever/HeWillNever.java)
- [02](hashes/student-counter/StudentCounter.java)
