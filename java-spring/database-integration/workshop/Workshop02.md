#Workshop02 - Spring Boot Gradle build for JPA connecting to MySQL instead

Take Workshop01 and redo it to instead use mySQL.

## Preparation
You'll need to:-
- either redo the project, or copy/change with Spring Intializr, ensuring you've choosen the right libraries (and for Gradle, not Maven)
- sure that your MySQL engine is running (In Windows, if the service is manual (run services.msc) you'll have to enable it)
- ensure that you know the name of the db, user and password
- have to set up the resources//application.properties file correctly (as described in Marinho's video)

## Outcome

After running this you should find the following customers in your database.

|id  |firstName|LastName|
|:---|:--------|:-------|
|1|Jack|Bauer|
|2|Chloe|O'Brian|
|3|Kim|Bauer|
|4|David|Palmer|
|5|Michelle|Dessler|
 

# Links
- [Unit Overview](../../README.md)
- [Prev Workshop01](./Workshop01.md)
- [Next Workshop03](./Workshop03.md)
