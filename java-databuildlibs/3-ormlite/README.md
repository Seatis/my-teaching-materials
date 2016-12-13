# Object Relational Mapping with ORMLite
> Object-relational mapping (ORM, but also referred to as *O/RM* and the *O/R mapping tool*) is a programming technique for converting data between incompatible data type systems which arise in object-oriented programming. In effect, it creates, a *virtual object database* that one can use from within the programming language. There are both free and commercial packages available that perform ORM.  However, some programmers opt to construct their own ORM tools.

Synopsised from Wikipedia

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
| [JDBC Introduction](https://docs.oracle.com/javase/tutorial/jdbc/overview/index.html) | 6:00 |
| [What is an ORM?](https://www.youtube.com/watch?v=LooPUh5_QKI) | 2:21 |
| [Object Relational Mapping](http://tech.lalitbhatt.net/2014/07/object-relationship-mapping-orm.html) | 05:00 |
| [ORMLite documentation (until chapter 2.12)](http://ormlite.com/docs/ormlite.pdf) | 20:00 |


### Optional
| Material | Time |
|:-------- |-----:|
| [ORMLite documentation (from chapter 2.12 to the end)](http://ormlite.com/docs/ormlite.pdf) | 20:00 |

## Material Review
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

## Workshop

### Account sample
Implement the sample project from ORMLite's documentation.

- Create a new Java project
- Add [Workshop01.java](workshop/Workshop01.java) to the project (this is the entry point)
- Add ormlite-core (com.j256.ormlite:ormlite-core:4.30), ormlite-jdbc (com.j256.ormlite:ormlite-jdbc:4.30) and h2 (com.h2database:h2:1.4.1892) packages to the project from Maven
- Create an Account class with a name and a password property. Do not forget to add the required Annotations to the class and to the fields
- Make sure the project compiles

The last line of the output has to be the following:

```
Account: Captain America
```

### Use MySQL as a database
In the previous exercise you used an in-memory H2 database for testing purposes. In this exercise you are going to change the database to use MySQL.

- Add [Workshop02.java](workshop/Workshop02.java) to the project
- Add mysql-connector-java (mysql:mysql-connector-java:6.0.52) package to the project from Maven
- Create a new database on the MySQL server with the following name: `workshop02`
- Change the `databaseUrl` variable to something like this `jdbc:mysql://{host}:{port}/{database}?user={username}&password={password}` where
  - host: your MySQL server host
  - port: the port number where the server runs
  - database: database name (in this case `workshop02`)
  - username: mysql server username
  - password: mysql server password
- Run the program and after that you should see one record in the `accounts` table in your `workshop02` database

### Add at least 3 Accounts to the database

- Use the previous class (Workshop02.java) and complete it with some lines of code which inserts 3 or 4 different accounts __without duplicates__ (add *Iron Man*, *Wolverine*, *Hulk* and *Loki*)
- Iterate through all the accounts from the database and print its name

Expected output (the order can differ):
```
Captain America
Iron Man
Wolverine
Hulk
Loki
```

#### Order alphabetically
Use QueryBuilder to query the database and order the accounts alphabetically.

Expected output:
```
Captain America
Hulk
Iron Man
Loki
Wolverine
```

### Introduce Address for every account
In this exercise you are going to extend the Account class with an address field.

- Create a new project
- Add [Workshop03.java](workshop/Workshop03.java) to the project
- Create a new database on the MySQL server with the following name: `workshop03`
- Change the `databaseUrl` variable to something like the previous workshop's url (`jdbc:mysql://{host}:{port}/{database}?user={username}&password={password}`)
- Create a new class called Address:

  <img src="http://yuml.me/diagram/scruffy/class/[Address|-street;-city;-postCode;-country|+toString()]" >
- The Address' toString() function should return a string like this:
```
{
postCode =  1061,
city =  Budapest,
country =  Hungary,
street =  Andrássy út
}
```
- Implement the `toString()` function in the Account class also
```
{
name =  Captain America,
address =  {
postCode =  1061,
city =  Budapest,
country =  Hungary,
street =  Andrássy út
}
}
```
