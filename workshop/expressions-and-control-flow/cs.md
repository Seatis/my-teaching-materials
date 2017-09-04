# Expressions and Control Flow
Get into *real* programming, installing a development environment and then running our first programs.

## Materials & Resources
### Environment
- Make sure that *Microsoft Visual Studio* is installed on your machine

| Material | Time |
|:---------|-----:|
|[C# wiki](https://en.wikipedia.org/wiki/C_Sharp_(programming_language))|-|
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

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(2 + 2);
            Console.WriteLine(7 - 2);
            Console.WriteLine(3 * 2);
            Console.WriteLine(5 / 2);
            Console.WriteLine(7 % 2);
            Console.WriteLine(7 / 2.0);

            Console.Read();
        }
    }
}
```

#### Booleans

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            //true, false
            Console.WriteLine(true);
            Console.WriteLine(false);

            //negation
            Console.WriteLine(!true);
            Console.WriteLine(!false);

            //and
            Console.WriteLine(true && true);
            Console.WriteLine(true && false);
            Console.WriteLine(false && true);
            Console.WriteLine(false && false);

            //or
            Console.WriteLine(true || true);
            Console.WriteLine(true || false);
            Console.WriteLine(false || true);
            Console.WriteLine(false || false);

            Console.Read();
        }
    }
}
```

#### Strings

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            // String and special characters
            Console.WriteLine("hello");
            Console.WriteLine("don't");
            Console.WriteLine("She said, \"you deserva a treat\" ");
            
            // String Operators
            // Concatination
            Console.WriteLine("hand" + "some");

            // Concat string with number
            Console.WriteLine("My favourite number is: " + 8);

            Console.Read();
        }
    }
}

```

#### Exercises
 -  [04 - IntroduceYourself](introduce-yourself/IntroduceYourself.java)
 -  [05 - TwoNumbers](two-numbers/TwoNumbers.java)
 -  [06 - CodingHours](coding-hours/CodingHours.java)

### Variables

#### Creating different variables for each type

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            // String
            string greeting = "Hello my friend";
            var bye = "It was good to see you friend";
            Console.WriteLine(greeting);
            Console.WriteLine(bye);

            // Boolean
            bool running = true;
            var working = false;
            Console.WriteLine(running);
            Console.WriteLine(working);

            // Whole number
            int a = 11;
            var b = 12;
            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(a + b);

            // Floating point number
            double pi = 3.141592;
            var e = 2.718;
            Console.WriteLine(pi);
            Console.WriteLine(e);

            // Declaring a variable
            int number;

            // Assigning a variable, (define its value)
            number = 12;

            // Mutate a variable, (redefine its value)
            number = 23;

            Console.Read();
        }
    }
}

```

#### Arithmetic Assignment Operators

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 12;
            a += 4;
            Console.WriteLine(a); // Prints 16

            int b = 12;
            b -= 4;
            Console.WriteLine(b); // Prints 8

            int c = 12;
            Console.WriteLine(c++); // Prints 12
            Console.WriteLine(c); // Prints 13

            int d = 12;
            Console.WriteLine(++d); // Prints 13
            Console.WriteLine(d); // Prints 13

            int e = 12;
            Console.WriteLine(e--); // Prints 12
            Console.WriteLine(e); // Prints 11

            int f = 12;
            Console.WriteLine(--f); // Prints 11
            Console.WriteLine(f); // Prints 11

            int g = 12;
            g *= 3;
            Console.WriteLine(g); // Prints 36

            int h = 12;
            h /= 3;
            Console.WriteLine(h); // Prints 4

            int i = 12;
            i %= 7;
            Console.WriteLine(i); // Prints 5

            Console.Read();
        }
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

```csharp
namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello user what is your name?");
            string name = Console.ReadLine();

            Console.WriteLine("Hello, " + name);
            Console.WriteLine("How old are you? ");

            string age = Console.ReadLine();
            Console.WriteLine(age + " is a nice age");

            Console.Read();

        }
    }
}
```
#### Exercises
 -  [14 - HelloUser](hello-user/HelloUser.java)
 -  [15 - MileToKmConverter](mile-to-km-converter/MileToKmConverter.java)
 -  [16 - AnimalsAndLegs 💪](animals-and-legs/AnimalsAndLegs.java)
 -  [17 - AverageOfInput 💪](average-of-input/AverageOfInput.java)

### Conditionals

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 13;

            if (a == 13)
            {
                Console.WriteLine("Yaaay! The value of the \"a\" variable is 13"); // This block will run
            }

            if (a == 8)
            {
                Console.WriteLine("Yaaay! The value of the \"a\" variable is 8"); // This block will NOT run
            }


            int b = 20;

            if (b < 10)
            {
                Console.WriteLine("Yaaay! The value of the \"b\" variable is lower than 10"); // This block will NOT run
            }
            else
            {
                Console.WriteLine("Yaaay! The value of the \"b\" variable is higher than 10"); // This block will run
            }


            int c = 15;

            if (c < 10)
            {
                Console.WriteLine("Yaaay! The value of the \"b\" variable is lower than 10"); // This block will NOT run
            }
            else if (c < 20)
            {
                Console.WriteLine("Yaaay! The value of the \"b\" variable is higher than 10 but less then 20"); // This block will run
            }
            else
            {
                Console.WriteLine("Yaaay! The value of the \"b\" variable is higher than 10"); // This block will NOT run
            }


            bool thirsty = true;
            bool hungry = false;

            if (thirsty && hungry)
            {
                Console.WriteLine("Lunch time!");
            }
            else if (thirsty || hungry)
            {
                Console.WriteLine("Snack time!");
            }
            else
            {
                Console.WriteLine("No food for you, little fatty.");
            }

            Console.Read();
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

```csharp
using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("while loop");
            int a = 0;
            while (a < 10)
            {
                Console.WriteLine(a++);
            }

            Console.WriteLine("\n\n do while loop:");
            int b = 0;
            do
            {
                Console.WriteLine(b++);
            } while (b < 10);

            Console.WriteLine("\n\n for loop:");
            for(int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
            }

            Console.Read();
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
Please follow the styleguide: [Our C# styleguide](#)

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
