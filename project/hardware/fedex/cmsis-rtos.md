Read the [fuc*in manual](https://www.keil.com/pack/doc/cmsis/RTOS/html/group__CMSIS__RTOS__ThreadMgmt.html)!!! Try to understand the functions you can work with.

```
#include "cmsis_os.h"

void Thread (void const *arg);                             // function prototype for a Thread
osThreadDef (Thread, osPriorityNormal, 3, 0);              // define Thread and specify to allow three instances

void ThreadCreate_example (void) {
  osThreadId id1, id2, id3;

  id1 = osThreadCreate (osThread (Thread), NULL);          // create the thread with id1
  id2 = osThreadCreate (osThread (Thread), NULL);          // create the thread with id2
  id3 = osThreadCreate (osThread (Thread), NULL);          // create the thread with id3
  if (id1 == NULL) {                                       // handle thread creation for id1
    // Failed to create the thread with id1
  }
  if (id2 == NULL) {                                       // handle thread creation for id2
    // Failed to create the thread with id2
  }
  if (id3 == NULL) {                                       // handle thread creation for id3
    // Failed to create the thread with id3
  }
  :
  osThreadTerminate (id1);                                  // stop the thread with id1
  osThreadTerminate (id2);                                  // stop the thread with id2
  osThreadTerminate (id3);                                  // stop the thread with id3
}
```
You can find example codes like this in the link above. Your task is to
learn how to use these example codes. Try the functions out! Think of something simple and create it! For example do a simple project on your STM board where you use the CMSIS RTOS functions and the BSP for printing out things on the LCD screen with threads.
