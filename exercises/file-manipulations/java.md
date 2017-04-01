# File manipulation exercises

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[Handling Basic Exceptions and File Reading with Java 8](https://www.youtube.com/watch?v=b1A9kI2zSe4)| 31:56 |

## Material Review

 - `Path` and `Paths.get()`
 - `Files`
 - `readAllLines()`
 - `write()`
 - Exception
 - Compile time error
 - Runtime error
 - Syntax error
 - Semantic error
 - `try`
 - `catch`
 - exception types
 - `finally`

## Workshop

### Exceptions

```java
import java.util.Scanner;

public class UnhandledException {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int divisor = scanner.nextInt();

    int result = 12 / divisor; // If the input value for divisor was 0 the program breaks
    System.out.println(result); // The program doesn't reach this line if the input was 0
  }
}

```

The result if the input value was zero:

```
Exception in thread "main" java.lang.ArithmeticException: / by zero
    at UnhandledException.main(UnhandledException.java:8)
```

Handle the exception:

```java
import java.util.Scanner;

public class ErrorHandling {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int divisor = scanner.nextInt();

    try { // Prevents the program breaking when attempting dividing by zero
      int result = 12 / divisor; // If the input value for divisor was 0 it stops the try block
      System.out.println(result); // The program doesn't reach this line if the input was 0
    } catch (ArithmeticException e) {
      System.out.println("Can't divide by zero!"); // This line only runs if the input was 0
    }
  }
}

```

#### Exercises

 - [01 - DivideByZero.java](divide-by-zero/DivideByZero.java)

### Reading files

```java
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;

public class ReadFile {
  public static void main(String[] args) {
    try { // Required by Files.readAllLines(filePath);
      // Reads the content from `lorem-psum.txt` in the `assets` folder line by line to a String List
      Path filePath = Paths.get("assets/lorem-ipsum.txt");
      List<String> lines = Files.readAllLines(filePath);   
      System.out.println(lines.get(0)); // Prints the first line of the file
    } catch (Exception e) {
      System.out.println("Uh-oh, could not read the file!");
    }
  }
}
```

#### Exercises

 - [02 - PrintEachLine.java](print-each-line/PrintEachLine.java)
 - [03 - CountLines.java](count-lines/CountLines.java)

### Writing files

```java
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;

public class WriteFile {
  public static void main(String[] args) {
    List<String> content = new ArrayList();
    content.add("First line of my file");
    try { // Required by Files.write(filePath, content)
      // Creates a new file if not exists and overwrites it's content
      // The elements of the content lists will become the lines of the file
      Path filePath = Paths.get("assets/new-file.txt");
      Files.write(filePath, content);
    } catch (Exception e) {
      System.out.println("Uh-oh, could not write the file!");
    }
  }
}
```

#### Exercises

 - [04 - WriteSingleLine.java](write-single-line/WriteSingleLine.java)
 - [05 - WriteMultipleLines.java](write-multiple-lines/WriteMultipleLines.java)
 - [06 - CopyFile.java](copy-file/CopyFile.java)

### Decryption

#### Exercise

 - [07 - Doubled.java](decrypt-doubled/Doubled.java) | [duplicated-chars.txt](decrypt-doubled/duplicated-chars.txt)
 - [08 - ReversedLines.java](decrypt-reversed-lines/ReversedLines.java) | [reversed-lines.txt](decrypt-reversed-lines/reversed-lines.txt)
 - [09 - ReversedOrder.java](decrypt-reversed-order/ReversedOrder.java) | [reversed-order.txt](decrypt-reversed-order/reversed-order.txt)


#### Optional Hard Exercises

 - [10 - EncodedLines.java](decrypt-encoded/EncodedLines.java) | [encoded-lines.txt](decrypt-encoded/encoded-lines.txt)
 - [11 - Lottery.java](lottery/Lottery.java) | [otos.csv](lottery/otos.csv)

