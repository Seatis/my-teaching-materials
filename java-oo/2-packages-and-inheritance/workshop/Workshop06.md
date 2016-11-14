First create a `Point` class which is a single point in a Cartesian system.  The Point consists of 2 fields:
+ x:int = 0
+ y:int = 0

It has constructors:-
+ The *default* constructor (without any parameter) which sets `x` and `y` to 0 (the origin).
+ An alternative that takes `x` and `y` parameters.

There are getters and setters:-
- getX() : int
- setX(x:int):void
- getY():int
- setY(y:int):void
- toString():String // "(x,y)"
- getXY(): int[2] - returns a 2 element int array of {x,y}
- setXY(x:int, y:int):void

An there are some other Methods:-
- distance(x:int, y:int):double - returns the distance from `this` to the given(x,y)
- distance(another:Point):double - returns the distance from `this` to another *instance* of Point
- distance():double - returns the distance of `this` from the origin (e.g. Point(0,0);

After defining this, execute the following testbed.

```java
public class Workshop06{
   public static void main(String[] args) {
      // Test constructors and toString()
      Point p1 = new Point(1, 2);
      System.out.println(p1);  // toString()
      Point p2 = new Point();  // default constructor
      System.out.println(p2);

      // Test Setters and Getters
      p1.setX(3);
      p1.setY(4);
      System.out.println(p1);  // run toString() to inspect the modified instance
      System.out.println("X is: " + p1.getX());
      System.out.println("Y is: " + p1.getY());
 
      // Test setXY() and getXY()
      p1.setXY(5, 6);
      System.out.println(p1);  // toString()
      System.out.println("X is: " + p1.getXY()[0]);
      System.out.println("Y is: " + p1.getXY()[1]);

      // Test the 3 overloaded versions of distance()
      p2.setXY(10, 11);
      System.out.printf("Distance is: %.2f%n", p1.distance(10, 11));
      System.out.printf("Distance is: %.2f%n", p1.distance(p2));
      System.out.printf("Distance is: %.2f%n", p2.distance(p1));
      System.out.printf("Distance is: %.2f%n", p1.distance());
   }
}

```

Next inherit from the above to create a `line` object:-

Constructor
- Line(point:Point,point:Point)
- Line(x:int,y:int;x2:int,y2:int)

Getters and Setters - As you'd expect, but be sure to have:-
- setStart(point:Point)
- setStart(x:int, y:int)
- setEnd(point:Point)
- setEnd(x:int, y:int)
- getLength():double

