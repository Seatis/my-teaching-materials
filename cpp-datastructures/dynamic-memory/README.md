# Dynamic Memory
*Using dynamically allocated structures in memory*

## Objectives
 - Understandig the concept of memory allocation and deallocation.
 - Using the new and delete operators.
 - Understandig the lifecycle of memory and the concept of memory leak.

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [45 New and Delete Operators in C++ Dynamic Memory Allocation CPP Programming Video Tutorials](https://www.youtube.com/watch?v=gVGnOsB1n_o) | 4:55 |
| [46 Dynamically Allocating Arrays Depending on User Input in C++ CPP Programming Video Tutorials](https://www.youtube.com/watch?v=8XAQzcJvOHk) | 8:44 |
| [47 Avoiding Dangling Pointer Reference in C++ CPP Programming Video Tutorials](https://www.youtube.com/watch?v=frQ1uTnh6Io) | 5:34 |
| [C++/Game Tutorial 27: new, delete, and delete\[\]](https://www.youtube.com/watch?v=LMpkhZc17Z0) | 12:33 |
| [Pointers and dynamic memory - stack vs heap](https://www.youtube.com/watch?v=_8-ht2AKyH4) | 17:25 |
| [Pointers and Dynamic Memory in C++ (Memory Management)](https://www.youtube.com/watch?v=CSVRA4_xOkw) | 13:53 |
| [Memory leak in C/C++](https://www.youtube.com/watch?v=F2nrej6Kjww) | 17:54 |

## Material Review
 - `new`
 - `delete`
 - `delete[]`
 - Memory Leak

## Workshop
```cpp
#include <iostream>

using namespace std;

int main() {
  float* number = new float(1.2);
  
  cout << *number << endl;

  delete number;
 
  return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main() {
  int* array = new int[5];

  for (int i = 0; i < 5; ++i) {
    array[i] = i * 2;
  }

  for (int i = 0; i < 5; ++i) {
    cout << array[i] << endl;
  }

  delete[] array;
 
  return 0;
}
```

### Exercises
 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 - [06.cpp](workshop/06.cpp)
 - [07.cpp](workshop/07.cpp)
 - [08.cpp](workshop/08.cpp)

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

