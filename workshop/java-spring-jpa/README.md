# Database Integration
Java Persistence API is a collection of classes and methods to persistently store the vast amounts of data into a database. Spring Data JPA focuses on using JPA to store data in a relational database. Its most compelling feature is the ability to create repository implementations automatically, at runtime, from a repository interface.

## Materials & Resources

### Training
| Material | Time |
|:---------|-----:|
|[Introduction to JPA](https://www.youtube.com/watch?v=WZLTwbeENGs)|2:59|
|[What is ORM?](https://www.youtube.com/watch?v=LooPUh5_QKI)|2:21|
|[JPA Basic Mappings](https://www.youtube.com/watch?v=8FC_h1xuh-s&t=1)|till 33:18|
|[Building CRUD Web App](https://www.youtube.com/watch?v=TcP5kFPq354&t=1)|29:38|
|[Accessing data with JPA (spring.io)](https://spring.io/guides/gs/accessing-data-jpa/)|reading|
|[Query methods](https://docs.spring.io/spring-data/jpa/docs/current/reference/html/#jpa.query-methods)|reading|

### Optional
| Material | Time |
|:---------|-----:|
|[JPA Creating Queries](https://www.youtube.com/watch?v=tU-sVLtHK7M)|16:21|
|[Relation between JPA and Hibernate](https://www.youtube.com/watch?v=L8JZi_rWBYM)|2:14|
|[JavaEE architecture, Web Layer, Service Layer, JPA](https://www.youtube.com/watch?v=wgklrYfaldk)|3:23|

## Material Review
- ORM
- H2
- JPA
  - @Entity
  - @Table (name = "<name to use>")
  - @Id
  - @Column
  - @GeneratedValue
    (strategy=GenerationType.AUTO)
  - @Temporal
  - @JoinColumn
  - @ManyToOne
- CRUD
- findOne()
- findBy...()
- findAllBy...()


### Additional
- Hibernate
- Web Layer, Service Layer
- @Query
- @NamedQuery

## Workshops
- create a SpringBoot project with Gradle
- add dependencies:
  - JPA
  - Web
  - Thymeleaf
- optional dependencies:
  - DevTools
  - Lombok

The Workshops are:-
- [Data Project with JDBC / Spring Boot Gradle build](./workshop/Workshop01.md) - using Spring Initialzr in IntelliJ to create a project, practice understanding JPA and using H2.
- [JPA with MySQL](./workshop/Workshop02.md)
- [JPA, MySQL and relationships between Objects](./workshop/Workshop03.md) - explore JPA
- [JPA Querying with MySQL](./Workshop/Workshop04.md)
