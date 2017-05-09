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


#### Optional
- Hibernate
- Web Layer, Service Layer
- @Query
- @NamedQuery

## Workshops
- [Listing Todos from embedded database](./workshops/ListingTodosWithH2.md)
- [Connection with MySQL](./workshops/ConnectionWithMySQL.md)
- [Listing Todos from MySQL](./workshops/ListingTodosfromMySQL.md)
- [Add creating function](./workshops/CreatingFunction.md)
- [Add deleting function](./workshops/DeletingFunction.md)
- [Add updating function](./workshops/UpdatingFunction.md)

### Optional
- Make the todo names clickable. On the event a new page should appear with the details of the selected todo only.
- Add date column with date of creation.
- Let's assume that our application used by more users (i.e. your mother/wife/brother/cat) and can add more things to your todolist. Add `User` model, create any fields with any information content you want to preserve of the user. Extend your main listing table with the name of the user (or with more info, if you want), but preserve every information of the user in a separate table. Extend your adding page with a user field (or fields for more info).
Try to find out and specify the relationship and the connection between `todo` and `user` tables.
- Create database and link to your 'tamagotchi' project ;)
