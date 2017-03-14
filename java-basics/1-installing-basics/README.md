# Installing & Basics
Get into *real* programming, installing a development environment and then running our first programs.

## Materials
| Material | Time |
|:---------|-----:|
|[Historic background leading to Java (Guru-01)](https://www.youtube.com/watch?v=2Xa3Y4xz8_s)| 6:01|
|[Installing Java & IntelliJ IDEA (Koets)](https://www.youtube.com/watch?v=qscQ3XT6qu4)| 15:58|
|[Basic Syntax](https://www.youtube.com/watch?v=SSEpAsKqRqA)|10:35|
|[Strings, String Functions](https://www.youtube.com/watch?v=0tDMZFyfNpY)| only until 7:00 |

### Environment
- download jdk (from Oracle, version 8) - this is the Java Development Kit; part of the challenge here is to figure out where to get this.  
- if *jre* (Java Runtime Environment) didn't download, get that too
- download the development environment tool: www.jetbrains.com - Install Intellij-IDEA; get the Ultimate edition (but ensure you get the license from a Mentor)

### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
|[Understanding what the Java compiliation and run process (illustrated and compared to "c", (Guru-02)](https://www.youtube.com/watch?v=G1ubVOl9IBw)| 2:24|
|[Clarifying JDK vs JRE and JVM, the components of Java (Prashun)](https://www.youtube.com/watch?v=yLkrw34VMNo) | 2:28|
|[Creating a new project using IntelliJ (IDEA)](https://www.youtube.com/watch?v=L_jXj0XTwSg) | 6:43|

### Nice To Know
IntelliJ has some tools that complete entering values for you; and of course, various keyboard combinations for jumping about.  
- [IntelliJ Reference card for keyboard shortcuts](https://resources.jetbrains.com/assets/products/intellij-idea/IntelliJIDEA_ReferenceCard.pdf)
- [Overview on autocompleting from IntelliJ](https://www.jetbrains.com/help/idea/2016.2/auto-completing-code.html)
- [Example of a shortcut for a statement](https://www.reddit.com/r/IntelliJIDEA/comments/3jyle4/does_intellij_have_a_shortcut_for_systemoutprint/)


## Material Review
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
- Arithmetic Operators (`+, -, *, /, %, ++, --, +=, -=, /=, *=`)
- length()
- isEmpty()
- Concatenation, concat()
- Escape special characters
    - `\\, \n, \t`
- indexOf(), contains(), lastIndexOf()
- substring()
- replace()
- toLowerCase(), toUpperCase()
- trim()


## Workshop

### "Hello World"
- Create your first file
- Add a main method: `public static void main(string args[]) {}`
- Run your program

```java
System.out.println("Hello world!");
```

- Run a simple Hello World!
- Change it to greet you instead of the World.

### Variables
#### Numbers

```java
byte b = 2;     // Byte (8 bit; min:-128; max: +127)
short s = 567;  // Short (16 bit; min: -32768 ; max: +32 767)
int i = 12;     // integer (32 bit; min: -2 147 483 648; max: 2 147 483 647)
long l = 30000000000000L; // long (64 bit; min: -9 223 372 036 854 775 808 ;max: 9 223 372 036 854 775 807)
float f = 1.3f;
float f2 = 45f; // Float (32 bit single precision IEEE 754)
double d = 23.03013103103; // Double ( 64 bit, double precision IEEE 754)

// Arithmetic operators
int addingNumbers = 3 + 4;
int multiplyingNumbers = 6 * 7;
int dividingNumbers = 8 / 4;
int modulingNumbers = 8 % 5;

int ff = 8;
ff *= 3;
ff /= 6; // ff = 4
```

- [Workshop01.java](workshop/Workshop01.java)
- [Workshop02.java](workshop/Workshop02.java)
- [Workshop03.java](workshop/Workshop03.java)
- [Workshop04.java](workshop/Workshop04.java)
- [Workshop05.java](workshop/Workshop05.java)
- [Workshop06.java](workshop/Workshop06.java)


#### Strings
```java

```

##### Exercise
*Exercises about Strings*
- [Workshop14.java](workshop/Workshop14.java)
- [Workshop15.java](workshop/Workshop15.java)
- [Workshop16.java](workshop/Workshop16.java)
- [Workshop17.java](workshop/Workshop17.java)
- [Workshop18.java](workshop/Workshop18.java)
- [Workshop19.java](workshop/Workshop19.java)
- [Workshop20.java](workshop/Workshop20.java)
- [Workshop21.java](workshop/Workshop21.java)


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
