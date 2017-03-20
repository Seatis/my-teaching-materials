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
 -  `str()`
 -  `int()`
 -  `float()`

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

#### Exercises
 -  [04](introduce-yourself/introduce-yourself.py)
 -  [05](two-numbers/two-numbers.py)
 -  [06](coding-hours/two-numbers.py)

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
print(c++) # Prints 12
print(c) # Prints 13

d = 12
print(++d) # Prints 13
print(d) # Prints 13

e = 12
print(e--) # Prints 12
print(e) # Prints 11

f = 12
print(--f) # Prints 11
print(f) # Prints 11

g = 12
g *= 3
print(g) # Prints 36

h = 12
h /= 3
print(h) # Prints 4

i = 12
i %= 7
print(i) # Prints 5
```

#### Exercises
 -  [07](favorite-number/favorite-number.py)
 -  [08](define-basic-info/define-basic-info.py)
 -  [09](bmi/bmi.py)
 -  [10](cuboid/cuboid.py)
 -  [11](seconds-in-a-day/seconds-in-a-day.py)
 -  [12](swap/swap.py)
 -  [13](variable-mutation/variable-mutation.py)

### User input (scanner)

```python
// Creates a scanner
Scanner scanner = new Scanner(System.in);

// The program stops and waits for user input and to press enter
String userInput1 = scanner.next();

// It only prints the first word of the line
System.out.println(userInput1);

// The program stops and waits for user input and to press enter
String userInput2 = scanner.nextLine();

// It prints the whole line
System.out.println(userInput2);

// The program stops and waits for user input that is an integer and to press enter
int userInput3 = scanner.nextInt();

// It prints the integer
System.out.println(userInput3);
```

#### Exercises
 -  [14](hello-user/HelloUser.java)
 -  [15](mile-to-km-converter/MileToKmConverter.java)
 -  [16](animals-and-legs/AnimalsAndLegs.java)
 -  [17](average-of-input/AverageOfInput.java)

### Conditionals

```java
public class Conditionals {
  public static void main(String[] args) {
    int a = 13;

    if (a == 13) {
      System.out.println("Yaaay! The value of the \"a\" variable is 13"); // This block will run
    }

    if (a == 8) {
      System.out.println("Yaaay! The value of the \"a\" variable is 8"); // This block will NOT run
    }


    int b = 20;

    if (b < 10) {
      System.out.println("Yaaay! The value of the \"b\" variable is lower than 10"); // This block will NOT run
    } else {
      System.out.println("Yaaay! The value of the \"b\" variable is higher than 10"); // This block will run
    }


    int c = 15;

    if (c < 10) {
      System.out.println("Yaaay! The value of the \"b\" variable is lower than 10"); // This block will NOT run
    } else {
      System.out.println("Yaaay! The value of the \"b\" variable is higher than 10"); // This block will run
    } else {
      System.out.println("Yaaay! The value of the \"b\" variable is higher than 10"); // This block will NOT run
    }


    boolean thirsty = true;
    boolean hungry = false;

    if (thirsty && hungry) {
      System.out.println("Lunch time!");
    } else if (thirsty || hungry) {
      System.out.println("Snack time!");
    } else {
      System.out.println("No food for you, little fatty.");
    }
  }
}
```

#### Exercises
 -  [18](odd-even/OddEven.java)
 -  [19](one-two-a-lot/OneTwoALot.java)
 -  [20](print-bigger/PrintBigger.java)
 -  [21](password-protected/PasswordProtected.java)
 -  [22](party-indicator/PartyIndicator)
 -  [23](food-you-like/FoodYouLike.java)
 -  [24](conditional-variable-mutation/ConditionalVariableMutation.java)

### Loops

```java
public class Conditionals {
  public static void main(String[] args) {
    int a = 0;
    while (a < 10) {
      System.out.println(a); // Prints the numbers from 0 to 9
      a += 1;
    }

    for (int i = 0; i < 100; i++) {
      System.out.println(i); // Prints the numbers from 0 to 99
    }
  }
}
```

#### Exercises
 -  [25](i-wont-cheat-on-the-exams/IWontCheatOnTheExams.java)
 -  [26](print-even/PrintEven.java)
 -  [27](count-from-to/CountFromTo.java)
 -  [28](multiplication-table/MultiplicationTable.java)
 -  [29](draw-triangle/DrawTriangle.java)
 -  [30](draw-pyramid/DrawPyramid.java)
 -  [31](draw-diamond/DrawDiamond.java)
 -  [32](draw-square/DrawSquare.java)
 -  [33](draw-diagonal/DrawDiagonal.java)
 -  [34](draw-chess-table/DrawChessTable.java)
 -  [35](fizz-buzz/FizzBuzz.java)
 -  [36](guess-the-number/GuessTheNumber.java)
 -  [37](parametric-average/ParametricAverage.java)


## Individual Workshop Review
Please follow the styleguide: [Our Java styleguide](../../styleguide/java.md)

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
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?




