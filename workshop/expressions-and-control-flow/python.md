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
| [Python 3 Programming Tutorial - Getting user input](https://www.youtube.com/watch?v=ArL54Nmx9oU0) | 1:42 |
| [Python Tutorial 4 - Input Function](https://www.youtube.com/watch?v=-Xyh9RUJuyE) | 6:40 |


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
     -  `!=`
     -  `+=`
     -  `-=`
     -  `*=`
     -  `/=`
     -  `==`
     -  `>=`
     -  `<=`
     -  `>`
     -  `<`
     -  `not`
     -  `or`
     -  `and`
 -  `print()`
 -  Hello World
 -  escape character
 -  `"Python's stuff"` and `'stuff of Python'`
 -  concatenation
 -  condition, `if`, `else`
 -  Loops: `for`, `while`
 -  block
 -  `input()`
 -  `str()`
 -  `int()`
 -  `float()`

## Workshop

💪 : If you see this emoji, it means that you can skip the exercise if you are in lack of time. You can pracitce with these exercises later to deepen your knowledge (or to prepare for the exam).

### Printing to the terminal window

#### Hello World

```python
# Prints "Hello, World!" to the terminal window.
print("Hello, World!")
```

#### Exercises
 - [01 hello_me](hello-me/hello_me.py)
 - [02 humpty_dumpty](humpty-dumpty/humpty_dumpty.py)
 - [03 hello_others](hello-others/hello_others.py)

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
print(6 / 2) # Prints 3.0
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

#### Exercises
 -  [04 intorduce_yourself](introduce-yourself/introduce_yourself.py)
 -  [05 two_numbers](two-numbers/two_numbers.py)
 -  [06 coding_hours](coding-hours/coding_hours.py)

### Variables

#### Creating different variables for each type

```python
# String
welcome = "Hello, World"
print(welcome)

# Boolean
is_awesome = True
print(is_awesome)

# Integer
the_meaning_of_life_and_the_universe_and_everything = 42
print(the_meaning_of_life_and_the_universe_and_everything)

# Floating point number
pi = 3.141592
print(pi)

# Assigning and creating a variable, (define its value)
number = 12

# Mutate a variable, (redefine its value)
number = 23
```

#### Arithmetic Assignment Operators

```python
a = 12
a += 4
print(a) # Prints 16

b = 12
b -= 4
print(b) # Prints 8

c = 12
c *= 3
print(c) # Prints 36

d = 12
d /= 3
print(d) # Prints 4

e = 12
e %= 7
print(e) # Prints 5
```

#### Exercises
 -  [07 favorite_number](favorite-number/favorite_number.py)
 -  [08 swap](swap/swap.py)
 -  [09 bmi 💪](bmi/bmi.py)
 -  [10 define_basic_info](define-basic-info/define_basic_info.py)
 -  [11 variable_mutation](variable-mutation/variable_mutation.py)
 -  [12 cuboid 💪](cuboid/cuboid.py)
 -  [13 seconds_in_a_day](seconds-in-a-day/seconds_in_a_day.py)

### User input (scanner)

```python
# The program stops and waits for user input and to press enter
user_input_1 = input()

# It prints the whole line that the user entered
print(user_input_1)

# The program stops and waits for user input that is an integer and to press enter
user_nput2 = int(input())

# It prints the integer
print(user_input_3)
```

#### Exercises
 -  [14 hello_user](hello-user/hello_user.py)
 -  [15 mile_to_km_converter](mile-to-km-converter/mile_to_km_converter.py)
 -  [16 animals_and_legs 💪](animals-and-legs/animals_and_legs.py)
 -  [17 average_of_input 💪](average-of-input/average_of_input.py)

### Conditionals

```python
a = 13

if a == 13:
  print("Yaaay! The value of the \"a\" variable is 13") # This block will run

if a == 8:
  print("Yaaay! The value of the \"a\" variable is 8") # This block will NOT run


b = 20

if b < 10:
  print("Yaaay! The value of the \"b\" variable is lower than 10") # This block will NOT run
else:
  print("Yaaay! The value of the \"b\" variable is higher than 10") # This block will run


c = 15

if c < 10:
  print("Yaaay! The value of the \"b\" variable is lower than 10") # This block will NOT run
elif c < 20:
  print("Yaaay! The value of the \"b\" variable is higher than 10") # This block will run
else:
  print("Yaaay! The value of the \"b\" variable is higher than 10") # This block will NOT run


thirsty = True
hungry = False

if thirsty and hungry:
  print("Lunch time!")
elif thirsty or hungry:
  print("Snack time!")
else:
  print("No food for you, little fatty.")
```

#### Exercises
 -  [18 odd_even](odd-even/odd_even.py)
 -  [19 one_two_a_lot](one-two-a-lot/one_two_a_lot.py)
 -  [20 print_bigger 💪](print-bigger/print_bigger.py)
 -  [21 party_indicator](party-indicator/party_indicator.py)
 -  [22 conditional_variable_mutation 💪](conditional-variable-mutation/conditional_variable_mutation.py)

### Loops

```python
a = 0:
while a < 10:
  print(a) # Prints the numbers from 0 to 9
  a += 1

for i in range(0, 100):
  print(i) # Prints the numbers from 0 to 99
```

#### Exercises
 -  [23 i_wont_cheat_on_the_exams](i-wont-cheat-on-the-exams/i_wont_cheat_on_the_exams.py)
 -  [24 print_even](print-even/print_even.py)
 -  [25 multiplication_table](multiplication-table/multiplication_table.py)
 -  [26 count_from_to](count-from-to/count_from_to.py)
 -  [27 fizz_buzz](fizz-buzz/fizz_buzz.py)
 -  [28 draw_triangle](draw-triangle/draw_triangle.py)
 -  [29 draw_pyramid 💪](draw-pyramid/draw_pyramid.py)
 -  [30 draw_diamond 💪](draw-diamond/draw_diamond.py)
 -  [31 draw_square 💪](draw-square/draw_square.py)
 -  [32 draw_diagonal](draw-diagonal/draw_diagonal.py)
 -  [33 guess_the_number](guess-the-number/guess_the_number.py)
 -  [34 parametric_average 💪](parametric-average/parametric_average.py)
 -  [35 draw_chess_table](draw-chess-table/draw_chess_table.py)


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
