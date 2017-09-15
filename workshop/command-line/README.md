# The Command line & Git
Start to use the command line for running programs and manipulating files.
Introduction to version control systems and Git.

## Objectives
 - Traversing in directories
 - Copy, move, delete and modify Files
 - Run commands and programs
 - Understanding pipe
 - Understanding the Basics of Git
   - Staging
   - Commit
   - Push
   - Cloning

## Materials & Resources
### Environment
 -  Install git on your system:
    -  Windows (*portable* is good however the *installed* version is better)
       -  Ensure you have the command-line, bash version also which you can find at
    http://cmder.net/ or https://git-scm.com/download/win
    -  Linux
       -  `sudo apt-get install git` (Ubuntu)
       -  `sudo yum install git` (Fedora)
    -  Mac
       -  http://git-scm.com/download/mac or `brew install git`
 -  Download Git-it for your system:
    -  [Windows](https://github.com/jlord/git-it-electron/releases/download/4.3.3/Git-it-Win-ia32.zip)
    -  [Linux](https://github.com/jlord/git-it-electron/releases/download/4.3.3/Git-it-Linux-x64.zip)
    -  [Mac](https://github.com/jlord/git-it-electron/releases/download/4.3.3/Git-it-Mac-x64.zip)

### Training
| Material | Duration |
|:---------|-----:|
| [Linux Terminal Tutorial Episode 1: Back to Basics](https://www.youtube.com/watch?v=2FiQSLdnBqA) | 11:32 |
| [Code Academy Command Line](https://www.codecademy.com/learn/learn-the-command-line) | - |
| [Git Tutorial for Beginners: Command-Line Fundamentals](https://www.youtube.com/watch?v=HVsySz-h9r4) | 30:32 |


### Optional
*If you've got time and/or want to dig deeper, consider the following:*

 - Proceed to read the next 2 chapters of git https://git-scm.com/book/en/v2
 - Try https://try.github.io/
 - GIT, the simple guide: http://rogerdudler.github.io/git-guide/
 - Bookmark: http://ohshitgit.com/
 - Windows users might enjoy [Total Commander](https://www.ghisler.com/)

## Material Review
 - `cd`
 - `.` and `..`
 - `pwd`
 - `ls`
 - `touch`
 - `mkdir`
 - `cp`
 - `mv`
 - `rm`
 - command options
 - `<` and `>` and `>>` and `|`
 - `sort`
 - `uniq`
 - `grep`
 - `sed`
 - `git` `init`, `clone`, `add`, `rm`, `commit`, `push`, `pull`, `remote`, `fork`
 - useful keyboard shortcuts
    - ALT+tab, CTRL+tab, CTRL+1-9
    - Command history (`up`, CTRL+r)
    - how to exit the Vi editor

## Workshop
  - Try to work without using your mouse; only use it if there's no other way (try to force yourself to learn the keyboard shortcuts; this improves your productivity)
  - Command-line
    - setup the environment
    - basic terminal operations
    - manipulations
    - redirections
    - scripts
  - Git
    - basics
    - workflow
    - getting used to
    - saving all your previous work
    - creating a website yaaay :)

## Tasks in detail

### Command Line Basics
  - Open a terminal (with git ;) )

#### Basic terminal operations
  - Check the current working directory
  - Check the files and directories in your working directory
  - Create a `greenfox` directory
  - Change into the `greenfox` directory
  - Check the files and directories in your working directory
  - Create an empty index.html file
  - Create an images directory
  - Create a css directory
  - Change into the images directory
  - Go back to the parent directory
  - Create at least one file to every directory using the command line
  - Create a `first-task` directory into `greenfox`
  - Move every file and folder from `greenfox` to `first-task`
  - From this point do everything in the `greenfox` directory

### Starting up Git
  - Run the downloaded Git-it App
  - Do the Challenges until `Branches Aren't Just For Birds` (you don't need to start this one)
    - We won't need branches at this point
    - If you finished all the challenges including `Forks and Clones` as the last one, proceed with the following:
  - Fork this git repository: https://github.com/greenfox-academy/git-lesson-repository.git
      - Visit the page
      - Fork it!
  - Clone your `git-lesson-repository` into your `greenfox` directory
      - `git clone <repository>`
      - Clone the forked version, not the original! (The url should be ...yourgithub/git-lesson-repository... not greenfox-academy/git-lesson-repository...)

#### Manipulations
  - Change into the project directory
  - List the detailed file and directory informations
  - Copy the index.html into about.html
  - Create a temp_images directory
  - Copy 1.jpg and 2.jpg into temp_images directory
  - Copy every jpg file into temp_images directory
  - Move 6.jpg file from css into images directory
  - Delete 7.jpg from css directory
  - Navigate up one directory from project/css/ to project/
  - Commit your changes and push (check it on github if you like)

#### Redirections
  - Echo a string to a file
  - cat a file content and redirect the content to another file
  - redirect a file content to cat command
  - count the words in index.html
  - cat a file content and pipe to wc
  - sort a file
  - sort a file and redirect the input to a file
  - remove the duplicated lines from tasks.txt
  - cat tasks.txt and filter basic tasks
  - cat tasks.txt and filter out with -v the basic tasks
  - Commit your changes and push (check it on github if you like)

#### Your working environment
  - create a repo on github (repo = short for repository)
      - under the [greenfox-academy](https://github.com/greenfox-academy) organisation and the repo's name should be your github username
  - clone it on your system using command line into your `greenfox` folder
  - your working directory should look like this
      - home
          - user (your username if you're using mac or linux, on windows its git env username)
              - .hidden_directories...
              - greenfox
                  - **githubusername (this should be the cloned repo, which is named after your github username, so the folder on your computer should be named that way as well)**
                      - **week-01**
                         - **day-1**
                              - contents created on your first day
                          - **day-3**
              - other_visible_directories
      - create the folder structure for the first week and a days that passed
        - you don't need a folder for the training day ;)
      - you can revisit the [folder structure](https://github.com/greenfox-academy/definitions/blob/master/github-usage.md#folder-structure) anytime in the definitions as well
      - move the first day contents to `day-1`
      - move the `first-task` folder to `day-2` or `day-3`
      - **repository folder inside repository folder won't work!**
        - so don't move the `git-lesson-repository` inside this folder structure, that's a different repo
        - or any other cloned folders
        - the different repositories should be under the `greenfox` folder sitting next to each other:
        - `greenfox`
          - `githubusername`
          - `git-lesson-repository`
          - `patchwork`

#### Practice a little more
  - change in to your `githubusername` directory
  - see the changes
  - set to staged
  - commit with a nice understandable commit message
      - it's nice if you can write commit messages to complete the following
      - "If this commit is applied it will..."
      - ...create my working directory for greenfox lessons
      - ...create a new directory for task 1
      - ...
  - change in to your `week-01/day-2` or `day-3` directory (depending on which day it is currently)
  - create 5 directory and 5 file with content
  - see the changes
  - add these files as staged files
  - use git status to check
  - commit it with commit message
  - change the content of two file
  - set to staged
  - use git status
  - commit it with commit message
  - git pull
  - git push origin master
  - check it on github

#### And some more
  - change the content of two file
  - use git status
  - remove from staged git reset HEAD file
  - change the content of two file
  - use git status
  - set to staged
  - git diff --staged or --cached
  - commit it
  - check it on github

#### Build Habits
*Get used to saving your work!*
  - From tomorrow you'll only work in one repository found under the [greenfox-academy](https://github.com/greenfox-academy)  organisation
    - easier to track everything related to your progress in one repository
    - we won't learn how to create git repositories inside other git repositories, but a link would be nice for today's learning curves ;)
    - create a README.md file in your main greenfox repository root with URLs pointing to your other repositories you have created today
    - check out how to create a link in Markdown syntax: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#links
    - create a link for your syllabus repo with a nice title (stage, commit and push)
    - for more details check out [github-usage](https://github.com/greenfox-academy/definitions/blob/master/github-usage.md) in definitions

#### Creating a website
*The cherry on the cake for today*
Create a new repo under your username at github called yourgithubusername.github.io
  - Make a local version of it (clone)
      - Pay attention not to clone inside another git repo!
  - Create an index.html file with content, images and styling or
      - use the ones from first day or
      - use the provided files (in the template folder)
  - push!
  - see your website at http://githubusername.github.io
  - note, this is another repo, so you should include links in your main README.md
      - about the website
      - and the repository as well

## Individual Workshop Review
Please check if all files is published to GitHub
