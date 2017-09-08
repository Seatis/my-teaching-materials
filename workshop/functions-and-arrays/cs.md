# Functions and arrays
Dive deeper into *real* programming, reuse code and get to know more complex data structures


## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[Introduction to Arrays](https://www.youtube.com/watch?v=7sqUaw4g_iQ)|9:35|
|[Arrays](https://www.youtube.com/watch?v=RQ0JHMGiobo)|24:20|
|[Methods & Using Functions](https://www.youtube.com/watch?v=QwygwfqOHsI)|17:07| 
|[Foreach](https://www.youtube.com/watch?v=Vlhcgb9Co4s)|7:40|
|[Constant & ReadOnly](https://www.youtube.com/watch?v=cPrcVeTEQXI)|2:09|
|[Debugging in VisualStudio](https://www.youtube.com/watch?v=7ab4z9u7Q_I)|16:15|


### Optional
Additional material, if the above is still unclear.

| Material | Time |
|:-------- |-----:|
|[Arrays again](https://www.youtube.com/watch?v=3UcJGikWJxs)|7:25|
|[Jagged/Multidimensional array](https://www.youtube.com/watch?v=T0Zg7kQ3RVE)|8:11|


## Material Review
- Declaring
  - const
  - readonly
  - initial values of arrays `{}`
  - `new` keyword
- Functions
  - void or return a value
  - can be used to compartmentalise code (make more readable)
  - have own variables
  - take parameters
- Arrays
  - can be measured (have `Length`)
  - can be iterated through
  - type definition (e.g. `string[]`)
  - CopyTo
  - sort
  - foreach statement
- Debugging
  - breakpoint
  - step over
  - watches
  - evaluate expression


## Workshop

### Functions

```c#
using System;

namespace Example
{
    class Program
    {
        public static void GreetingFunction(){
            Console.WriteLine("hello");
        }
        
        static void Main(string[] args)
        {
            GreetingFunction();
            Console.ReadLine();
        }
    }
}
```

#### Excercises
-  [Doubling](exercises/functions/doubling/Doubling.cs)
-  [Greeter function](exercises/functions/greet/Greet.cs)
-  [Append a](exercises/functions/append-a/AppendA.cs)
-  [Summing](exercises/functions/sum/Sum.cs)
-  [Factorial](exercises/functions/factorio/Factorio.cs)
-  [Print arguments](exercises/functions/printer/Printer.cs)

### Arrays

```c#
using System;

namespace Example
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = {1, 2, 3 , 8};
            
            // Print the second element of the array
            Console.WriteLine(array[1]);
            
            // Print all the array elements
            for(int i = 0; i < array.Length; i++)
            {
                Console.WriteLine(array[i]);
            }
            Console.ReadLine();
        }
    }
}
```

#### Excercises
-  [Third](exercises/arrays/third/Third.cs)
-  [Compare Length](exercises/arrays/compare-length/CompareLength.cs)
-  [Sum elements](exercises/arrays/sum-elements/SumElements.cs)
-  [Change element](exercises/arrays/change-element/ChangeElement.cs)
-  [Increment element](exercises/arrays/increment-element/IncrementElement.cs)
-  [Print elements](exercises/arrays/print-all/PrintAll.cs)
-  [Matrix](exercises/arrays/diagonal-matrix/DiagonalMatrix.cs)
-  [Double items](exercises/arrays/double-items/DoubleItems.cs)
-  [Colors](exercises/arrays/colors/Colors.cs)
-  [Append a](exercises/arrays/append-a/AppendA.cs)
-  [Swap elements](exercises/arrays/swap-elements/SwapElements.cs)
-  [Sum all elements](exercises/arrays/sum-all/SumAll.cs)
-  [Reverse list](exercises/arrays/reverse/Reverse.cs)


## Individual Workshop Review
Please follow the styleguide: [Our C# styleguide](../../styleguide/cs.md)

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
