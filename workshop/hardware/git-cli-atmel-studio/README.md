# The Command line & Git
Start to use the command line for running programs and manipulating files.
Introduction to version control systems and Git.

## Summary
 - [Objectives](#objectives)
 - [Materials & Resources](#materials-&-resources)
 - [Material Review](#material-review)
 - [Workshop](#workshop)

## Objectives
  - Know what kind of main components a microcontroller has
  - Learn how these components work
  - Get familiar with the command-line and GIT
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
  - Software needed during this week
    - Make sure that Code::Blocks is installed on your machine
    - Install Atmel Studio on your machine
    - Complete installation guide can be found [here](https://github.com/greenfox-academy/totoro-syllabus/blob/master/IDE-Installation-Guide.md).
  - Software needed for this workshop
    - Install git on your system:
       - Windows (*portable* is good however the *installed* version is better)
         - Ensure you have the command-line, bash version also which you can find at
         http://cmder.net/ or https://git-scm.com/download/win
       - Linux
         - `sudo apt-get install git` (Ubuntu)
         - `sudo yum install git` (Fedora)
       - Mac
         - http://git-scm.com/download/mac or `brew install git`
      - Windows users might enjoy [Total Commander](https://www.ghisler.com/)

### Training
#### Electronics
Watch these videos on electronic signals:

| Material | Duration |
|:---------|-----:|
| [What is AC and DC?](https://www.youtube.com/watch?v=vN9aR2wKv0U) | 4:22 |
| [Difference between Analog and Digital](https://www.youtube.com/watch?v=WxJKXGugfh8) | 4:01 |
| [Analogue and Digital Signals](https://www.youtube.com/watch?v=XCu6L4kQF3k) | 2:53 |

Also read this article
about the differences between analog and digital signals.
The "Analog and Digital Circuits" section is not needed.

| Material | Duration |
|:---------|-----:|
| [Analog vs. Digital](https://learn.sparkfun.com/tutorials/analog-vs-digital) | - |

Watch these videos on basic digital components:

| Material | Duration |
|:---------|-----:|
| [Boolean Logic & Logic Gates](https://www.youtube.com/watch?v=gI-qXk7XojA) | 4:01 |
| [Logic Gates from Transistors: Transistors and Boolean Logic](https://www.youtube.com/watch?v=SW2Bwc17_wA) | 13:59 |
| [Summary of logic gates and their truth tables](http://www.ee.surrey.ac.uk/Projects/CAL/digital-logic/gatesfunc/) | - |

These gates can be used to do lot's of stuff, every digital circuit is based on
logic gates. We are going to use a microcontroller during the next workshop, so
let's take a closer look at it's architecture.

These videos will help you to understand the basic components. You don't have to
understand every little bit of information, just try to understand the concept of
 ALU, RAM, registers. Magic word: Abstraction!

| Material | Duration |
|:---------|-----:|
| [How Computers Calculate - the ALU](https://www.youtube.com/watch?v=1I5ZMmrOfnA) | 11:09 |
| [Registers and RAM](https://www.youtube.com/watch?v=fpnE6UAfbtU) | 12:16 |
| [The Central Processing Unit (CPU)](https://www.youtube.com/watch?v=FZGugFqdr60) | 11:37 |

I know, I know. It was a bit hard to understand, but you can find these components
in our microcontroller.
[Here](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf)
you can find it's datasheet. (The datasheet is a document
which contains information of the usage and parameters of an electric component.)

Take a look at page 13. Can you recognize the previously learned components?

The datasheet has 461 pages, it's a lot. Don't start to read it, we will get
into it later this week.

#### Command-line and GIT
Watch these videos on our main topic:

| Material | Duration |
|:---------|-----:|
| [Linux Terminal Tutorial Episode 1: Back to Basics](https://www.youtube.com/watch?v=2FiQSLdnBqA) | 11:32 |
| [Code Academy Command Line](https://www.codecademy.com/learn/learn-the-command-line) | - |
| [Git Tutorial for Beginners: Command-Line Fundamentals](https://www.youtube.com/watch?v=HVsySz-h9r4) | 30:32 |

#### Optional
*If you've got time and/or want to dig deeper, consider the following:*

 - Proceed to read the next 2 chapters of git https://git-scm.com/book/en/v2
 - Try https://try.github.io/
 - GIT, the simple guide: http://rogerdudler.github.io/git-guide/
 - Bookmark: http://ohshitgit.com/

## Material Review

### Electronics
- AC vs DC signals
  - AC and DC usage for voltage?!
  - mistake in the first video, the bulb actually flashes 100 times/sec
- analog signal properties
  - amplitude
  - period
  - frequency
- differences between analog and digital signals
  - digital is also analog  
- truth tables
- logic gates and symbols
  - NOT
  - NOR/OR
  - AND/NAND
  - XOR
- ALU
  - Abstraction levels
  - OP code
- RAM and registers
  - RS flip-flop
  - register
  - RAM
    - address
    - data
- CPU
  - control unit
    - instruction address register
    - instruction register
    - flags
  - ALU
  - CPU registers
  - clock

### Command-line and Git
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

## Tasks in detail

### Command Line Basics
 - Open a terminal (with git ;) )

#### Basic terminal operations
 - Check the current working directory
 - Check the files and directories in your working directory
 - Create a Greenfox directory
 - Change into the Greenfox directory
 - Check the files and directories in your working directory
 - Create an empty index.html file
 - Create an images directory
 - Create a css directory
 - Change into the images directory
 - Go back to the parent directory
 - Create at least one file to every directory

---
 - Fork this git repository: https://github.com/greenfox-academy/git-lesson-repository.git
     - Visit the page
     - Fork it!
 - Clone your greenfox repository
     - `git clone <repository>`

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

#### Redirections
 - Echo a string to a file
 - cat a file content and redirect the content to another file
 - redirect a file content to cat command
 - count the words in index.html
 - cat a file content and pipe to wc
 - sort a file
 - sort a file and redirect the input to a file
 - remove the duplicated lines from tasks.txt
 - cat task.txt and filter basic tasks
 - cat task.txt and filter out with -v the basic tasks

### Git

#### Basics
 - setup your environtment
 - `git config --global user.name "Your Name"`
 - `git config --global user.email yourname@example.com`

---
 - create a repo on github
     - under the [greenfox-academy](https://github.com/greenfox-academy) organisation and the repo name should be your github username
 - clone it on your system using command line
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

---
 - change in to your githubusername directory
 - see the changes
 - set to staged
 - commit with a nice understandable commit message
     - it's nice if you can write commit messages to complete the following
     - "If this commit is applied it will..."
     - ...create my working directory for greenfox lessons
     - ...create a new directory for task 1
     - ...
 - change in to your week-02/day-1 directory
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

---
 - change the content of two file
 - use git status
 - remove from staged git reset HEAD file

---
 - change the content of two file
 - use git status
 - set to staged
 - git diff --staged or --cached
 - commit it
 - check it on github

#### Build Habits
*Get used to saving your work!*
 - Save the Command-line edits
   - change back to the directory where you completed the Command-line phase
   - this should be a git repository as well
   - stage and commit the changes, and push it to your remote repo
   - see it on Github
 - From tomorrow you'll only work in one repository found under the [greenfox-academy](https://github.com/greenfox-academy)  organisation
   - easier to track everything related to your progress in one repository
   - we won't learn how to create git repositories inside other git repositories, but a link would be nice for today's learning curves ;)
   - create a README.md file in your main greenfox repository root
   - check out how to create a link in Markdown syntax: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#links
   - create a link for your syllabus repo with a nice title (stage, commit and push)
   - for more details check out [github-usage](https://github.com/greenfox-academy/definitions/blob/master/github-usage.md) in definitions

## Individual Workshop Review
Please check if all files is published to GitHub
