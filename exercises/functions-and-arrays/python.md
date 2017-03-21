# Functions and Data structures
# Functions and Data structures
# Functions and Data structures
# Functions and Data structures
# Functions and Data structures
# Functions and Data structures
Dive deeper into *real* programming, reuse code and get to know more complex data structures

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [Python Programming Tutorial - 12 - Functions](https://www.youtube.com/watch?v=j2xhtI0WTew) | 6:41 |
| [Python Programming Tutorial - 13 - Return Values](https://www.youtube.com/watch?v=xRIzPZlei9I) | 6:05 |
| [Python Programming Tutorial - 14 - Default Values for Arguments](https://www.youtube.com/watch?v=mwr1AtpLMpI) | 4:04 |
| [Python Programming Tutorial - 15 - Variable Scope](https://www.youtube.com/watch?v=f3TVuuhe-fY) | 3:08 |
| [Python Programming Tutorial - 16 - Keyword Arguments](https://www.youtube.com/watch?v=DASOXeFFkCg) | 4:20 |
| [Python Programming Tutorial - 17 - Flexible Number of Arguments](https://www.youtube.com/watch?v=QSTo9F8E6GE) | 3:37 |
| [Python Programming Tutorial - 18 - Unpacking Arguments](https://www.youtube.com/watch?v=DJ2HSCT6Z8w) | 4:16 |
| [Python Programming Tutorial - 5 - Lists](https://www.youtube.com/watch?v=1yUn-ydsgKk) | 7:43 |
| [Python Programming Tutorial - 20 - Dictionary](https://www.youtube.com/watch?v=BSNFRKG1MfE) | 5:23 |

### Optional
*If you've got time and/or want to dig deeper, consider the following:*
- [General introduction to functions][1]
- [Introduction to Python built-in data structures][2]
- [Codecademy course on Python functions][4]
- [Codecademy course on Python lists and dictionaries][5]
- [Hands-on Python Tutorial: Defining Functions of your Own][3]

[1]: http://www.cs.utah.edu/~germain/PPS/Topics/functions.html
[2]: http://pymbook.readthedocs.org/en/latest/datastructure.html
[3]: http://anh.cs.luc.edu/python/hands-on/3.1/handsonHtml/functions.html
[4]: https://www.codecademy.com/en/courses/python-beginner-c7VZg/0/1?curriculum_id=4f89dab3d788890003000096
[5]: https://www.codecademy.com/en/courses/python-beginner-en-pwmb1/0/1?curriculum_id=4f89dab3d788890003000096

## Material Review
- Python
- functions we already knew
  -  `print()`
  -  `input()`
  -  `str()`
  -  `int()`
  -  `float()`
- function
- return value
- argument
  - default value
  - keyword arguments
  - unpacking
- variable scope
- list
- dictionary


## Workshop

### Functions

```python
def greet_fox():
  print("Hello Green Fox!")

greet_fox()
greet_fox()
```

#### Function arguments

```python
def greet_by_name(name):
  print("Well hi there,", name)

greet_by_name("Tojas")
greet_by_name("Barbi")
```

#### Default values for function arguments

```python
def greet(greet="Hi", name="pal"):
  print(greet, name)

greet("Hello", "Tojas")
greet("Howdy", "Barbi")
greet("Hey")
greet(name="Everyone")
```

#### Function return values

```python
def make_green(name):
  new_name = "Green " + name
  return new_name

name = make_green("Tojas")
greet_by_name(name)
```

#### Excercises
-  [Doubling](exercises/doubling/doubling.py)
-  [Greeter function](exercises/greet/greet.py)
-  [Append a](exercises/append-a/append-a.py)
-  [Summing](exercises/sum/sum.py)
-  [Factorial](exercises/factorio/factorio.py)
-  [Print arguments](exercises/printer/printer.py)

### Lists & Data structures

#### Excercises
-  [Third](exercises/third/third.py)
-  [Compare Length](exercises/compare-length/compare-length.py)
-  [Sum elements](exercises/sum-elements/sum-elements.py)
-  [Change element](exercises/change-element/change-element.py)
-  [Increment element](exercises/increment-element/increment-element.py)
-  [Print elements](exercises/print-all/print-all.py)
-  [Matrix](exercises/diagonal-matrix/diagonal-matrix.py)
-  [Double items](exercises/double-items/double-items.py)
-  [Colors](exercises/colors/colors.py)
-  [Append a](exercises/append-a/append-a.py)
-  [Swap elements](exercises/swap-elements/swap-elements.py)
-  [Sum all elements](exercises/sum-all/sum-all.py)
-  [Reverse list](exercises/reverse/reverse.py)
