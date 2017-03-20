# Expressions and Control flow
Get into *real* programming, installing a development environment and then running our first programs.

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [Python Programming Tutorial - 1 - Installing Python](https://www.youtube.com/watch?v=HBxCHonP6Ro) | 5:24 |
| [Python Programming Tutorial - 2 - Numbers](https://www.youtube.com/watch?v=hnxIRVZ0EyU) | 5:28 |
| [Python Programming Tutorial - 3 - String](https://www.youtube.com/watch?v=nefopNkZmB4) | 8:24 |
| [Python Programming Tutorial - 4 - Slicing up Strings](https://www.youtube.com/watch?v=YbipxqSKx-E) | 5:40 |
| [Python Programming Tutorial - 5 - Lists](https://www.youtube.com/watch?v=1yUn-ydsgKk) | 7:43 |
| [Python Programming Tutorial - 7 - if elif else](https://www.youtube.com/watch?v=bk22K1m0890) | 9:11 |
| [Python Programming Tutorial - 8 - for](https://www.youtube.com/watch?v=llguiJHU0kk) | 7:08 |
| [Python Programming Tutorial - 9 - Range and While](https://www.youtube.com/watch?v=Neir-vgPyxw) | 6:13 |
| [Python Programming Tutorial - 10 - Comments and Break](https://www.youtube.com/watch?v=k6rkvgQkW04) | 10:06 |
| [Python Programming Tutorial - 11 - Continue](https://www.youtube.com/watch?v=68EhtQbgXRc) | 4:02 |


### Environment
 -  Please install the latest Python from the 3.* version
    [https://www.python.org/downloads/](https://www.python.org/downloads/)

## Material Review
 -  Python
 -  statement
 -  variables
     -  definition
     -  mutating the value
     -  integer
     -  float
     -  boolean
     -  String
 -  operators
     -  `+`
     -  `-`
     -  `*`
     -  `/`
     -  `%`
     -  `=`
     -  `+=`
     -  `-=`
     -  `*=`
     -  `/=`
     -  `==`
     -  `>=`
     -  `<=`
     -  `>`
     -  `<`
     -  `||`
     -  `&&`
     -  `!`
 -  `print()`
 -  Hello World
 -  escape character
 -  `"Python's stuff"` and `'stuff of Python'`
 -  concatenation
 -  condition, `if`, `else`
 -  Loops: `for`, `while`
 -  `input()`

## Workshop

### Printing to the terminal window

#### Hello World

```python
# Prints "Hello, World!" to the terminal window.
print("Hello, World!")
```

#### Exercises
 - [01](hello-me/hello-me.py)
 - [02](hello-others/hello-others.py)
 - [03](humpty-dumpty/humpty-dumpty.py)

### Types

#### Print values with different types

```python
# Prints a string to the terminal window.
print("Hello, World!")

# Prints an integer to the terminal window.
print(42)

# Prints a floating point number to the terminal window.
print(3.141592)
```

#### Integers

```python
# Positive, negative and zero
print(42) # Prints 42
print(-1) # Prints -1
print(0) # Prints 0
```

#### Floats

```python
# Positive, negative and zero
print(3.1415) # Prints 3.1415
print(-1.5) # Prints -1.5
print(0.0) # Prints 0.0

# Leading and closing zero is not mandatory
print(.5) # Prints 0.5
print(5.) # Prints 5.0
```

#### Number Operations

```python
#Arithmetric operations
print(1 + 1) # Prints 2
print(5 - 2) # Prints 3
print(3 * 4) # Prints 12
print(6 * 2) # Prints 3
print(5 / 2) # Prints 2.5
print(5 // 2) # Prints 2
print(5 % 2) # Prints 1
```

#### Booleans

```python
# true, false
print(True) # Prints True
print(False) # Prints False

# Boolean Operators
# Negation
print(not True) # Prints False
print(not False) # Prints True

# And
print(True and True) # Prints True
print(True and False) # Prints False
print(False and True) # Prints False
print(False and False) # Prints False

# Or
print(True or True) # Prints True
print(True or False) # Prints True
print(False or True) # Prints True
print(False or False) # Prints False
```

#### Strings

```python
# String and special characters
print("apple") # Prints apple
print("don't") # Prints don't
print("\"Everything you can imagine is real.\" - Picasso") # Prints "Everything you can imagine is real." - Picasso

# String Operators
# Concatination
print("tooth" + "brush") # Prints toothbrush

# Concat string with number
print("My favorite number is: " + str(8)) # Prints My favorite number is: 8
```



