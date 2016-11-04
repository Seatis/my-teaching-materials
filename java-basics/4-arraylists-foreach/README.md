# Module 03: Day 3 - ArrayList (LinkedLists),  Iterators and Foreach
Working with lists is core to computing; the first computers were little more than engines for sorting tables.  In this day we look further into storing and working with lists.

As this is a short week, we are not doing any demos.  However, we are assigning some videos and a review for over the weekend to reinforce the various items that were learnt so far in this module.


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[ArrayLists with types (Fudge.14)](https://www.youtube.com/watch?v=FhqdMFJbsxs) __until 11:42 only!!!__|11:42|
|[Arrays (related to Object, Bana.11)](https://www.youtube.com/watch?v=IEqvmsqjpT0)|11:07|
|[Interators on ArrayList (Vidal)](https://www.youtube.com/watch?v=5TaZbcXkpxs)|6:47|
|[Using foreach (Miskew)](https://www.youtube.com/watch?v=eByBsjUazII)|7:34|


### Optional
*These are other type of Collections, the usage of them all is basically the same just working differently under the hood.*
| Material | Time |
|:-------- |-----:|
|[Introduction (Visual  illustration) of Linked Lists (Reel)](https://www.youtube.com/watch?v=pBrz9HmjFOs)| 13:39 |
|[Linked Lists (High Level, Bana.12)](https://www.youtube.com/watch?v=HLwijvzWNKo)|11:45|
|[Linked Lists (Deeper/Part 1 Bana.LL1)](https://www.youtube.com/watch?v=195KUinjBpU)|17:35|
|[Linked Lists (Deeper/Part 2 (doubly linked & Interators)](https://www.youtube.com/watch?v=iR5wyCaIayk)|19.12|
|[LinkedLists, Stacks & Queue - Algorithm Theory (bhee)](https://www.youtube.com/watch?v=LOHBGyK3Hbs)|6:02|
|[Hash Table concepts (CS50)](https://www.youtube.com/watch?v=h2d9b_nEzoA)|7:41|
|[HashSet/HashMap Demo (vidal)](https://www.youtube.com/watch?v=jwtx6GVPdyw)|13:24|
|[HashMap/Set examples from Minecraft (vector)](https://www.youtube.com/watch?v=j442WG8YzM4)|5:53|


## Assignment Review
- ArrayLists
  - means to *add* and *remove*
  - addAll
  - contains
  - containsAll *comparing one Array with another*
  - clear
  - isEmpty
  - initialise
    - empty
    - with values
    - using a loop
  - add (to the next position, at an index)
  - remove (by index, by value)
  - set
  - size()
  - isEmpty
  - searching: contains(), containsAll()
  - assigning between arrays (*copying* toArray(), addAll())
  - casting as string toString()
  - difference between arrays & collection (*primitive* data types)
- Iterator
  - supports ArrayList
  - hasNext
  - associated with an ArrayList
  - List
  - `List<String>`
  - add
  - foreach()
  - size (not length)
  - next
  - hasNext
  - remove
- `for(Datatype item : Collection)`

## Workshop

### ArrayLists with types

### ArraysLists & Collections

### Iterator

### Foreach


### Optional
#### HashSet &amp; HashMaps
- concepts: hash function, collision, order of magnitude rating
- add &amp; put
- keyset
- remove


#### LinkedLists
- concept: pointing to the next, previous, first, last
- add(), addFirst(), addLast
- set()
- remove()
- size
- get(), getFirst(), getLast()
- peek()
- poll(), pollFirst(), pollLast()
- clear()

#### Other well-known types of lists
It's worth knowing conceptually what these are as they come up in interviews and are instrumental in various types of processes like email servers, windows engines, etc.
- Dictionary - ordered pairs
- Queue
  - push
  - pop
- Stack  


### Challenge - Kata Descending Order
- https://www.codewars.com/kata/descending-order/train/java

## Individual Workshop Review
Please follow the styleguide: [Our Java styleguide](../../styleguide/java.md)
- Is the directory structure and the name of the files correct?
- Are the includes placed on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Are the names of things following the styleguide?
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
    - functions: lowerCamelCase(paramsLowerCase)
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
