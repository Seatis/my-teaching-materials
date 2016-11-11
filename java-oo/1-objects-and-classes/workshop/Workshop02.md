Create a class called `Car`
+ It should have a `type` property that stores the car's type in a string eg: "Mazda"
+ It should have a `km` property that stores how many kilometers it has run

The `km` and the `type` property should be the parameters of the constructor.
It should have a method called `ride` that takes a number and increments the `km` property by it.

```java
public class CarWorkshop {
    public static void main(String... args){
        Car myCar = new Car("Mazda", 10);
        myCar.ride(12000);
        System.out.println(String.format("I have a %s with %d kilometres.",
                myCar.getType(), myCar.getKm()));
    }
}
```
