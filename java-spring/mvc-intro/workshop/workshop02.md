# Spring MVC - Workshop 02 Refactor the database connection
In this workshop we're going to replace the database connection to use Jpa as discussed in "[Learn Spring Boot (Djalas)](https://www.youtube.com/watch?v=Ke7Tr4RgRTs&t=2695)."

## Copy from a previous build (Workshop01)

If you have trouble with the copy, consider the following steps:-
- Close the project you're going to clone
- Create a new directory for the new version project (e.g. Workshop02)
  - OS Copy in the contents of source, eg. "Workshop01" (I did this as I could not see how else to specify a source and target)
- File New -> Create Project From Existing -> Select the Workshop02 directory
- Import - as this is from a Gradle project, import from an external model
- For this build, as before, also tick "Use Auto Import" and "Create directories for empty content ..."

### Settings 
Remember to tick on Annotations.

### Test
Ensure that all is still working.

## Refactor &amp; Create an Interface Class

### Carve out the Interface
The existing StudentDao will become both an implementation and the basis of an *interface*.
- Rename `StudentDao` to `FakeStudentDaoImpl`
- With the rename `FakeStudentDaoImpl` apply Refactor -> Extract -> Extract Interface to generate `StudentDao`
- Check 
  - `FakeStudentDaoImpl` - this should now implement `StudentDao`
  - `StudentDao` should now be an interface

### Create MySql Repository

- Create a new class for a MysqlStudentDaoImpl; remember this implements StudentDao.  Note that Dao is an unfortunate name.  We are not using DAO, but to keep consistent with the rest of the tutorial, we're leaving this as is.  
- As this *implements* you need to be sure you have stubs (methods that do nothing yet) for all the methods as required by the interface.
- Add the @Qualifier("mysqlData") and @Qualifier("fakeData") to the 2 `...Impl` and in `StudentService`, when wiring in the Bean, select @Qualifier("fakeData") as Djalas illustrates
- Test - be sure that you've not corrupted anything.  As we are pointing to fakeData, everything should still work.

If you need to add the mysql to the build:-
- Go to file `build.gradle`
- Add to the dependences `compile('mysql:mysql-connector-java:5.1.40')` (_Note_ we determined this particular connector by looking at previous Gradle mysql builds; this is not the latest, but it worked previously)
- Refresh gradle - this way it finds everything.

Remember to:- 
- set up the target database (for example mvc_ws02) in mySql
- update application.properties to reference teh datasource.url
- start mySQL to be sure that the server is waiting to answer calls

The first method to try to replace is getAllStudents().  For this you'll face a challenge.  In the *interface* this returns a `Collection` however, a CrudRepository equivalent is `Iterable<E> .findAll()`.  You'll have to convert the data for this to work.  Use Google to find a way to convert.

You may find you get the following issue:

`
Field studentDao in com.greenfox.Service.StudentService required a bean of type 'com.greenfox.Dao.StudentDao' that could not be found.
` 

Consider what you've Beaned and marked as Autowired.

The MysqlStudentDaoImpl needs a local studentRepo (so that it can do various things); and this needs to be Autowired.

And for beans to be created, remember that you must not only identify what gets @Autowired, but must also mark the class as a @Component so that SpringBoot knows to read them up.

For testing, consider the following once you get the application to start:-
- Go to Mysql, and in particular the new db you created, "mvc_ws02"
- If your `application.properties` had `spring.jpa.hibernate.ddl-auto=create`, then you'll see an empty version of the students table
- with the application running, add some records:-
```sql
INSERT INTO students VALUES (1, "Billy", "Software");
INSERT INTO students VALUES (2, "Joe", "Icing");
INSERT INTO students VALUES (3, "Kath", "Business");
Select * from students; -- just to check.
```
- if you restart, and find that the records have disappeared it'll be because the `application.properties` has `spring.jpa.hibernate.ddl-auto=create`.  Thus each time you restart you app, the data in the database is erased.  You need to switch it to `spring.jpa.hibernate.ddl-auto=none //create`.

### getStudentById
This should be a fairly simple one to convert; however, if it's failing because of a data conversion error, then consider what you've specified as your identifier...  Did you just copy <Student,Long>?  If so, your problem lies there.

Keep in mind, the CrudRepository's findOne data type is driven by the key value, while the earlier design had `int` and not `Long` or `Integer`.

###Remaining elements 
These should be a straight forward:-
- removeStudentById
- updateStudentById
- insertStudentToDb

Test with the same items as before, using Postman.
 
#Links
- [Parent - Java Spring](../README.md)
- [Prior - WS1 - Reproduce Djalas tutorial](../Workshop/Workshop01.md)
- [Next - Reddit](../Workshop/reddit.md)
