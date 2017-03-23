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

- [01 Middle lines](line-in-the-middle/LineInTheMiddle.java)
- [02 Colored box](colored-box/ColoredBox.java)
- [03 Diagonals](diagonals/Diagonals.java)
- [04 To the center](go-to-center/GoToCenter.java)
- [05 Horizontal](horizontal-lines/HorizontalLines.java)

- [06 Square in the center](centered-square/CenteredSquare.java)
- [07 Fill with rectangles](four-rectangles/FourRectangles.java)
- [08 Square positioning](position-square/PositionSquare.java)
- [09 Centered boxes](center-box-function/CenterBoxFunction.java)
- [10 Rainbow boxes](rainbow-box-function/RainbowBoxFunction.java)

-
| [11 Purple steps](purple-steps/PurpleSteps.java) |
|:--------------:|
| ![Purple steps](purple-steps/r3.png) |
-
| [12 Purple steps 3d](purple-steps-3d/PurpleSteps3d.java) |
|:--------------:|
| ![Purple steps 3d](purple-steps-3d/r4.png) |


- [13 Checkerboard](checkerboard/Checkerboard.java)
- [14 Everything goes to center](function-to-center/FunctionToCenter.java)

-
| [15 Line play](line-play/LinePlay.java) |
|:--------------:|
| ![Line play](line-play/r1.png) |

- [16 Line play quarters](line-play-quarters/LinePlayQuarters.java)
-
| [17 Envelope star](envelope-star/EnvelopeStar.java) |
|:--------------:|
| ![Envelope star](envelope-star/r2.png) |

- [18 Connect the dots](connect-the-dots/ConnectTheDots.java)
- [19 Starry night](starry-night/StarryNight.java)

-
| [20 Triangles](triangles/Triangles.java) |
|:--------------:|
| ![Triangles](triangles/r5.png) |

-
| [21 Super Hexagon](super-hexagon/SuperHexagon.java) |
|:--------------:|
| ![Super Hexagon](super-hexagon/r6.gif) |
