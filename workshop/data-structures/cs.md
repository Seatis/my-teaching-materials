# Strings and Lists

Get familiar with C# string functions and a new data structure: List.

Make sure you finish the sorting assignment, rewatch the video if needed.

## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[Learn How To Program In C# - String Manipulation](https://www.youtube.com/watch?v=afY8t4Iv-nc)|16:31|
|[Working with Strings in C#](https://www.youtube.com/watch?v=CLsmRBmteas)|25:47|
|[C# List & Generics](https://www.youtube.com/watch?v=Kx8ij3WZpSg)|6:52| 
|[C# Dictionary Tutorial](https://www.youtube.com/watch?v=UG8s4sWDOqI)|2:26
|[Hash Tables](https://www.youtube.com/watch?v=h2d9b_nEzoA)|7:41|


## Material Review
- String
  - `.Length()`
  - `.Substring()`
  - `.Replace()`
  - `.Equals()`
  - `.ToLower()`
  - `.ToUpper()`
  - `.Contains()`
  - `.IndexOf()`
  - `.LastIndexOf()`
  - `.Split()`
- StringBuilder
- List
  - Object
  - means to *add* and *remove*
  - initialize
    - what are the situation? empty, with values
    - how does one use such; loops
  - `.Add()` (to the next position, at an index)
  - `.AddRange()`
  - `.Remove()`, `.RemoveAt()`
  - `.Capacity()`
  - `.Count()`
  - `.Clear()`
  - searching: `.Contains()`, `.Find()`
  - assigning between arrays (*copying* `.ToArray()`)
  - casting as string `.ToString()`
- Dictionary
  - key
  - value
  - `.Add()`

## Workshop

### Strings

Strings are basic data structures, they can be treated like a list or array of characters.

- [01](strings/simplereplace/SimpleReplace.cs)
- [02](strings/urlfixer/UrlFixer.cs)
- [03](strings/takeslonger/TakesLonger.cs)
- [04](strings/todoprint/TodoPrint.cs)
- [05](strings/reverse/Reverse.cs)


### Lists

Let's play more with list manipulation

- [01](lists/solarsystem/SolarSystem.cs)
- [02](lists/matchmaking/Matchmaking.cs)
- [03](lists/appendletter/AppendLetter.cs)
- [04](lists/candyshop/Candyshop.cs)
- [05](lists/elementfinder/ElementFinder.cs)
- [06](lists/isinlist/IsInList.cs)
- [07](lists/quoteswap/QuoteSwap.cs)

*Okay, you've made it this far. Awesome. If you feel you can get back to any remaining tasks you're unsure of from the previous days. If list is still not your friend, redo all (or some of) the* [tasks for arrays](../functions-and-arrays/cs.md#excercises-1) *just with lists instead*
```csharp
// You can simply convert the examples from this
int[] example = { 1, 2, 3 };
// To this
List<int> converted = new List<int>  { 1, 2, 3 }; 
```

Only proceed to these if you're confident using lists, functions, loops, conditions
- [08](lists/calculator/Calculator.cs)

### Dictionary

Dictionaries are key-value pairs. If you think of it, the list or array is also a dictionary, just with specifically integers as keys.

- [01](strings/hewillnever/HeWillNever.cs)
- [02](hashes/student-counter/StudentCounter.cs)
