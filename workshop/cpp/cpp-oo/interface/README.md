# Struct
*Define classes, properties and methods, then creating instances and mutate them*

## Objectives

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [Advanced C++: Duality Of Public Inheritance - Interface & Implementation](https://www.youtube.com/watch?v=iFK-D13LX2U) | 10:36 |
| [Abstract Classes and Interfaces](https://www.youtube.com/watch?v=AU07jJc_qMQ) till 14:46 | 14:46 |
| [C++ Interface Classes - An Introduction](https://accu.org/index.php/journals/233) |  |
| [C++ Tutorial: Operator Overloading Part 1 - Vector2 Class](https://www.youtube.com/watch?v=wZLC5hMZLLo) | 13:36 |
| [C++ Tutorial: Operator Overloading Part 2 - Inserters and Extractors](https://www.youtube.com/watch?v=WtoHf6gPnCs) | 18:54 |
| [C++ Tutorial: Operator Overloading Part 3 - More on Inserters and Extractors](https://www.youtube.com/watch?v=HLnjigSqpJs) | 9:31 |
| [C++ Tutorial: Operator Overloading Part 4 - Equality Operators](https://www.youtube.com/watch?v=2qJhR8cn_Pc) | 11:01 |
| [C++ Tutorial: Operator Overloading Part 5 - Copy Constructor + Assignment Operator](https://www.youtube.com/watch?v=upxJVLNevoc) | 11:55 |

### Optional
| Material | Time |
|:---------|-----:|
| [C++ Tutorial: Operator Overloading Part 6 - Increment and Decrement Operators](https://www.youtube.com/watch?v=XYHO1mQCHvE) | 18:33 |
| [C++ Tutorial: Operator Overloading Part 7 - Addition and Subtraction Operators](https://www.youtube.com/watch?v=BB2hSkEDLZo) | 11:58 |
| [C++ Tutorial: Operator Overloading Part 8 - More on Addition and Subtraction Operators](https://www.youtube.com/watch?v=kiHLh9rysLE) | 14:45 |



## Material Review
 - interface
 - operator overloading
 - inserter / extractor
 - copy constructor
 - const reference parameter
 - return reference


## Excercises
### Color
Create a class that represents a color.
It should store the base colors: Red, Green and Blue as unsigned chars. (0-255)

#### Constructors
 - The default constructor should create a black color.
 - It should have a constructor that takes 3 unsigned chars.
 - It should have a constructor that takes a string like: `"#AAF0C2"` (it should work for lower- and upper-case as well)
   - If the string is not a valid hex code it should throw an Exception (it should throw and exception instance)
 - It should have a user defined copy constructor

#### Methods
 - `Color blend(const Color& other)` It should take an other color and return a
   new color that has the blended color of the two
 - `void darken(float amount)` It should take a number between 0 and 1 and scale down it's base colors with it, it should throw an Exception on wrong input
 - `void lighten(float amount)` It should take a number between 0 and 1 and scale up it's base colors with it, it should throw an Exception on wrong input

#### Operators
 - `color1 + color2` It should blend the two colors
 - `color++` It should make the color lighter by 10% than return the color itself
 - `++color` It should return the color itself than make the color lighter by 10%
 - `color--` It should make the color darker by 10% than return the color itself
 - `--color` It should return the color itself than make the color darker by 10%
 - `color * 0.2` It should return a new color that is lighter by 20%
 - `color / 0.2` It should return a new color that is darker by 20%
 - `cout << color` It should represent the color in hex code like: `#AAF0C2`
 - `cin >> color` It should read the color from the input in hex form
 - `color1 == color2` It should return true if the colors are the same
 - `color1 != color2` It should return true if the colors are not the same
 - `color1 < color2` It should return true if the color1 is darker than color2
 - `color1 > color2` It should return true if the color1 is lighter than color2
 - `color1 <= color2` It should return true if the color1 is darker than or equal with color2
 - `color1 >= color2` It should return true if the color1 is lighter than or equal with color2

##### Optional
#### Operators
 - `!color` It should return the complement color http://serennu.com/colour/rgbtohsl.php
 

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

