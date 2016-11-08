#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

};

// Create 2 methods for both parameters of the Student class.
// One should be called getParameterName, the other should be called setParameterName
// e.g.: string getName(void), void setName(string name) etc.
// Consider what decisions You'l have to make:
//   - Does it take a type, a reference or a pointer as argumnet?
//   - What happens with the current parameters if You get new ones?
// 
// Create code in teh main function that uses all these functions and ilustrates that they work 
// by printing out something.

int main() {

  return 0;
}
