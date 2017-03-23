# Graphics in Python

## Objectives
* draw on a canvas using Tkinter

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [Python GUI with Tkinter - 1 - Introduction](https://www.youtube.com/watch?v=RJB1Ek2Ko_Y&index=1&list=PL6gx4Cwl9DGBwibXFtPtflztSNPGuIB_d) | 8:37 |
| [Python GUI with Tkinter - 13 - Shapes and Graphics](https://www.youtube.com/watch?v=O12aT42okYE&list=PL6gx4Cwl9DGBwibXFtPtflztSNPGuIB_d&index=13) | 9:51 |
| [Python Tkinter Canvas docs](http://www.tutorialspoint.com/python/tk_canvas.htm) | |

### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [Canvas Widgets](http://www.python-course.eu/tkinter_canvas.php) | |

## Material Review
 - Tkinter
 - GUI
 - canvas
 - shapes
    - line
    - rectangle
    - polygon
    - oval
    - image
    - arc
 - options
    - height
    - width
    - bg
    - bd
    - fill

## Workshop
* cheatsheet for the tasks with all the canvas methods: http://www.python-course.eu/tkinter_canvas.php

### TKinter
```python
from tkinter import *

root = Tk()

# here goes the drawing part

root.mainloop()

```

### Canvas
```python
from tkinter import *

root = Tk()

canvas = Canvas(root, width='200', height='100')
canvas.pack()

teal_line = canvas.create_line(0, 0, 200, 50, fill='light sea green')
lime_box = canvas.create_rectangle(50, 50, 100, 90, fill='lime green')
olive_oval = canvas.create_oval(120, 10, 180, 90, fill='olive drab')

root.mainloop()
```

### Exercises

- [Middle lines](line-in-the-middle/line-in-the-middle.py)
- [Colored box](colored-box/colored-box/py)
- [Diagonals](diagonals/diagonals.py)
- [To the center](go-to-center/go-to-center.py)
- [Horizontal](horizontal-lines/horizontal-lines.py)
- [Square in the center](centered-square/centered-square.py)
- [Fill with rectangles](four-rectangles/four-rectangles.py)
- [Square positioning](position-square/position-square.py)
- [Centered boxes](center-box-function/center-box-function.py)
- [Rainbow boxes](rainbow-box-function/rainbow-box-function.py)
- Reproduce these:   
![square one](workshop/r3.png)   
![square two](workshop/r4.png)   
- [Checkerboard](checkerboard/checkerboard.py)
- [Everything goes to center](function-to-center/function-to-center.py)
- [Line play](line-play/line-play.py)
- [Line play quarters](line-play-quarters/line-play-quarters.py)
- [Envelope star](envelope-star/envelope-star.py)
- Reproduce these:   
![doodle one](workshop/r1.png)   
![doodle two](workshop/r2.png)   
- [Connect the dots](connect-the-dots/connect-the-dots.py)
- [Starry night](starry-night/starry-night.py)
- Reproduce these:
![doodle one](workshop/r5.png)   
![doodle one](workshop/r6.gif)   


## Individual Workshop Review
Please follow the style guide: [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)
