# File manipulation exercises

## Materials & Resources

| Material | Time |
|:---------|-----:|
|[File read and write](https://www.youtube.com/watch?v=kGZD_k1M938)|5:09|
|[using keyword](https://www.youtube.com/watch?v=Dxbbtx-8MKw)|5:35|
|[exceptions](https://www.youtube.com/watch?v=DzUFm2FNeyo)|6:56|
|[exceptions(reading)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/exceptions/exception-handling)|3:00|

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
 - `@` and `\`

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
            // If the input value for divisor was 0 the program breaks
            int result = 12 / divisor;
            // The program doesn't reach this line if the input was 0
            Console.WriteLine(result);
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
                // If the input value for divisor was 0 the program breaks
                int result = 12 / divisor;
                // The program doesn't reach this line if the input was 0
                Console.WriteLine(result);
            }
            catch (DivideByZeroException e)
            {
                // This line only runs if the input was 0
                Console.WriteLine("Can't divide by zero!");
            }
            catch (Exception e)
            {
                // This line only runs if uncatched exception generated
                Console.WriteLine("uuups, some serious thing happened!");
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

 - [01 - DivideByZero.cs](divide-by-zero/DivideByZero.cs)

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
                // Prints the first line of the file
                Console.WriteLine(content[0]);
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

 - [02 - PrintEachLine.cs](print-each-line/PrintEachLine.cs)
 - [03 - CountLines.cs](count-lines/CountLines.cs)

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

 - [04 - WriteSingleLine.cs](write-single-line/WriteSingleLine.cs)
 - [05 - WriteMultipleLines.cs](write-multiple-lines/WriteMultipleLines.cs)
 - [06 - CopyFile.cs](copy-file/CopyFile.cs)

### Decryption

#### Exercise

 - [07 - Doubled.cs](decrypt-doubled/Doubled.cs) | [duplicated-chars.txt](decrypt-doubled/duplicated-chars.txt)
 - [08 - ReversedLines.cs](decrypt-reversed-lines/ReversedLines.cs) | [reversed-lines.txt](decrypt-reversed-lines/reversed-lines.txt)
 - [09 - ReversedOrder.cs](decrypt-reversed-order/ReversedOrder.cs) | [reversed-order.txt](decrypt-reversed-order/reversed-order.txt)


#### Optional Hard Exercises

 - [10 - EncodedLines.cs](decrypt-encoded/EncodedLines.cs) | [encoded-lines.txt](decrypt-encoded/encoded-lines.txt)
 - [11 - Lottery.cs](lottery/Lottery.cs) | [otos.csv](lottery/otos.csv)

