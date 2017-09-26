# Command Line Todo App
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources

- [What is a ToDo App?](https://opensource.com/sites/default/files/images/life-uploads/todolist.png)
- [File I/O in C](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)

## Workshop
This is a quite long project, at first read the whole specification. Try to figure out
what kind of data storing technique (for example structure, array etc.) would fit
for this project. It's enough to store 10 tasks. Try to make a concept in your head about how you will implement the
application.

### Basics (mandatory) tasks
- [Print usage](#print-usage)
- [Add new task](#add-new-task)
- [List tasks](#list-tasks)
- [Write to file](#write-to-file)
- [Read from file](#read-from-file)
- [Empty the list](#empty-the-list)
- [Remove task](#remove-task)
- [Add task error handling](#add-task-error-handling)
- [Remove task error handling](#remove-task-error-handling)

### Advanced tasks
- [Check task](#check-task)
- [Checked state](#checked-state)
- [Add priority to a task](#add-priority-to-a-task)
- [List tasks by priority](#list-tasks-by-priority)
- [Command error handling](#command-error-handling)
- [Check task error handling](#check-task-error-handling)

### Print usage
 - At application startup the following message should be shown:

```
Todo application
====================
Commands:
 -a   Adds a new task
 -wr  Write current todos to file
 -rd  Read todos from a file
 -l   Lists all the tasks
 -e   Empty the list
 -rm   Removes a task
 -c   Completes a task
 -p   Add priority to a task
 -lp  Lists all the tasks by priority
 ```

### Add new task
- While the application is running and `-a "Feed the monkey"` is entered
- Then it should add a new todo task (with the content `Feed the monkey`)
- If the todos are listed it should show up on the end

### List tasks
- By entering `-l`
- It should print the todos, it should add numbers before them when it prints it
- use `\t` to formatting

For example the content is:

```
List by number
====================
Num | Tasks
1   - Walk the dog
2   - Buy milk
3   - Do homework
4   - Do something
```

### Write to file
- While the application is running and `-wr "file.txt"` is entered
- Then it should write the todos from the memory into `file.txt`

### Read from file
- While the application is running and `-rd "file.txt"` is entered
- Then it should read the todos into the memory from `file.txt`

### Empty the list
- While the application is running and `-e` is entered
- Then all the todos should be deleted
- Also it should show a message like this: `No todos for today! :)`

### Remove task
- While the application is running and `-r 2` is entered
- Then it should remove the second item from the list
- If it is listed it should not show up

### Add task error handling
- While the application is running and `-a` is entered
- Thenit should show an error message like: `Unable to add: No task is provided`

### Remove task error handling

1)
- While the application is running and `-r` is entered
- Then it should show an error message like: `Unable to remove: No index is provided`

2)
- While the application is running and `-r 20` is entered
- Then it should show an error message, if there is no todo item on that index, like: `Unable to remove: Index is out of bound`

3)
- While the application is running and `-r apple` is entered
- Then it should show an error message like: `Unable to remove: Index is not a number`

### Check task
- While the application is running and `-c 3` is entered
- Then it should check the third item from the list
- If it is listed it should show up as checked

### Checked state
- While the application is running and `-l` is entered
- Then it should show the checked state for each task like:

```
List by number
====================
Num | Tasks | Prio
1 - [ ] Walk the dog
2 - [ ] Buy milk
3 - [x] Do homework
4 - [ ] Do something
5 - [ ] Feed the Monkey
```

### Add priority to a task
- While the application is running and `-p "Feed the monkey" 2` is entered
- Then it should add a tast with the content `Feed the monkey` and with priority `2`
- If the todos are listed it should show up on the end, for example:

```
List by priority
====================
Num | Tasks | Prio
1 - [ ] Walk the dog - 3
2 - [ ] Buy milk
3 - [ ] Do homework - 1
4 - [ ] Do something
5 - [ ] Feed the Monkey - 2
```

### List tasks by priority
- While the application is running and `-lp` is entered
- Then it should print the todos, it should list by priority numbers before them when it prints it.
- use `\t` to formating

So in this case for example the content is:
```
List by priority
====================
Num | Tasks | Prio
1 - [ ] Walk the dog - 3
2 - [ ] Feed the Monkey - 2
3 - [ ] Do homework - 1
4 - [ ] Buy milk
5 - [ ] Do something
```


### Add priority error handling
- While the application is running and `-p` is entered
- Then it should show an error message like: `Unable to add priority: No task is provided`

### Command error handling

- While the application is running and `-g` or with any other not listed commands
- Then it should show an error message like: `Unsupported argument`, also it should print the usage information

### Check task error handling
1)
- While the application is running and `-c` is entered
- Then it should show an error message like: `Unable to check: No index is provided`

2)
- While the application is running and `-c 20` is entered
- Then it should show an error message, if there is no todo item on that index, like: `Unable to check: Index is out of bound`

3)
- While the application is running and `-c apple` is entered
- Then it should show an error message like: `Unable to check: Index is not a number`

4)
- If your storage is full and you try to add more tasks
- Then it should show an error message like: `Unable to add more task`

## Solution
[Solution](https://github.com/greenfox-academy/teaching-materials/tree/master/project-hardware/solutions/solutions/todo-app)

