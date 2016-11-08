# Module 03 #4 - ArrayList (LinkedLists),  Iterators and Foreach
The previous workshop introduced Arrays.  Here we look at arrays a little more; though it's over 35 minutes, it should be a *refresher* only.  
- ArrayLists - these are generally used when we have lists of values and are not so concerned about navigating (e.g. element "x" or "x","y")
- We see here (again, but perhaps you didn't catch it before) that the item tracked might have to be of a certain data type (e.g. &lt;String&gt;)
- There are various ways to step through a list
  - Foreach - which we saw earlier
  - Iterator - knowing the list and waiting to be told, *go to the next one*

As we have already played with Strings, we can revisit the idea of immutable (*One Love, ...* as Bob Marley would say).  But there are other situations where the string can change (mutable).

Lastly, as you may have suspected, switching between datatypes can sometimes be inferred; other times you need to be forceful and explicit.  For example what happens with `System.out.println("1" + 1)`?  What if it were `System.out.println((int) "1" + 1)`?  This is casting and conversion.

In the optional materials there are a few other *List* types that are good to know about.  Normally in a full year's course you'd go deeper; we have them here so that you know about them.  You might, later in the course, consider one of these approaches for a project - or in your later career.
- Linked Lists - these are lists where an item in the list points to the next (and/or previous) item in the list; this lets us insert and remove items from a list without having to clean up memory
- Stacks - we use these for figuring out, for example, what to process.  Think of an ambulance passing through heavy traffic; the ambulance goes to the top of the stack at the traffic light.
- Queues - welcome to the post office, supermarket...  you've probably heard of *First in, First Out* (aka *FIFO*) and others.
- Hash - yet another way to store lists so that the values can be found quickly; but at a price.
- Dictionary - these are *ordered pairs* where one might use a text value to look something up (for example in a configuration).

We'll be doing these Workshops as well as reviewing last week's through the end of tomorrow.  So there's time to get a handle on all of  this stuff.  If you find you're getting ahead, then look at the optional materials.  So please, at the end of this posting note the questions about style when reviewing your own work and that of the people you are code reviewing.


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[ArrayLists with types (Fudge.14)](https://www.youtube.com/watch?v=FhqdMFJbsxs) __until 11:42 only!!!__|11:42|
|[Arrays (related to Object, Bana.11)](https://www.youtube.com/watch?v=IEqvmsqjpT0)|11:07|
|[Interators on ArrayList (Vidal)](https://www.youtube.com/watch?v=5TaZbcXkpxs)|6:47|
|[Using foreach (Miskew)](https://www.youtube.com/watch?v=eByBsjUazII)|7:34|
|[String, StringBuilder, Immutable (Bana 13)](https://www.youtube.com/watch?v=RxeDe6BsTMI)|15:43|
|[Casting & Conversion](https://www.youtube.com/watch?v=AzO5pYE3y5o)|14:13|


### Optional
*These are other type of Collections, the usage of them all is basically the same just working differently under the hood.*

| Material | Time |
|:-------- |-----:|
|[Introduction (Visual  illustration) of Linked Lists (Reel)](https://www.youtube.com/watch?v=pBrz9HmjFOs)|13:39|
|[Linked Lists (High Level, Bana.12)](https://www.youtube.com/watch?v=HLwijvzWNKo)|11:45|
|[Linked Lists (Deeper/Part 1 Bana.LL1)](https://www.youtube.com/watch?v=195KUinjBpU)|17:35|
|[Linked Lists (Deeper/Part 2 (doubly linked & Interators)](https://www.youtube.com/watch?v=iR5wyCaIayk)|19.12|
|[LinkedLists, Stacks & Queue - Algorithm Theory (bhee)](https://www.youtube.com/watch?v=LOHBGyK3Hbs)|6:02|
|[Hash Table concepts (CS50)](https://www.youtube.com/watch?v=h2d9b_nEzoA)|7:41|
|[HashSet/HashMap Demo (vidal)](https://www.youtube.com/watch?v=jwtx6GVPdyw)|13:24|
|[HashMap/Set examples from Minecraft (vector)](https://www.youtube.com/watch?v=j442WG8YzM4)|5:53|
|[Refresher on data types & conversion (indian English)](https://www.youtube.com/watch?v=bqPIWlnjWbA)|14:53|
|[StringBuilder (Posch)](https://www.youtube.com/watch?v=1yynLCFRuAk|6:13|


## Assignment Review
- ArrayLists
  - means to *add* and *remove*
  - `.addAll()`
  - `.contains()`
  - `.containsAll()` *comparing one Array with another*
  - `.clear()`
  - `.isEmpty()`
  - initialise
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
  - difference between arrays & collection (*primitive* data types)
- Iterator
  - supports ArrayList
  - `.hasNext()`
  - associated with an ArrayList
  - List
  - List&lt;String&gt;
  - add
  - foreach()
  - `.size()` (not length)
  - `.next()`
  - `.remove()`
- `for(Datatype item : Collection)`
- String (and StringBuilder)
  - escape character (e.g. \", \n, \b
  - `.length()`
  - `.subString()`
  - `.trim()`
  - `.replace()`
  - `.charAt()`
  - `.equals()` function
  - `.compare()`
  - `toLowerCase()` and lower case
  - `.contains()`
  - `.endsWith()`
  - `.startsWith()`
  - `indexOf()`
  - `.lastIndexOf()`
  - `.split()`
- Specifically StringBuilder
  - `.append()`
  - `.insert()`
  - `.delete()`
  - `.capacity()`
  - `.ensureCapacity()`
  - `.trimToSize()` 
  - `.toString()`

### Optional
It's worth knowing conceptually what these are as they come up in interviews and are instrumental in various types of processes like email servers, windows engines, etc.  Here, it's partly about understanding the concepts and recognising the terms.

- HashSet &amp; HashMaps
  - concepts: hash function, collision, order of magnitude rating
  - add &amp; put
  - keyset
  - remove
- LinkedLists
  - concept: pointing to the next, previous, first, last
  - `.add()`, `.addFirst()`, `.addLast()`
  - `.set()`
  - `.remove()`
  - `.size()`
  - `.get()`, `getFirst()`, `.getLast()`
  - `.peek()`
  - `.poll()`, `.pollFirst()`, `.pollLast()`
  - `.clear()`

- Dictionary *note this is an actual term*, it refers to *ordered pairs* - this is used a lot

- Queue & Stack
  - `push`
  - `pop`
  - `clear`


## Workshops

### StringBuilder
Work on the Stringbuilder stuff first.  Once this feels comfortable, look at the collection stuff more.

- [Workshop18.java](workshop/Workshop18.java)
- [Workshop19.java](workshop/Workshop19.java)
- [Workshop20.java](workshop/Workshop20.java)
- [Workshop21.java](workshop/Workshop21.java)
- [Workshop22.java](workshop/Workshop22.java)
- [Workshop23.java](workshop/Workshop23.java)

### ArraysLists & Collections

- [Workshop01.java](workshop/Workshop01.java)
- [Workshop02.java](workshop/Workshop02.java)
- [Workshop03.java](workshop/Workshop03.java)
- [Workshop04.java](workshop/Workshop04.java)
- [Workshop05.java](workshop/Workshop05.java)
- [Workshop06.java](workshop/Workshop06.java)
- [Workshop07.java](workshop/Workshop07.java)
- [Workshop08.java](workshop/Workshop08.java)
- [Workshop09.java](workshop/Workshop09.java)
- [Workshop10.java](workshop/Workshop10.java)
- [Workshop11.java](workshop/Workshop11.java)
- [Workshop12.java](workshop/Workshop12.java)

### Iterator & Foreach
There are different ways of navigating through collections; here are a few exercises to get more experience.
- [Workshop13.java](workshop/Workshop13.java)
- [Workshop14.java](workshop/Workshop14.java)
- [Workshop15.java](workshop/Workshop15.java)
- [Workshop16.java](workshop/Workshop16.java)
- [Workshop17.java](workshop/Workshop17.java)

### Challenge - Data conversion (simple calculator)
Now, let's try something with a purpose.
- [Workshop24.java](workshop/Workshop24.java)


### Challenge - Kata Descending Order
It's fun to try out some of the algorithm puzzles posed on codewars.com.
- https://www.codewars.com/kata/descending-order/train/java

## Individual Workshop Review
Neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)

Key questions to consider:
- Are the directory structure and the names of the files correct?
- Are the includes placed at the top of the file?
- Does the code follow the right level of indentation?
- Are all of the brackets positioned correctly?
- Are the whitespaces where they should be; and not where they shouldn't?
- Is the code *pithy* (meaning to the point, not superfluous or un-necessary)?
  - Not using extra variables (unless needed to understand the logic)
  - Not confusingly or overly commented
  - Does the computation instead of repeating stuff (aka *code duplication*)?
  - Does not contain empty blocks
  - Non repetitive and where needing to repeat a block instead, carved out to a function?
- Are there un-used variables - added during development but later made surplus to requirements through simplification?
- Is the commentary in the code at the right level?
  - Can one deduce the purpose of a block from the variable naming combined with the explanation
  - Are there *Watch outs* warnings just in case somebody later maintains the code and needs to beware of something tricky (or not obvious)?
- Are the data types used right for the purpose
- Is the "commit message" meaningful?
- Do the names conform to the Styleguide?
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
    - functions: lowerCamelCase(paramsLowerCase)

# Links
- [Java Basic Module](..\README.md)
- [Prev Day](..\3-arrays-collections-functions\README.md)
- [Next Day](..\5-io-exceptions-try-catch-finally\README.md)
- [Projects](..\P-project-options\README.md)

