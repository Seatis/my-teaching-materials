# Graphics
Draw on a canvas using our previous knowledge about control flow and functions

## Materials
| Material | Time |
|:---------|-----:|
| [Java Programming Tutorial - 84 - Drawing Graphics](https://www.youtube.com/watch?v=2l5-5PMUc5Y) | 8:58 |
| [Java Programming Tutorial - 86 - Drawing More Stuff](https://www.youtube.com/watch?v=OWOeE90ET6w) | 7:15 |
| [Using Java's Math.random() Method](https://www.youtube.com/watch?v=o-A-M6syLI4) | 5:12 |


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

### Exercises

- [Middle lines](line-in-the-middle/LineInTheMiddle.java)
- [Colored box](colored-box/ColoredBox.java)
- [Diagonals](diagonals/Diagonals.java)
- [To the center](go-to-center/GoToCenter.java)
- [Horizontal](horizontal-lines/HorizontalLines.java)
- [Square in the center](centered-square/CenteredSquare.java)
- [Fill with rectangles](four-rectangles/FourRectangles.java)
- [Square positioning](position-square/PositionSquare.java)
- [Centered boxes](center-box-function/CenterBoxFunction.java)
- [Rainbow boxes](rainbow-box-function/RainbowBoxFunction.java)
- Reproduce these:   
![square one](workshop/r3.png)   
![square two](workshop/r4.png)   
- [Checkerboard](checkerboard/Checkerboard.java)
- [Everything goes to center](function-to-center/FunctionToCenter.java)
- [Line play](line-play/LinePlay.java)
- [Line play quarters](line-play-quarters/LinePlayQuarters.java)
- [Envelope star](envelope-star/EnvelopeStar.java)
- Reproduce these:   
![doodle one](workshop/r1.png)   
![doodle two](workshop/r2.png)   
- [Connect the dots](connect-the-dots/ConnectTheDots.java)
- [Starry night](starry-night/StarryNight.java)
- Reproduce these:
![doodle one](workshop/r5.png)   
![doodle one](workshop/r6.gif)
