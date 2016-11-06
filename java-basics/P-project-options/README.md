# Module 03 #P - Projects for Demos
_NOTE if you are reading this right now, be ware, we are not done! (But may we also say well done for looking ahead.)_

By now, we've covered the basics of most programming languages and that means we can write something interesting.  We have a collection of ideas here for you to choose from; or, with a well reasoned argument, we Mentors might be convinced by you to try something else.

For the projects we're looking for something that:-
- Must (meaning it has to)
  - Use one or more functions
  - Employs Loops
  - Can be called with different parameters so as to generate different results
- Should (you have some *choice* here)
  - Employ strings and some string manipulation
  - Involve arrays
- Could (this is at your discretion)
  - Work like a game
  - Be inspired by something from Codewars, the exercises, the ideas proposed here.

These projects can be refined for the demos at the end of the week.


## Materials & Resources
N/A

## Assignment Review
N/A


## Workshops
So here below are *our" ideas

### Challenge: Palindrome Builder (Simple)
Take any input, validate whether it's a palindrome and output the value in reverse.  The program must operate as a game, asking a series of questions and then determining the output.  It must also reverse the capitalisation of start and end.

Note the &gt;&gt;&gt; is the function's output.

####Sample Operation
&gt;&gt;&gt;What do you want to do [1=Test if such is a Palindrome, 0=Quit]?
1
&gt;&gt;&gt;Enter the phrase please? 
Mark is here

&gt;&gt;&gt;Ereh si kram
&gt;&gt;&gt;Nope, not a palindrome.

&gt;&gt;&gt;What do you want to do [1=Generate A Palindrome, 2=Test if such is a Palindrome, 0=Quit]?
2
&gt;&gt;&gt;Enter the phrase please? 
Able I was ere I saw elba.
&gt;&gt;&gt;Able I was ere I saw elba.
&gt;&gt;&gt;Yup, it's a palindrome

&gt;&gt;&gt;What do you want to do [1=Generate A Palindrome, 2=Test if such is a Palindrome, 0=Quit]?
0
&gt;&gt;&gt;Bye!

### Challenge: Prime Factors (Simple)
Enter a numeric value and report back the prime factors.

Note the &gt;&gt;&gt; is the function's output.

####Sample Operation
&gt;&gt;&gt;Enter a number to test, or 0 to Quit?
12
&gt;&gt;&gt;"12" has the following factors: 2 3 3
&gt;&gt;&gt;Or by count:-
&gt;&gt;&gt;"2" - 1 (once)
&gt;&gt;&gt;"3" - 2 times

&gt;&gt;&gt;Enter a number to test, or 0 to Quit?
120
&gt;&gt;&gt;"120" has the following factors: 2 2 3 3 5
&gt;&gt;&gt;Or by count:-
&gt;&gt;&gt;"2" - 2 times
&gt;&gt;&gt;"3" - 2 times
&gt;&gt;&gt;"5" - 1 (once)

&gt;&gt;&gt;Enter a number to test, or 0 to Quit?
17
&gt;&gt;&gt;"17" is a prime number

&gt;&gt;&gt;Enter a number to test, or 0 to Quit?
0
&gt;&gt;&gt;Bye!

### Challenge: Guess my number 
The program randomly choses a number and then gives hints and/or goads the user for not determining it

Note the &gt;&gt;&gt; is the function's output.

####Sample Operation
&gt;&gt;&gt;Enter a top number in the range, or 0?
64

&gt;&gt;&gt;Okay, I've got a number.  You should be able to figure that out in 6 goes, let's begin.  
&gt;&gt;&gt;Guess?
32

&gt;&gt;&gt;Nope, you're high. You've got 5 guesses left.  Guess?
48

&gt;&gt;&gt;Nope, you're high. You've got 4 guesses left.  Guess?
40

&gt;&gt;&gt;Nope, you're low. You've got 3 guesses left.  Guess?
35

&gt;&gt;&gt;Nope, you're high. You've got 2 guesses left.  Guess?
37

&gt;&gt;&gt;Nope, you're high and you've just repeated yourself, what a waste. Last chance.  Guess?
37

&gt;&gt;&gt;What are you thick?  You just guessed 37.  Guess?
37

&gt;&gt;&gt;Ugh, you tried that before! Guess?
38

&gt;&gt;&gt;Ever considered being a fortune teller?  Guess not.  Guess?
36

&gt;&gt;&gt;Yippee, I was running out of insults.

&gt;&gt;&gt;Try again?  Enter a top number in the range, or 0?
1

&gt;&gt;&gt;Okay, I've got a number.  You should be able to figure that out in 1 go, let's begin.  
&gt;&gt;&gt;Guess?
11

&gt;&gt;&gt;Well done, you managed to guess it in 1 go.
&gt;&gt;&gt;Try again?  Enter a top number in the range, or 0?
0
&gt;&gt;&gt;It was fun playing.  Bye!


### Challenge: Rotate a Matrix
Take any input and then rotate the matrix.

Note the &gt;&gt;&gt; is the function's output.

####Sample Operation
&gt;&gt;&gt; Enter a matrix and terminate with the symbol !
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
!

&gt;&gt;&gt;
&gt;&gt;&gt;-- 1st Rotation
&gt;&gt;&gt;41 31 21 11
&gt;&gt;&gt;42 32 22 12
&gt;&gt;&gt;43 33 23 13
&gt;&gt;&gt;44 34 24 14
&gt;&gt;&gt;-- 2nd Rotation
&gt;&gt;&gt;44 43 42 41
&gt;&gt;&gt;34 33 32 31
&gt;&gt;&gt;24 23 22 21
&gt;&gt;&gt;14 13 12 11
&gt;&gt;&gt;-- 3rd Rotation
&gt;&gt;&gt;14 24 34 44
&gt;&gt;&gt;13 23 33 43
&gt;&gt;&gt;12 22 32 42
&gt;&gt;&gt;11 21 31 41

&gt;&gt;&gt; Enter a matrix and terminate with the symbol !
11 12 13
21 22 23
31 32 33
!
&gt;&gt;&gt;
&gt;&gt;&gt;-- 1st Rotation
&gt;&gt;&gt;31 21 11
&gt;&gt;&gt;32 22 12
&gt;&gt;&gt;33 23 13
&gt;&gt;&gt;-- 2nd Rotation
&gt;&gt;&gt;33 32 31
&gt;&gt;&gt;23 22 21
&gt;&gt;&gt;13 12 11
&gt;&gt;&gt;-- 3rd Rotation
&gt;&gt;&gt;13 23 33
&gt;&gt;&gt;12 22 32
&gt;&gt;&gt;11 21 31

&gt;&gt;&gt; Enter a matrix and terminate with the symbol !
dogs cats
bats rats
!
&gt;&gt;&gt;
&gt;&gt;&gt;-- 1st Rotation
&gt;&gt;&gt;bats dogs
&gt;&gt;&gt;rats cats
&gt;&gt;&gt;-- 2nd Rotation
&gt;&gt;&gt;rats bats
&gt;&gt;&gt;cats dogs
&gt;&gt;&gt;-- 3rd Rotation
&gt;&gt;&gt;cats rats
&gt;&gt;&gt;dogs bats

&gt;&gt;&gt; Enter a matrix and terminate with the symbol !
!

&gt;&gt;&gt; Bye

####Extra challenge
Handle a jagged array, for example 

11 12 13 14
21 22 23
31 32 33 34 35
!

&gt;&gt;&gt;31 21 11
&gt;&gt;&gt;32 22 12
&gt;&gt;&gt;33 23 13
&gt;&gt;&gt;34    14
&gt;&gt;&gt;35
... etc.



### Challenge: Combinatorics
Stefan is a board game developer who has the option to use a couple of different sided dice.  Of course he can use 6 sided dice, but he can also use 8, 12, etc.  The thing is, for the various game play options, he wants to stack the percentages a certain way and therefore needs to see what sums occur with a frequency to match his "design".

Note the &gt;&gt;&gt; is the function's output.

####Sample Operation
&gt;&gt;&gt;Enter the number of dice sides.  0 to end; add an ! if you want to see all the combinatorics
4 4!

&gt;&gt;&gt; You asked for a listing of all the combinatorics ...
&gt;&gt;&gt; 1 + 1 
&gt;&gt;&gt; 1 + 2
&gt;&gt;&gt; 1 + 3
&gt;&gt;&gt; 1 + 4
&gt;&gt;&gt; 2 + 1 
&gt;&gt;&gt; 2 + 2
&gt;&gt;&gt; 2 + 3
&gt;&gt;&gt; 2 + 4
&gt;&gt;&gt; 3 + 1
&gt;&gt;&gt; 3 + 2
&gt;&gt;&gt; 3 + 3
&gt;&gt;&gt; 3 + 4
&gt;&gt;&gt; 3 + 4
&gt;&gt;&gt; 4 + 1
&gt;&gt;&gt; 4 + 2 
&gt;&gt;&gt; 4 + 3
&gt;&gt;&gt; 4 + 4
&gt;&gt;&gt;
&gt;&gt;&gt; Total combinations = 16
&gt;&gt;&gt; Sum   Occurs   Probability
&gt;&gt;&gt;   2        1      6.25%
&gt;&gt;&gt;   3        2     12.50%
&gt;&gt;&gt;   4        3     18.75%
&gt;&gt;&gt;   5        4     25.00%
&gt;&gt;&gt;   6        3     18.75%
&gt;&gt;&gt;   7        2     12.50%
&gt;&gt;&gt;   8        1      6.25%



### Challenge: Monster Dodge 'Ems
This is a old standard for playing with multi-dimensional arrays.  You have a game board and you have to populate it with "monsters" who if they get you, you're toast.  But monsters can be blocked by walls and will be destroyed if they run into other monsters, hit traps you lay or run into swamps that are also randomly distributed when the game starts.

Note the &gt;&gt;&gt; is the function's output.

#### Sample Operation

&gt;&gt;&gt; Enter game board size (up to 50 square), or ! to stop?
10
&gt;&gt;&gt; Enter number of monsters, or ! to stop?
4
&gt;&gt;&gt; Enter level of difficulty (1 to 5) or ! to stop?
1
&gt;&gt;&gt; Generating initial matrix
&gt;&gt;&gt;
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         *
&gt;&gt;&gt; 1
&gt;&gt;&gt; 2       X  
&gt;&gt;&gt; 3   @   W
&gt;&gt;&gt; 4     W             
&gt;&gt;&gt; 5
&gt;&gt;&gt; 6   W
&gt;&gt;&gt; 7 *
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=2.
&gt;&gt;&gt; @=is You. !=Trap. X=Swamp. W=Wall. Press A=Left. W=Up. D=Right. X=Down. To lay a trap, type !.
&gt;&gt;&gt; Your move?
X!
&gt;&gt;&gt; Moved Down, Trap laid.
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         
&gt;&gt;&gt; 1         *
&gt;&gt;&gt; 2       X  
&gt;&gt;&gt; 3       W
&gt;&gt;&gt; 4   !@W             
&gt;&gt;&gt; 5
&gt;&gt;&gt; 6 * W
&gt;&gt;&gt; 7 
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=1.
&gt;&gt;&gt; @=is You. !=Trap. X=Swamp. W=Wall. Press A=Left. W=Up. D=Right. X=Down. To lay a trap, type !.
&gt;&gt;&gt; Your move?
W
&gt;&gt;&gt; Moved Up
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         
&gt;&gt;&gt; 1         
&gt;&gt;&gt; 2       X * 
&gt;&gt;&gt; 3    @  W
&gt;&gt;&gt; 4   ! W             
&gt;&gt;&gt; 5 *
&gt;&gt;&gt; 6   W
&gt;&gt;&gt; 7 
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=1.
&gt;&gt;&gt; @=is You. !=Trap. X=Swamp. W=Wall. Press A=Left. W=Up. D=Right. X=Down. To lay a trap, type !.
&gt;&gt;&gt; Your move?
hit the return key, no move.
&gt;&gt;&gt; Moved Up
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         
&gt;&gt;&gt; 1         
&gt;&gt;&gt; 2       X* 
&gt;&gt;&gt; 3    @  W
&gt;&gt;&gt; 4   ! W             
&gt;&gt;&gt; 5  *
&gt;&gt;&gt; 6   W
&gt;&gt;&gt; 7 
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=1.
&gt;&gt;&gt; @=is You. !=Trap. X=Swamp. W=Wall. Press A=Left. W=Up. D=Right. X=Down. To lay a trap, type !.
&gt;&gt;&gt; Your move?
A
&gt;&gt;&gt; Moved Left, 1 monster drowned in the swamp.
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         
&gt;&gt;&gt; 1         
&gt;&gt;&gt; 2       X 
&gt;&gt;&gt; 3   @   W
&gt;&gt;&gt; 4   ! W             
&gt;&gt;&gt; 5   *
&gt;&gt;&gt; 6   W
&gt;&gt;&gt; 7 
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=1.
&gt;&gt;&gt; @=is You. !=Trap. X=Swamp. W=Wall. Press A=Left. W=Up. D=Right. X=Down. To lay a trap, type !.
&gt;&gt;&gt; Your move?
W
&gt;&gt;&gt; Moved Up, Last monster destroyed by your trap. You won
&gt;&gt;&gt;  0123456789
&gt;&gt;&gt; 0         
&gt;&gt;&gt; 1         
&gt;&gt;&gt; 2       X 
&gt;&gt;&gt; 3   @   W
&gt;&gt;&gt; 4   ! W             
&gt;&gt;&gt; 5   *
&gt;&gt;&gt; 6   W
&gt;&gt;&gt; 7 
&gt;&gt;&gt; 8
&gt;&gt;&gt; 9
&gt;&gt;&gt; Traps left=1.
&gt;&gt;&gt; Play Again (Y/N)?


### Challenge: Hangman
This is a 2 person game, one person enters a value.  And the other person then has to guess.

Note the &gt;&gt;&gt; is the function's output.

#### Sample Operation

&gt;&gt;&gt; Enter the word to guess?
One Love
&gt;&gt;&gt; Good choice sir, "One Love" it is.  Press "Enter" and I'll scroll the display.
User presses "Enter" key
&gt;&gt;&gt; STARTING!!!
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;      m m     |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    _ _ _   _ _ _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
H
&gt;&gt;&gt; Sorry, there are no "H"s.
&gt;&gt;&gt;
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    _ _ _   _ _ _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt; Enter a letter?
L
&gt;&gt;&gt; Yup, there's a(n) "L".
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    _ _ _   L _ _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
O
&gt;&gt;&gt; Well done, there are 2 "O"s.
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ _   L O _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
W
&gt;&gt;&gt; Nope, "W"s we have not.
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ _   L O _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
Y
&gt;&gt;&gt; Nope, "Y", why not!
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ _   L O _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
X
&gt;&gt;&gt; Nope, "X", might mark the spot, but here it definitely does not! It's not looking good mate!
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ _   L O _ _
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
E
&gt;&gt;&gt; Well done, there are 2 "E"s.
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ E   L O _ E
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
B
&gt;&gt;&gt; Nope, to "B" or not to be, we'll it's looking like it's not to be.
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ E   L O _ E
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
B
&gt;&gt;&gt; Nope, I guess "C" stands for "see you later".  Think man! One more wrong guess and it's my toes and I'm toast!
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O _ E   L O _ E
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?
N
&gt;&gt;&gt; Yup, there's a(n) "L".  Think man! One more wrong guess and it's curtains for me!
&gt;&gt;&gt;       +------+
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;       0      |
&gt;&gt;&gt;       |      |
&gt;&gt;&gt;     /+++\    |
&gt;&gt;&gt;    / +++ \   |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;      | |     |
&gt;&gt;&gt;              |
&gt;&gt;&gt;              |
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;    O N E   L O _ E
&gt;&gt;&gt;   +----------+
&gt;&gt;&gt;
&gt;&gt;&gt; Enter a letter?

I think I'll leave it there (it's a cliffhanger)... Does he live or does he die?  Who knows... Mwaahahah.

#### Extra ideas
- There should a cache of messages to send depending upon where the player is in the game
  - not guessing right
  - same letter again, ugh, you're playing with the poor guy's life.
- Watch for singular and plurals (note how he says there are 2 and there is a(n))


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
