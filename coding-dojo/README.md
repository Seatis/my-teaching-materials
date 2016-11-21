# Coding Dojo
Get familiar with the TDD process through a strict Coding Dojo practice.

![red-green-refactor](red_green_refactor.jpg)

## Red - Green - Refactor
1. The facilitator demonstrates the red-green-refactor cycle with a simple example
2. The facilitator introduces the programming problem (kata) to solve. See [a list of katas to try below](#katas).
3. The facilitator writes a first test, makes sure it runs red. This is the first *Red* phase.
4. The first person taking the facilitator's seat writes the simplest possible code to pass the test. Encourage baby steps. This is the first *Green* phase.
5. The next person takes the seat at the keyboard and looks for ways to refactor: improve code quality while keeping current functionality.
6. The next person writes the next easiest - failing - test and the red-green-refactor circle starts again.

## Katas
### Get index
Create a function that takes a list and a value, and returns the index of that value in the list. If the value is not it the list, the function should return -1.

### Anagram
Create a function that takes two strings, and returns a boolean that should be `True` if the strings are anagrams and `False` otherwise.

### FizzBuzz
Write a program that prints the numbers from 1 to 100. But for multiples of three print "Fizz" instead of the number and for the multiples of five print "Buzz". For numbers which are multiples of both three and five print "FizzBuzz".

### Potter
Once upon a time there was a series of 5 books about a very English hero called Harry. (At least when this Kata was invented, there were only 5. Since then they have multiplied) Children all over the world thought he was fantastic, and, of course, so did the publisher. So in a gesture of immense generosity to mankind, (and to increase sales) they set up the following pricing model to take advantage of Harry's magical powers.

One copy of any of the five books costs 8 EUR. If, however, you buy two different books from the series, you get a 5% discount on those two books. If you buy 3 different books, you get a 10% discount. With 4 different books, you get a 20% discount. If you go the whole hog, and buy all 5, you get a huge 25% discount.

Note that if you buy, say, four books, of which 3 are different titles, you get a 10% discount on the 3 that form part of a set, but the fourth book still costs 8 EUR.

Potter mania is sweeping the country and parents of teenagers everywhere are queueing up with shopping baskets overflowing with Potter books. Your mission is to write a piece of code to calculate the price of any conceivable shopping basket, giving as big a discount as possible.

For example, how much does this basket of books cost?

 - 2 copies of the first book
 - 2 copies of the second book
 - 2 copies of the third book
 - 1 copy of the fourth book
 - 1 copy of the fifth book
(answer: 51.20 EUR)

#### Clues

You’ll find that this Kata is easy at the start. You can get going with tests for baskets of 0 books, 1 book, 2 identical books, 2 different books… and it is not too difficult to work in small steps and gradually introduce complexity.

However, the twist becomes apparent when you sit down and work out how much you think the sample basket above should cost. It isn’t 5*8*0.75+3*8*0.90. It is in fact 4*8*0.8+4*8*0.8. So the trick with this Kata is not that the acceptance test you’ve been given is wrong. The trick is that you have to write some code that is intelligent enough to notice that two sets of four books is cheaper than a set of five and a set of three.

You will have to introduce a certain amount of clever optimization algorithm. But not too much! This problem does not require a fully fledged general purpose optimizer. Try to solve just this problem well in order to share it for everyone or even in the ??? . Trust that you can generalize and improve your solution if and when new requirements come along.
