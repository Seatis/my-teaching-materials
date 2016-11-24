# Misc
*Define classes, properties and methods, then creating instances and mutate them*

## Objectives

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [Buckys C++ Programming Tutorials - 30 - Function Overloading](https://www.youtube.com/watch?v=IAMzWp3kS_k) | 6:20 |
| [Buckys C++ Programming Tutorials - 50 - Operator Overloading](https://www.youtube.com/watch?v=PgGhEovFhd0) | 5:34 |
| [Buckys C++ Programming Tutorials - 51 - More on Operator Overloading](https://www.youtube.com/watch?v=q4vZIF-uMzs) | 5:57 |
| [C++ const Initializer Lists](https://www.youtube.com/watch?v=sruGkv3dQZQ) | 3:51 |
| [C++ Copy Constructors](https://www.youtube.com/watch?v=-_uSj6lrmZ0) | 3:41 |
| [C++ Copy Constructor Gotchas](https://www.youtube.com/watch?v=n4zZ7KxhmVM) | 8:17 |
| [C++ Deep and Shallow Copy Constructors](https://www.youtube.com/watch?v=YFcd1bojN8Q) | 9:04 |
| [Cognitive apprenticeship: Zerda Sparta w05 Command Line App (Hungarian)](https://www.youtube.com/watch?v=dKGOwkl1R8k) | 1:37:13 |

## Material Review
 - function overloading
 - operator overloading
 - const initializer list
 - copy constructor
 - shallow copy
 - deep copy

#### Excercises
Implement the game called Bulls and Cows

Please read the rules of the game:
https://en.wikipedia.org/wiki/Bulls_and_Cows

Features:
 - The game should generate a random 4 digit number
 - It should ask guesses in the standard input, than answer on the standard output
 - The answer should show the number of Cows and Bulls like: `Cows: 2, Bulls: 2`
 - If the guess is right it should print: `Congratulations: You win!`
 - If the player could not figure out the number in 10 rounds it should print: `Game over!`
 - Every invalid guess that is not a 4 digit number should raise an error like: `Please provide a 4 digit number` and re-request the guess

Try to use the concepts you have learned this week, you are free to use any
method or tool you find online. Try to separate responsibilites and create
small self-contained functions and classes that are only doing one thing.
Pay attention when you are naming things also be conscious about your commits
and commit messages.

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

