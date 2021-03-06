# Graphics in Python
Draw on a canvas using Tkinter and our previous knowledge about control flow and functions

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

- [01 Middle lines](line-in-the-middle/line_in_the_middle.py)
- [02 Colored box](colored-box/colored_box.py)
- [03 Diagonals](diagonals/diagonals.py)
- [04 To the center](go-to-center/go_to_center.py)
- [05 Horizontal](horizontal-lines/horizontal_lines.py)


- [06 Square in the center](centered-square/centered_square.py)
- [07 Fill with rectangles](four-rectangles/four_rectangles.py)
- [08 Square positioning](position-square/position_square.py)
- [09 Centered boxes](center-box-function/center_box_function.py)
- [10 Rainbow boxes](rainbow-box-function/rainbow_box_function.py)


-
| [11 Purple steps](purple-steps/purple_steps.py) |
|:--------------:|
| ![Purple steps](purple-steps/r3.png) |
-
| [12 Purple steps 3d](purple-steps-3d/purple_steps_3d.py) |
|:--------------:|
| ![Purple steps 3d](purple-steps-3d/r4.png) |

- [13 Checkerboard](checkerboard/checkerboard.py)
- [14 Everything goes to center](function-to-center/function_to_center.py)

-
| [15 Line play](line-play/line_play.py) |
|:--------------:|
| ![Line play](line-play/r1.png) |

- [16 Line play quarters](line-play-quarters/line_play_quarters.py)
-
| [17 Envelope star](envelope-star/envelope_star.py) |
|:--------------:|
| ![Envelope star](envelope-star/r2.png) |

- [18 Connect the dots](connect-the-dots/connect_the_dots.py)
- [19 Starry night](starry-night/starry_night.py)

-
| [20 Triangles](triangles/triangles.py) |
|:--------------:|
| ![Triangles](triangles/r5.png) |

-
| [21 Super Hexagon](super-hexagon/super_hexagon.py) |
|:--------------:|
| ![Super Hexagon](super-hexagon/r6.gif) |



## Individual Workshop Review
Please follow the style guide: [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Can iterating over lists and arrays simplifed?
- Are the names of things following the styleguide?
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
