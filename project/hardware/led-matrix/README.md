# LED matrix controller
*Create a multithreading LED matrix controller*

## Objectives
- Learn inter-thread communication methods
- Practice STM32 peripheral usage

## Materials & Resources

| Material | Duration |
|:---------|---------:|
|[Multi-dimensional Arrays in C](https://www.tutorialspoint.com/cprogramming/c_multi_dimensional_arrays.htm)| - |
|[Electronic Basics #5: How to Multiplex](https://www.youtube.com/watch?v=uQMUPhyoXoE)| 4:53 |
|[Lecture 1, unit 1: Introduction to Concurrency](https://www.youtube.com/watch?v=iKtvNJQoCNw&index=3&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3)| 12:02 |
|[Lecture 1, unit 2: Races and synchronization](https://www.youtube.com/watch?v=Nen47rzZMZY&index=2&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3)| 7:04 |
|[Lecture 1, unit 3: Locks](https://www.youtube.com/watch?v=r_-w_lRndR8&index=1&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3)| 8:59 |
|[Lecture 2, unit 1: Introduction to Semaphores](https://www.youtube.com/watch?v=KZU4ANBoLTY&index=4&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3)| 7:50 |
|[Lecture 2, Unit 2: semaphore values](https://www.youtube.com/watch?v=lLJErQna3no&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3&index=5)| 5:43 |
|[Lecture 4, unit 1: Deadlock](https://www.youtube.com/watch?v=4qTZBrsIxMo&list=PLrWfHqCHBgVJ4jPMXnv2tbB6zg5uegbc3&index=8)| 4:54 |
|[Mutex Lock](https://www.youtube.com/watch?v=9lAuS6jsDgE)| 1:17 |
|[CMSIS-OS mutex](https://www.keil.com/pack/doc/cmsis/RTOS/html/group__CMSIS__RTOS__MutexMgmt.html)| - |
|[CMSIS-OS message queue](https://www.keil.com/pack/doc/cmsis/RTOS/html/group__CMSIS__RTOS__Message.html)| - |

## Material review
- LED matrix multiplexing
- 2D arrays
- Race condition
- Mutex
- Semaphore
- Deadlock
- Message queue
- Other inter-thread communication methods
  - Memory pool
  - Signal events
  - Mail queue

## Workshop
[LED matrix datasheet](http://www.tme.eu/hu/Document/361f1f02acd9affe00be9c253ebe9536/LMD20057AUE-101A.pdf)

### LED matrix driver with multiple threads
Using mutexes.

### Change animation speed with a potentiometer
Using message queues.

### Characters on the matrix
Show characters on the LED matrix.

### Characters from the network
Running a socket server and receiving strings.

## Solution
[Solution](#)
