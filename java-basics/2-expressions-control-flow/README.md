# Module 03: Day 1 - Intro, Expressions & Control-Flow
and gaining knowledge of the basic building blocks of Java.

## Objectives

- Expressions
- Control Flow
- Some of the Java *Lingo*

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Variables, Math functions & Scanner class (Bana 02)](https://www.youtube.com/watch?v=yYN8u90MKCg)|17:05|
|[Conditional statement (Bana 03)](https://www.youtube.com/watch?v=qZ2pb6BljLk)|13:10|
|[Looping, collecting user input with Scanner class (Bana 04)](https://www.youtube.com/watch?v=efvZmFd1prA)|13:23|
|[Strings (mathtutordvd 07) - basic items](https://www.youtube.com/watch?v=r3DBIDyzLUI)|11:38|
|[String resource on Java, specifically focused on strings](http://tutorials.jenkov.com/java/strings.html)||

### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:-------- |-----:|
|[Using IDEA (instead of Eclipse)](https://www.jetbrains.com/help/idea/2016.2/tutorial-creating-running-and-packaging-your-first-java-application.html)||
|[Alternative discussion on Variables and Binary (JCode.01)](https://www.youtube.com/watch?v=DnBTGtmJdzA)|5:19|
|[Deeper on how memory works (storing variables. Stack & Heap) (JCode.02)](https://www.youtube.com/watch?v=tUW2kIPY3is)|3:52|
|[Official Java docs on Strings](http://docs.oracle.com/javase/8/docs/api/java/lang/String.html)||

## Material Review
- condition
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
- `Math.*`
- ...


## Workshop

### Conditional
- comparison operators
  - ==      equal to
  - !=      not equal to
  - >       greater than
  - >=      greater than or equal to
  - <       less than
  - <=      less than or equal to
- if
- else
- elseif
- switch
- conditional operators
   - and &&
   - or ||
   - negation !

```java
// Conditionals                                                                                 
// Example 1                                                                                    
if(1 == 1)                                                                                      
    System.out.println("1 equals 1, wohooo");                                                   

// Example 2                                                                                    
if(2 >= 1)                                                                                      
    System.out.println("2 is greater than or equal to 1");                                      

// Example 3 (!= not equal)                                                                     
if(4 != 5)                                                                                      
    System.out.println("4 is not equal to 5");                                                  

// Example 4                                                                                    
int a = 5;                                                                                      
int b = 7;                                                                                      

if(a > b) {                                                                                     
    System.out.println(String.format("%d is bigger than %d", a, b));                            
} else {                                                                                        
    System.out.println(String.format("%d is less than %d", a, b));                              
}                                                                                               
// What happens when a equals b? (Let's see Example 3)                                          

// Example 5                                                                                    
b = 5;                                                                                          

if(a > b) {                                                                                     
    System.out.println(String.format("%d is bigger than %d", a, b));                            
} else if(a < b) {                                                                              
    System.out.println(String.format("%d is less than %d", a, b));                              
}else {                                                                                         
    System.out.println(String.format("%d is equals to %d", a, b));                              
}                                                                                               

// Example 6 -> check if "a" is in the 1..9 range (inclusive)                                   
a = 5;                                                                                          

if(a >= 1 && a <=9) {                                                                           
    System.out.println("It is in the range!");                                                  
}                                                                                               

// Example 7 -> check if "a" is outside of the 1..9 range (use conditional "or" operator)       
a = -2;                                                                                         

if(a < 1 || a > 9)                                                                              
    System.out.println("\"a\" is outside of the specified range.");                             

// Example 8 -> check if "a" is outside of the 1..9 range, but with using negation operator (!)
a = -2;                                                                                         

if(!(a >= 1 && a <=9)) {                                                                        
    System.out.println("\"a\" is outside of the specified range.");                             
}                                                                                               

// Example 9                                                                                    
Boolean trueBool = true;                                                                        
Boolean falseBool = Boolean.FALSE;                                                              

if(trueBool || falseBool)                                                                       
    System.out.println("One of the variables is \"true\"");                                     
```

- bitwise operators
   - and &
   - or |
   - xor ^


##### Exercise
*Exercises about Conditions*
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
- for
- while
- do while
- break
- continue

```java
// Loops                                                                        
// For statement/loop                                                           
/*                                                                              
    for (initialization; termination; increment) {                              
        statement(s)                                                            
    }                                                                           
*/                                                                              

// Example 1                                                                    
for (int i = 0; i < 10; i++) {                                                  
    System.out.print(i);                                                        
}                                                                               

// Example 2 -> going by 2                                                      
int j = 0;                                                                      
for (; j < 10; j += 2)                                                          
    System.out.print(j);                                                        

// Example 3 -> infinity loop ( :D )                                            
for(;;)                                                                         
    System.out.print(j);                                                        

// While statement/loop                                                         
/*                                                                              
    while (expression) {                                                        
        statement(s)                                                            
    }                                                                           
*/                                                                              

// Example 1                                                                    
int k = 0;                                                                      
while (k < 10) {                                                                
    System.out.print(k);                                                        
    k++;                                                                        
}                                                                               

// Example 2                                                                    
k = 0;                                                                          
while (k < 10) {                                                                
    System.out.print(k);                                                        
    k += 2;                                                                     
}                                                                               

// Do-While statement/loop (it executes at least once)                          
/*                                                                              
    while (expression) {                                                        
        statement(s)                                                            
    }                                                                           
*/                                                                              

// Example 1                                                                    
int l = 0;                                                                      
do {                                                                            
    System.out.print(l);                                                        
    l++;                                                                        
} while (l < 10);                                                               

// Example 2                                                                    
l = 0;                                                                          
do {                                                                            
    System.out.print(l);                                                        
    l += 2;                                                                     
} while (l < 10);                                                               


// Break statement (jump out from the loop)                                     

// Example 1 -> break when  the first element has found which is divisible by 5
for (int m = 1; m < 10; m++) {                                                  
    if (m % 5 == 0)                                                             
        break;                                                                  
    System.out.print(m);                                                        
}                                                                               


// Continue statement (jump to the next loop iteration)                         

// Example 1 -> continue on elements which is divisible by 2                    
for (int m = 1; m < 10; m++) {                                                  
    if (m % 2 == 0)                                                             
        continue;                                                               
    System.out.print(m);                                                        
}                                                                               
```

##### Exercise
*Exercises about Loops*
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
