# Strings and ArrayLists
Get familiar with Java String functions and a new data structure: Arraylist.


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[String Methods](https://www.youtube.com/watch?v=Hb_IVskG_Ck)|11:39|
|[ArrayLists with types (Fudge.14)](https://www.youtube.com/watch?v=FhqdMFJbsxs) __until 11:42 only!!!__|11:42|
|[Java HashMap Example](https://www.youtube.com/watch?v=J-klDVEtwkM)|3:21|


## Material Review
- ArrayLists
  - means to *add* and *remove*
  - `.addAll()`
  - `.contains()`
  - `.containsAll()`
  - `.clear()`
  - `.isEmpty()`
  - initialize
    - what are the situation? empty, with values
    - how does one use such; loops
  - `.add()` (to the next position, at an index)
  - `.remove()` (by index, by value)
  - `.set()`
  - `.size()`
  - `.isEmpty()`
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
- Object

## Workshop

### Strings

Strings are basic data structures, they can be treated like a list or array of characters.

- [01](strings/simplereplace/simplereplace.java)
- [02](strings/urlfixer/urlfixer.java)
- [03](strings/takeslonger/takeslonger.java)
- [04](strings/todoprint/todoprint.java)
- [05](strings/reverse/reverse.java)


### Lists

Let's play more with list manipulation

- [01](lists/solarsystem/solarsystem.java)
- [02](lists/matchmaking/matchmaking.java)
- [03](lists/appendletter/appendletter.java)
- [04](lists/candyshop/candyshop.java)
- [05](lists/elementfinder/elementfinder.java)
- [06](lists/isinlist/isinlist.java)
- [07](lists/quoteswap/quoteswap.java)

*Okay, you've made it this far. Awesome. If you feel you can get back to any remaining tasks you're unsure of from the previous days. If list is still not your friend, redo all (or some of) the* [tasks for arrays](../functions-and-arrays/java.md#excercises-1) *just with arraylists instead*
```java
// You can simple convert the examples from this
int[] example = {1, 2, 3};
// To this
ArrayList<Integer> converted = Arrays.asList(1, 2, 3);
```

Only proceed to these if you're confident using arraylists, functions, loops, conditions
- [08](lists/calculator/calculator.java)

### Map

Maps are key-value pairs. If you think of it, the list or array is also a map, just with specifically integers as keys.

- [01](strings/hewillnever/hewillnever.java)
- [02](hashes/student-counter/student-counter.java)
