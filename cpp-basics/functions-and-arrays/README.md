# Functions and Arrays
*Meet the base elements of the C++ language by implementing small programs*

## Objectives
 - Defining and calling functions
 - Iterating on arrays

## Materials & Resources
### Environment
 - Install Eclipse IDE C/C++ on your system!
	- http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/lunasr1
 - Windows help for installing:
	- https://www.youtube.com/watch?v=TXbuATMlVNY

### Training
| Material | Time |
|:---------|-----:|
| [Introduction to Array](https://www.youtube.com/watch?v=odTejLbwbnc) | 6:35 |
| [Introduction to Functions](https://www.youtube.com/watch?v=4bgabzer4OE) | 7:09 |
| [Function Parameters](https://www.youtube.com/watch?v=WqukJuBnLQU) | 6:39 |
| [Default Function Parameters](https://www.youtube.com/watch?v=QHk_hg5NOU4) | 5:11 |
| [Inline Function](https://www.youtube.com/watch?v=TGwl3tJYFRg) | 3:54 |
| [Local, Global Variable Scopes](https://www.youtube.com/watch?v=kMdoS47ySjs) | 8:19 |
| [Break](https://www.youtube.com/watch?v=S6WkTenfEHk) | 6:08 |
| [Continue](https://www.youtube.com/watch?v=VYEhDnQ-2mE) | 6:14 |
| [Switch](https://www.youtube.com/watch?v=AqV9_7c9X7s) | 11:35 |
| [Multiple Return Statements](https://www.youtube.com/watch?v=jNfSTNrGItM) | 3:59 |
| [Passing an Array to a Function](https://www.youtube.com/watch?v=mnaD9bH6y6A) | 4:49 |
| [Const Keyword with Functions and Arrays](https://www.youtube.com/watch?v=SVggWRRzPRE) | 6:46 |
| [Sizeof](https://www.youtube.com/watch?v=QXPh65KtDPw) | 4:34 |
| [Strings](https://www.youtube.com/watch?v=3-v_RigflHs) | 5:48 |
| [Recursive Functions and Recursion](https://www.youtube.com/watch?v=bmTn2mkfxuE) | 5:12 |

## Material Review
 - Array
 - Index
 - Function
 - Function paramerter
 - `return`
 - Inline function
 - Scope
 - Local variable
 - `break`
 - `continue`
 - `switch`
 - `sizeof`
 - Recursion

## Workshop
### Arrays and sizeof
```cpp
int myArray = {1, 2, 3, 4, 5, 6};

cout << myArray[3]; // 4

myArray[1] = 15;

double myDouble = 4.5;

cout << sizeof(myDouble) // 8

```
 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 - [06.cpp](workshop/06.cpp)
 - [07.cpp](workshop/07.cpp)
 - [08.cpp](workshop/08.cpp)

### Functions
```cpp
void greet() {
  cout << "Hello!";
}

int main() {
  greet();
}
```

```cpp
void sayNumber(int number) {
  cout << number;
}

int main() {
  sayNumber(15);
}
```

```cpp
int add(int a, int b) {
  return a + b;
}

int main() {
  cout << add(1, 2);
}
```
 - [09.cpp](workshop/09.cpp)
 - [10.cpp](workshop/10.cpp)
 - [11.cpp](workshop/11.cpp)
 - [12.cpp](workshop/12.cpp)
 - [13.cpp](workshop/13.cpp)
 - [14.cpp](workshop/14.cpp)
 - [15.cpp](workshop/15.cpp)
 - [16.cpp](workshop/16.cpp)


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

