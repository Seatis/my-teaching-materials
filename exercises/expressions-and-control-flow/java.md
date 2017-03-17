# Expressions and Control Flow

## Materials
| Material | Time |
|:---------|-----:|
|[Historic background leading to Java (Guru-01)](https://www.youtube.com/watch?v=2Xa3Y4xz8_s)| 6:01|
|[Installing Java & IntelliJ IDEA (Koets)](https://www.youtube.com/watch?v=qscQ3XT6qu4)| 15:58|
|[Basic Syntax](https://www.youtube.com/watch?v=SSEpAsKqRqA)|10:35|
|[Strings & Scanner Input](https://www.youtube.com/watch?v=aNm8DK_1ApU)|14:43|
|[Boolean Operators & IF Statement](https://www.youtube.com/watch?v=6O_lwNnWFR0)|10:29|
|[Else/Else If Statements & AND/OR Operators](https://www.youtube.com/watch?v=3J4jCSXA1Pw)|14:22|
|[While, Do While & For Loops](https://www.youtube.com/watch?v=6djggrlkHY8)| only until 8:35 |

### Material Review
- Java
- IntelliJ IDEA
- statement
- variables
  - declaration
  - giving value
  - byte
  - int
  - float
  - boolean
  - char
  - String
- difference between variable declaration and statements
- println
- Hello World
- escape character
- `"Java's stuff"` and `'stuff of Java'`
- concatenation
- condition, if, else
- loops: for, while
- scanner
  - `System.in`
  - next()
  - nextLine()
  - nextInt()
- operators
  - `+, +=`
  - `-, -=`
  - `*, *=`
  - `/, /=`
  - `%`
  - `==`
  - `>=`
  - `<=`
  - `>`
  - `<`
  - `||`
  - `&&`
  - `!`

## Workshop

### Printing to the terminal window

#### Hello World

```java
public class HelloWorld {
  public static void main(String[] args) {
    // Prints "Hello, World!" to the terminal window.
    System.out.println("Hello, World!");
  }
}
```

#### Exercises
 - [01](hello-me/HelloMe.java)
 - [02](hello-others/HelloOthers.java)
 - [03](humpty-dumpty/HumptyDumpty.java)


### Types

#### Print values with different types

```java
public class PrintValues {
  public static void main(String[] args) {
    // Prints a string to the terminal window.
    System.out.println("Hello, World!");

    // Prints an integer to the terminal window.
    System.out.println(42);

    // Prints a floating point number to the terminal window.
    System.out.println(3.141592);
  }
}
```

### Variables

#### Creating different variables for each type

```java
public class Variables {
  public static void main(String[] args) {
    // String
    String welcome = "Hello, World";
    System.out.println(welcome);

    // Whole number
    // integer (32 bit; min: -2 147 483 648; max: 2 147 483 647)
    int theMeaningOfLifeAndTheUniverseAndEverything = 42;
    System.out.println(theMeaningOfLifeAndTheUniverseAndEverything);

    // Floating point number
    // Double ( 64 bit, double precision IEEE 754)
    double pi = 3.141592;
    System.out.println(pi);

    // Other mentioned types
    byte b = 2;     // Byte (8 bit; min:-128; max: +127)
    short s = 567;  // Short (16 bit; min: -32768 ; max: +32 767)
    long l = 30000000000000L; // long (64 bit; min: -9 223 372 036 854 775 808 ;max: 9 223 372 036 854 775 807)
    float f = 1.3f;
    float f2 = 45f; // Float (32 bit single precision IEEE 754)
  }
}

// Arithmetic operators

```

#### Exercises

### Operators

#### Trying out all Arithmetic Operators

```java
int addingNumbers = 3 + 4;
int multiplyingNumbers = 6 * 7;
int dividingNumbers = 8 / 4;
int modulingNumbers = 8 % 5;

int ff = 8;
ff *= 3;
ff /= 6; // ff = 4
```

#### Exercises

### Conditionals

### Loops
