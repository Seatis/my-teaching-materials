# Bookstore endpoints

Use the bookstore (data.sql) database form the previously completed SQL basics workshop. 

## List books titles

 - Create an API endpoint that lists all book names
 - Return HTML that contains the list

## All books with full data

 - List the following data: 
	- book title
	- authors name
	- category
	- publishers name
	- price
- Return HTML that contains the list as a `<table>`

## Create filters

 - Add filtering options to the previous endpoint
 - If a filter exists, only list records when the cell matches the filter's value
 - Implement these filters as query string parameters:
	 - Category as `category`
	 - Publisher as `publisher`
	 - Price lower than as `plt`
	 - Price greater than as `pgt`
 - Multiple filters can be present at the same time

For example `/books?category=Science` should only return books in the Science category.
