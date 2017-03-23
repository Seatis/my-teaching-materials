# Graphics
Draw on a canvas using our previous knowledge about control flow and functions

## Materials
| Material | Time |
|:---------|-----:|
| (Java Programming Tutorial - 84 - Drawing Graphics)[https://www.youtube.com/watch?v=2l5-5PMUc5Y] | 8:58 |
| (Java Programming Tutorial - 86 - Drawing More Stuff)[https://www.youtube.com/watch?v=OWOeE90ET6w] | 7:15 |


## Material Review
- Graphics
- drawLine, fillLine
- drawRect, fillRect
- drawOval, fillOval
- drawPolygon, fillPolygon
- setColor, Color

## Workshop
[Java Graphics API Docs](https://docs.oracle.com/javase/7/docs/api/java/awt/Graphics.html)

### Shapes
```java
  public static void mainDraw(Graphics graphics){
      graphics.drawLine(0, 0, 200, 50);
      graphics.drawRect(50, 50, 100, 90);
      graphics.fillRect(60, 60, 100, 90);
      graphics.fillOval(120, 10, 180, 90);
  }
```

### Colors
```java
    public static void mainDraw(Graphics graphics){
        graphics.fillRect(200,200,200,200);
        graphics.setColor(new Color(200,200,0,150));
        graphics.fillRect(210,210,200,200);
    }
```

### Polygons
```java
    public static void mainDraw(Graphics graphics){
        int xpoints[] = {25, 145, 25, 145, 25};
        int ypoints[] = {25, 25, 145, 145, 25};
        int npoints = 5;

        graphics.drawPolygon(xpoints, ypoints, npoints);
    }
```
