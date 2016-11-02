# Struct
*Creating structs and mutate them with functions*

## Objectives
 - Creating structs
 - Accessing and mutating properties on structs
 - Dynamically create structs and struct based datastructures
 - Define functions that are mutating and creating structs
 - Creating header files

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [38 Introduction to Structures in C++ CPP Programming Video Tutorials](https://www.youtube.com/watch?v=6gg9Xlv35-I) | 8:31 |
| [39 Arrow Operator with Pointers to Access Structure Members CPP Programming Video Tutorials](https://www.youtube.com/watch?v=jH2b6bKgrhs) | 4:40 |
| [40 Passing Structure to Functions by Value, Pointer (Address) C++ Video Tutorials For Beginners](https://www.youtube.com/watch?v=lVRtKPvgvTs) | 9:05 |
| [Header Files in C++](https://www.youtube.com/watch?v=jz0k_uHbwnk) | 11:49 |
| [Intro to C++: Structs](https://www.youtube.com/watch?v=DBQzxCHk9uI) | 21:31 |
| [Pointers and Structs](https://www.youtube.com/watch?v=_1ybxs60-Sc) (until 4:21) | 4:21 |
| [Lesson 18-Enumerations](https://www.youtube.com/watch?v=yA-bqGv-Q5Y) | 6:39 |

## Material Review
 - struct
 - property
 - mutate property
 - header file
 - pointers to structures
 - `->`
 - `#define`
 - `#ifndef`
 - `#endif`
 - `enum`

## Workshop
```cpp
#include <iostream>

using namespace std;

struct Student {
  int age;
  string name;
}

void print_student(Student& s) {
  cout << "Name: " << s.name << " Age: " << s.age << endl;
}

int main() {
  Studen john;
  john.age = 12;
  john.name = "John Doe";

  print_student(john);
 
  return 0;
}
```

### Exercises
 - [01.cpp](workshop/01.cpp)

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
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

