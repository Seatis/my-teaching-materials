#Algorithms
*Understanding basic algorithm theory*

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [2. Dynamic Connectivity](https://www.youtube.com/watch?v=XxyG_aPHjvg) | 10:18 |
| [3. Quick Find](https://www.youtube.com/watch?v=4SZTsQO9d6k) | 10:13 |
| [4. Quick Union](https://www.youtube.com/watch?v=H0bkmI1Xsxg) | 7:44 |
| [5. Quick Union Improvements](https://www.youtube.com/watch?v=RE-Xho-gwlo) | 12:57 |
| [1. Analysis of Algorithms Introduction](https://www.youtube.com/watch?v=ZN-nFW0mEpg) | 8:10 |
| [2. Observations](https://www.youtube.com/watch?v=DRf8kcrpkVA) | 10:00 |
| [3. Mathematical Models](https://www.youtube.com/watch?v=bp0QafRl7hc) | 12:43 |
| [4. Order of Growth Classifications](https://www.youtube.com/watch?v=pssp_N8HPVA) | 14:33 |
| [5. Theory of Algorithms](https://www.youtube.com/watch?v=ZA3rmAlYNzw) | 11:30 |
| [6. Memory](https://www.youtube.com/watch?v=Yv1qoT7K-RA) | 8:06 |

## Material Review
 - Eager evaluation or Greedy evaluation
 - Lazy Approach
 - Input data vs running time
 - Cost model
 - Order of growth:
   - 1
   - log N
   - N
   - N log N
   - N^2
   - N^3
   - 2^N
 - Binary search
 - Best, Worst, Average case
 - Big Theta
 - Big O
 - Big Omega
 - Optimal Algorithm

## Workshop

### Binary Search
Implement the binary search algorithm as a method, in a programing language of your favor.
The method should take a sorted array of numbers and a number. (The array can be any array like container like vector)
The method should return true if the array consists the number and false otherwise.
The method should have better than linear order of growth based on the input array size.

### Quick Union
Implement the quick union algorithm as an object.
It should take an array length in its constructor.
It should have a `unite` method that takes two indexes of nodes and connects them.
It should have a `find` method that takes two indexes of nodes and returns a boolean if they are in the same group.
It shoudl have a `getGroups` method that returns a list of all groups.

### Percolation

#### Percolation checking
Watch [this](https://www.youtube.com/watch?v=zeF_d5ok_1k)
Create a function that determinate if an N*N grid percolates or not.
The function should take a N*N Matrix of numbers (0 and 1). If the element of
the Matrix is 0 it means it blocks, and 1 if it is vacant.
The function should return a boolan that determinates if the Matrix percolates.
The Matrix percolates if top and bottom are connected by vacant elements.

#### Find percolation treshold

Create a program that generates a N*N Matrix and starts to add random vacant elements to it.
The program should check the percolation on each iteration. The loop should stop if the Matrix percolates.
The program should store the fraciton of the vacant elements to the all elements in the Matrix.
It should generate this fraction for a given number of Matrices and print the average treshold.
