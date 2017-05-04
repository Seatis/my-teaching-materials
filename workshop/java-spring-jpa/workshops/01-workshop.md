# Workshop01 Listing Todos from embedded database

- Create a Spring project with Gradle
- Add dependencies:
  - JPA, H2, DevTools, Web, Thymeleaf
- Optional dependencies:
  - Lombok

### Create classes
- Add a Todo class with the fields(id:int, title:String, isUrgent:boolean(default false), isDone:boolean(default false))
#### Controller
- Create a new controller called TodoController which maps to `/todo`
- Add a single `public String list(Model model)` method which maps to `/` and `/list` in the controller, which returns with "This is my first todo" string. Use the @Responsebody annotation.
- Run the application. If all works fine, we can go ahead.
#### Repository
- Create a new repository which extends `CrudRepository<Todo, Long>`
- Inject the new repository into the controller with @Autowired

- Put the classes into *model, controller, repository* packages

### Create template
- Remove @Responsebody from the Controller list method
- Make sure that the method returns to "todoslist" template
- Create a new template in the `src/main/resources/templates/todo.html` folder and in its html body display the todos [like this](../assets/ListTodos.PNG).

### Connect to database
- Map the Todo class to the embedded database
  - Use relevant annotations
  - Make the `id` field auto-generated, incrementing value
- In the list method of Controller add `"todos"` attribute with *finding All* elements from the repository

### Populate database with new Todos in the Application class
- Inject the repository with @Autowired
- Implement CommandLineRunner `run()`
- In the `run()` use the `save()` method of the repository and save some `new Todo("I have to learn Object Relational Mapping")` i.e.
