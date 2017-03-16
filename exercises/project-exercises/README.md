# Project Exercises

## Summary
 - [Anagram](#anagram)
 - [Palindrome builder](#palindrome-builder)
 - [Palindrome searcher](#palindrome-searcher)
 
## Anagram

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

[What the hell is a palindrome?](#palindrome-builder)

### Exercise

Create a function named **search palindrome** following your current language's style guide. It should take a string, search for palindromes that at least 3 characters long and return a list with the found palindromes.

### Examples

|input|output|
|:---:|:---:|
|"dog goat dad duck doodle never"|["og go", " dad ", "d d", "dood", "eve"]|
|"apple"|[]|
|""|[]|
