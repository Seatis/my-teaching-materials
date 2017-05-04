# Listing ToDos from MySQL

- From now on we are going to extend the project, so use the same project as in Workshop02.
- Populate the "todo" table in MySQL with new ToDos either in CommandLineRunner or directly in MySQL
- Create some elements which isDone or isUrgent already.

### Create table template

- Create a table format, the outlook should be [something similar](../assets/TableTodos.PNG).

### Extend Listing

Extend the listing method with a request parameter for listing the active todos (active means !isDone)
If you write [`http://localhost:8080/todo/?isActive=true`](../assets/isActiveTodos.PNG) then only those todos which are not done yet should be lsited.
