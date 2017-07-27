# Expressions and Control flow chapter two
*Meet the base elements of the C language by implementing small programs*

## Objectives
 - Understanding the Compiler
 - Using basic types
 - Creating and reading expressions
 - Declaring and defining variables
 - Using variables and mutate values
 - Understanding conditionals
 - Using while and for loops
 - Casting Types

## Materials & Resources

### Environment
  - Make sure that Code::Blocks is installed on your machine

### Training


#### C programming language

| Material | Duration |
|:---------|-----:|
| [switch statement](https://www.youtube.com/watch?v=qZRP5hKGHrs) | 7:30 |
| [switch statement](http://www.w3schools.in/c-tutorial/decision-making/switch/) | - |
| [switch vs if](http://www.geeksforgeeks.org/switch-vs-else/) | - |
| Logical operators |-|
| [Basics](https://www.youtube.com/watch?v=PO3BibcbkK8) | 5:44 |
| [Or](https://www.youtube.com/watch?v=brC8O7AeCFA) | 5:44 |
| [List of operators](http://www.w3schools.in/c-tutorial/operators/) | - |
| Loops |-|
| [while loop](https://www.youtube.com/watch?v=7pAXm7WEA2I) | 8:28 |
| [while loop](http://www.w3schools.in/c-tutorial/loops/while/) | - |
| [do-while loop](https://www.youtube.com/watch?v=eU6no0EEJM0) | 10:42 |
| [do-while loop](http://www.w3schools.in/c-tutorial/loops/do-while/) | - |
| [for loop](https://www.youtube.com/watch?v=FPjLbPu5BsQ) | 5:19 |
| [for loop](http://www.w3schools.in/c-tutorial/loops/for/) | - |
| [break](https://www.youtube.com/watch?v=JKVc02-GmGs) | 6:26 |
| [continue](https://www.youtube.com/watch?v=4XaaIGBdhaw) | 4:47 |
| [Loop control statements](http://www.w3schools.in/c-tutorial/loops/) | - |
| [Why never use goto](https://tr1.cbsistatic.com/hub/i/2015/05/07/294fc704-f487-11e4-940f-14feb5cc3d2a/goto.png) | - |

## Material Review


### C programming language

- switch
- while loop
- do while loop
- for loop


### While / Do - While / For
```c_cpp
int a = 0;
while (a < 5) {
    a += 1;
    printf("%d\n", a);
}

do {
    a += 1;
    printf("%d\n", a);
} while (a < 5);

for (a = 0; a < 5; a++) {
    printf("%d\n", a);
}
```

#### Excercises
Please do the excercises with while && do-while && for
 - [01.c](Workshop/01.c)
 - [02.c](Workshop/02.c)
 - [03.c](Workshop/03.c)
 - [04.c](Workshop/04.c)

### Switch

 ```
 switch (expressions){

 case (condition_1):
     execute your code;
 case (condition_2):
     execute your code;
 ...
 defaul:
     execute your code;
 }
 ```

#### Excercises

 - [05.c](Workshop/05.c)
 - [06.c](Workshop/06.c)
 - [07.c](Workshop/07.c)
 - [08.c](Workshop/08.c)
 - [09.c](Workshop/09.c)

### If vs. Switch
 Programming languages provide various constructs to support this
 requirement, e.g., the if-statement (which often supports checking against a single value) and the switchstatement
 (which supports the checking against a set of values). Measurements show that approximately
 every fifth statement is a selection statement. The last sentence sums up great why should we talk about it.

 You can already tell that switch is unnecessary, there is not such a task or problem where you have to use switch-statement. One of the main reasons using switch-statement is compiler optimalization. Right now it might not be such a big deal, but it is an important skill to know how to optimalize a code or what can you do to lower the run time. I have to mention that switch-statement also requiers less developer effort in certain situations.

 Common constraints on the use of the switch-statements include:
 - the value must be known at translation time
 - and that value must be representable as an integer type

#### Excercise

 - [10.c](Workshop/10.c)

##### Advanced

- [11.c](Workshop/11.c)
- [12.c](Workshop/12.c)
- [13.c](Workshop/13.c)
- [14.c](Workshop/14.c)
- [15.c](Workshop/15.c)
- [euclid.c](Workshop/euclid.c)
- [pascal.c](Workshop/pascal.c)
- [project.c](Workshop/project.c)

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](https://github.com/greenfox-academy/teaching-materials/blob/master/styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
