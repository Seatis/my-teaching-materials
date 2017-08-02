# Project Exercises

## Summary
 - [Anagram](#anagram)
 - [Palindrome builder](#palindrome-builder)
 - [Palindrome searcher](#palindrome-searcher)
 - [Guess my number](#guess-my-number)
 - [Josephus Problem](#josephus-problem)

### Experience points
- Each project has a certain amount of experience points (XP) that can be earned by completing the project
- To level up and journey safely to the next week's challenges make sure you earn at least 2 XP
- *Tip: Go with 3XP if you're on __insane__ difficulty setting.*

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

### Exercise
Write a function to solve Josephus Problem. The return value should be the number of the "winning" seat. The program should ask for a number, this number represents how many people are in the "game".
There are two additional solutions to this Problem:
- first one is when you use arrays and some basic mathematics
- second one is with binary numbers (here you can also use arrays but in this case it it optional)

### What the hell is Josephus Problem?

> Flavius Josephus was a famous historian of the first century. During the Jewish-Roman war, he was among a band of 41 Jewish rebels trapped in a cave by the Romans. Preferring suicide to capture, the rebels decided to form a circle and to kill every remaining person until no one was left. But Josephus, wanted none of this suicide nonsense and therefore quickly calculated where he should stand in the circle so that he can survive.
> *[for more detail check [Josephus Problem](https://en.wikipedia.org/wiki/Josephus_problem) on Wikipedia]*

### Examples

|input|output|
|:---:|:---:|
|1|1|
|2|1|
|3|3|
|7|7|
|12|9|
|41|19|
