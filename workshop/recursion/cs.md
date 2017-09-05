# Recursion
What happens when a function calls itself?

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [How Recursion Works](https://www.youtube.com/watch?v=EpU0opEeP6g) | 6:24 |
| [Algorithms: Recursion](https://www.youtube.com/watch?v=KEEKn7Me-ms)| 5:40 |
| [c# Recursion](https://www.youtube.com/watch?v=wXvJSv3lS1c) 16:41 |
| [Fractals](https://www.youtube.com/watch?v=WFtTdf3I6Ug) | 4:12 |
| [Green Fox Teaching Materials on Recursion](cs.md) | ∞ |




### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [Hanoi-tower](https://www.youtube.com/watch?v=5_6nsViVM00)| 7:18 |
| [Benoit BM Mandelbrot: Fractals and the art of roughness](https://www.ted.com/talks/benoit_mandelbrot_fractals_the_art_of_roughness?language=en) | 17:09 |


## Material Review
 - recursion
 - base case

## Workshop


### Factorial with loop

```c#
public static int FactorialWithLoop(int n) {
  int factorial = 1;
  for (int i = 1; i  < n + 1; i++) {
    factorial *= i;
  }
  return factorial;
}
```


### Factorial with recursion

```c#
public static int FactorialWithRecursion(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * FactorialWithRecursion(n - 1);
  }
}
```

### Exercises

 - [01 Counter](counter/Counter.cs)
 - [02 Numberadder](numberadder/Numberadder.cs)
 - [03 Sumdigit](sumdigit/Sumdigit.cs)
 - [04 Power](power/Power.cs)
 - [05 Bunnies](bunnies/Bunny1.cs)
 - [06 Bunnies again](bunnies2/Bunny2.cs)
 - [07 Strings](strings/String1.cs)
 - [08 Strings again](strings2/String2.cs)
 - [09 Strings again and again](strings3/String3.cs)
 - [10 Fibonacci](fibonacci/Fibonacci.cs)
 - 11: reproduce this:   
![11](drawing/graphic.png)
 - 12: reproduce this:   
![12](drawing/graphic2.png)
