#Workshop06 - General practice

You've now been through setting up bean, autowiring and and pre and post life of Beans.

## Review
You should be able to answer the following questions:-
- What is Dependency Injection and give an example?
- What are the different ways to define Beans?
- When using Annotation, what form would you use when declaring a *context* (which kicks off the configuration and is what gives you a `.getBean()` method)?
- How do you identify a Component that should be scanned for Beans?
- What's the difference between @Component and @ComponentScan?
- What does @Configuration do?
- Where do you use @Autowire?  And what does it do?

## Practice Ideas
Obviously doing helps to retain the knowledge.  Here're some practice ideas.

### One class dependent upon another Example
### One class dependent upon another Example
Define the following set of dependencies.

There is the Nespresso machine (check it out at www.nespresso.com/fr/en/machinelistblock).  
These depend upon
- Capsules


### Add a bean to machines that track the name of the model:
- Ciliz (99 EUR, it's on sale!)
- Inissia (59 EUR, also on sale)
  
### Add methods
The machine has a hopper that holds spent (that means *used*) capsules.  It's capacity is finite (3 capsules) and can be later swapped out for a different size.  Hence, as a bean it should be switchable.

There's a brew option (method), which each time it's called, increments the waste (e.g. drops a capsule in the hopper).

When the hopper gets to the max, the program cannot brew, but sends back the Message first "empty hopper".

The empty hopper method clears the hopper to zero.
  
### Add startup and shutdown functions
- On startup, method that sends the message "warming up"
- On shutdown, the method 
  - first checks the hopper first, if its full, it says "empty hopper"
  - always say "goodbye"
  

### Change the Configuration - 
Replace the startup message with "Give me a min".
Change the Hopper size to 4 and retest.

## Links
[Previous Workshop - ](../Workshop05.md)