# Backend storires

### 0. Initialize a node package in this folder.
- the test command should be `node test.js`

### 1. Plan and create your database

The database should store the user's tasks. Every task should have a unique, auto increment id, a title and a state (done or not). The task's name needs to be at least 3 charachter long, but not longer than 100 charachters.

### 2. Create the given [endpoints](todo-endpoints.md) in Express.js

According to the specification create the endpoints on the server side.

### 3. Create database queries

Write the MySQL queries that return live data from your database.

### 4. Test with `Tape`

Create tests to the new todo inputs:
 - Insert a new todo item to the DB, check if it's inserted
 - Test if the insert endpoint accepts todos with length out of range (3-100)
 - They mustn't contain any of the following words: CREATE, DROP, INSERT, SELECT
