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
 -  activate IntelliJ IDEA following [this activation guide](https://github.com/greenfox-academy/teaching-materials/blob/master/exercises/expressions-and-control-flow/intellij-activation.md)


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
 -  block
 -  scanner
     -  `System.in`
     -  `nextLine()`
     -  `nextInt()`

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

    // Concat string with number
    System.out.println("My favorite number is: " + 8); // Prints My favorite number is: 8
  }
}
```

#### Exercises
 -  [04](introduce-yourself/IntroduceYourself.java)
 -  [05](two-numbers/TwoNumbers.java)
 -  [06](coding-hours/CodingHours.java)

### Variables

#### Creating different variables for each type

```java
public class Variables {
  public static void main(String[] args) {
    // String
    String welcome = "Hello, World";
    System.out.println(welcome);

    // Boolean
    boolean isAwesome = true;
    System.out.println(isAwesome);

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

    // Declaring a variable
    int number;

    // Assigning a variable, (define its value)
    number = 12;

    // Mutate a variable, (redefine its value)
    number = 23;
  }
}
```

#### Arithmetic Assignment Operators

```java
public class Variables {
  public static void main(String[] args) {
    int a = 12;
    a += 4;
    System.out.println(a); // Prints 16

    int b = 12;
    b -= 4;
    System.out.println(b); // Prints 8

    int c = 12;
    System.out.println(c++); // Prints 12
    System.out.println(c); // Prints 13

    int d = 12;
    System.out.println(++d); // Prints 13
    System.out.println(d); // Prints 13

    int e = 12;
    System.out.println(e--); // Prints 12
    System.out.println(e); // Prints 11

    int f = 12;
    System.out.println(--f); // Prints 11
    System.out.println(f); // Prints 11

    int g = 12;
    g *= 3;
    System.out.println(g); // Prints 36

    int h = 12;
    h /= 3;
    System.out.println(h); // Prints 4

    int i = 12;
    i %= 7;
    System.out.println(i); // Prints 5
  }
}
```

#### Exercises
 -  [07](favorite-number/FavoriteNumber.java)
 -  [08](define-basic-info/DefineBasicInfo.java)
 -  [09](bmi/Bmi.java)
 -  [10](cuboid/Cuboid.java)
 -  [11](seconds-in-a-day/SecondsInADay.java)
 -  [12](swap/Swap.java)
 -  [13](variable-mutation/VariableMutation.java)

### User input (scanner)

```java
// Loads the scanner to the file
import java.util.Scanner;

public class UserInput {
  public static void main(String[] args) {
    // Creates a scanner
    Scanner scanner = new Scanner(System.in);

		// The program stops and waits for user input and to press enter
		String userInput1 = scanner.nextLine();

		// It prints the whole line that was given by the user
		System.out.println(userInput1);

		// The program stops and waits for user input that is an integer and to press enter
		int userInput2 = scanner.nextInt();

		// It prints the integer
		System.out.println(userInput2);
  }
}
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
    } else if (c < 20) {
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
 -  [21](party-indicator/PartyIndicator.java)
 -  [22](conditional-variable-mutation/ConditionalVariableMutation.java)

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
 -  [23](i-wont-cheat-on-the-exams/IWontCheatOnTheExams.java)
 -  [24](print-even/PrintEven.java)
 -  [25](count-from-to/CountFromTo.java)
 -  [26](multiplication-table/MultiplicationTable.java)
 -  [27](draw-triangle/DrawTriangle.java)
 -  [28](draw-pyramid/DrawPyramid.java)
 -  [29](draw-diamond/DrawDiamond.java)
 -  [30](draw-square/DrawSquare.java)
 -  [31](draw-diagonal/DrawDiagonal.java)
 -  [32](draw-chess-table/DrawChessTable.java)
 -  [33](fizz-buzz/FizzBuzz.java)
 -  [34](guess-the-number/GuessTheNumber.java)
 -  [35](parametric-average/ParametricAverage.java)


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
