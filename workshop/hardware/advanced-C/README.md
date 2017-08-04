# Algorithms

*The study of algorithms is interesting because it is a new field, with a rich tradition*

## Objectives

- learn how to create and code specific algorithms
- be prepared for tricky interview questions

### Materials & Resources

#### Call stack
| Material        | Duration    |
| ------------- |:-------------:|
| [Call stack](https://www.youtube.com/watch?v=Q2sFmqvpBe0)     | 6:25 |  
| [Stack vs heap](https://www.youtube.com/watch?v=_8-ht2AKyH4)     | 17:25 |  

#### Data storing techniques
| Material        | Duration    |
| ------------- |:-------------:|
| [Linked list](https://www.youtube.com/watch?v=NobHlGUjV3g)   |17:12 |
| [Stack](https://www.youtube.com/watch?v=FNZ5o9S9prU)   |5:58 |

#### Algorithms
| Material        | Duration    |
| ------------- |:-------------:|
| [7 Steps to Solve Algorithm Problems](https://www.youtube.com/watch?v=GKgAVjJxh9w)    | 8:06|
| [What is an algorithm](https://www.youtube.com/watch?v=6hfOvs8pY1k)     | 4:57    |
| [Josephus problem](https://www.youtube.com/watch?v=uCsD3ZGzMgE&t=330s)     | 13:57 |   
| [Euclid's method](https://www.youtube.com/watch?v=JUzYl1TYMcU&t=102s)   | 4:09    |   
| [Cocktail shaker sort](https://www.youtube.com/watch?v=njClLBoEbfI)   | 0:41 |   
| [The sieve of Eratosthenes](https://www.youtube.com/watch?v=V08g_lkKj6Q)   |5:30 |
| [Big O](https://www.youtube.com/watch?v=v4cd1O4zkGw)   |8:36 |
| [Recursion](https://www.youtube.com/watch?v=KEEKn7Me-ms&t=75s)     | 6:25 |  
| [Memoization](https://www.youtube.com/watch?v=a7EjmdQzPqY)     | 6:25 | 

#### Advanced - if you are very interested in the algorithms topic
| Material        | Duration    |
| ------------- |:-------------|
| [Brute-force search](https://www.youtube.com/watch?v=vtnpzDPgaU0)     | 6:43 |  
| [Binary search](https://www.youtube.com/watch?v=P3YID7liBug)     | 6:21 |
| [Linear search](https://www.youtube.com/watch?v=CX2CYIJLwfg)     | 3:31 |
| [Merge sort](https://www.youtube.com/watch?v=KF2j-9iSf4Q)     | 9:52 |
| [Heap sort](https://www.youtube.com/watch?v=MtQL_ll5KhQ)     | 1:59|
| [Bubble sort](https://www.youtube.com/watch?v=lyZQPjUT5B4)     | 5:15|
| [Selection  sort](https://www.youtube.com/watch?v=Ns4TPTC8whw)     | 7:06|

| classification of algorithms |explanation |example|
| ------------- |:-------------:| -----:|
| *constant*  | the times stays constant during run time | accessing array index, pushing and poping on stack |
| *log N*  | gets slightly slower as N grows | binary search |
| *N*     | if N is doubled the running time is doubled as well      |   linear search |
| *N log N* | when N doubles the running time is more than doubles (but not much more)  |  merge sort, heap sort |
| *quadratic* | when N doubles the running time is fourfold |    bubble sort, selection sort |
| *cubic* | when N doubles the running time is eightfold     | triple nested loop |
| *exponential* | when N doubles the running time squares     | brute-force search |



#### Material review
- Euclid's method
- The sieve of Eratosthenes
- Josephus problem
- Data structures
    - arrays (sieve of Eratosthenes)
        - the size of the array is known
        - each element can be accesed
    - linked lists
        - nodes and links
        - head points to the first node of the list
        - changing the order of items
        - add and delete an element
    - stacks
        - O(1)
        - LIFO
        - push, pop, top, IsEmpty
        - undo operation
    - queues
        - O(1)
        - FIFO
        - rear, front
        - enqueue(push), dequeue(pop), peek(top), IsEmpty
    - min
    - max
    - average
    - moving average
    - call stack
        - store return address
        - recurion
        - memoization
            - dynamic programming

##### Exercises
##### Euclid's algorithm
First implement Euclid's algorithm to find the greatest common divisor. Don't use modulus. When you have a functional algorithm:
- check out the values that the program computes when *x* and *y* are not positive
- try to count how many statements are executed when you run the program with two positive numbers, print out or store  the values of *x* and *y*
- **Advanced task:** compute the greatest common divisor of three integers (*x, y and z*)

##### Moving average
Cearte an array and fill it with integers:
- find the minimum value of the array
- find the maximum value of the array
- calculate the average and the moving average

##### Linked lists
Implement a linked list using some resources from the internet, your goal is to understand how they work. Take your time don't rush just to finish this exercise.

##### Josephus problem
Write a program to solve Josephus problem using arrays.
