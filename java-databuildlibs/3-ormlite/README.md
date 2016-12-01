# Object Relational Mapping with ORMLite
> Object-relational mapping (ORM, O/RM, and O/R mapping tool) in computer science is a programming technique for converting data between incompatible type systems in object-oriented programming languages. This creates, in effect, a "virtual object database" that can be used from within the programming language. There are both free and commercial packages available that perform object-relational mapping, although some programmers opt to construct their own ORM tools. - Wikipedia

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
| Great material on JDBC | 6:00 |
| [What is an ORM?](https://www.youtube.com/watch?v=LooPUh5_QKI) | 2:21 |
| [Object Relational Mapping](http://tech.lalitbhatt.net/2014/07/object-relationship-mapping-orm.html) | 05:00 |
| [ORMLite documentation (until chapter 2.12)](http://ormlite.com/docs/ormlite.pdf) | 20:00 |


### Optional
| Material | Time |
|:-------- |-----:|

## Material Review
- JDBC
- @DatabaseTable
  - tableName
  - daoClass
- @DatabaseField
  - id
  - canBeNull
  - columnName
  - dataType
  - persisted (default value?)
  - generatedId
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

## Workshop

### Account sample
Implement the sample project from ORMLite's documentation.

- Create a new Java project
- Add [Workshop01.java](workshop/Workshop01.java) to the project (this is the entry point)
- Add ormlite-core (com.j256.ormlite:ormlite-core:4.30), ormlite-jdbc (com.j256.ormlite:ormlite-jdbc:4.30) and h2 (com.h2database:h2:1.4.1892) packages to the project from Maven
- Create an Account class with a name and a password property. Do not forget to add the required Annotations to the class and to the fields.
- Make sure the project compiles

The last line of the output has to be the following:

```
Account: Captain America
```
