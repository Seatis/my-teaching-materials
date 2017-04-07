Create a `Point` class which has two instance fields: `x` and `y`.

Reuse the `Rectangle` class.

Create a `Drawable` interface which has a `draw` method signature.

`Point` and `Rectangle` should implement the `Drawable` interface.

```java
public static void main(String... args){
  Drawable[] drawables = new Drawable[] {
    new Point(12,30),
    new Point(40,10),
    new Rectangle(new Point(1,1), 3,8),
    new Point(1,20),
    new Rectangle(new Point(23,1), 6,5)
  };
  for(Drawable el : drawables){
    el.draw();
  }
}
```

Expected output:
```
DRAW a Point at 12.00,30.00
DRAW a Point at 40.00,10.00
DRAW a Rectangle at 1.00, 1.00 with 3.00 width and 8.00 height
DRAW a Point at 1.00,20.00
DRAW a Rectangle at 23.00, 1.00 with 6.00 width and 5.00 height
```
