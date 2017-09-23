# Preprocessor macros, threads and mutex in C
*Learn how to use preprocessor macros, meet the multithreading techniques in C with mutexes*

## Objectives
- Know the concept of multithreaded programming in C
- Practice preprocessor macros
- Use mutex or semaphore in a multithreaded program

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine

### Training

#### Preprocessor macros
| Material | Duration |
|:---------|-----:|
| [The C Preprocessor](https://www.youtube.com/watch?v=pP4laGRP-c0) | 5:57 |
| [Preprocessor macro list](http://www.w3schools.in/c-tutorial/preprocessors/) | - |
| [An example of a microcontroller library - you can see the fact that half of the code is full of preprocessor macros](https://github.com/mkschreder/avr-ultimate-driver-pack/blob/master/uart.c) | - |


#### Threads and mutex
| Material | Duration |
|:---------|-----:|
| [Processes vs threads 1](https://www.youtube.com/watch?v=oIN488Ldg9k) | 4:06 |
| [Processes vs threads 2](https://www.youtube.com/watch?v=h_HwkHobfs0) | 7:35 |
| [Processes vs threads 3](https://www.youtube.com/watch?v=Dhf-DYO1K78) | 1:44 |
| [Mutual exclusion](https://en.wikipedia.org/wiki/Mutual_exclusion) | - |
| [Mutex lock](https://www.youtube.com/watch?v=9lAuS6jsDgE) | 1:17 |
| [```pthread.h```](http://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html) | - |
| [Threading basics](https://www.youtube.com/watch?v=nVESQQg-Oiw) | 4:44 |
| [```pthread_mutex_init()```]() | - |
| [```pthread_mutex_lock()``` and ```pthread_mutex_unlock()```](https://www.cs.nmsu.edu/~jcook/Tools/pthreads/library.html) | - |
| [```pthread_join()```](https://vcansimplify.wordpress.com/2013/03/08/pthread-tutorial-simplified/) | - |
| [Deadlock](http://www.codingtree.com/c/c-pthreads-deadlocks.html) | - |


#### Semaphores

| Material | Duration |
|:---------|-----:|
| [Semaphores](https://www.youtube.com/watch?v=KZU4ANBoLTY&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3&index=4) | 7:50 |
| [Mutex vs semaphores](https://www.youtube.com/watch?v=DvF3AsTglUU) | 6:59 |
| [Mutex is actually a binary semaphore](https://www.youtube.com/watch?v=TYnNKdf7cZM) | 13:23 |

#### Computer Science

| Material | Duration |
|:---------|-----:|
| [Keyboard and CLI's](https://www.youtube.com/watch?v=4RPtJ9UyHS0&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=23) | 11:23 |
| [Screens and 2D Graphic](https://www.youtube.com/watch?v=7Jr0SFMQ4Rs&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=24) | 11:33 |
| [PC Revolution](https://www.youtube.com/watch?v=M5BZou6C01w&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=26) | 10:14 |


## Material Review

### Preprocessor macros
- when does it compiles?
    - at the start of the compilation process
- why and when do we use them
- substitution
    - #include
    - #define/#undef
    - #ifdef/#ifndef
- inclusion
    - #if/#elif/#else/#endif
- compiler control
    - #error

### Threads, mutex and semaphore

- thread vs process
	- threads
		- within a process
		- shared memory
		- synchronizing problems when accessing shared resources
	- process
		- allocated memory
		- can contain multiple threads
- mutex vs semaphores
	- mutex
		- for avoiding mutual exclusion -> only one access to a shared resource
	- semaphore
		- paralell access to shared resource -> more than one access yet limited
- deadlock and mutual exclusion
	- mutual exclusion
		- shared resource is not allowed to access by more than one process at same time
	- deadlock
		- a situation in which process waiting for resource, which hold by another process , which in turn waiting for resource hold 		by another process. in this way all process waiting for resource form cycle, and no process can complete its execution



## Workshop
### Preprocessor macros
- [`#define`](Workshop/01.c)
- [`#ifdef/#ifndef`](Workshop/02.c)
- [`#if/#elif/#else`](Workshop/03.c)
- [`#error`](Workshop/Macros/04.c)

### Threads and mutex
- [joining_to_main_thread](Workshop/05.c)
- [color printer](Workshop/06.c)
- [mutex](Workshop/07.c)
- [semaphore](Workshop/08.c)
- [two_threads_with_delay](Workshop/09.c)

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

## Solutions
[Solutions](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop-hardware/solutions/solutions/macros-thread-mutex)