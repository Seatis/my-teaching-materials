Extend the `Car` class with `getters` and `setters`.

In this exercise we change the way that we access the values in the class.  Now, rather than the values being "public" and accessible, they'll sit in a different .java file and one can only get to the values by using a controlled method.

We'll now do a new "Workshop" which will access the previously defined Class (which you'll need to modify).

```java
public class Car {

    //note that these are now private!
    private int sizeEngine;
    private String color;
    private int kmOdometer;
    private String tyCar;

    //Add something here to access the various fields
    public Car(){
        sizeEngine = 1600;
        color = "red";
    }
}
```

And separately, now we'll have Workshop01.

```java
public class Workshop01 {

  psvm //you know the drill by now
  {
     //same myCars as before and then print out.
  }
}
```

If you try 
```java
    Car myCar = new Car();
    myCar.color = "red";
```

This will no longer work (unless you forgot to set the fields to `private`).

Again, we're expecting you to create 3 cars in 1 block and then in a separate block show the output of the 3 separate objects as follows:

```
This Mazda is red, has 1600 cc engine and clocked 12312 km's.
This Ford is silver, has 2500 cc engine and clocked 152312 km's.
This Beamer is green, has 2800 cc engine and clocked 42521 km's.
```

