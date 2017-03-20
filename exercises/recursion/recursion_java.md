# Recursion
What happens when a function calls itself? [Learn more here](
https://github.com/gy0p4k/test/recursion_java.md)

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

 - [01](java/recursive_counter.java)
 - [02](java/recursive_add.java)
 - [03](java/recursive_sumdigit.java)
 - [04](java/recursive_power.java)	
 - [05](java/recursion_bunny1.java)
 - [06](java/recursion_bunny2.java)
 - [07](java/recursion_string1.java)
 - [08](java/recursion_string2.java)
 - [09](java/recursion_string3.java)
 - [10](java/recursion_fibonacci.java)
 - 11: reproduce this:   
![11](java/recursive_graphic.png)
 - 12: reproduce this:   
![12](java/recursive_graphic2.png)