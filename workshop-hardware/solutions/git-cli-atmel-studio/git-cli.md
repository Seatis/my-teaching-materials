## Command Line Basics: Solutions
### Basic terminal operations
- open a terminal with git
- check the current working directory:
```javascript
pwd
```
- check the files and directories in your working directory:
```javascript
ls
```
- create a Greenfox directory:
```javascript
mkdir Greenfox
```
- change into the Greenfox directory:
```javascript
cd Greenfox
```
- check the files and directories in your working directory:
```javascript
ls
```
- create an empty index.html file:
```javascript
touch index.html
```
- create an images directory:
```javascript
mkdir images
```
- create a css directory:
```javascript
mkdir css
```
- change into the images directory:
```javascript
cd images
```
- go back to the parent directory:
```javascript
cd ..
```
- create at least one file to every directory:
```javascript
cd images
touch my_image.jpg
cd ..
cd css
touch my_stylesheet.css
```
***
- Fork this git repository: https://github.com/greenfox-academy/git-lesson-repository.git and visit the page
- clone yout greenfox repositroy:
```javascript
git clone https://github.com/greenfox-academy/git-lesson-repository.git
```
### Manipulations
- change into the project directory:
```javascript
cd greenfox-academy
```

- list the detailed file and directory informations:
```javascript
ls -l
```

- copy the index.html into about.html:
```javascript
mv index.html about.html
```

- create a temp_images directory:
```javascript
mkdir temp_images
```

- copy 1.jpg and 2.jpg into temp_images directory:
```javascript
cd images
cp 1.jpg temp_images/
cp 2.jpg temp_images/
```

- copy every jpg file into temp_images directory:
```javascript
cp 3.jpg 4.jpg 5.jpg temp_images/
```

- delete 7.jpg from css directory:
```javascript
cd ..
cd css
rm 7.jpg
```


### Redirections
- echo a string to a :
```javascript
echo "mystring" > myfile.txt
```
- cat a file content and redirect the content to another file
```javascript
cat my_file.txt > another_file.txt
```
- redirect a file content to cat command:
```javascript
cat < myfile.txt
```

- count the words in index.html
```javascript
wc -w myfile.txt
```
- cat a file content and pipe to wc:
```javascript
```
- sort a file:
```javascript
sort myfile.txt
```
- sort a file and redirect the input to a file:
```javascript
sort myfile.txt > another_file.txt
```
- remove the duplicated lines from tasks.txt:
```javascript
uniq tasks.txt
```
- cat task.txt and filter basic tasks:
```javascript
grep "basic task" task.txt
```
- cat task.txt and filter out with -v the basic tasks:
```javascript
grep -v "basic task" task.txt
```

## Git
#### Basics
- setup your environtment:
```javascript
git config --global user.name "Your Name"
git config --global user.email yourname@example.com
```
***
- create a repo on github (under the greenfox-academy organisation and the repo name should be your github username)
- clone it on your system using command line:
```javascript
git clone https://github.com/greenfoxacademy/mygithubusername/myrepo.git
```

- then you have to shape your folder structure within your cloned repo like this:
```javascript
mkdir week-01
cd week-01
mkdir day-1
mkdir day-3
```

- change in to your githubusername directory:
```javascript
cd greenfox/mygithubusername
```
- see the changes:
```javascript
git status
```
- set to staged:
```javascript
git add .
```
- change in to your week-02/day-1 directory:
```javascript
cd week-02/day-1
```
- create 5 directory and 5 file with content:
```javascript
mkdir folder1 folder2 folder3 folder4 folder5
touch file1 file2 file3 file4 file5
mv file1 folder1/
#and so on...
```
***
- change in to your githubusername directory:
```javascript
cd mygithubusername
```
- see the changes
```javascript
git status
```
- add these files as staged files
```javascript
git add .
```
- use git status to check:
```javascript
git status
```
- commit it with commit message:
```javascript
git commit m 'My commit message'
```
- change the content of two file
- set to staged:
```javascript
git add .
```
- use git status:
```javascript
git add .
```
- commit it with commit message:
```javascript
git commit -m 'My commit message'
```
- git pull:
```javascript
git pull
```
- git push origin master:
```javascript
git push origin master
```
- check it on github
***
- change the content of two file
- use git status:
```javascript
git status
```
- remove from staged git reset HEAD file:
```javascript
git reset HEAD --
```
***
- change the content of two file
- use git status:
```javascript
git status
```
- set to staged:
```javascript
git add .
```
- git diff --staged or --cached:
```javascript
git diff --cached
```
- commit it:
```javascript
git commit -m 'valami'
```
- check it on github


