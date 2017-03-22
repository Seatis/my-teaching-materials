# Recursion
What happens when a function calls itself? [Learn more here](
python.md)

## Materials & Resources
| Material | Time |
|:---------|-----:|
| *Khan academy series on iterative functions to Recursion:* |  |
| [Writing a Simple Factorial Program. (Python 2)](https://www.youtube.com/watch?v=ZyYp1V84Xqc&index=6&list=PL36E7A2B75028A3D6) | 8:08 |
| [Stepping Through the Factorial Program](https://www.youtube.com/watch?v=dn9XjHz33O8&index=7&list=PL36E7A2B75028A3D6) | 9:23 |
| [Flowchart for the Factorial Program](https://www.youtube.com/watch?v=EiR6cf8Towc&list=PL36E7A2B75028A3D6&index=8) | 5:35 |
| [Defining a Factorial Function](https://www.youtube.com/watch?v=JwO_25S_eWE&index=10&list=PL36E7A2B75028A3D6) | 10:05 |
| [Diagramming What Happens with a Function Call](https://www.youtube.com/watch?v=6qCQB8E5bkI&list=PL36E7A2B75028A3D6&index=11) | 9:11 |
| [Recursive Factorial Function](https://www.youtube.com/watch?v=o920mj0NbhE&index=12&list=PL36E7A2B75028A3D6) | 5:35 |
| [Comparing Iterative and Recursive Factorial Functions](https://www.youtube.com/watch?v=kx6DfrYfWnQ&list=PL36E7A2B75028A3D6&index=13) | 7:47 |
| [Recursive Fibonacci Example](https://www.youtube.com/watch?v=urPVT1lymzU&list=PL36E7A2B75028A3D6&index=17) | 7:36 |
| [Stepping Through Recursive Fibonacci Function](https://www.youtube.com/watch?v=zg-ddPbzcKM&index=18&list=PL36E7A2B75028A3D6) | 8:03 |
| | |
| [Fractals](https://www.youtube.com/watch?v=WFtTdf3I6Ug) | |
| [Green Fox Teaching Materials on Recursion](https://github.com/greenfox-academy/teaching-materials/tree/master/python/recursion) | ∞ |


### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [Benoit BM Mandelbrot: Fractals and the art of roughness](https://www.ted.com/talks/benoit_mandelbrot_fractals_the_art_of_roughness?language=en) | 17:09 |
|[Hanoi-tower](https://www.youtube.com/watch?v=5_6nsViVM00) | 7:18 |




## Material Review
 - recursion
 - base case

## Workshop


### Factorial with loop

```python
def factorial_iterative(number):
    product = 1
    for i in range(number):
        product *= i+1
    return product

print('5! is', factorial_iterative(5))
```



### Factorial with recursion

```python
def factorial(number):
    if number <= 1: #base case
        return 1
    else:
        return number * factorial(number-1)

print('5! is', factorial(5))
```

### Exercises

 - [01](basic_math_examples/counter.py)
 - [02](basic_math_examples/numberadder.py)
 - [03](basic_math_examples/sumdigit.py)
 - [04](basic_math_examples/power.py)	
 - [05](bunnies/bunny1.py)
 - [06](bunnies/bunny2.py)
 - [07](strings/string1.py)
 - [08](strings/string2.py)
 - [09](strings/string3.py)
 - [10](fibonacci/fibonacci.py)
 - 11: reproduce this:   
![11](drawing/graphic.png)
 - 12: reproduce this:   
![12](drawing/graphic2.png)