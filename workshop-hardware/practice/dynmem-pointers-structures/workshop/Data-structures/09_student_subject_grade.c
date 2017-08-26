#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject_t;

typedef struct {
    subject_t subject;
    int value;
} grade_t;

typedef struct {
    char name[128];
    int age;
    grade_t* grades;
    int grade_count;
} student_t;

// TODO:
// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0

// TODO:
// Create a function that takes 3 parameters:
// A pointer to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments

// TODO:
// Create a function that takes a Student as a pointer and returns the subject
// that the student has worst grade in

// TODO:
// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should free each Grade and the Student itself

int main()
{

    return 0;
}
