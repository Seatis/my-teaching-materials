# Project: Extension of TODO Application

> Extend and refactor your command-line todo application to easily add more features.
> This is **a complex exercise**, so please read through the whole first, then start at the beginning.

*Note: Most of the stories are based on specifically Java language treats.*

## Stories

### Add Gradle Building to your project
- Create a new project with gradle and copy the source

### Extend your Todo class with ID
- Every todo should have a unique `id` field
- The `id` field should be continously incrementing, starting from 1
- The `id` should be stored in the database

### Extend your Todo class with dates
- Every todo should have a `createdAt` and a `completedAt` field
- Remove the `completed` field and refactor your complition mechanism to:
  - todo is completed if it has a `completedAt` field filled and the date is in the past
- Have a `complitionTime` method that returns the time required to completed the todo in days

### Extend the functionality with update
- Based on Id you should be able to update the Todo's description
```
-u [id] [new todo description]
```

### Refactor saving and loading data
- Every file manipulation should happen in a separate class
- Methods should be:
  - `save(Todo)` - saves the given Todo, if
  - `saveAll(List<Todo>)`
  - `load(int)`
  - `load(String)`
  - `loadAll()`

### Create an interface for Persistance
- The methods should be the same as in the current file manipulation class
- Let that class implement this interface
- Create another implementation for Persistance which only saves the todos in the memory (eg. an ArrayList)
