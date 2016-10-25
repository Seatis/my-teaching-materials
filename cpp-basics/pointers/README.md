#Pointers
*Underestanding the basics and usage of pointers in C++*

## Objectives
 - Understanding the difference between handing over a value or an address
 - Understanding the difference between pointers and references
 - Using pointers to pass arrays
 - Using pointers and void functions to operate on an array as opposed to returning a new one
 - Understanding the difference between heap and stack.
   - Scope and lifecycle of objects on heap and stack.
 - Understanding and using pointer arithmethics (eg.: iterating over an array)
 - Special cases:
   - Character arrays
   - Void pointers

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [Introduction to Pointers in C++, Tutorial on Pointers, C++ Pointers](https://www.youtube.com/watch?v=W0aE-w61Cb8) | 11:37 |
| [Buckys C++ Programming Tutorials - 38 - Introduction to Pointers](https://www.youtube.com/watch?v=Fa6S8Pz924k) | 6:07 |
| [Buckys C++ Programming Tutorials - 39 - Pass by Reference with Pointers](https://www.youtube.com/watch?v=_ja8iizm7nk) | 8:38 |
| [Buckys C++ Programming Tutorials - 41 - Pointers and Math](https://www.youtube.com/watch?v=dPAbm-3iAN4) | 6:04 |
| [C++/Game Tutorial 26: Stack vs Heap memory!](https://www.youtube.com/watch?v=woHnBfiBbhs) | 8:59 |
| [Pointers as function returns in C/C++](https://www.youtube.com/watch?v=E8Yh4dw6Diw) | 15:14 |
| [C++ Part 52 - Reference Parameters](https://www.youtube.com/watch?v=X9-a-MiMwEI) | 5:43 |


#### The next videos are in C
Things to know about C:
 - `#include<stdio.h>` is `#include<iostream>`
 - `cout <<` is `print`

| Material | Time |
|:---------|-----:|
| [Introduction to pointers in C/C++](https://www.youtube.com/watch?v=h-HBipu_1P0) | 10:06 | 
| [Working with pointers](https://www.youtube.com/watch?v=X1DcpcgSUXw) | 11:37 |
| [Pointer types, pointer arithmetic, void pointers](https://www.youtube.com/watch?v=JTttg85xsbo) | 10:56 |
| [Pointers to Pointers in C/C++](https://www.youtube.com/watch?v=d3kd5KbGB48) | 9:20 |
| [Pointers as function arguments - call by reference](https://www.youtube.com/watch?v=LW8Rfh6TzGg) | 14:15 |
| [Pointers and arrays](https://www.youtube.com/watch?v=ASVB8KAFypk) | 8:42 |
| [Arrays as function arguments](https://www.youtube.com/watch?v=CpjVucvAc3g) | 12:53 |
| [Character arrays and pointers - part 1](https://www.youtube.com/watch?v=Bf8a6IC1dE8) | 14:40 |
| [Character arrays and pointers - part 2](https://www.youtube.com/watch?v=vFZTxvUoZSU) | 10:00 |



## Material Review
 - Memory address
 - Global variable
 - Heap
 - Stack
 - pointer
 - pointer types
 - void pointers
 - `&` operator
 - `*` operator
 - Pass by refrenece with pointer
 - Return pointers
 - Reference Parameters

## Workshop
### Addresses and values
```cpp
#include <iostream>
using namespace std;


int main(int argc, char** argv){
	int a = 42; // An integer type variable called "a" that stores 42 as a value
	int *address_of_a = &a; // A pointer to integer type variable called "address_of_a" that stores the memory adress of the variable called "a"
	cout << "Value of variable \"a\": " << a << endl; // Prints: Value of variable "a": 42
	cout << "Value of pointer to variable \"a\": " << address_of_a << endl; // Prints: Value of pointer to variable "a": 0x7fff37922684
	cout << "Value of variable referenced by pointer \"address_of_a\": " << *address_of_a << endl; // Prints: Value of variable referenced by pointer "address_of_a": 42
	cout << "Address of variable \'a\': " << &a << endl; // Prints: Address of variable 'a': 0x7fff37922684
	return 0;
}
```
#### Exercises:

 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 - [06.cpp](workshop/06.cpp)
 - [07.cpp](workshop/07.cpp)
 - [08.cpp](workshop/08.cpp)

### Illustrating different modes of handing over variables to functions
 ```cpp
#include <iostream>
#include <string>
using namespace std;

void operateOnString(string *str){
	cout << "Variable \"str\": "<<  str << endl;
	cout << "Value of variable pointed to by variable \"str\" before operation: " << *str << endl;
	*str += 'A';
	cout << "Value of variable pointed to by variable \"str\" after operation: " << *str << endl;
}

string operateOnValue(string str2) {
	cout << "Address of variable \"str2\": " << &str2 << endl;
	str2 += 'A';
	cout << "Value of variable \"str2\" after operation: " << str2 << endl;
	return str2; 
}

void illustrateHandoverByValue(string str, string *str_original) {
	cout << "Values of both arguments: \"str\": " << str << " \"str_original\": " << str_original << endl;
	cout << "Values of the strings: \"str\": " << str << " \"str_original\": " << *str_original << endl;
	cout << "Addresses of both strings: \"str\": " << &str << " \"str_original\": " << str_original << endl;
	cout << "Are these addresses the same? ";
	if(&str == str_original) {
		cout << "true";
	} else {
		cout << "false";
	}
	cout << endl;
} 


int main(int argc, char** argv){
	cout << "\n\n";
	
	cout << "Illustrating a function operating on an object handed over by it's address!" << endl;
	string a = "kuty";
	cout << "Address of variable \"a\": " << &a << endl;
	operateOnString(&a);
	cout << endl << endl;	

	cout << "Illustrating a function operating on an object handed over by it's value!" << endl;
	string b = "kuty";
	cout << "Address of variable \"b\": " << &b << endl;
	cout << operateOnValue(b) << endl;	
	cout << endl << endl;
	
	cout << "Illustrating the difference between handing over a value or the object itself referenced by it's address!" << endl;
	string c = "kuty";
	cout << "Address of variable \"c\": " << &c << endl;
	illustrateHandoverByValue(c, &c);
	cout << endl << endl; 

	return 0;
}
```
#### Exercises:
 - [09.cpp](workshop/09.cpp)
 - [10.cpp](workshop/10.cpp)
 - [11.cpp](workshop/11.cpp)
 - [12.cpp](workshop/12.cpp)

#### Arrays and Pointers
```cpp
#include <iostream>

using namespace std;

int double_using_array_notation(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    array[i] *= 2;
  }
}

int double_using_pointer_notation(int* array, int length) {
  for (int i = 0; i < length; ++i) {
    *array *= 2;
    array += 1;
  }
}

int double_using_mixed_notation(int* array, int length) {
  for (int i = 0; i < length; ++i) {
    array[i] *= 2;
  }
}

void print_array(int array[], int length) {
  for (int i = 0; i < 6; ++i) {
    cout << array[i] << endl;
  }
}

int main() {
  int my_first_array[] = {1, 2, 3, 4, 5, 6};

  double_using_array_notation(my_first_array, 6);
  print_array(my_first_array, 6);

  int my_second_array[] = {1, 2, 3, 4, 5, 6};
  double_using_pointer_notation(my_second_array, 6);
  print_array(my_second_array, 6);

  int my_third_array[] = {1, 2, 3, 4, 5, 6};
  double_using_mixed_notation(my_third_array, 6);
  print_array(my_third_array, 6);

  return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int get_size(int array[]) {
  cout << "Size of the array in the function: " << (sizeof(array) / sizeof(*array)) << endl; // Don't work this way :(
}

int main() {
  int my_array[] = {1, 2, 3, 4, 5, 6};
  int* pointer = &my_array[0];

  cout << "Size of the array normaly: " << (sizeof(my_array) / sizeof(*my_array)) << endl; // prints 6

  get_size(my_array);

  cout << "Size of the array with pointer: " << (sizeof(pointer) / sizeof(*pointer)) << endl; // Don't work this way :(

  cout << "First element: " << *pointer << endl; // prints 1

  pointer += 4;

  cout << "Fifth element: " << *pointer << endl; // prints 5
  return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int filter_even(int* input, int input_length, int* output) {
  int output_index = 0;

  for (int i = 0; i < input_length; ++i) {
    if (input[i] % 2 == 0) {
      output[output_index] = input[i];
      output_index++;
    }
  }
}

int main() {
  int my_array[] = {1, 2, 3, 4, 5, 6};
  int my_empty_array[3];

  filter_even(my_array, 6, my_empty_array);

  for (int i = 0; i < 3; ++i) {
    cout << my_empty_array[i] << endl;
  }

  return 0;
}
```

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

