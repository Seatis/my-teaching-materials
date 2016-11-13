Create a `Car` class.

The mentors' have already laid out a starter for you.

When a new car is created, the size of the Engine should be 1600 cc and the color should be red.

```java
public class Car {

    //Add somethings here to create a car and some fields
  
    public static void main(String[] args){
        Car myCar = new Car();
        System.out.printf("Just got a new Car, it's %s and has a %d cc Engine!\n",
        "puke" , 1 // replace this stuff with the way we get those attributes about myCar 
    );
    }
}
```

The output should be:

`Just got a new Car, it's red and has a 1600 cc Engine!`

And not

`Just got a new Car, its puke and has a 1 cc Engine!`

And the settings for the color and sizeEngine must not be in the declaration (e.g. no `int sizeEngine = 1600;`)
