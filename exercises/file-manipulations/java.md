# File manipulation exercises

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[Handling Basic Exceptions and File Reading with Java 8](https://www.youtube.com/watch?v=b1A9kI2zSe4)| 31:56 |

## Material Review
- Exception
- `try`
- `catch`
- `Path` and `Paths.get()`
- `Files`
- `readAllLines()`
- `write()`


## Reading files

```java
try {
      // Reads the content from `lorem_ipsum.txt` in the `assets` folder line by line to a String List
      Path filePath = Paths.get("assets/lorem_ipsum.txt");
      List<String> lines = Files.readAllLines(filePath);   
    } catch (Exception e) {
      System.out.println("Uh-oh, an error happend: " + e.getClass());
    }
```

#### Exercise
 - [Lotto.java](read_lotto_csv/Lotto.java) | [otos.csv](read_lotto_csv/otos.csv)


### Decryption
#### Exercise
 - [Doubled.java](decrypt_function_doubled/Doubled.java) | [duplicated-chars.txt](decrypt_function_doubled/duplicated-chars.txt)
 - [ReversedLines.java](decrypt_function_reversed_lines/ReversedLines.java) | [reversed-lines.txt](decrypt_function_reversed_lines/reversed-lines.txt)
 - [ReversedOrder.java](decrypt_function_reversed_order/ReversedOrder.java) | [reversed-order.txt](decrypt_function_reversed_order/reversed-order.txt)
 - [EncodedLines.java](decrypt_function_encoded_lines/EncodedLines.java) | [encoded-lines.txt](decrypt_function_encoded_lines/encoded-lines.txt)
