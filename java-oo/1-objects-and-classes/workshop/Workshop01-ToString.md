Extend the `Car` class with combined `method()`'s.

There are situations where we read and/or do stuff with several Class fields.  This is a typical situation, to have a toString method (which you've already seen with ArrayList).

We want to call the following method

```java
	Car car = new Car();
	System.out.println(car.toString());
```

And this would show.

```
This Mazda is red, has 1600 cc engine and clocked 12327 km's.
This Ford is silver, has 2500 cc engine and clocked 152312 km's.
This Beamer is green, has 2800 cc engine and clocked 42521 km's.
```
