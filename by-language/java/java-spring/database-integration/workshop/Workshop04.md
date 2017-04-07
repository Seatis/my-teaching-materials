#Workshop04 - CrudRepository Queries
In this exercise we'll explore extending the JpaRepository/CrudRepository. Jpa extends the CrudRepository by adding paging.

In this exercise we'll revisit skills learnt previously.

## Preparation
Create a new project from scratch, expecting to use MySQL, Lombok, JPA.

## Tasks

### Create the following 2 objects
- students
  - id (not necessary make auto increment)
  - name (last name only)
  - group - string
- class
  - code
- grades
  - student_id - relates to students
  - code_class - relates to class
  - grade (1-5, where 5 is a top mark)
    
### Populate the tables

Use the @Sql to populate
```sql
INSERT INTO students (id, name, group) VALUES ( 2, "Gomez", "red");
INSERT INTO students (id, name, group) VALUES ( 2, "Roberts", "blue");
INSERT INTO students (id, name, group) VALUES ( 3, "Sanderson", "red");
INSERT INTO students (id, name, group) VALUES ( 4, "Fredricks", "blue");
INSERT INTO students (id, name, group) VALUES ( 5, "Baylor", "red");
INSERT INTO students (id, name, group) VALUES ( 6, "Munoz", "blue");
INSERT INTO students (id, name, group) VALUES ( 7, "Halibi", "blue");
INSERT INTO students (id, name, group) VALUES ( 8, "Mortimer", "red");

INSERT INTO class (code) VALUES ("Radio");
INSERT INTO class (code) VALUES ("Demo");
INSERT INTO class (code) VALUES ("Saper");
INSERT INTO class (code) VALUES ("Recon");
INSERT INTO class (code) VALUES ("Survival");
INSERT INTO class (code) VALUES ("Desert");

INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Radio", 4 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Demo", 3 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Saper", 4 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Recon", 5);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Desert", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Radio", 2 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Demo", 4 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Saper", 2 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Recon", 2);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 2, "Desert", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 3, "Radio", 5 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 3, "Demo", 5);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 3, "Saper", 5 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 3, "Recon", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 3, "Desert", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 4, "Radio", 3);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 4, "Demo", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 4, "Saper", 3 );
INSERT INTO grades (student_id, code_class, grade) VALUES ( 4, "Recon", 5);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 4, "Desert", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 5, "Radio", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 5, "Demo", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 5, "Saper", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 5, "Recon", 2);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 5, "Desert", 2);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 7, "Radio", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 7, "Demo", 3);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 7, "Saper", 1);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 7, "Recon", 2);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 7, "Desert", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 8, "Radio", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 8, "Demo", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 8, "Saper", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 8, "Recon", 4);
INSERT INTO grades (student_id, code_class, grade) VALUES ( 8, "Desert", 4);

### Exercises
- For each student, retrieve his grades
- For each class, retrieve the students and grades earnt

#### Extra
- Determine which class was not taken by any students
- For each class, get the count of students that took the class, the average grade 
- For each student, get the number of classes taken, the average grade
- For each class, determine which student(s) were the best
- For all the students, determine which had the lowest grade

# Links
[Unit Overview](../README.md)
[Prev Workshop03](./workshop03.md)
[Next Workshop05](./workshop05.md)