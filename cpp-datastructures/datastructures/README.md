# Data-structures
*Creating simple data-structures using struct and functions*

## Objectives
 - Define functions that are mutating and creating structs
 - Creating a stack implementation using functions and struct
 - Creating a linked list implementation using functions and struct

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [Pointers and Structs](https://www.youtube.com/watch?v=_1ybxs60-Sc) (the whole video) | 9:58 |
| [Data structures: Introduction to stack](https://www.youtube.com/watch?v=F1F2imiOJfk) | 8:25 |
| [Data structures: Array implementation of stacks](https://www.youtube.com/watch?v=sFVxsglODoo) | 13:08 |
| [Introduction to linked list](https://www.youtube.com/watch?v=NobHlGUjV3g) | 17:12 |
| [Data Structures: Introduction to Linked Lists](https://www.youtube.com/watch?v=pBrz9HmjFOs) | 13:39 |
| [How to Create a Linked List C++ Introduction to Linked Lists](https://www.youtube.com/watch?v=o5wJkJJpKtM) | 12:24 |

## Material Review
 - Pointers in structs
 - Linked list
 - Linked list operations
 - Stack
 - Stack operations

## Workshop
### Stack
Implement a stack data-structure that stores doubles in C++, and several functions that operate on stacks
Each stack should have size property that stores how many elements are in the stack.
#### Functions
##### Construct
```cpp
Stack* stack_construct(double input[], int size);
```
 - It should dynamically allocate the `Stack` instance
 - It should set the `size`
 - It should dynamically allocate the `double` array

##### Push
```cpp
void stack_push(Stack& stack, double value);
```
 - It should push the value to the end of the stack
 - It should increment the `size` by 1
 - It should reallocate the array inside by the incremented `size`, and copy it's values

##### Pop
```cpp
double stack_pop(Stack& stack);
```

 - It should return the value that was pushed the last time
 - It should decrement the `size` by 1
 - It should reallocate the array inside by the decremented `size`, and copy it's values
 
##### Is empty
```cpp
bool is_empty(Stack& stack);
```

 - It should return true if the stack is empty and false otherwise
 
### Optimized Stack
Implement a stack data-structure that stores doubles in C++, and several functions that operate on stacks
Each stack should have `size` property that stores how many elements are in the stack.
The length of the inner array should be independent form the `size`,
to optimize on reallocation, this case it does not need to reallocate each time on push.
#### Functions
##### Construct
```cpp
Stack* stack_construct(double input[], int size);
```
 - It should dynamically allocate the `Stack` instance
 - It should set the `size`
 - It should dynamically allocate the `double` array
 - The length of the allocated array should be independent from the `size`, to optimize on the reallocation of the array
 - It should allocate at least a double length array then the `size`
 - The length of the array should be always some power of two and at least 16 (16, 32, 64, 128, ...) 

##### Push
```cpp
void stack_push(Stack& stack, double value);
```
 - It should push the value to the end of the stack
 - It should increment the `size` by 1
 - If the `size` exceeds the 80% of the current allocated length of the array it should reallocate the size of the array to it's double

##### Pop
```cpp
double stack_pop(Stack& stack);
```

 - It should return the value that was pushed the last time
 - It should decrement the `size` by 1
 - It should not resize the array

### Vector
Implement an array like data structure called DoubleVector, that behaves like and array but it have
some predefined operations in functions.
It should store doubles.
It should have an inner array of doubles that stores the values.
Each vector should have `size` property that stores how many elements are in the stack.

#### Functions
##### Construct
```cpp
Vector* vector_construct(double input[], int size);
```
 - It should dynamically allocate the `Vector` instance
 - It should set the `size`
 - It should dynamically allocate the `double` array

##### At
```cpp
double vector_at(Vector& v, unsigned int index);
```
 - It should return the value inder the given index
 - It should return zero if the value is out of bound

##### Insert
```cpp
void vector_insert(Vector& v, unsigned int index, double value);
```
 - It should insert the value to the given index like:
   - array: `{1, 2, 3, 4}`
   - index: `2`
   - value: `8`
   - result: `{1, 2, 8, 3, 4}`
 - It should increment the `size` by one
 - It should reallocate the array

##### Remove
```cpp
void vector_remove(Vector& v, unsigned int index);
```
 - It should remove the element under the index
 - It should reallocate the array

##### Concat
```cpp
Vector* vector_concat(Vector& v1, Vector v2);
```
 - It should return a new Vector that has all the elements of v1 and v2 like:
   - v1: `{1, 2}`
   - v2: `{3, 4}`
   - return: `{1, 2, 3, 4}`
 - It should have the sum size of the vectors

### Linked list
Implement a linked list using structs that stores doubles
A struct called `Node` should represent one node in the list.
The linked lists should stored by a pointer that points to it's head.

#### Functions
##### Construct One
```cpp
Node* list_construct_one(double value);
```
 - It should set the next element to `nullptr`
 - It should set it's value

##### Length
```cpp
unsigned int list_length(Node& head);
```
 - It should return the size of the list

##### Get Last
```cpp
Node* list_get_last(Node& head);
```
 - It should return the last node

##### Append
```cpp
void list_append(Node& head, double value);
```
 - It should append a new node to the end of the list with the given value

##### At
```cpp
Node* list_at(Node& head, unsigned int index);
```
 - It should return the node with the given index counted from it's head

##### Insert
```cpp
void list_insert(Node& head, unsigned int index, double value);
```
 - It should insert a node to the given index

##### Find
```cpp
unsigned int list_find(Node& head, value);
```
 - It should return the index of the given value

##### Remove
```cpp
void list_remove(Node& head, double value);
```
 - It should remove the node with the given value

##### Concat
```cpp
void list_concat(Node& head, Node& other_list);
```
 - It should concat the other list to the and of the list

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

