### Writing files

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream my_file; // Creates an object that represents a file
  my_file.open("example.txt"); // The object opens the file called "example.txt"
  my_file << "Write this line to a file\n"; // Writes a string to the file
  my_file.close(); // Closes the object

  return 0;
}
```

#### Exercise
 - [exercise01.cpp](exercise-01/exercise01.cpp)

