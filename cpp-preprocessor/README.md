# Preprocessor

## Objectives

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [Preprocessor tutorial on cplusplus.com](http://www.cplusplus.com/doc/tutorial/preprocessor/)| Read |
| [C++ Tutorial 18: Preprocessor Directives] (https://www.youtube.com/watch?v=CLPzcFaA-Dk) | 5:37 |
| [C++ Tutorial 18: Preprocessor Commands] (https://www.youtube.com/watch?v=xro8-rObtP0)| 15:43|



## Material Review

###Examples
#### Basic define
```cpp
#define TABLE_SIZE 123

int main(){
	int a = TABLE_SIZE;
	return 0;
}
```

####Function like Macros
```cpp
#include <iostream>

#define max(a,b) (a < b ? b : a)

int main() {
	std::cout << max(12,34) << std::endl;
	return 0;
}
```

####Difference between funtion like Macro & functions
```cpp
#include <iostream>
#define dmax(a,b) (a<b?b:a)

unsigned int function_max(unsigned int a, unsigned int b){
	return a<b?b:a;
}


// Let's check how much the macro cares about type safety and how many times I have to define it. 
// And what's up with the function.

int main() {
	unsigned int a = 12;
	unsigned int b = 24;
	std::cout << function_max(a,b) << std::endl;

	int c = -2;
	int d = -44;
	char e = 2;
	char f = 4;
	std::cout << function_max(c,d) << std::endl;
	std::cout << function_max(e,f) << std::endl;
	std::cout << dmax(c,d) << std::endl;
	std::cout << dmax(e,f) << std::endl;
	return 0;
}
```

####Pre-defined macro values
```cpp
#include <iostream>


int main() {
	std::cout << "in " << __FILE__ << ": @line:" << __LINE__ << std::endl;
	std::cout << __cplusplus << std::endl;
	std::cout << "in " << __FILE__ << ": @line:" << __LINE__ << std::endl;
	return 0;
}
```

####Using pre-defined macro values & different definitions
```cpp
#include <iostream>

#ifdef __DEBUG
// What is for(;;); good for?
// Basically: it's a completely empty for loop.
// It doesn't do anything, but it keeps the process alive.
// This enables us to attach a debugger if something goes wrong.
// Even if we did not attach it before we started running the program.
	#define MyAssert0(a) if(!(a) ){std::cout << "Assertion failed: (" << #a << ") in:  " << __FILE__ << " at: " << __LINE__ << std::endl; for(;;);}
	#define MyAssert1(a, msg) if(!(a)) {std::cout << "Assertion failed: (" << #a <<") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << std::endl; for(;;);}
	#define MyAssert2(a, msg, p1) if(!(a)) {std::cout << "Assertion failed: (" << #a <<") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << ' ' << p1 << std::endl; for(;;);
	#define MyAssert3(a, msg, p1, p2) if(!(a)) {std::cout << "Assertion failed: (" << #a <<") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << ' ' << p1 << ' ' << p2 << std::endl; for(;;);}
#elif defined(__LOGGING)
	#define MyAssert0(a) if(!(a) ){std::cout << "Assertion failed: (" << #a << ") in:  " << __FILE__ << " at: " << __LINE__ << std::endl;}
	#define MyAssert1(a, msg) if(!(a)) {std::cout << "Assertion failed: ("<< #a << ") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << std::endl;}
	#define MyAssert2(a, msg, p1) if(!(a)) {std::cout << "Assertion failed: ("<< #a << ") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << ' ' << p1 << std::endl;}
	#define MyAssert3(a, msg, p1, p2) if(!(a)) {std::cout << "Assertion failed: ("<< #a << ") in: " << __FILE__ << "at: " << __LINE__ << " | " << msg << ' ' << p1 << ' ' << p2 << std::endl;}
#elif defined (__RELEASE)
	#define MyAssert0(a)
	#define MyAssert1(a, msg)
	#define MyAssert2(a, msg, p1)
	#define MyAssert3(a, msg, p1, p2)
#else
	#define MyAssert0(a) if(!(a))for(;;);
	#define MyAssert1(a, msg) if(!(a))for(;;);
	#define MyAssert2(a, msg, p1) if(!(a))for(;;);
	#define MyAssert3(a, msg, p1, p2) if(!(a))for(;;);
#endif

int main(){
	int smaller_number = 2;
	int larger_number = 22;
	MyAssert1(smaller_number > larger_number,"smaller_number: " << smaller_number << " larger_numer:" << larger_number);
	return 0;
}

```


#### Excercises
- [01.cpp](workshop/01.cpp)
- [02.cpp](workshop/02.cpp)
- [03.cpp](workshop/03.cpp)
- [04.cpp](workshop/04.cpp)
- [05.cpp](workshop/05.cpp)
- [06.cpp](workshop/06.cpp)
- [07.cpp](workshop/07.cpp)
- [08.cpp](workshop/08.cpp)
- [09.cpp](workshop/09.cpp)
- [10.cpp](workshop/10.cpp)
- [11.cpp](workshop/11.cpp)
- [12.cpp](workshop/12.cpp)





Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)
## Individual Workshop Review

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

