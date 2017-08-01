# Contributing to definitions

## Coding Rules

With the exceptions listed below, we follow the rules contained in
[Google's Markdown Style Guide](https://github.com/google/styleguide/blob/gh-pages/docguide/style.md):

 -  **Lists**: Use `-` as bullets instead of `*`
 -  **Nested list spacing**: Use a single space before a bullet or a numbered list
    ```markdown
     1. One space after a numbered list.
        Four space indent for wrapped text.
     2. One space again.

     -  Two spaces after a bullet.
        Four space indent for wrapped text.
         1. One space after a numbered list.
            Eight space indent for the wrapped text of a nested list.
         2. Looks nice, don't it?
     -  Three spaces after a bullet.

     -  Two spaces after a bullet.
        Four space indent for wrapped text.
         -  Two spaces after a bulleted list.
            Eight space indent for the wrapped text of a nested list.
         -  Looks nice, don't it?
     -  Three spaces after a bullet.

    ```

## Git Commit Guidelines

Read this article how to write meaningful commit messages:
[How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/)

With the expectations listed below, we follow the rules contained in
[Angular.js's Git Commit Guidelines](https://github.com/angular/angular.js/blob/master/CONTRIBUTING.md#-git-commit-guidelines):

 -  **Type**: Must be one of the following
     -  **feat**: A new definition, exercise, workshop or material
     -  **fix**: A bug fix
     -  **refactor**: A code change that neither fixes a bug nor adds a feature
     -  **style**: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
     -  **chore**: Changes to the build process or auxiliary tools and libraries such as documentation generation

## Submission Guidelines

Before you submit your changes consider the following guidelines:
 -  We use Pull Requests for reviewing definitions and materials
 -  The pull request must be reviewed by an other mentor
 -  Delete your branches after the pull request is merged


## Directory structure of this repository

### Description of root folders

We have several type of materials each of them go in their separate folder:
-  [workshop](workshop): full or half day workshops containing the homework materials, the materials review and the exercises
-  [cognitive-apprenticeship](cognitive-apprenticeship): 1-2 hour long coding practice for experienced mentors in front of mentees
-  [dojo](dojo): half day workshop containing only exercises without any new lectural material
-  [project](project): multiple day long single person exercise containing specification, user stories / mockups / design
-  [team-project](team-project): multiple week long multiple person exercise containing specification, user stories, api documentation
-  [material](material): only lectural materials without any exercises
-  [interview](interview): job interview related materials and exercises
-  [by-language](by-language): currently contains all deprecated workshops in a previous structure
-  [styleguide](styleguide): coding styleguide rules

### Lower level directory structure

#### Any workshop folder
- The folder name is the title of the workshop
-  If the outline and the exercises are language independent:
    -  **README.md**: materials and outline
    -  **exercises**:
        -  **README.md**: exercise specification
        -  **tests**:
            -  If unittest:
                -  **test_exercise-name.ext**
            -  If IO test:
                -  **test_exercise-name.json**
-  If not language independent:
    -  **language.md**: materials and outline for the language
    -  **exercises**:
        -  **exercise-name**:
            -  **language.ext**: a language specific boilerplate containing the exercise specification as comments
        -  **tests**:
            -  If unittest:
                -  **test_exercise-name.ext**
            -  If IO test:
                -  **test_exercise-name.json**

**For example**:

```
example-workshop
  ├ hello-me
  | ├ tests
  | | └ test_hellome.json
  | ├ c.md
  | ├ java.md
  | ├ python.md
  | └ javascript.md
  ├ draw-pyramid
  | ├ tests
  | | └ test_draw_pyramid.json
  | ├ draw_pyramid.c
  | ├ DrawPyramid.java
  | ├ draw_pyramind.py
  | └ draw-pyramid.js
  ├ motionless
  | ├ tests    
  | | ├ test_motionless.c
  | | ├ TestMotionless.java
  | | ├ test_motionless.py
  | | └ motionless.test.js
  | ├ motionless.c
  | ├ Motionless.java
  | ├ motionless.py
  | └ motionless.js
  ├ c.md
  ├ java.md
  ├ python.md
  └ javascript.md
```

## Writing tests

There are two different style of testing that we use: unittests and "IO-tests".
The meaning of IO-tests:
There are exercises where students don't need to write functions. These contains very basic tasks, such as declare a variable and print it or ask for a user input and print it. To test the solutions for these kind of tasks, we write IO tests which are looking for outputs which are fitting with defined regex's.
These IO "tests" need to be written in ```json``` files in a specified strucutre. To understand better how tests should be look like, check out the examples below.

### IO tests with no input

#### **Exercise:**

**hello_me.py**

```
# Modify this program to greet you instead of the World!
print("Hello, World!")
```
#### **Test:**

**test_hello_me.json**


```
{
  "cases": [
    {
      "ex_input" : [],
      "ex_output" : "^Hello, (?!World)[a-zA-Z]+!$"
    }
  ]
}
```

### IO tests with input

#### **Exercise:**

**draw_trianlge.py**

```
# Write a program that reads a number from the standard input, then draws a
# triangle like this:
#
# *
# **
# ***
# ****
#
# The triangle should have as many lines as the number was
```
#### **Test:**

**test_draw_triangle.json**

```
{
  "cases": [
    {
      "ex_input" : ["1"],
      "ex_output" : ["^\\*$"]
    }
    {
      "ex_input" : ["2"],
      "ex_output" : ["^\\*$", "^\\*{2}$"]
    }
    {
      "ex_input" : ["5"],
      "ex_output" : ["^\\*$", "^\\*{2}$", "^\\*{3}$", "^\\*{4}$", "^\\*{5}$"]
    }
  ]
}
```
