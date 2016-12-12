# Plain SQL Basics

## Materials & Resources
### Environment
Preparation:
- Install MySQL for your computer - you'll need to have admin rights to your pc;
- Add MySQL Workbench 

### Training
| Material | Time |
|:-------- |-----:|
|[What is Database & SQL?](https://www.youtube.com/watch?v=FR4QIeZaPeM)|6:19|
|[Relational Database Concepts](https://www.youtube.com/watch?v=NvrpuBAMddw)|5:24|
|[MySQL Tutorial 2 - How Data is Organized and Normalization](https://www.youtube.com/watch?v=IIdfqFxercg)|6:31|
|[MySQL Tutorial (Bana)](https://www.youtube.com/watch?v=yPu6qV5byu4)|41:09|
|[Marble](https://www.youtube.com/watch?v=h7mhFTAJvxA)|2:18|

## Assignment review
- data
- database
    - navigational
    - relational
    - oodb
- dbms
- SQL
- normalization - data is only defined in 1 place, no repeated definitions
    - 1nf - id|name|list-of-phone-numbers|
    - 2nf - mfg|mfg-city|model-machine|
    - 3nf - tournament|year|winner|winner's date of birth|
- keys
  - primary key
  - candidate
  - composite
  - cascading deletes
- database operations - create, use
- table operations - create, alter, alter column, drop, describe, insert into ... values()
- data types 
  - text
  - varchar vs char
  - n (text, varchar, char); nvarcharX = n'text'
  - datetime, timestamp
  - null
- select statement
    - where, predicate, constraint
    - operators (= , > , < , <>, like, between, not like , not between, in, ...)
    - nested selects
    - group by; aggregate functions (max, sum, min, avg, count); having
- join
    - inner, outer
    - on operator
- coalesce(), isnull(), ifnull()    

## Work With
Review the first 7+ exercises with class in http://sqlbolt.com/.
Review the concept of joins
<img src="Moffat-SQL-Joins-Representation.png">

### Practice Exercises
Complete the challenges here:
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_core/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_extra/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_query_core/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_query_extra/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_mod/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_mod/

### MySQL
- Create a new database on your computer:
```mysql
CREATE DATABASE bookstore;
```
- Import all data from `data.sql` file:
```
$ mysql bookstore < data.sql
```
- for windows users: Navigate to the directory where you have mysql and issue this command, changing the bold values to your file/database locations.
```
c:\mysql\bin\> mysql -u USERNAME -p bookstore < data.sql
```
- list all tables
- select all data from all tables
- create a query selecting all books with its name, authors name, category name, publishers name and price

---
- create a database for Todos
- plan and create the only table you'll need
- use auto incremented primary key
- add some sample data from sql
