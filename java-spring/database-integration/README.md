#Database Integration
!!Explain


## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[Spring Boot to create a program with data base connectivity (Code Taming)](https://www.youtube.com/watch?v=oBqTpe5ciMo)|4:10|
|Database Access (Romanian.03)](https://www.youtube.com/watch?v=C3bNEz9opuU)|19:37|
|[Accessing data with JPA (spring.io)](https://spring.io/guides/gs/accessing-data-jpa/)|reading|
|[Accessing a relational DB (spring.io)](http://spring.io/guides/gs/relational-data-access/)|reading|
!!videos; additional sql
!!integrating with MySQL engine
!!Logger factory

### Optional
| Material | Time |
|:---------|-----:|
|[JdbcTemplate (spring.io)](http://docs.spring.io/spring-framework/docs/2.5.x/api/org/springframework/jdbc/core/JdbcTemplate.html) - catalogue of the different methods and data types available from the library|reference|
|[MySQL Download](https://www.mysql.com/why-mysql/windows/)|link|
!!Java 8 Lambdas


## Review
- org.springframework.boot.CommandLineRunner;
- H2
- JPA
  - @Entity
  - @Table
  - @Id
  - @GeneratedValue
    - (strategy=GenerationType.AUTO)
  - FindBy########()
  - FindOne()
  - FindAll()
- JDBC
  - batchUpdate()
  - query()
  - execute()
  
- slf4j / aka Lombok
- @SpringBootApplication
  - @Configuration
  - @EnableAutoConfiguration
  - @ComponentScan
- LoggerFactory
- SQL
  - replacing values marked by `?`

- CurdRepository


### Optional Items


## Workshops
We saw previously how to use the web-based Spring Tool Suite (STS) to build; in this series of W/S's will use the built-in, IntelliJ tool to talk to STS called Spring Initializr.  We'll use this to prepare the environment.

Start by creating a new project and choosing Spring Initializr:-
<img src="Workshop/workshop01-A.jpg">

Next, you're generating a Gradle Project (note there're 2 Gradle options).  You should name it appropriately and set the group and package.
<img src="Workshop/workshop01-B.jpg">

Depending upon the workshop's objectives, we're chosing
- DevTools
- Lombok (as that gives us messages to the console (CommandLineRunner and Logger (org.slf4j)).
- H2 which allows us to do SQL using the in-memory SQL Engine
- JDBC which allows us to talk to an SQL database, or 
- JPA which allows us to talk to an SQL database 

<img src="readme-A.jgp">

Lastly, we're generating this to use the gradle wrapper (giving us a Gradlew.bat and bootRun).  We specifically unticked "Create separate module per source set":
<img src="Workshop/workshop01-D.jpg">

The Workshops are:-
- [Data Project with JPA / Spring Boot Gradle build](./workshop/Workshop03.md) - explore JPA 
- [Practice with `@Table` and other JPA Annotations](./Workshop/Workshop04.md)
- [Data Project with JDBC / Spring Boot Gradle build](./workshop/Workshop01.md) - using Spring Initialzr in IntelliJ to create a project, practice understanding JDBC and get a short intro to Java 8 and Lambdas
- [Practice by extending W/S1 with another table](./workshop/Workshop02.md)
- [Read data from MySQL using JDBC](./Workshop/Workshop05.md) 


#Links
- [Parent - Java Spring](../README.md)
- [Prev - Beans (IoC)](../ioc-bean/README.md)
- [Next - Project](../project-calorie/README.md)
