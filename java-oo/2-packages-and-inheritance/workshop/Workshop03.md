Revisit the `Circle` class.  This object consists of 2 fields:
+ radius:double = 1.0
+ color:String = "red"

It has constructors:-
+ The *default* constructor (without any parameter) sets the radius to 1, and color red
+ Circle(radius:double) - sets just the radius
+ Circle(radius:double, color:String) - as you'd expect

There are getters and setters:-
- getRadius():double
- setRadius(radius:double):void
- getColor():String
- setColor(color:String):void

An there are some other Methods:-
- toString():String - returns "Circle[radius=<value>,color=<value>]"
- getArea():double
- getCircumference():double

After defining this, execute the following testbed.

```java
public class Workshop03{
   public static void main(String[] args) {
      // Test constructors and toString()
      Circle c1 = new Circle(1.1, "blue");
      System.out.println(c1);  // toString()
      Circle c2 = new Circle(2.2);
      System.out.println(c2);  // toString()
      Circle c3 = new Circle();
      System.out.println(c3);  // toString()

      // Test Setters and Getters
      c1.setRadius(2.2);
      c1.setColor("green");
      System.out.println(c1);  // toString() to inspect the modified instance
      System.out.println("The radius is: " + c1.getRadius());
      System.out.println("The color is: " + c1.getColor());

      // Test getArea() and getCircumference()
      System.out.printf("The area is: %.2f%n", c1.getArea());
      System.out.printf("The circumference is: %.2f%n", c1.getCircumference());
   }
}
```

The results should be:-
```
Circle[radius=1.1, color=blue]
Circle[radius=2.2, color=red]
Circle[radius=8.8, color=red]
Circle[radius=2.2, color=green]
Radius is: 2.2
Color is: green
Area is: 15.21
Circumference is: 13.82
```