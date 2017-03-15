# Expressions & Control-Flow
Having installed IntelliJ and tested our installs (with a "Hello World") program, we can now start laying the foundation of programming specifically using Java.


## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Boolean Operators & IF Statement](https://www.youtube.com/watch?v=6O_lwNnWFR0)|10:29|
|[Else/Else If Statements & AND/OR Operators](https://www.youtube.com/watch?v=3J4jCSXA1Pw)|14:22|
|[While, Do While & For Loops](https://www.youtube.com/watch?v=6djggrlkHY8)| only until 8:35 |

### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:-------- |-----:|
|[Variables, Math functions & Scanner class (Bana 02)](https://www.youtube.com/watch?v=yYN8u90MKCg)|17:05|
|[Conditional statement (Bana 03)](https://www.youtube.com/watch?v=qZ2pb6BljLk)|13:10|
|[Looping, collecting user input with Scanner class (Bana 04)](https://www.youtube.com/watch?v=efvZmFd1prA)|13:23|
|[Strings (mathtutordvd 07) - basic items](https://www.youtube.com/watch?v=r3DBIDyzLUI)|11:38|
|[String resource on Java, specifically focused on strings](http://tutorials.jenkov.com/java/strings.html)||
|[Using IDEA (instead of Eclipse)](https://www.jetbrains.com/help/idea/2016.2/tutorial-creating-running-and-packaging-your-first-java-application.html)||
|[Alternative discussion on Variables and Binary (JCode.01)](https://www.youtube.com/watch?v=DnBTGtmJdzA)|5:19|
|[Deeper on how memory works (storing variables. Stack & Heap) (JCode.02)](https://www.youtube.com/watch?v=tUW2kIPY3is)|3:52|
|[Official Java docs on Strings](http://docs.oracle.com/javase/8/docs/api/java/lang/String.html)||

## Material Review
- condition, if, else
- loops: for, while
- scanner
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

### Boolean
```java

boolean trueBool = true;
boolean falseBool = false;

boolean isBigger = 3 > 4;
boolean isTheSame = 5 == 5;         
```

- [Workshop07.java](workshop/Workshop07.java)
- [Workshop08.java](workshop/Workshop08.java)
- [Workshop09.java](workshop/Workshop09.java)
- [Workshop10.java](workshop/Workshop10.java)
- [Workshop11.java](workshop/Workshop11.java)
- [Workshop12.java](workshop/Workshop12.java)
- [Workshop13.java](workshop/Workshop13.java)

### Conditionals
```java
if(thirsty && hungry) {
  System.out.println("Lunch time!");
} else if (thirsty || hungry) {
  System.out.println("Snack time!");
} else {
  System.out.println("No food for you, litle fatty.");
}
```

- [Workshop22.java](workshop/Workshop22.java)
- [Workshop23.java](workshop/Workshop23.java)
- [Workshop24.java](workshop/Workshop24.java)
- [Workshop25.java](workshop/Workshop25.java)
- [Workshop26.java](workshop/Workshop26.java)
- [Workshop27.java](workshop/Workshop27.java)
- [Workshop28.java](workshop/Workshop28.java)
- [Workshop29.java](workshop/Workshop29.java)
- [Workshop30.java](workshop/Workshop30.java)

### Loops

```java
while(boolCondition) {
  System.out.println("I'm just printing until the boolCondition is true.");
}
for(int i = 0; i < 100; i++) {
  System.out.println("I won't cheat on my exams again.");
}
```

- [Workshop31.java](workshop/Workshop31.java)
- [Workshop32.java](workshop/Workshop32.java)
- [Workshop33.java](workshop/Workshop33.java)
- [Workshop34.java](workshop/Workshop34.java)
- [Workshop35.java](workshop/Workshop35.java)
- [Workshop36.java](workshop/Workshop36.java)
- [Workshop37.java](workshop/Workshop37.java)

### Challenge
- https://www.codewars.com/kata/563f037412e5ada593000114/train/java - Interest rate computation

### Challenge
- Loop printing out prime numbers from 2 to 100

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
