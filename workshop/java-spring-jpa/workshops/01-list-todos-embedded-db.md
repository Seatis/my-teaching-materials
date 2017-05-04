# Listing ToDos from embedded database

- create a spring project
- add dependencies:
  - JPA, H2, DevTools, Web, Thymeleaf
- optional dependencies:
  - Lombok


### Create classes
- Add a Todo class with the fields(id:int, title:String, isUrgent:boolean, isDone:boolean)
#### Controller
- Create a new controller called TodoController which maps to `/todo`
- Add a new method which maps to `/` and `/list` in the controller, which returns with "This is my first todo" string. Use the @Responseody annotation.
- Run the application. If all works fine, we can go ahead.
#### Repository
- Create a new repository which extends `CrudRepository`
- Inject the new repository into the controller with @Autowired

- Put the classes into *model, controller, repository* packages

### Connect to database
- Map the Todo class to the embedded database
- Use relevant annotations
- Make the `id` field auto-generated, incrementing value

### Create template
- Create a new template in the `src/main/resources/templates/todo.html` folder and in its html body display the todos [like this](assets/ListTodos.PNG).

### Populate database with new Todos in the Application class
- inject the repository with @Autowired
- implement CommandLineRunner `run()`
- in the `run()` use the `save()` method of the repository and save `new Todo()`s
