# Big O notation

How to describe the complexity of an algorithm?

## Objectives
 - Understanding what the notation is for
 - Determine the complexity of an algorithm 
 - Experience differences in execution times

### Training
| Material | Duration |
|:---------|-----:|
|[A beginner's guide to Big O notation](https://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/) | reading |
|[Intro to algorithms](https://www.youtube.com/watch?v=HFLczUUHWNw) | 3:25 |
|[Big O notation by HackerRank](https://www.youtube.com/watch?v=v4cd1O4zkGw)| 8:36 |

## Material Review
 - What is a cost?
 - `O(1)`
 - `O(N)`
 - `O(N²)`
 - `O(2ᴺ)`
 - `O(log N)`

## Workshop

It might come handy to Google first `how to kill a process + [insert your platform here]` if you are not aware of it.

### Measure execution time

In this example we start a timer before executing time intensive commands, then stop it and display the difference.

[Measuring time](workshop/measure-time.py)

### Squared

Revisit the article why the squared 

[Squared time: O(N²)](workshop/measure-time.py)

### Exponential

Can we make dramatic changes by bumping up the amount of calculations?

[Exponential time: O(2ᴺ)](workshop/exponential.py)

