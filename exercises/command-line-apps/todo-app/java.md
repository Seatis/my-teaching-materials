# Project
## Todo App

This is a complex exercise, so please read through the whole first, then start at the beginning.

### Tasks
#### Basics (mandatory):

 - Prints usage
 - A todo task has (at least) a completed state and a description
 - List tasks
 - Add new tasks
 - Complete tasks
 - Remove tasks
 - Store in file
 - Load state from file
 - One type of commands (see later in the Usage)

#### Advanced (optional):
 - Refactor the application to align with the proposed architecture
 - Multiple users
 - Shorthands for the commands (or the longhands)
 - Anything else that comes to your mind

### Stories
To follow the state of our projects and manage our work, we use so-called kanban boards.
They usually contains our tasks separated in columns (todo, doing, done).

Please create a kanban board for yourself and add the tasks (stories) that need to be done.
Later on, update your board, so you can always see your project's state and your next steps.

**How to create your kanban board and where to work?**
  - Create a new public repository with the name: YourGithubHandle-todoApp under greenfox-academy organization,
    and work in it later.
  - Add tag to your new repository with your class name (so we can find your project easily).
  - In your new repository: in the Projects view on Github, please create a new project called TODO Application
  - Then create your board. It should consist 4 columns:
    - Todo
    - Doing
    - Review
    - Done
  - Add stories to your board

You should not have 2 or more stories in Doing and Review
If you have a story in Review show it to one of the mentors to push it to done.

#### Usage
 - Run the application in the IDE
 - Then it should print the usage information:
```
CLI Todo application
====================

Available commands:
 list       Lists all the tasks
 l          shorthand for list
 add        Adds a new task
 a          shorthand for add
 remove     Removes an task
 r          shorthand for remove
 complete   Completes an task
 c          shorthand for complete
 help       Print out this list again
 h          shorthand for help
```
 - And wait for a command

#### List
 - Starting the project
 - When `list` command is given
 - Then it should print the todos that are stored in the list
```
1 - Walk the dog
2 - Buy milk
3 - Do homework
```

So in this case for example the elements of the list are:
```
Walk the dog
Buy milk
Do homework
```

#### Empty List
 - When the storage list is empty
 - And the `list` command is given
 - Then it should show a message like this: `No todos for today! :)`

#### Add new task
 - When `add Feed the monkey` command is given
 - Then it should add a new todo task (with the content `Feed the monkey`) to the list, so if the todos are listed it should show up on the end

#### Add task error handling
 - When `add` command is given, without specifying the todo
 - Then it should show an error message like: `Unable to add: No task is provided`

#### Remove task
 - When `remove 2` command is given, where the `2` is the index of the todo as showed when listing
 - Then it should remove the second item from the list, so if it is listed it should not show up

#### Remove task error handling
1:

 - When `remove` command is given, without specifying the index of the todo
 - Then it should show an error message like: `Unable to remove: No index is provided`

2:

 - When `remove 20` command is given, when there are only 3 todos
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to remove: Index is out of bound`

3:

 - When `remove apple` command is given
 - Then it should show an error message like: `Unable to remove: Index is not a number`

#### Argument error handling
 - When any other (eg. `get`) command is given
 - Then it should show an error message like: `Unsupported argument`, also it should print the usage information


#### Checked state
 - Starting the project with a file already created that stores todos
 - When `list` command is given
 - Then it should show the checked state for each task like:

```
1 - [ ] Walk the dog
2 - [ ] Buy milk
3 - [x] Do homework
```

#### Check task
 - When `complete 2` command is given
 - Then it should check the second item from the file, if it is listed it should show up as checked

#### Check task error handling
1:

 - When `complete` command is given, without specifying the index of the todo
 - Then it should show an error message like: `Unable to complete: No index is provided`

2:

 - When `complete 20` command is given, when there are only 3 todos
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to complete: Index is out of bound`

3:

 - When `complete apple` command is given
 - Then it should show an error message like: `Unable to complete: Index is not a number`

#### Store state in file & load it at start
 - When the application running is finished, before exiting
 - The program should save the current state of todos, so next time the user can check them again
 - When the application is starting the program should check the file and load its contents to the list
 - The name and the state of the todos should be stored in the storage file. (CSV is recommended)
 - For example:

 ```
 not_checked;Walk the dog
 not_checked;Buy milk
 checked;Do homework
 ```

 - or you can just use `0` and `1` instead of checked and not_checked

##### Missing file
 - When the application starts it should check if the storage file exists
 - Then it should create a new storage file in the current directory if not

##### Help
 - Ignore the storage file in the git repository using .gitignore

#### Multiple users
 - When the program starts it should ask for the username and load the todos for the user
 - Obviously different storage files are needed for different users



## Individual Workshop Review
Please follow the styleguide: [Our Java styleguide](../../styleguide/java.md)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Are the names of things following the styleguide?
   - Classes: UpperCamelCase
   - variables: lowerCamelCase
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
