# Introduction to Classes and Objects
Classes and Objects lay at the heart of Java.  Until this point we have covered the foundations of programming (that is variables, conditionals, simple I/O and loops) as well as learning some core skills (getting a program to run and watching it execute so as to debug).  

Now that we have a foundation, we can turn our attention to a core element of the Java *Object Orientation* (aka "OO").  In the late 80s, this was the &quot;Promised Land&quot; (that&apos;s a biblical metaphor for *the future of programming*).  

With OO, a new realm of programming opened up.  It became easier to deliver more complex problems as they could be broken down into simpler units.  OO removed complexity and ensured a common understanding leading to standards that in turn has allowed one to develop more complex and distributed systems.

In this segment we'll first cover the theory (and how it arose); then go through a series of videos that show how Java provides these features and build your vocabulary and knowledge base.

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[The origins of OO (CodeGuru.06)](https://www.youtube.com/watch?v=pBlH24tFRQk)|2:31|
|[What do objects consist of? (JCode.03)](https://www.youtube.com/watch?v=eKC04ztp09o)|1:37|
|[Defining a class programmatically (JCode.04)](https://www.youtube.com/watch?v=X8D2FVAfNtI)|1:00|
|[What is a field in a class (JCode.05)](https://www.youtube.com/watch?v=UDVVPUqjsRg)|1:37|
|[Programmatically creating a class, an instance of a class and accessing its properties (Cave.13](https://www.youtube.com/watch?v=OHw2t8BaIUg#t=50)|11:44|
|[Methods (JCode.06)](https://www.youtube.com/watch?v=chWtlHxYS8Y)|3:58|
|[Methods of a Class (Cave.14)](https://www.youtube.com/watch?v=-eoNHtILOs4)|11:05|
|[Getters and Return (Cave.15)](https://www.youtube.com/watch?v=foX28s2Qw0w)|10:31|
|[Setters and this (Cave.17)](https://www.youtube.com/watch?v=x-gBJ6q3Ufc)|10:58|
|[Constructors (Cave.18)](https://www.youtube.com/watch?v=oSiN1J_G01Q)|10:18|
|[New Operator; Declaration, Instantiation & Initialization (Ross)](https://www.youtube.com/watch?v=VyPFa1Slh7A#t=50) - what happens when you create an object; also give you an idea of what its like to work without an IDE|12:11|


### Optional
| Material | Time |
|:---------|-----:|
|[Static and Final Cave.19](https://www.youtube.com/watch?v=yImBET6EO8c)|19:46|
|[IntelliJ tool: Getters &amp; Setters Generator](https://www.jetbrains.com/help/idea/2016.2/generating-getters-and-setters.html)||

## Review
- class
  - contains fields and methods
- object
- instantiation
  - initialization
  - *instance*
- method
- constructor
  - same as the name of the class
  - can have multiple versions (signatures)
- new
- fields (aka, properties, attributes)
- setter
- getter
- static

### Optional Items
- IntelliJ Tools


## Workshops
In today's workshops you'll be building up from 1 exercise to the next to produce a final upload (to git) bit of code.

### *The Car*
Introducing the basic anatomy of an object.
- [01) Add a constructor](workshop/Workshop01.md) - The mentors have started to build something but you have to finish it
- [02) Add some fields](workshop/Workshop01-AddFields.md) - There are a couple of ways to setting values in fields and getting their values
- [03) Add getters &amp; setters](workshop/Workshop01-AddGetters.md) - Separate the Class from the Main(), creating a separate file called Workshop01.java.
- If you created the `getters` and `setters` by hand, repeat the previous workshop, but use the IntelliJ tool (Code.Generate) to generate the getters &amp; setters (described above in the optional section; and don't feel silly you missed it, but glad that we've now shown you a tool).
- [04) Create a drive method](workshop/Workshop01-AddDrive.md) - drive the car some distance, updates the odometer.
- [05) Combine fields together into a method](workshop/Workshop01-ToString.md) - create a `toString` method that can get us the Make, km and top speed; making it easier for us to report
- [06) Extend object with an alternative constructor](workshop/Workshop01-Constructor2.md) - rather than having to write separate lines for each attribute, do it all in 1 go when the object gets created
- [07) ArrayList and an Object](workshop/Workshop01-ArrayOf10.md) - add 10 cars and then print them out
- [08) Static property](workshop/Workshop01-Static.md) - illustrate what is in the Car Class initially (before creating 10 cars), then see the final value once 10 cars are created.
- [+1) The Garage](workshop/Garage.md)

### From Scratch
Having stepped through the *Car* Class, let's repeat such from start to finish with some other classes.
- [09) The Circle](workshop/Workshop02.md)
- [10) Pirates *Arghhh*](workshop/Workshop03.md)
- [+1) The Armada of Pirate Ships](workshop/Ship.md)



## Individual Workshop Review
Neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)


#Links
- [Parent - Java OO](../README.md)
- [Next - Packages and Inheritance ](../2-packages-and-inheritance/README.md)
