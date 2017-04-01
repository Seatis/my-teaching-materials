# Objet-oriented programming
*Cognitive apprenticeship material ideas*

## Objectives
- Show them that already exciting thing could be built with the skillset they have learnt in this week
- Show them how we make a flowchart to demonstrate the logic of our thinking
- Show them how we resolve errors and how we use the debug tool for investigation
- Show them how we style our code and name variables
- By thinking out loud show them how we start to solve a problem, how we design the solution, how we break the task to smaller pieces
- It's NOT a goal for them to have a full understanding on all the logic we use, they won't be able to reproduce the same by their own right now. BUT they should start to get familiar with "developer thinking"


## Materials
I used the following materials in this exercise:

- Class
- Object
- Fields
- Encapsulation
- This
- New

## Live coding suggestions
### Before coding:
- Tell them the objectives
- Ask them to focus on the best practices, the ideas, the ways of thinking and NOT to understand the actual working of everything (it's not expected for them to be able to reproduce this right now)
- Ask them to keep attention, don't ask questions during the session, write notes about the things they learnt, noticed, we'll discuss these together after the live coding
- Tell them not to try writing the code simultaneously, the code will be available on github if they'd like to analyze it later
### While coding:
- Don't explain too much, because you'll run out of time. Just think out loud and write the code.
### After coding
- Tell them that this was not the "best" way to code this, there are better implementation solutions to get the same result, we'll learn about them later



## Example: LibraryApp 


### Author
Create an `Author` class.  It is designed to model a document's author. It contains:

 - Three private instance variables:     
   	  - `name` (String)
	  - `email` (String)
   	  - `nationality` (String)
 - One Constructor to initialize an author with the given values. 
 - A `toString()` method that returns similar to this: `Name: Author Name, Email: author@mail.com, Nationality: Hungary   `

### Document
A class called `Document` is designed  to model a single document written authors. It contains:

- Private instance variables:
	- `title` (String)
	- `authors` (Author list)
	- `status` (Boolean)
	- `type` (String)
- A constructor that create a single document.  
    

### Book
A class called `Book` is derived from  `Document` class.  It has a few more parameters and methods:

 - Private instance variables:
	- `year` (int)
	-  `subtype` (String)
 - `rent()` method:
	- change the status to `0`
	-  it has to fail if the book is not avaible
 - `takeBack()` method:
	- change the status to `1`
	-  it has to fail if the book is not avaible
 - `toString()` method that returns similar to this: `Author(s): A1,A2 , Title: Mybook,  Type: Fantasy, Year: 1982, Status: avaible`
	

### Magazine
A class called `Magazine` is derived from  `Document` class. It has a few more parameters and methods:

 - Private instance variables:
	- `period` (String)
	- `publishDate` (String)
	
 - `read()` method
 - `toString()` method that returns similar to this: `Title: MyMagazine,  Publish date: 2001/09 `
 



### Library
Create a `Library` class. It contains:

 - ` documents`  (` Document`  as a list)
 - ` searchByTitle(String Title)`  method: returns the first document's index what contains the input title.
 - ` searchByAuthor(String AuthorName)`  method: returns the first document's index what contains the input author name.

### LibraryApp
This contains the main() method (see below).



### Optional (depends on how much time you have): 

 - make a console-based administrative interface, where you can add instances of documents and authors
 - make an user class, where passwords stored by hashes of Strings
 - make a console based login-system where you can create users and log in the administrative interface with them 
  


