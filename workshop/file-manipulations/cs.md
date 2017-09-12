# File manipulation exercises

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[File read and write](https://www.youtube.com/watch?v=kGZD_k1M938)||
|[using keyword](https://www.youtube.com/watch?v=Dxbbtx-8MKw)|5:35|
|[exceptions](https://www.youtube.com/watch?v=DzUFm2FNeyo)|6:56|

## Optionals

| Material | Time |
|:---------|------:|
|[File read n write advanced](https://www.youtube.com/watch?v=HKqMqFJr4SY)|20:44|
|[File read with exception and fun](https://www.youtube.com/watch?v=LkpODZE2vmk)|5:26|
|[Runtime vs Compile time](https://stackoverflow.com/questions/846103/runtime-vs-compile-time)|1:30|
|[💪💪💪Custom exception](https://www.youtube.com/watch?v=ybd7nHiDCCY)|7:37|

## Material Review


 - `Files`
 - `ReadAllLines()` / `ReadAllText()`
 - `WriteAllLines()` / `WriteAllText()`
 - `StreamWriter`
 - `using`
 - `Dispose()`
 - Exception
 - Compile time error
 - Runtime error
 - Syntax error
 - Semantic error
 - `try`
 - `catch`
 - exception types
 - `throw`
 - `finally`
 - `Parse()`

## Workshop

### Exceptions

```c#
using System;

namespace Example
{
    class Program
    {
        public static void Main(string[] args)
        {
            var divisor = Constole.ReadLine();
            int result = 12 / divisor; // If the input value for divisor was 0 the program breaks
            Console.WriteLine(result); // The program doesn't reach this line if the input was 0
            Console-ReadLine();
        }
    }
}
```

The result if the input value was zero:

```
Exception unhandled!
System.DivideByZeroException: 'Attempted to divide by zero.'
```

Handle the exception:

```c#
using System;

namespace Example
{
    class Program
    {
        public static void Main(string[] args)
        {
            try  // Prevents the program breaking when attempting dividing by zero
            {
                var divisor = int.Parse(Console.ReadLine());
                int result = 12 / divisor; // If the input value for divisor was 0 the program breaks
                Console.WriteLine(result); // The program doesn't reach this line if the input was 0
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine("Can't divide by zero!"); // This line only runs if the input was 0
            }
            catch (Exception e)
            {
                Console.WriteLine("uuups, some serious thing happened!"); // This line only runs if uncatched exception generated
            }
            finally
            {
                Console.ReadLine();
            }
        }
    }
}
```

#### Exercises

 - [01 - DivideByZero.java](divide-by-zero/DivideByZero.java)

### Reading files

```c#
using System;
using System.IO;

namespace Example
{
    class Program
    {
        public static void Main(string[] args)
        {
            string path = @"./assets/lorem-psum.txt";
            try
            {
                // Reads the content from `lorem-psum.txt` in the `assets` folder line by line to a string List
                var content = File.ReadAllLines(path);
                Console.WriteLine(content[0]); // Prints the first line of the file
            }
            catch (Exception)
            {

                Console.WriteLine("Uh-oh, could not read the file!");
            }

            Console.ReadLine();
        }
    }
}
```

#### Exercises

 - [02 - PrintEachLine.java](print-each-line/PrintEachLine.java)
 - [03 - CountLines.java](count-lines/CountLines.java)

### Writing files

```c#
using System;
using System.IO;

namespace Example
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"./lorem-psum.txt";
            using (StreamWriter writer = new StreamWriter(path))
            {
                writer.WriteLine("Hello Alpaga!");
            }
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

