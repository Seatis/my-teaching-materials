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

### Reading files

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream my_file; // Creates an object that represents a file
  my_file.open("example.txt"); // The object opens the file called "example.txt"
  string file_content;
  my_file >> file_content; // Reads a line from the file and puts it into the variable called file_content
  my_file.close(); // Closes the object

  return 0;
}
```

#### Exercise
 - [exercise02.cpp](exercise-02/exercise02.cpp) | [second-exercise.txt](exercise-02/second-exercise.txt)

### Multiple lines and errors
```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream my_file; // Creates an object that represents a file
  my_file.open("example.txt"); // The object opens the file called "example.txt"
  string file_content;
  if (my_file) {
    
  }

  return 0;
}
```

#### Exercise
 - [exercise03.cpp](exercise-03/exercise03.cpp)
 - [exercise04.cpp](exercise-04/exercise04.cpp) | [fourth-exercise.txt](exercise-04/fourth-exercise.txt)
 - [exercise05.cpp](exercise-05/exercise05.cpp)
 - [exercise06.cpp](exercise-06/exercise06.cpp) 
 - [exercise07.cpp](exercise-07/exercise07.cpp) 
 - [exercise08.cpp](exercise-08/exercise08.cpp)

### Decryption
#### Exercise
 - [exercise09.cpp](exercise-09/exercise08.cpp) | [duplicated-chars.txt](exercise-09/duplicated-chars.txt)
 - [exercise10.cpp](exercise-10/exercise09.cpp) | [reversed-lines.txt](exercise-10/reversed-lines.txt)
 - [exercise11.cpp](exercise-11/exercise10.cpp) | [reversed-order.txt](exercise-11/reversed-order.txt)
 - [exercise12.cpp](exercise-12/exercise11.cpp) | [encoded-lines.txt](exercise-12/encoded-lines.txt)

