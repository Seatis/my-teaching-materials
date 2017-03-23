#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "first-exercise.txt"
  // Write your name and a new line to the file using this program
  ofstream file;
  file.open("first-exercise.txt");
  file << "John Doe\n";
  file.close();

  return 0;
}
