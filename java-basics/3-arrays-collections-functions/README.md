# Module 03: Day 2 - Array, Functions and Debugging
Expanding from the the primitive datatypes, computers also work with lists of data; one of the most basic is the *array*.  An array offers a way to process a list of items, apply rules repeatedly and collect a series of results.

As students are now conversant with the basic data types and flow, we introduce some tools so that we can watch what is happening when a program runs and find where a program does the __bad__ thing (that is to say, *goes awry*).  

Lastly we show how you can extend a program to use external code (or objects &amp; methods) developed by others (i.e. libraries).

## Objectives
- Functions (methods) and fields
- Main
- Arrays
- Intro to debugging code


## Materials & Resources
- One of the examples makes use of a library that is available over the internet (from a source called Maven).  Called `commons-lang` you will need it for use in the Array exercise.

| Material | Time |
|:-------- |-----:|
|[Methods & Fields, Using Functions (Bana.05)](https://www.youtube.com/watch?v=1HTsLK_m2ao)|14:06|
|[Arrays (Bana.09) (before 08!)](https://www.youtube.com/watch?v=eNPX2pTiaHI)|18:08|
|[Functions with Classes (Bana.08)](https://www.youtube.com/watch?v=rGlJiUO-dZA)| 16:48|
|[Arrays & For Loop](https://www.youtube.com/watch?v=_pUz-GJcdRU)| 21:00|
|[Arrays (related to Object, Bana.11)](https://www.youtube.com/watch?v=IEqvmsqjpT0)| 11:07|
|[How to debug using IntelliJ](https://www.jetbrains.com/help/idea/2016.2/tutorial-debugging-your-first-java-application.html)||
|[Describing how one uses the debugger in IntelliJ](http://blog.javafortesters.com/2016/07/how-to-debug-java-with-intellij.html)||


### Optional
No optional for today :)

## Material Review


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

### Main()
- Fixed invocation
- There can only be 1 per program
  - Identify which is the *entry* point
- How to read the parameter(s) passed

### Debugging - Introduction
- Setting a break point-  How to walk through the program
- Inspecting a variable

### External Libraries/Maven (Optional)
As there are many examples where external libraries are used, we will briefly now show how to add such in.  We will cover libraries in more depth later in the course.

### Challenges
- https://www.codewars.com/kata/descending-order/train/java
- http://www.homeandlearn.co.uk/java/java_for_loops.html


## Individual Workshop Review
Please follow the styleguide: [Our Java styleguide](../../styleguide/java.md)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
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
