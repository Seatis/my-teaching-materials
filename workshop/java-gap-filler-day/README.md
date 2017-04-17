# Gap Filling Day
*You are a wizard, Harry!*

## Materials & Resources

### Material
| Material | Time |
|:-------- |-----:|
|[Ternary Opeartor in Java](https://www.youtube.com/watch?v=qdudJfu2C04)| 3:57 |
|[Java Tutorial For Beginners 24 - The final keyword in Java](https://www.youtube.com/watch?v=aN8znC-ME-w) | 6:32 |
|[Final Keyword In Java](http://www.javatpoint.com/final-keyword) | |
|[Enums](https://www.youtube.com/watch?v=5VyDsO0mFDU)| 9:32 |
|[Generic Methods](https://www.youtube.com/watch?v=J6B_qauxfuc)| 4:39 |
|[Implementing a Generic Method](https://www.youtube.com/watch?v=ZoJaD0Qoi0o)| 4:56 |
|[Exceptions](https://www.youtube.com/watch?v=EWj60p8esD0)| 15:42 |
|[Intro to Java Annotations](https://www.youtube.com/watch?v=lA1n_HBrFwY)| 9:04 |
|[Annotation in Java - Basics](https://www.youtube.com/watch?v=JV0atjBcUv4)| 8:33 |

### Optional
| Material | Time |
|:-------- |-----:|
|[Generic Return Types](https://www.youtube.com/watch?v=QB5pQT45zvg)| 6:04 |
|[Enums](https://www.youtube.com/watch?v=ZtEyZuXgUoY)| 13:14 |
|[Java - Exceptions](https://www.tutorialspoint.com/java/java_exceptions.htm) | |

## Material Review
 - condition `?` true `:` false
 - `final` keyword - variable, method, class
 - `enum`
 - `<T>`
 - Exceptions
 - `@Deprecated`, `@Override`, and `@SuppressWarnings`

## Workshop

### Ternary Operator
```java
class Calculator {  
  public boolean isHigherA(int a, int b) {  
    if (a > b) {
        return a;
    } else {
        return b;
    }
  }  

  public boolean isHigherB(int a, int b) {
    return a > b ? a : b;
  }
}  
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()

### Final
```java
class Bike {  
  //final variable  
  final int SPEEDLIMIT = 90;

  void run() {  
    SPEEDLIMIT = 400;  
  }  

  public static void main(String args[]) {  
  Bike bike = new Bike();  
  bike.run();  
  }  
}  
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()

### Enum
```java
public enum Currency { 
  PENNY(1), NICKLE(5), DIME(10), QUARTER(25); 
  
  private int value; 

  private Currency(int value) { 
    this.value = value; 
  } 
}; 
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()

### Generics
```java
public class GenericMethodTest {
  // generic method printArray
  public static <T> void printArray( T[] inputArray ) {
    // Display array elements
    for(T element : inputArray) {
      System.out.printf("%s ", element);
    }
    System.out.println();
  }

  public static void main(String args[]) {
    // Create arrays of Integer, Double and Character
    Integer[] intArray = { 1, 2, 3, 4, 5 };
    Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
    Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };

    System.out.println("Array integerArray contains:");
    printArray(intArray);   // pass an Integer array

    System.out.println("\nArray doubleArray contains:");
    printArray(doubleArray);   // pass a Double array

    System.out.println("\nArray characterArray contains:");
    printArray(charArray);   // pass a Character array
  }
}
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()

### Exceptions
```java
try {
  FileInputStream file = new FileInputStream(fileName);
} catch(FileNotFoundException ex) {
  ex.printStackTrace();
} catch(IOException ex) {
  ex.printStackTrace();
} catch(Exception ex) {
  ex.printStackTrace();  
} finally {
  System.out.println("In the end...");
}
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()

### Annotations
```java
class Animal {
  public void eatMe() {
    System.out.println("You ate an animal!");
  }
}

class Chicken extends Animal {  
  @Override
  public void eatMe() {
    System.out.println("You ate a chicken!");
  }
}
```
 - [Placeholder]()
 - [Placeholder]()
 - [Placeholder]()
