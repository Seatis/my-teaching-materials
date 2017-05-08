# MySQL
Get introduced to MySQL

## Objectives
 - Understand what RDBMS are
 - Start to think with data in mind
 - Learn to structure and normalize your data

## Materials & Resources
### Environment
 - [MySQL Community Server](https://dev.mysql.com/downloads/mysql/)

### Tools
Install a GUI client to manage DB tables
 - [HeidiSQL](http://www.heidisql.com/) - Windows
 - [Sequel pro](http://www.sequelpro.com/) - OSX

### Training
| Material | Time |
|:---------|-----:|
| [What is Data, Database, DBMS?](https://www.youtube.com/watch?v=FR4QIeZaPeM) | 6:19 |
| [Introduction to Databases](https://www.youtube.com/watch?v=KgiCxe-ZW8o) | 7:31 |
| [Learn MySQL in one video](https://www.youtube.com/watch?v=yPu6qV5byu4) | 41:10 |
| [Normalization - 1NF, 2NF, 3NF and 4NF](https://www.youtube.com/watch?v=UrYLYV7WSHM) | 19:01 |
| [Bonus material](https://www.youtube.com/watch?v=h7mhFTAJvxA) | 2:04 |

## Material review
- data
- dbms
- database
    - navigational
    - relational
    - oodb
- SQL
- primary key
- normalizations
    - 1nf
    - 2nf
    - 3nf
- create database
- use database
- create table
    - text
    - varchar
    - integer
    - datetime
    - ...
- describe
- insert into
- value / values
- select
    - where
    - operators
        - =
        - >
        - <
        - <>
        - IN
        - ...
    - group by
    - having
    - sql functions
        - sum
        - max
        - min
        - avg
        - ...
- join

## Workshop



### Practice Exercises

Complete all challenges here:

- http://sqlbolt.com/

#### Exercise further

- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_core/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_extra/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_query_core/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_query_extra/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_mod/
- https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_mod/

### Setting up MySQL

- Install MySQL for your computer
- (you can install MySQL Workbench as well)
- set password  to something general flike "12345", because it will be committed to github with the time
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

### Prepare a Todo app database
- create a database for Todos
- plan and create the only table you'll need
- use auto incremented primary key
- add some sample data
