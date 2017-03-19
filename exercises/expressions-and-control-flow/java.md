# Expressions and Control Flow
Get into *real* programming, installing a development environment and then running our first programs.

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

### Environment
 -  download jdk (from Oracle, version 8) - this is the Java Development Kit; part of the challenge here is to figure out where to get this.  
 -  if *jre* (Java Runtime Environment) didn't download, get that too
 -  download the development environment tool: www.jetbrains.com - Install Intellij-IDEA; get the Ultimate edition (but ensure you get the license from a Mentor)


## Material Review
 -  Java
 -  IntelliJ IDEA
 -  statement
 -  variables
     -  declaration
     -  giving value
     -  byte
     -  int
     -  float
     -  boolean
     -  char
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
 -  difference between variable declaration and statements
 -  `System.out.println()`
 -  Hello World
 -  escape character
 -  `"Java's stuff"` and `'stuff of Java'`
 -  concatenation
 -  condition, `if`, `else`
 -  loops: `for`, `while`
 -  scanner
     -  `System.in`
     -  next()
     -  nextLine()
     -  nextInt()

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
 -  [01](hello-me/HelloMe.java)
 -  [02](hello-others/HelloOthers.java)
 -  [03](humpty-dumpty/HumptyDumpty.java)

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

#### Integers

```java
public class Integers {
  public static void main(String[] args) {
    // Positive, negative and zero
    System.out.println(42); // Prints 42
    System.out.println(-1); // Prints -1
    System.out.println(0); // Prints 0

    // Maximum and minimum value
    // A simple integer is represented in 4 bytes (32bit)

    // Maximum value:  2 147 483 647
    System.out.println(2147483647);
    // Minimum value: -2 147 483 648
    System.out.println(-2147483648);

    System.out.println(2147483648); // Compilation error
  }
}
```

#### Floats

```java
public class Floats {
  public static void main(String[] args) {
    // Positive, negative and zero
    System.out.println(3.1415); // Prints 3.1415
    System.out.println(-1.5); // Prints -1.5
    System.out.println(0.0); // Prints 0.0

    // Leading and closing zero is not mandatory
    System.out.println(.5); // Prints 0.5
    System.out.println(5.); // Prints 5.0
  }
}
```

#### Number Operations

```java
public class NumberOperations {
  public static void main(String[] args) {
    // Arithmetric operations
    System.out.println(1 + 1); // Prints 2
    System.out.println(5 - 2); // Prints 3
    System.out.println(3 * 4); // Prints 12
    System.out.println(6 * 2); // Prints 3
    System.out.println(5 / 2); // Prints 2
    System.out.println(5. / 2); // Prints 2
    System.out.println(5 / 2.); // Prints 2.5
    System.out.println(5. / 2.); // Prints 2.5
    System.out.println(5 % 2); // Prints 1
  }
}
```

#### Booleans

```java
public class Booleans {
  public static void main(String[] args) {
    // true, false
    System.out.println(true); // Prints true
    System.out.println(false); // Prints false
    
    // Boolean Operators
    // Negation
    System.out.println(!true); // Prints false
    System.out.println(!false); // Prints true

    // And
    System.out.println(true && true); // Prints true
    System.out.println(true && false); // Prints false
    System.out.println(false && true); // Prints false
    System.out.println(false && false); // Prints false

    // Or
    System.out.println(true || true); // Prints true
    System.out.println(true || false); // Prints true
    System.out.println(false || true); // Prints true
    System.out.println(false || false); // Prints false
  }
}
```

#### Strings

```java
public class Strings {
  public static void main(String[] args) {
    // String and special characters
    System.out.println("apple"); // Prints apple
    System.out.println("don't"); // Prints don't
    System.out.println("\"Everything you can imagine is real.\" - Picasso"); // Prints "Everything you can imagine is real." - Picasso 
    
    // String Operators
    // Concatination
    System.out.println("tooth" + "brush"); // Prints toothbrush
    System.out.println("My favorite number is: " + 8); // Prints My favorite number is: 8
  }
}
```

#### Exercises
 -  [04](introduce-yourself/IntroduceYourself.java)
 -  [05]

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
    // Double (64 bit, double precision IEEE 754)
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
