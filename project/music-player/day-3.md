
# Day 3: Database and functional REST API

## Stories

### Design the database

Here's a *suggested* schema, implement it in MySQL

- You'll need two tables
	- Playlists
		- id: INT, AUTO INCREMENT
		- playlist: TINYTEXT
		- system: TINYINT(1) // For the favorites functionality, default 0
	- Tracks
		- id: INT, AUTO INCREMENT
		- path: TINYTEXT
		- playlist_id: INT

Insert the "Favorites" playlist by hand (like animals do) and set "system" to 1. 
This will keep it protected from accidental deletion. 

### REST API
- Implement the REST API [according to the specification](specification.md)
- For extracting ID3 tags from MP3 files, use https://github.com/leetreveil/musicmetadata

### Run tests
- Run the tests you created yesterday (of course you did, didn't you?) ;)
