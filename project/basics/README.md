# Project Exercises

## Summary
 - [Anagram](#anagram)
 - [Palindrome builder](#palindrome-builder)
 - [Palindrome searcher](#palindrome-searcher)
 - [Guess my number](#guess-my-number)
 - [Josephus Problem](#josephus-problem)
 - [Armstrong number](#armstrong-number)

### Experience points
- Each project has a certain amount of experience points (XP) that can be earned by completing the project
- To level up and journey safely to the next week's challenges make sure you earn at least 3 XP
- *Tip: Go with 4XP if you're on __insane__ difficulty setting.*

## Anagram
*1XP*

### What the hell is an anagram?
> An anagram is direct word switch or word play, the result of rearranging the letters of a word or phrase to produce a new word or phrase, using all the original letters exactly once; for example, the word anagram can be rearranged into nag-a-ram.
> *[for more detail check [anagram](https://en.wikipedia.org/wiki/Anagram) on Wikipedia]*

### Exercise
Create a function named **is anagram** following your current language's style guide. It should take two strings and return a boolean value depending on whether its an anagram or not.

### Examples
|input 1|input 2|output|
|:-----:|:-----:|:---:|
|"dog"|"god"|true|
|"green"|"fox"|false|

## Palindrome builder
*1XP*

### What the hell is a palindrome?

> A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward, such as madam or racecar.
> *[for more detail check [palindrome](https://en.wikipedia.org/wiki/Palindrome) on Wikipedia]*

### Exercise

Create a function named **create palindrome** following your current language's style guide. It should take a string, create a palindrome from it and then return it.

### Examples

|input|output|
|:---:|:---:|
|""|""|
|"greenfox"|"greenfoxxofneerg"|
|"123"|"123321"|

## Palindrome searcher
*2XP*

[What the hell is a palindrome?](#palindrome-builder)

### Exercise

Create a function named **search palindrome** following your current language's style guide. It should take a string, search for palindromes that at least 3 characters long and return a list with the found palindromes.

### Examples

|input|output|
|:---:|:---:|
|"dog goat dad duck doodle never"|["og go", "g g", " dad ", "dad", "d d", "dood", "eve"]|
|"apple"|[]|
|""|[]|

## Guess my number
*2XP*

### Exercise

Write a program where the program chooses a number between 1 and 100. The player is then asked to enter a guess. If the player guesses wrong, then the program gives feedback and ask to enter an other guess until the guess is correct.
- Make the range customizable (ask for it before starting the guessing).
- You can add lives. (optional)

### Example
`I've the number between 1-100. You have 5 lives.`
> 20

`Too high. You have 4 lives left.`
> 10

`Too low. You have 3 lives left.`
> 15

`Congratulations. You won!`

## Josephus Problem
*2XP*

### What the hell is Josephus Problem?

> Flavius Josephus was a famous historian of the first century. During the Jewish-Roman war, he was among a band of 41 Jewish rebels trapped in a cave by the Romans. Preferring suicide to capture, the rebels decided to kill themselves. Using a method to form a circle and in clockwise direction everybody kills the person on his left side until everyone dies. But Josephus, wanted none of this suicide nonsense and therefore quickly calculated where he should stand in the circle so that he will be the last one (he knew who is the first one). So basicly Josephus Problem is when you have a circle of *n* people standing and you want to cross out every second person step-by-step until only one remains. 
> *[for more detail check [Josephus Problem](https://en.wikipedia.org/wiki/Josephus_problem) on Wikipedia]*

![](https://imgur.com/7f0jIDW.gif)

### Exercise
Write a function to solve Josephus Problem. The program should ask for a number, this number represents how many people are in the "game". The return value should be the number of the "winning" seat.

### Examples

|number of people|number of the winning seat|
|:---:|:---:|
|1|1|
|2|1|
|3|3|
|7|7|
|12|9|
|41|19|

## Armstrong number
*2XP*

### What is Armstrong number?
> An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
- Let's demonstrate this for a **4-digit number**: 1634 is a 4-digit number, raise each digit to the fourth power, and add: 1^4 + 6^4 + 3^4 + 4^4 = 1634, so it is an Armstrong number.
- For a **3-digit number**: 153 is a 3-digit number, raise each digit to the third power, and add: 1^3 + 5^3 + 3^3 = 153, so it is an Armstrong number.

### Exercise
Write a simple program to check if a given number is an armstrong number. The program should ask for a number. E.g. if we type 371, the program should print out:
```The 371 is an Armstrong number.```
