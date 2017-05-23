#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} Subject;

typedef struct {
    Subject subject;
    int value;
} Grade;

typedef struct {
    char name[128];
    int age;
    Grade* grades;
    int grade_count;
} Student;

// TODO:
// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0
#define GRADE_ALLOCATION 5
Student* CreateStudent(char* name, int age)
{
    // Allocate 5 grades
    Grade* grades = (Grade*)calloc(GRADE_ALLOCATION, sizeof(Grade));
    // Create new Student
    // We have to use dynamic memory allocation
    Student* student = (Student*)malloc(sizeof(Student));
    student->age = age;
    // We have to copy the content of the "name" not just copying the pointer
    strcpy(student->name, name);
    student->grades = grades;
    student->grade_count = 0;

    return student;
}

// TODO:
// Create a function that takes 3 parameters:
// A pointer to a Student
// A Subject
// An int (1-5)
// It should add a new grade of the subject to the student's grades array
void AddGrade(Student* student, Subject subject, int num)
{
    student->grades[student->grade_count].subject = subject;
    student->grades[student->grade_count].value = num;
    student->grade_count++;
}

// TODO:
// Create a function that takes a Student as a pointer and returns the subject
// that the student has worst grade in
Subject GetWorstGradeSubjet(Student* student)
{
    Grade* worst_grade_ptr;
    int worst_grade_value = 5;
    for(int i = 0; i < student->grade_count; i++) {
        if(student->grades[i].value < worst_grade_value) {
            worst_grade_value = student->grades[i].value;
            worst_grade_ptr = &(student->grades[i]);
        }
    }

    return worst_grade_ptr->subject;
}

// TODO:
// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should free each Grade and the Student itself
void DeleteStudent(Student* student)
{
    free(student->grades);
    free(student);
}

int main() {
    Student* ili = CreateStudent("Ili", 11);
    AddGrade(ili, HISTORY, 5);
    AddGrade(ili, ENGLISH, 5);
    AddGrade(ili, SCIENCE, 3);

    printf("%s's worst grade subject is: %d\n", ili->name, GetWorstGradeSubjet(ili));

    return 0;
}