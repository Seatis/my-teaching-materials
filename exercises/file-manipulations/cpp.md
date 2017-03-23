# File manipulation exercises
## Writing files

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

### Exercise
 - [write-line.cpp](write_single_line/write-line.cpp)

## Reading files

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream my_file; // Creates an object that represents a file
  my_file.open("example.txt"); // The object opens the file called "example.txt"
  string file_content;
  my_file >> file_content; // Reads the first word from the first line of the file and puts it into the variable called file_content
  my_file.close(); // Closes the object

  return 0;
}
```
Be aware that this method only reads a word, so if the line consists
any white space character it only reads the line till that character.


### Exercise
 - [read-line.cpp](read_single_line/read-line.cpp) | [second-exercise.txt](read_single_line/second-exercise.txt)

### Reading lines

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
 - [write-lines.cpp](write_multiple_lines/write-lines.cpp)
 - [fourth-exercise.cpp](read_multiple_lines/fourth-exercise.cpp) | [fourth-exercise.txt](read_multiple_lines/fourth-exercise.txt)
 - [no-file.cpp](file_not_found_handling/no-file.cpp)
 - [read-lines2.cpp](read_from_file_function/read-lines2.cpp) 
 - [write-lines2.cpp](write_to_file_function/write-lines2.cpp) 
 - [copy-file.cpp](file_copy_function/copy-file.cpp)

### Decryption
#### Exercise
 - [exercise09.cpp](decrypt_function_doubled/exercise09.cpp) | [duplicated-chars.txt](decrypt_function_doubled/duplicated-chars.txt)
 - [exercise10.cpp](decrypt_function_reversed_lines/exercise10.cpp) | [reversed-lines.txt](decrypt_function_reversed_lines/reversed-lines.txt)
 - [exercise11.cpp](decrypt_function_reversed_order/exercise11.cpp) | [reversed-order.txt](exercise-11/reversed-order.txt)
 - [exercise12.cpp](decrypt_function_encoded_lines/exercise12.cpp) | [encoded-lines.txt](decrypt_function_encoded_lines/encoded-lines.txt)

