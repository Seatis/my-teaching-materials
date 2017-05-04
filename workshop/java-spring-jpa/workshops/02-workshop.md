# Workshop02 Connection with MySQL

- Create a new Spring project with Gradle
- Add dependencies:
  - JPA, MySQL, Web, Thymeleaf
- Optional dependencies:
  - Lombok, DevTools


- Copy previously created classes and template

### Connect to database
- Create new database in MySQL

#### Configuration
- Configure application.properties file in the needed structure
- Add url, localhost:3306 (most probably, if not check in Data Sources and Drivers in IntelliJ or in MySQL with 'SHOW variables LIKE "%port%";' command or in Workbench)

- Add MySQL username, password (**you should set it to something general first like "12345", because it will be committed to github**)

- Add "spring.jpa.show-sql = true"


- Add hibernate ddl auto (create, create-drop, update):         
    - spring.jpa.hibernate.ddl-auto=create
      - with "create" first
      - and after first recompiling, with "update", so the database schema will be automatically updated accordingly to java entities found in the project


- Add "spring.jpa.properties.hibernate.dialect = org.hibernate.dialect.MySQL5Dialect"


### Run the program
- If you did well then a new and empty "todo" table should appear with 4 columns(id, title, isUrgent, isDone)
- And your webpage should look [like this](../assets/EmptyTodos.PNG).
