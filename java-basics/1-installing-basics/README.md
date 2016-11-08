# Installing & Basics
Get into *real* programming, installing a development environment and then running our first programs.

## Objectives
- Get a working environment going
- Create first program in Java
- Variables

## Materials & Resources
### Environment
- download jdk (from Oracle, version 8) - this is the Java Development Kit; part of the challenge here is to figure out where to get this.  
- if *jre* (Java Runtime Environment) didn't download, get that too
- download the development environment tool: www.jetbrains.com - Install Intellij-IDEA; get the Ultimate edition (but ensure you get the license from a Mentor)

### Training
| Material | Time |
|:---------|-----:|
|[Historic background leading to Java (Guru-01)](https://www.youtube.com/watch?v=2Xa3Y4xz8_s)| 6:01|
|[Installing Java & IntelliJ IDEA (Koets)](https://www.youtube.com/watch?v=qscQ3XT6qu4)| 15:58|
|[Getting started (Bana 01, note he's using eclipse)](https://www.youtube.com/watch?v=TBWX97e1E9g)|17:42|

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

## Workshop
### The Java environment
- Programs with the .java, .class extensions
- Compiling to bytecode
- RAM
- Just-in-time (JIT) compiling vs linking together
- Interpreter to machine code
- JDK, JRE, JVM

### "Hello World"
*Test that everything is installed correctly.*
- Get output
- Practice creating file, directories
- How to run a program
- `public static void main(string args[])`

```java
System.out.println("Hello world!");
```

##### Exercise
- Run a simple Hello World!
- Change it to greet you instead of the World.
- [Workshop01.java](workshop/Workshop01.java)

### Variables
#### Numbers
- Integer
- Byte
- Short
- Long
- Float
- Double
- Range limitations
- Arithmetic Operators (+, -, *, /, %, ++, --, +=, -=, /=, *=)

```java
// Integers
// Byte (8 bit; min:-128; max: +127)
byte a = -127;
byte b = 2;
byte c = 278; // error by the IDE

// Short (16 bit; min: -32768 ; max: +32 767)
short d = -32768;
short e = 65000; // error by the IDE
Short f = 567;

// Integer (32 bit; min: -2 147 483 648; max: 2 147 483 647)
int g = 12;
Integer h = 13;


// Long (64 bit; min: -9 223 372 036 854 775 808 ;max: 9 223 372 036 854 775 807 )
long i = 200;
long j = 30000000000000L;
long k = -34500000000L;

// Floats
// Float (32 bit single precision IEEE 754)
float l = 1.3f;
float m = 45f;
Float n = 0; // use 0f

// Double ( 64 bit, double precision IEEE 754)
double o = 23.03013103103d;
Double p = 1d;

// Arithmetic operators
int aa = 3 + 4;
int bb = 6 * 7;
int cc = 8 / 4;
int dd = 8 % 4;
int ee = 8 % 5;

int ff = 8;
ff *= 3;
ff /= 6; // ff = 4
```
**
#### Exercise
*Exercises about simple types and numbers*
- [Workshop02.java](workshop/Workshop02.java)
- [Workshop03.java](workshop/Workshop03.java)
- [Workshop04.java](workshop/Workshop04.java)
- [Workshop05.java](workshop/Workshop05.java)
- [Workshop06.java](workshop/Workshop06.java)

#### Other datatypes
- Boolean
```java
// Boolean (8 bit, 1 byte), true or false         
Boolean trueCondition = Boolean.TRUE;    
System.out.println(trueCondition); // true        

boolean trueBool = true;
boolean falseBool = false;

boolean isBigger = 3 > 4;
boolean isTheSame = 5 == 5;         
```
- Date (will cover later)
- Objects (will cover later)


##### Exercise
*Exercises about other data types*
- [Workshop07.java](workshop/Workshop07.java)
- [Workshop08.java](workshop/Workshop08.java)
- [Workshop09.java](workshop/Workshop09.java)
- [Workshop10.java](workshop/Workshop10.java)
- [Workshop11.java](workshop/Workshop11.java)
- [Workshop12.java](workshop/Workshop12.java)
- [Workshop13.java](workshop/Workshop13.java)


#### Strings
 - char
 - String Class
 - length()
 - isEmpty()
 - Concatenation, concat()
 - Escape special characters
 - indexOf(), contains(), lastIndexOf()
 - substring()
 - format()
 - compareTo(), compareToIgnoreCase()
 - replace()
 - toLowerCase(), toUpperCase
 - trim()
 - \\, \n, \t
 *general familiarity with how to check syntax and find functions on the internet*

```java
// Strings and char                                                                                                                                           
// char 16 bit unicode character (unsigned -> min: 0; max: 65535)                                                                                             
String actionsProverb = "Actions speak louder than words.";                                                                                                   

// select the first char from the string, it is the uppercase A                                                                                               
char firstChar = actionsProverb.charAt(0);                                                                                                                    
System.out.println(firstChar);                                                                                                                                

// string concatenation                                                                                                                                       
String concated = "Hope for the best " + "but";                                                                                                               
concated = concated + " prepare";                                                                                                                             
concated += " for ";                                                                                                                                          
concated.concat("the worst.");                                                                                                                                
System.out.println(concated);                                                                                                                                 

// escape special character                                                                                                                                   
String strWithSpecialCharacters = "I can \"put\" special 'characters' in a \\string\\.";                                                                      
System.out.println(strWithSpecialCharacters);                                                                                                                 

// length of a string                                                                                                                                         
int myLength = "what is my length?".length();                                                                                                                 
System.out.println(myLength);                                                                                                                                 

System.out.println(actionsProverb.length());                                                                                                                  

// isEmpty()                                                                                                                                                  
String emptyString = "";                                                                                                                                      
System.out.println("Is \"emptyString\" empty? " + emptyString.isEmpty());                                                                                     
System.out.println("Is \"actionsProverb\" empty? " + actionsProverb.isEmpty());                                                                               

// contains                                                                                                                                                   
System.out.println(actionsProverb.contains("than")); // true                                                                                                  
System.out.println(actionsProverb.contains("five")); // false                                                                                                 

// indexOf                                                                                                                                                    
System.out.println(actionsProverb.indexOf("t")); // 2 (t in "Actions")                                                                                        
System.out.println(actionsProverb.indexOf("t", 3)); // second parameter is called fromIndex, result will be 21 (t in "than")                                  
System.out.println(actionsProverb.indexOf("thinking")); // -1                                                                                                 

// lastIndexOf                                                                                                                                                
System.out.println(actionsProverb.lastIndexOf("t")); // 21 (t in "than")                                                                                      

// substring                                                                                                                                                  
System.out.println(actionsProverb.substring(0,7)); // result will be "Actions"                                                                                
System.out.println(actionsProverb.substring(14,20)); // result will be "louder" (startIndex, endIndex)                                                        

// format strings                                                                                                                                             
System.out.println(String.format("I have %d cats.", 2)); // %d -> integer                                                                                     
System.out.println(String.format("I have %d %s and I love them!", 3, "raptors")); // %d -> integer; %s -> string, %f -> float                                 

// compareTo                                                                                                                                                  
System.out.println("a".compareTo("b")); // -1                                                                                                                 
System.out.println("b".compareTo("a")); // 1                                                                                                                  
System.out.println("a".compareTo("c")); // -2                                                                                                                 
System.out.println("a".compareTo("deli")); // -3                                                                                                              
System.out.println("a".compareTo("a")); // 0 -> equals                                                                                                        

// compareToIgnoreCase                                                                                                                                        
System.out.println("a".compareToIgnoreCase("A")); // 0 -> equals                                                                                              

// replace                                                                                                                                                    
String weakestLinkProverb = "A rope is only as strong as its weakest link."; // it has a mistake, correctly: "A chain is only as strong as its weakest link."
System.out.println(weakestLinkProverb.replace("rope", "chain"));                                                                                              
System.out.println(weakestLinkProverb.replace("a", "b"));                                                                                                     

// toLowerCase; toUpperCase                                                                                                                                   
System.out.println("How much is the fish?".toUpperCase());                                                                                                    
System.out.println("HOOOORRRAAAAAYYYY".toLowerCase());                                                                                                        

// trim                                                                                                                                                       
System.out.println("     string with lots of spaces       ".trim());                                                                                          
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

# Links
- [Java Basic Module](../README.md)
- [Next Day](../2-expressions-control-flow/README.md)
