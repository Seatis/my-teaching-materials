# Module 03: #3 - Array, Functions and Debugging
Expanding from the the primitive datatypes, computers also work with lists of data; one of the most basic is the *array*.  An array offers a way to process a list of items, apply rules repeatedly and collect a series of results.  We look at 1 and 2 dimensional arrays, and briefly touch on Lists (an alternative, related construct).

As we are now conversant with the basic data types and flow, we introduce some tools that give us a way to figure out what is happening when a program runs and which we can use to find where a program does the __bad__ thing (that is to say, *does not do what we want it to do*).  

- Functions (methods) and fields
- Arrays
- Array List
- List
- Intro to a debugger


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[What is an Array?](https://www.youtube.com/watch?v=NptnmWvkbTw) *It has some objects and stuff we haven't covered yet, but just focus on the idea here, not the specifics. Either this or HINDENGLISH ;)*|7:08|
|[Introduction to Arrays](https://www.youtube.com/watch?v=L06uGnF4IpY)|7:25|
|[Arrays (Bana.09)](https://www.youtube.com/watch?v=eNPX2pTiaHI)|18:08|
|[Methods & Fields, Using Functions (Bana.05)](https://www.youtube.com/watch?v=1HTsLK_m2ao)|14:06|
|[Arrays (Bana.09)](https://www.youtube.com/watch?v=eNPX2pTiaHI)|18:08|
<!--- |[Functions with Classes (Bana.08)](https://www.youtube.com/watch?v=rGlJiUO-dZA)| 16:48|
|[Arrays & For Loop](https://www.youtube.com/watch?v=_pUz-GJcdRU)| 21:00| -->
|[Array Lists (related to Object, Bana.11)](https://www.youtube.com/watch?v=IEqvmsqjpT0)| 11:07|
|[Lists (with Arrays and data typed, NewBoston.04)](https://www.youtube.com/watch?v=jU5ACV5MucM)|7:16|
|[Using IntelliJ's Debugger (JavaForTesters YT and text)](http://blog.javafortesters.com/2016/07/how-to-debug-java-with-intellij.html)|08:47|


### Optional
If unclear only.

| Material | Time |
|:-------- |-----:|
|[Arrays & For Loop (LearningLad.29)](https://www.youtube.com/watch?v=UZOxpbtlVWg)|4:54|
|[2 dimensional arrays (LearningLad.30)](https://www.youtube.com/watch?v=udHgmxK9oAI)|10:55|
|[2 dimensional arrays, more (LearningLad.31)](https://www.youtube.com/watch?v=w40VcpGWHBM)|11:00|

## Material Review
- Declaring
  - constants
  - initial values of arrays `{}`
  - `new` keyword
- Functions
  - void or return a value
  - can be used to compartmentalise code (make more readable)
  - have own variables
  - take parameters
- Arrays
  - can be measured (have `length`)
  - can be iterated through
  - type definition (e.g. `String[]`)
  - toString
  - copyOf
  - sort
  - binarySearch
  - foreach statement (e.g. `for(int row: numberArray) {System.out.print(row);}`)

We also saw:
- Object - brief notation
- System.out.printf and "s% " as the format by which to print

## Workshop

### Add in a library
*There's a useful set of routines that exists outside of the main Java built-in statements which, as we are covering arrays, we'd like to loop in.*
- Why are there libraries
- How are they added so that IDEA knows about them
- How do you include them in a program; reference them in the code.

### Arrays
- overview
  - index and content
  - static vs dynamic
  - dimensioned (space allocated)
- initalise arrays
  - "new"
  - redefine the values
  - declaration
  - initialise with values {"a","b"}
- loop through an array
- multi-dimensional arrays
- fill()
- Arrays.toString(*array variable*) __NOT__ *array variable*.toString as *Arrays* is a library function
- type in an array (i.e. Array&lt;type&gt;)

*jagged arrays*

### Exercise
*Exercises about arrays*
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
- [Workshop13.java](workshop/Workshop13.java)
- [Workshop14.java](workshop/Workshop14.java)


### Functions
- Purpose
- Return statement and value
- Input Parameters
- Scoping
  - re-use named variable
  - global variable
  - passing by reference vs value

#### Exercise
*Exercises about Functions*
- [Workshop15.java](workshop/Workshop15.java)
- [Workshop16.java](workshop/Workshop16.java)
- [Workshop17.java](workshop/Workshop17.java)
- [Workshop18.java](workshop/Workshop18.java)
- [Workshop19.java](workshop/Workshop19.java)
- [Workshop20.java](workshop/Workshop20.java)
- [Workshop21.java](workshop/Workshop21.java)
- [Workshop22.java](workshop/Workshop22.java)
- [Workshop23.java](workshop/Workshop23.java)

### Debugging - Introduction
Review some of your previous programs to play around with the debugger.
- Setting a break point and walk through the program
- Inspecting a variable
- Change a variable value
- Try with an example that has a function (subroutine)
- Run to the next breakpoint
- Run to a point in the code
Look at what happens with Loops, coming back to the same statement.

### Challenge Using Codewars
- https://www.codewars.com/kata/descending-order/train/java

### More worked examples for Loops
The following site has a series of challenges relating to loops.
- http://www.homeandlearn.co.uk/java/java_for_loops.html


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
