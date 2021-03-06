# Functions and arrays
Dive deeper into *real* programming, reuse code and get to know more complex data structures


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[Introduction to Arrays](https://www.youtube.com/watch?v=L06uGnF4IpY)|7:25|
|[Arrays (Bana.09)](https://www.youtube.com/watch?v=eNPX2pTiaHI)|18:08|
|[Methods & Fields, Using Functions (Bana.05)](https://www.youtube.com/watch?v=1HTsLK_m2ao)|14:06|
|[Debugging in IntelliJ](https://www.youtube.com/watch?v=1bCgzjatcr4)|17:39|


### Optional
Reading material only, if the above is still unclear.

| Material | Time |
|:-------- |-----:|
|[Arrays (official Oracle docs)](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/arrays.html)|reading|
|[Java methods (TutorialsPoint)](https://www.tutorialspoint.com/java/java_methods.htm)|reading|


## Material Review
- Declaring
  - constants
  - initial values of arrays `{}`
  - `new` keyword
- Functions
  - void or return a value
  - can be used to compartmentalise code (make more readable)
  - have own variables
  - take parameters
- Arrays
  - can be measured (have `length`)
  - can be iterated through
  - type definition (e.g. `String[]`)
  - toString
  - copyOf
  - sort
  - foreach statement
- Debugging
  - breakpoint
  - step over
  - watches
  - evaluate expression


## Workshop

### Functions

```java
public class HelloWorld {

  public static void main(String[] args) {
    greetFunction();
  }

  public static void greetFunction() {
    // Prints "Hello Green Fox!" to the terminal window.
    System.out.println("Hello Green Fox!");
  }
}
```

#### Excercises
-  [Doubling](exercises/functions/doubling/Doubling.java)
-  [Greeter function](exercises/functions/greet/Greet.java)
-  [Append a](exercises/functions/append-a/AppendA.java)
-  [Summing](exercises/functions/sum/Sum.java)
-  [Factorial](exercises/functions/factorio/Factorio.java)
-  [Print arguments](exercises/functions/printer/Printer.java)

### Arrays

```java
public class Arrays {
  public static void main(String[] args) {
    int[] myList = {1, 2, 3, 6};

    // Print the second element of the array
    System.out.println("The second element is " + myList[1]);

    // Print all the array elements
    for (int i = 0; i < myList.length; i++) {
      System.out.println(myList[i] + " ");
    }
  }
}
```

#### Excercises
-  [Third](exercises/arrays/third/Third.java)
-  [Compare Length](exercises/arrays/compare-length/CompareLength.java)
-  [Sum elements](exercises/arrays/sum-elements/SumElements.java)
-  [Change element](exercises/arrays/change-element/ChangeElement.java)
-  [Increment element](exercises/arrays/increment-element/IncrementElement.java)
-  [Print elements](exercises/arrays/print-all/PrintAll.java)
-  [Matrix](exercises/arrays/diagonal-matrix/DiagonalMatrix.java)
-  [Double items](exercises/arrays/double-items/DoubleItems.java)
-  [Colors](exercises/arrays/colors/Colors.java)
-  [Append a](exercises/arrays/append-a/AppendA.java)
-  [Swap elements](exercises/arrays/swap-elements/SwapElements.java)
-  [Sum all elements](exercises/arrays/sum-all/SumAll.java)
-  [Reverse list](exercises/arrays/reverse/Reverse.java)


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
