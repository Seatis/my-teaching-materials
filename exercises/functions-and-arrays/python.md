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
-  [Doubling](exercises/functions/doubling/doubling.py)
-  [Greeter function](exercises/functions/greet/greet.py)
-  [Append a](exercises/functions/append-a/append-a.py)
-  [Summing](exercises/functions/sum/sum.py)
-  [Factorial](exercises/functions/factorio/factorio.py)
-  [Print arguments](exercises/functions/printer/printer.py)

### Data structures

#### Lists

```python
[1, 2, 3]
[]
[1, 2] + [3]
[1] - [2]
[1, 2] * 3
1 in [1, 2]
len([1, 2, 3])
arr = [1, 2, 3]
arr[0]
arr[1:3]
[] is []
```

#### dictionaries

```python
giraffe = {'color': 'yellow', 'pattern': 'polygonal patches'}
whale = {'color': 'blue', 'size': 10000}

print(giraffe)
print(giraffe['pattern'])
print(whale['size'])

whale['say'] = 'eeeeeeeeeeeeuuuuuuw'

print(whale)
```

#### Excercises
-  [Third](exercises/arrays/third/third.py)
-  [Compare Length](exercises/arrays/compare-length/compare-length.py)
-  [Sum elements](exercises/arrays/sum-elements/sum-elements.py)
-  [Change element](exercises/arrays/change-element/change-element.py)
-  [Increment element](exercises/arrays/increment-element/increment-element.py)
-  [Print elements](exercises/arrays/print-all/print-all.py)
-  [Matrix](exercises/arrays/diagonal-matrix/diagonal-matrix.py)
-  [Double items](exercises/arrays/double-items/double-items.py)
-  [Colors](exercises/arrays/colors/colors.py)
-  [Append a](exercises/arrays/append-a/append-a.py)
-  [Swap elements](exercises/arrays/swap-elements/swap-elements.py)
-  [Sum all elements](exercises/arrays/sum-all/sum-all.py)
-  [Reverse list](exercises/arrays/reverse/reverse.py)


## Individual Workshop Review
Please follow the styleguide: [Our Python styleguide](../../styleguide/python.md)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Are the names of things following the styleguide?
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
