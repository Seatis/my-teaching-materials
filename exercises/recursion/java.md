# Recursion
What happens when a function calls itself? [Learn more here](
java.md)

## Materials & Resources
| Material | Time |
|:---------|-----:|


### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|



## Material Review
 - recursion
 - base case

## Workshop


### Factorial with loop

```java
public static int factorial_loop(int n) { 
      int factorial = 1;
      for(int i = 1; i<n+1; i++){
      	factorial *= i;
      	}
      return factorial;	
 }
 ```


### Factorial with recursion

```java
public static int factorial_recursive(int n) { 
      if(n == 1)
           return 1;
      else
           return n * factorial_recursive(n - 1);
 }
 ```

### Exercises

 - [01](basic_math_examples/counter.java)
 - [02](basic_math_examples/numberadder.java)
 - [03](basic_math_examples/sumdigit.java)
 - [04](basic_math_examples/power.java)	
 - [05](bunnies/bunny1.java)
 - [06](bunnies/bunny2.java)
 - [07](strings/string1.java)
 - [08](strings/string2.java)
 - [09](strings/string3.java)
 - [10](fibonacci/fibonacci.java)
 - 11: reproduce this:   
![11](drawing/graphic.png)
 - 12: reproduce this:   
![12](drawing/graphic2.png)