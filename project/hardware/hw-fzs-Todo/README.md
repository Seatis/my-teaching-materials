# Command Line Todo App
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources

 - [What is a Toso App?](https://opensource.com/sites/default/files/images/life-uploads/todolist.png)

## Workshop
### Tasks
#### Basics (mandatory):

- [Print usage](#print-usage)
- [List tasks](#list-tasks)
- [List tasks by priority](#list-tasks-by-priority)
- [Empty list](#empty-list)
- [Add new task](#add-new-task)
- [Check task](#check-task)
- [Remove task](#remove-task)
- [Argument error handling](#argument-error-handling)

### Print usage
 - The application ran by exectuing `..\project_folder\bin\Debug\your_project_name.exe`
 - Then it should print the usage information:

```
Todo application
====================
Commands:
 - l   Lists all the tasks
 - lp  Lists all the tasks by priority
 - p   Add priority to a task
 - a   Adds a new task
 - r   Removes a task
 - c   Completes a task
 - e   Empty the list
 ```

#### List tasks
 - When the application is ran by executing `-l`
 - Then it should print the todos, it should add numbers before them when it prints it
 - use `\t` to formating

 So in this case for example the content is:

```
List by number
====================
Num | Tasks | Prio
1   - Walk the dog - 3
2   - Buy milk
3   - Do homework - 1
4   - Do something
```

#### List tasks by priority
 - When the application is ran by executing `-lp`
 - Then it should print the todos, it should list by priority numbers before them when it prints it.
 - use `\t` to formating

So in this case for example the content is:
```
List by priority
====================
Num | Tasks | Prio
1   - Walk the dog - 3
3   - Do homework - 1
2   - Buy milk
4   - Do something
```

#### Empty the list
 - When the application is ran by executing `-e` and the struct is empty
 - Then it should show a message like this: `No todos for today! :)`

### Add new task
 - When the application is ran by executing `-a "Feed the monkey"`
 - Then it should add a new todo task (with the content `Feed the monkey`), if the todos are listed it should show up on the end

#### Add task error handling
 - When the application is ran by executing `-a`
 - Then it should show an error message like: `Unable to add: No task is provided`

### Add prority to a task
  - When the application is ran by executing `-p "Feed the monkey" "2"`
  - Then it should add a priority to task (with the content `Feed the monkey`) if the todos are listed it should show up on the end

  ```
  List by priority
  ====================
  Num | Tasks | Prio
  1   - Walk the dog - 3
  5   - Feed the Monkey - 2
  3   - Do homework - 1
  2   - Buy milk
  4   - Do something
  ```

#### Add task error handling
    - When the application is ran by executing `-p`
    - Then it should show an error message like: `Unable to add priority: No task is provided`

#### Add task error handling
  - When the application is ran by executing `-a`
  - Then it should show an error message like: `Unable to add: No task is provided`


#### Remove task
 - When the application is ran by executing `-r 2`
 - Then it should remove the second item from the list, if it is listed it should not show up

#### Remove task error handling

1:
 - When the application is ran by executing `-r`
 - Then it should show an error message like: `Unable to remove: No index is provided`

2:
 - When the application is ran by executing `-r 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to remove: Index is out of bound`

3:
 - When the application is ran by executing `-r apple`
 - Then it should show an error message like: `Unable to remove: Index is not a number`

#### Argument error handling

 - When the application is ran by executing `-g` or with any other not listed arguments
 - Then it should show an error message like: `Unsupported argument`, also it should print the usage information

#### Check task

  - When the application is ran by executing `-c 3`
  - Then it should check the third item from the list, if it is listed it should show up as checked

#### Checked state

 - When the application is ran by executing `-l`
 - Then it should show the checked state for each task like:

```
List by number
====================
Num | Tasks | Prio
1 - [ ] Walk the dog - 3
2 - [ ] Buy milk
3 - [x] Do homework - 1
4 - [ ] Do something
5 - [ ] Feed the Monkey - 2
```
#### Check task error handling
1:
 - When the application is ran by executing `-c`
 - Then it should show an error message like: `Unable to check: No index is provided`

2:
 - When the application is ran by executing `-c 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to check: Index is out of bound`

3:
 - When the application is ran by executing `-c apple`
 - Then it should show an error message like: `Unable to check: Index is not a number`

 ## Extra
 Take a look to [conio.h](https://code-reference.com/c/conio.h) and play with it.
 - Make the higher prio tasks to red lower yellow...the task that's done green

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide] (https://github.com/greenfox-academy/totoro-syllabus/blob/master/STYLEGUIDE.md)

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
