#include <string>
#include <iostream>

using namespace std;

enum Subject {MATH, HISTORY, ENGLISH, SCIENCE};

struct Grade {
  Subject subject;
  int value;
}

struct Student {
  string name;
  int age;
  Grade* grades;
  int grade_count;
};

// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0

// Create a function that takes 3 parameters:
// A reference to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments

// Create a function that takes a Student as a reference and returns the subject
// that the student has worst grade in

// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should deallocate each Grade and the Student itself

int main() {

  return 0;
}
