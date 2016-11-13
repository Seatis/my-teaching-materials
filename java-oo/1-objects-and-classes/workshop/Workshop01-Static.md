Illustrate to yourself the difference between a `static` value and *instances*.

Before you create your first car, you can have and access values and methods in the class; but only if they are *static*.

In the class of Car, we need to add a variable that counts the number of available vehicles (`countCar`) and that also can tell us how many cars there are for rent.  Of course, as I own the car rental agency, we start at -1 (as the first car is for my sole use as own the company).

```java
         System.out.println("Number of Cars Available = " + Car.getCount());
```

So, run this test several times in teh code:-
- 1) before anything is 
- 2) after the first car is created
- 3) after 2 cars are there
- 4) after the array is built.

We're expecting something *like*:-

```
Number of Cars Available = -1
Number of Cars  Available = 0
This Mazda is red, has 1600 cc engine and clocked 12312 km's
This Ford is silver, has 2500 cc engine and clocked 152312 km's
This Beamer is green, has 1600 cc engine and clocked 42521 km's
Number of Cars Available = 2
...
```
