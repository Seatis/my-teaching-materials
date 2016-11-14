Extend the `Car` class with fields (aka properties or attributes).

+ It should have a `typeCar` property that stores the car's type in a string eg: "Mazda"
+ It should have a `kmOdometer` property that stores how many kilometers it has run

These values should be set after the car is first created.  So in the code, we want the following...  You have to set it up right btw.

```java
public class Car {

    //stuff here reused from before and extended now

    public static void main(String... args){
        Car myCar = new Car();

         // km's set to 12312
         // type should be Mazda

         //sout "This %s is %s, has %d cc engine and clocked %d km's\n"
```
We're expecting you to create 3 cars in 1 block and then in a separate block show the output of the 3 separate objects as follows:

```
This Mazda is red, has 1600 cc engine and clocked 12312 km's.
This Ford is silver, has 2500 cc engine and clocked 152312 km's.
This Beamer is green, has 2800 cc engine and clocked 42521 km's.
```
