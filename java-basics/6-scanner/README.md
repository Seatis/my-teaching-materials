# Usage of the Scanner class

## Objectives
- Just a little practice on the Scanner class

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
| [Scanner tutorial](https://www.youtube.com/watch?v=aNm8DK_1ApU) | 14:43 |
| [Random number tutorial](https://www.youtube.com/watch?v=AhwIYAXPASw) | 5:14 |


## Material Review


## Workshop
### Scanner

#### Exercise 01
Create a program, that asks the user's name and then greet it!

#### Exercise 02 - Guess my number
The program randomly choses a number and then gives hints and/or goads the user for not determining it

##### Sample Operation
```
Enter a top number in the range, or 0?
```
> 64

```
Okay, I've got a number.  You should be able to figure that out in 6 goes, let's begin.  
Guess?
```
> 32

```
Nope, you're low. You've got 5 guesses left.  Guess?
```
> 48

```
Nope, you're high. You've got 4 guesses left.  Guess?
```
> 40

```
Nope, you're high. You've got 3 guesses left.  Guess?
```
> 35

```
Nope, you're low. You've got 2 guesses left.  Guess?
```
> 37

```
Nope, you're high and you've just repeated yourself, what a waste. Last chance.  Guess?
```
> 37

```
What are you thick?  You just guessed 37.  Guess?
```
> 37

```
Ugh, you tried that before! Guess?
```
> 38

```
Ever considered being a fortune teller?  Guess not.  Guess?
```
> 36

```
Yippee, I was running out of insults.

Try again?  Enter a top number in the range, or 0?
```
> 1

```
Okay, I've got a number.  You should be able to figure that out in 1 go, let's begin.  

Guess?
```
> 1

```
Well done, you managed to guess it in 1 go.

Try again?  Enter a top number in the range, or 0?
```
> 0

```
It was fun playing.  Bye!
```

## Individual Workshop Review
Neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)

Key questions to consider:
- Are the directory structure and the names of the files correct?
- Are the includes placed at the top of the file?
- Does the code follow the right level of indentation?
- Are all of the brackets positioned correctly?
- Are the whitespaces where they should be; and not where they shouldn't?
- Is the code *pithy* (meaning to the point, not superfluous or un-necessary)?
  - Not using extra variables (unless needed to understand the logic)
  - Not confusingly or overly commented
  - Does the computation instead of repeating stuff (aka *code duplication*)?
  - Does not contain empty blocks
  - Non repetitive and where needing to repeat a block instead, carved out to a function?
- Are there un-used variables - added during development but later made surplus to requirements through simplification?
- Is the commentary in the code at the right level?
  - Can one deduce the purpose of a block from the variable naming combined with the explanation
  - Are there *Watch outs* warnings just in case somebody later maintains the code and needs to beware of something tricky (or not obvious)?
- Are the data types used right for the purpose
- Is the "commit message" meaningful?
- Do the names conform to the Styleguide?
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
    - functions: lowerCamelCase(paramsLowerCase)
