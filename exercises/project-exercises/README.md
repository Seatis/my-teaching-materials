# Project Exercises

## Summary
 - [Anagram](#anagram)
 - [Palindrome builder](#palindrome-builder)
 - [Palindrome searcher](#palindrome-searcher)
 - [Guess my number](#guess-my-number)

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
|input 1|input 2|outut|
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
|"dog goat dad duck doodle never"|["og go", " dad ", "d d", "dood", "eve"]|
|"apple"|[]|
|""|[]|

## Guess my number

### Exercise

Write a program where the program chooses a number between 1 and 10. The player is then asked to enter a guess. If the player guesses wrong, then the program gives feedback and ask to enter an other guess until the guess is correct.

 - You can make the range customizable.
 - You can add lives.

### Example
`I've the number between 1-100. You have 5 lives.`
> 20

`Too high. You have 4 lives left.`
> 10

`Too low. You have 3 lives left.`
> 15

`Congratulations. You won!`