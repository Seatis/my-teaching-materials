### Hello World

```c
#include <stdio.h>

int main() {
  // Prints "Hello, World!" to the terminal window.
  printf("Hello, world!\n");

  return 0;
}
```

#### Print different type of values
```c
#include <stdio.h>

int main() {
  // Prints a string to the terminal window.
  printf("Hello, world!\n");

  // Prints an integer to the terminal window.
  printf("%d\n", 100);

  // Prints a floating point number to the terminal window.
  printf("%f\n", 3.14);
  
  return 0;
}
```

 - `\n`: inserts a new line character to the end of the lines
 - `%d`: substitutes with the following integer value
 - `%f`: substitutes with the floating point value

#### Exercise
 - [exercise01.c](exercise-01/exercise01.c)
