# Databuild Competencies
## Gradle
- gradlew
- bootRun
- dependency definition
 

## ORMLite
- Persistence (state that outlives the process that created it) technology
- JDBC
- @DatabaseTable
  - tableName
  - daoClass
- @DatabaseField
  - id
  - generatedId
  - canBeNull
  - columnName
  - dataType
  - persisted (default value?)
  - foreign
  - foreignAutoCreate
  - foreignAutoRefresh
- DataTypes
  - DataType.DATE
  - DataType.STRING
  - DataType.INTEGER
  - ...
- ConnectionSource class
- Dao<T, ID> interface
  - create(T)
  - update(T)
  - delete(T)
  - queryForId(ID)
  - queryForAll()
- DaoManager.createDao(..) function
- TableUtils
  - createTable(ConnectionSource, Class)
  - createTableIfNotExists(ConnectionSource, Class)
  - dropTable(ConnectionSource, Class, boolean ignoreErrors)
  - clearTable(ConnectionSource, Class)
- QueryBuilder

## Lombok
- `@Data` - super annotation for `@Getter`, `@Setter`, `@ToString`, `@EqualsAndHashCode`
- `@Getter`, `@Setter` - avoiding having to regenerate code; used on a particular field
- `@ToString`
- `@NonNull`
- `@EqualsAndHashCode`
- `@NoArgsConstructor`
- `@AllArgsConstructor` 
- instructions
  - `staticName` - e.g. `@AllArgsConstructor(staticName="of"`) leads to xOfClass`.of()`
  - `callToSuper`
  - `AccessLevel.NONE`
- `@Builder` - build an object using a *fluent* API (Java 8, chaining)
- `@Log`
  - utility logger
- pom.iml
- *pojo* - stands for "plain old java object" - meaning not using special features
- The Terminal - in IntelliJ
- Fluent Interfaces
- Method Chaining

# Spring Competencies

  - @Configuration
  - @EnableAutoConfiguration
  - @ComponentScan
  - @Component


## IoC
- Dependency Injection via either: constructor or setter (for fine-tuning beans)

- Container (creates the objects needed; instantiates from *blueprint*)
  - Object Factory
    - gets a request
    - reads a configuration (blueprint / meta-data)
     - does the *new*
- Bean
  - Handle to an object that is made by the factory (repository)
  - Object lifecycle
    - instantiation
    - properties injected
    - .setBeanName() - method of BeanNameAware
    - preDestroy
method-level annotation
- @SpringBootApplication
  - `@Configuration` - indicates that the class will be used as a source of Bean definition
  - `@Component`
  - `@ComponentScan`
- wiring
  - `@Bean(name="*override the name of the bean here if you so wish, otherwise it's derived from the bean's name*")` - 
  - `@Autowired`
    - on a setter method (that is `setX(Integer x) {this.x = x});`) -  will make required (unless told otherwise); byType wiring
    - on a property (that is `private AProperty aProperty;`) - will remove the need for a setter method; Spring automatically assigns the property with the values passed
    - on a constructor (that is `public class AClass { public AClass(){}; ...`)
    - `@Autowired(required=false)` - will turn off the default behaviour so that the bean will be construct even if the value(s) to instantiate it are missing.
- Libraries
  - `org.springframework.context.annotation*` - to reach use annotation directives to instead read a Java class and pick up on `@configuration`, `@bean`, `@PostConstruct` &amp; `@PreDestroy` and to have a Java class with embedded annotation
  - `org.springframework.beans.factory.*` (note also has annotation support)
- Different ways of instantiating the Factory, but as we are using annotation:-
  - `AnnotationConfigApplicationContext(&lt;name of the class to use&gt;.class)`  - e.g. `newAnnotationConfigApplicationContext(AppConfig.class)`
- working with beans
  - .getBean(&lt;name of bean&gt;)  - ``` Service service = (Service) context.getBean("ServiceA");```
- the naming convention for beans; start off lowercase (as opposed to a Class)

## MVC

## Thymeleaf
- @Controller
- @RequestMapping
- @RequestParam
  - required
- @PathVariable
- @ModelAttribute
- Model
- xmlns:th="http://www.thymeleaf.org"

HTML 
- insertion/substitutions
  - `${...}` : Variable expressions.
    - `${session.user.name}` = OGNL (Open Graph Notation Language)
  - `*{...}` : Selection expressions - used to replace one item for another, eg. a parent
  - `#{...}` : Message (i18n) expressions - found in the properties file
  - `@{...}` : Link (URL) expressions.
  - `~{...}` : Fragment expressions.
- extensions
  - `th:text` - will replace the text
  - `th:attrib` 
  - `th:utext`
  - `th:each` - `<li th:each= "book : ${books}>" iterating book which can be used beneath, for each item in the list books
  - `th:insert`
  - `th:replace`
  - `th:with`
  - `th:unless`
- operators
  - use of `?`
    - to supply a default replacement if *value* is null (eg. `(value) ?: (defaultvalue)`)
	- for an `if then` statement (eg. `(if) ? (then)`)
	- for a ternary conditional statement (eg. `(if) ? (then) : (else)`)
  - `__` - preprocessor - eg `#{selection.__${sel.code}__}` where `{sel.code}` = "ALL" becomes `#{select.ALL}` before evaluating
	
## JPA &amp; Data
- Hibernate - JPA extended from it; can be used to supply the DDL 
  - Cardinality: `@OneToOne`, `@OneToMany`, `@ManyToMany`
  - `@JoinColumn`
- H2
- CrudRepository
- JpaRepository  
  - data access layer
  - public interface ... extends JpaRepository (`object class`, `key data type`)  
  - adds pages
- JPA
  - @Entity
  - @Table (name = "&lt;name to use&gt;")
  - @Id
  - @Column
  - @GeneratedValue
    - (strategy=GenerationType.AUTO)
  - Generated Queries
    - FindBy########()
    - FindOne()
    - FindAll()
  - Generated Methods
    - save (T entity)
	- Iterable<T> save(Iterable <? extends T> entities)
	- exists (ID id)
	- count()
	- delete (ID id); delete (T entity), delete (Iterable <? extends T> entities), deleteAll()
