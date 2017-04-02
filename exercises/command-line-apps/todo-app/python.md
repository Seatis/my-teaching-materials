# Project: TODO Application

Write a command-line todo application to easily keep track of your day-to-day tasks.

Basics (mandatory):

 - Prints usage
 - A todo task has (at least) a completed state and a description
 - Add new tasks
 - Complete tasks
 - Remove tasks
 - List tasks

Advanced (optional):
 - Refactor the application to align with the proposed architecture
 - Write unittests for any unit it feels possible

### Stories
To follow the state of our projects and manage our work, we use so-called kanban boards.
They usually contains our tasks separated in columns (todo, doing, review, done).

Please create a kanban board for yourself and add the tasks (stories) that need to be done.
Later on, update your board, so you can always see your project's state and your next steps.

**How to create your kanban board and where to work?**
  - Create a new public repository with the name: your_github_handle-todoApp under greenfox-academy organization,
    and work in it later.
  - Develop your todo application in this repo
  - Add tag to your new repository with the name of your class (so we can find your project easily).
  - In your new repository: in the Projects view on Github, please create a new project called TODO Application
  - Then create your board. It should consist 4 columns:
    - Todo
    - Doing
    - Review
    - Done
  - Add stories to your board

You should not have 2 or more stories in Doing.
If you already have a few stories in Review show them to one of the mentors to push it to done.

#### Usage
 - Given the terminal opened in the project directory
 - When the application is ran by executing `python todo.py`
 - Then it should print the usage information:
```
Python Todo application
=======================

Command line arguments:
 -l   Lists all the tasks
 -a   Adds a new task
 -r   Removes an task
 -c   Completes an task
```


#### List
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -l`
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
 - http://www.tutorialspoint.com/python/python_command_line_arguments.htm
 - https://docs.python.org/3/tutorial/inputoutput.html
 - Ignore the storage file in the git repository using .gitignore


#### Empty List
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -l` and the file is empty
 - Then it should show a message like this: `No todos for today! :)`

#### Add new task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -a "Feed the monkey"`
 - Then it should add a new todo task (with the content `Feed the monkey`) to the file, if the todos are listed it should show up on the end

#### Add task error handling
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -a`
 - Then it should show an error message like: `Unable to add: No task is provided`

#### Remove task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -r 2`
 - Then it should remove the second item from the file, if it is listed it should not show up

#### Remove task error handling
1:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -r`
 - Then it should show an error message like: `Unable to remove: No index is provided`

2:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -r 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to remove: Index is out of bound`

3:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -r apple`
 - Then it should show an error message like: `Unable to remove: Index is not a number`

#### Argument error handling
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.pt -g` or with any other not listed arguments
 - Then it should show an error message like: `Unsupported argument`, also it should print the usage information

#### Missing file
 - Given the terminal opened in the project directory, and no storage file
 - When the application is ran by executing any command that uses the storage file
 - Then it should create a new storage file in the current directory

#### Checked state
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -l`
 - Then it should show the checked state for each task like:

```
1 - [ ] Walk the dog
2 - [ ] Buy milk
3 - [x] Do homework
```
The state of the todos should be stored in the storage file. (CSV is recommended)

#### Check task
 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -c 2`
 - Then it should check the second item from the file, if it is listed it should show up as checked

#### Check task error handling
1:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -c`
 - Then it should show an error message like: `Unable to check: No index is provided`

2:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -c 20`
 - Then it should show an error message, if there is no todo item on that index, like: `Unable to check: Index is out of bound`

3:

 - Given the terminal opened in the project directory, and a file that stores the todos
 - When the application is ran by executing `python todo.py -c apple`
 - Then it should show an error message like: `Unable to check: Index is not a number`


## Individual Workshop Review
Please follow the style guide: [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)

- Is the directory structure and the name of the files correct?
- Are the includes palced on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
- Can iterating over lists and arrays simplifed?
- Are the names of things following the styleguide?
- Are all of the brackets in the perfect place?
- Whitespaces, where they should be, where shouldn't?
