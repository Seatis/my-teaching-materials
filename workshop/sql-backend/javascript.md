# Node.js and MySQL

## Training
| Material | Time |
|:---------|-----:|
| [How to Connect to MySQL Database from Node.Js](https://www.youtube.com/watch?v=XuLRKMqozwA) | 13:33 |
| [Using node mysql JavaScript client](https://www.sitepoint.com/using-node-mysql-javascript-client/) | 30 min |

## Docs for today's library
https://github.com/mysqljs/mysql

## Material review
- MySQL server
- Connection
   - Required fields
- Executing queries
- Sync or async?

### Package features: `mysql`

- `.createConnection`
- `.connect`
- `.end`
- `.query`

## Workshop

### Connect to database
```JavaScript
var mysql = require("mysql");

var conn = mysql.createConnection({
  host: "localhost",
  user: "'jaj'",
  password: "alma"
});

conn.connect(function(err){
  if(err){
    console.log("Error connecting to Db");
    return;
  }
  console.log("Connection established");
});

conn.end();
```


### Querying a database
```JavaScript
conn.query("SELECT * FROM table_name;",function(err,rows){
  console.log("Data received from Db:\n");
  console.log(rows);
});
```

### Error handling
```JavaScript
conn.query("SELECT * FROM table_name;",function(err,rows){
  if(err) {
    console.log(err.toString());
    return;
  }

  console.log("Data received from Db:\n");
  console.log(rows);
});
```

### MySQL and Express
 ```JavaScript
 var app = express();

 app.get('/', function(req, res) {
   conn.query('SELECT book_name FROM book_mast;',function(err,rows){
     if(err) {
       console.log(err.toString());
       return;
     }
     res.send(rows);
   });
 });
 ```

## Exercises

 - [Bookstore endpoints](workshop/bookstore.md)
 - [Import user data](workshop/import.md)
 