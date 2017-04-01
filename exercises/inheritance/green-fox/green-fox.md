# Green Fox inheritance exercise

## Person
Create a `Person` class with the following fields:
- `name`: the name of the person
- `age`: the age of the person (whole number)
- `gender`: the gender of the person (male / female)


And the following methods:
- `introduce()`: prints out "Hi, I'm `name`, a `age` year old `gender`."
- `getGoal()`: prints out "My goal is: Live for the moment!"


And the following constructors:
- `Person(name, age, gender)`
- `Person()`: sets `name` to Jane Doe, `age` to 30, `gender` to female


## Student
Create a `Student` class that has the same fields and methods as the `Person` class, and has the following additional
- fields:
    - `previousOrganization`: the name of the student’s previous company / school
    - `skippedDays`: the number of days skipped from the course
- methods:
    - `getGoal()`: prints out "Be a junior software developer."
    - `introduce()`: "Hi, I'm `name`, a `age` year old `gender` from `previousOrganization` who skipped `skippedDays` days from the course already."
    - `skipDays(numberOfDays)`: increases `skippedDays` by `numberOfDays`

The `Student` class has the following constructors:
- `Student(name, age, gender, previousOrganization)`: beside the given parameters, it sets `skippedDays` to 0
- `Student()`: sets `name` to Jane Doe, `age` to 30, `gender` to female, `previousOrganization` to The School of Life, `skippedDays` to 0

## Mentor
Create a `Mentor` class that has the same fields and methods as the `Person`class, and has the following additional
- fields:
    - `level`: the level of the mentor (junior / intermediate / senior)
- methods:
    - `getGoal()`: prints out "Educate brilliant junior software developers."
    - `introduce()`: "Hi, I'm `name`, a `age` year old `gender` `level` mentor."


The `Mentor` class has the following constructors:
- `Mentor(name, age, gender, level)`
- `Mentor()`: sets `name` to Jane Doe, `age` to 30, `gender` to female, `level` to intermediate


## Sponsor
Create a `Sponsor` class that has the same fields and methods as the `Person`class, and has the following additional
- fields:
    - `company`: name of the company
    - `hiredStudents`: number of students hired
- method:
    - `introduce()`: "Hi, I'm `name`, a `age` year old `gender` who represents `company` and hired `hiredStudents` students so far."
    - `hire()`: increase `hiredStudents` by 1
    - `getGoal()`: prints out "Hire brilliant junior software developers."


The `Sponsor` class has the following constructors:
- `Sponsor(name, age, gender, company)`: beside the given parameters, it sets `hiredStudents` to 0
- `Sponsor()`: sets `name` to Jane Doe, `age` to 30, `gender` to female, `company` to Google and `hiredStudents` to 0


## LagopusClass
Create a `LagopusClass` class that has the following
- fields:
    - `className`: the name of the class
    - `students`: a list of `Student`s
    - `mentors`: a list of `Mentor`s
- methods:
	- `addStudent(Student)`: adds the given `Student` to `students` list
	- `addStudent(Mentor)`: adds the given `Mentor` to `mentors` list
	- `info()`: prints out "Lagopus `className` class has `students.size` students and `mentors`.size mentors."


The `LagopusClass` class has the following constructors:
- `LagopusClass(className)`: beside the given parameter, it sets `students` and `mentors` as empty lists

## Result
- Your program should result [this output](green-fox_output.md) if you run it with [this input](green-fox_input.md)