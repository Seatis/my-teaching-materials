# Command Line Todo App
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources
### Training
| Material - Day 1 | Time |
|:---------|-----:|
| [C++ Tutorial 23 - Static Member Variables](https://www.youtube.com/watch?v=7u7ti-S69uY) | 20:56 |
| [ITK BarCamp - C++ Training - Command Line Arguments](https://www.youtube.com/watch?v=3iATEcmhB8w) | 13:28 |



| Material - Day 2 | Time |
|:---------|-----:|
| [UML 2.0 Tutorial #01 - Intor & Use Cases](https://www.youtube.com/watch?v=OkC7HKtiZC0&index=1&list=PLGLfVvz_LVvQ5G-LdJ8RLqe-ndo7QITYc) | 12:47 |
| [UML 2.0 Tutorial #03 - Class Diagramms](https://www.youtube.com/watch?v=3cmzqZzwNDM&index=3&list=PLGLfVvz_LVvQ5G-LdJ8RLqe-ndo7QITYc) | 16:46 |

| HomeWork Exercise | Tools |
|:---------|-----:|
| Create the UML class diagramm for Your ToDo App | [UML editor](http://staruml.io/downloadq) |


## Material Review
 - `static`

## Workshop
### Tasks
#### Basics (mandatory):

 - Prints usage
 - A todo task has (at least) a completed state and a description
 - Add new tasks
 - Complete tasks
 - Remove tasks
 - List tasks

#### Advanced (optional):
 - Refactor the application to align with the proposed architecture
 - Write unittests for any unit it feels possible

### Stories
Please create a trello board for yourself and add these stories.
The trello board should consist 4 columns:
 - Todo
 - Doing
 - Review
 - Done

You should not have 2 or more stories in Doing and Review
If you have a story in Review show it to one of the mentors to push it to done.

#### Usage
 - Given the terminal opened in the project directory
 - When the application ran by exectuing `./todo` 
 - Then it should print the usage information:
```
CLI Todo application
====================

Command line arguments:
 -l   Lists all the tasks
 -a   Adds a new task
 -r   Removes an task
 -c   Completes an task
```


#### List
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -l`
 - Then it should print the todos that are stored in the file and it should add numbers before them when it prints it
```
1 - Walk the dog
2 - Buy milk
3 - Do homework
```

So in this case for example the content of the file is:
```
Walk the dog
Buy milk
Do homework
```

##### Help
 - [Handling command line arguments](http://www.cplusplus.com/articles/DEN36Up4/)
 - Ignore the storage file in the git repository using .gitignore


#### Empty List
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -l` and the file is empty
 - Then it should show a message like this: `No todos for today! :)`

#### Add new task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -a "Feed the monkey"`
 - Then it should add a new todo task (with the content `Feed the monkey`) to the file, if the todos are listed it should show up on the end

#### Add task error handling
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -a`
 - Then it should show an error message like: `Unable to add: No task is provided`

#### Remove task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -r 2`
 - Then it should remove the second item from the file, if it is listed it should not show up

#### Remove task error handling
1:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -r`
 - Then it should show an error message like: `Unable to remove: No index is provided`

2:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -r 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to remove: Index is out of bound`

3:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -r apple`
 - Then it should show an error message like: `Unable to remove: Index is not a number`

#### Argument error handling
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -g` or with any other not listed arguments
 - Then it should show an error message like: `Unsupported argument`, also it should print the usage information

#### Missing file
 - Given the terminal opened in the project directory, and no storage file
 - When the application is ran by executing any command that uses the storage file
 - Then it should create a new storage file in the current directory

#### Checked state
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -l`
 - Then it should show the checked state for each task like:

```
1 - [ ] Walk the dog
2 - [ ] Buy milk
3 - [x] Do homework
```
The state of the todos should be stored in the storage file. (CSV is recommended)

#### Check task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -c 2`
 - Then it should check the second item from the file, if it is listed it should show up as checked

#### Check task error handling
1:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -c`
 - Then it should show an error message like: `Unable to check: No index is provided`

2:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -c 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to check: Index is out of bound`

3:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `./todo -c apple`
 - Then it should show an error message like: `Unable to check: Index is not a number`

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

