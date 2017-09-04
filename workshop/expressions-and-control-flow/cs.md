# Expressions and Control Flow
Get into *real* programming, installing a development environment and then running our first programs.

## Materials & Resources
### Environment
- Make sure that *Microsoft Visual Studio* is installed on your machine

| Material | Time |
|:---------|-----:|
|[C# wiki](https://en.wikipedia.org/wiki/C_Sharp_(programming_language)|-|
|[Install Guide](https://www.youtube.com/watch?v=IwxkVL5DGg8)|6:28|

### Materials

| Material | Time |
|:---------|-----:|
|[Declaring Variables](https://www.youtube.com/watch?v=jB3cWjnWpwc)|20:25|
|[Console Input/Output](https://www.youtube.com/watch?v=wrl_OOgAjj0)|4:52|
|[Boolean Operators and variables](https://www.youtube.com/watch?v=u0JPMd8KSaU)|9:23|
|[If, Else and Else If Statements](https://www.youtube.com/watch?v=cIaMFKxxHj8)|5:44|
|[Switch statement](https://www.youtube.com/watch?v=soKhwNYxs2I)|7:55|
|[While and Do... While Loops](https://www.youtube.com/watch?v=A5P8sQSOWgI)|7:57|
|[For Loop](https://www.youtube.com/watch?v=IuTDC7FkPRI)|8:42|
|[Programming Basics: Statements & Functions](https://www.youtube.com/watch?v=l26oaHV7D40)|only until 7:34|
|[Operators](https://www.tutorialspoint.com/csharp/csharp_operators.htm)|Miscellaneous and Bitwise Operators are not needed |

## Optional materials
| Material | Time |
|:---------|-----:|
|[Boolean Logic & Logic Gates](https://www.youtube.com/watch?v=gI-qXk7XojA)|10:06|
|[Algorithms: Bit Manipulation](https://www.youtube.com/watch?v=NLKQEOgBAnw)|9:05|

## Material Review
 -  C#
 -  Visual Studio
 -  basic syntax
 -  variables
     -  declaration
     -  giving value
     -  byte
     -  int
     -  double
     -  boolean
     -  char
     -  string
 -  statements
    - if
    - else if
    - else
    - switch
 -  operators
     -  `+`
     -  `-`
     -  `*`
     -  `/`
     -  `%`
     -  `++`
     -  `--`
     -  `!=`
     -  `+=`
     -  `-=`
     -  `*=`
     -  `/=`
     -  `%=`
     -  `==`
     -  `>=`
     -  `<=`
     -  `>`
     -  `<`
     -  `||`
     -  `&&`
     -  `!`
 -  difference between variable declaration and statements
 -  `Console.WriteLine("Hello World");`
 -  Hello World
 -  condition, `if`, `else`
 -  loops: `for`, `while`, `do while `
 -  Console I/O
     -  `using System`
     -  `ReadLine()`
     -  `ReadKey()`
 - C# interactive

## Bookmark


## Workshop

💪: If you see this emoji, it means that you can skip the exercise if you are
in lack of time. You can practice with these exercises later to deepen your
knowledge (or to prepare for the exam).

### Printing to the terminal window

#### Hello World

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
```

#### Exercises
 -  [01 - HelloMe](hello-me/HelloMe.c)
 -  [02 - HumptyDumpty](humpty-dumpty/HumptyDumpty.c)
 -  [03 - HelloOthers](hello-others/HelloOthers.c)

### Types

#### Print values with different types

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Console.WriteLine(42);

            Console.Write(3.1415);

            Console.Read();
        }
    }
}

```

#### Integers

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Console.WriteLine(42);

            Console.Write(3.1415);

            // Maximum and minimum value
            // A simple integer is represented in 4 bytes (32bit)

            // Maximum value:  2 147 483 647
            Console.WriteLine(2147483647);

            // Minimum value: -2 147 483 648
            Console.WriteLine(-2147483648);

            Console.Read();
        }
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
 -  [04 - IntroduceYourself](introduce-yourself/IntroduceYourself.java)
 -  [05 - TwoNumbers](two-numbers/TwoNumbers.java)
 -  [06 - CodingHours](coding-hours/CodingHours.java)

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
 -  [07 - FavoriteNumber](favorite-number/FavoriteNumber.java)
 -  [08 - Swap](swap/Swap.java)
 -  [09 - Bmi 💪](bmi/Bmi.java)
 -  [10 - DefineBasicInfo](define-basic-info/DefineBasicInfo.java)
 -  [11 - VariableMutation](variable-mutation/VariableMutation.java)
 -  [12 - Cuboid 💪](cuboid/Cuboid.java)
 -  [13 - SecondsInADay](seconds-in-a-day/SecondsInADay.java)

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
 -  [14 - HelloUser](hello-user/HelloUser.java)
 -  [15 - MileToKmConverter](mile-to-km-converter/MileToKmConverter.java)
 -  [16 - AnimalsAndLegs 💪](animals-and-legs/AnimalsAndLegs.java)
 -  [17 - AverageOfInput 💪](average-of-input/AverageOfInput.java)

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
 -  [18 - OddEven](odd-even/OddEven.java)
 -  [19 - OneTwoALot](one-two-a-lot/OneTwoALot.java)
 -  [20 - PrintBigger 💪](print-bigger/PrintBigger.java)
 -  [21 - PartyIndicator](party-indicator/PartyIndicator.java)
 -  [22 - ConditionalVariableMutation 💪](conditional-variable-mutation/ConditionalVariableMutation.java)

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
 -  [23 - IWontCheatOnTheExams](i-wont-cheat-on-the-exams/IWontCheatOnTheExams.java)
 -  [24 - PrintEven](print-even/PrintEven.java)
 -  [25 - MultiplicationTable](multiplication-table/MultiplicationTable.java)
 -  [26 - CountFromTo](count-from-to/CountFromTo.java)
 -  [27 - FizzBuzz](fizz-buzz/FizzBuzz.java)
 -  [28 - DrawTriangle](draw-triangle/DrawTriangle.java)
 -  [29 - DrawPyramid 💪](draw-pyramid/DrawPyramid.java)
 -  [30 - DrawDiamond 💪](draw-diamond/DrawDiamond.java)
 -  [31 - DrawSquare 💪](draw-square/DrawSquare.java)
 -  [32 - DrawDiagonal](draw-diagonal/DrawDiagonal.java)
 -  [33 - GuessTheNumber](guess-the-number/GuessTheNumber.java)
 -  [34 - ParametricAverage 💪](parametric-average/ParametricAverage.java)
 -  [35 - DrawChessTable](draw-chess-table/DrawChessTable.java)


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
- Are your solutions optimized? What are their big O values?
