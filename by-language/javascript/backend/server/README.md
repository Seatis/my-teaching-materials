# Creating a server in Node.js

## Objectives
 - practice setting up an npm project
 - serve content with node.js
 - write a todo app backend

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [The Net Ninja: Node JS Tutorial for Beginners #11 - Clients & Servers](https://www.youtube.com/watch?v=qSAze9b0wrY) | 6:12 |
| [The Net Ninja: Node JS Tutorial for Beginners #12 - Creating a Server](https://www.youtube.com/watch?v=lm86czWdrk0) | 9:30 |
| [The Net Ninja: Node JS Tutorial for Beginners #20 - The Node Package Manager](https://www.youtube.com/watch?v=kQ1j0rEI7EI) | 5:22 |
| [The Net Ninja: Node JS Tutorial for Beginners #21 - The package.json File](https://www.youtube.com/watch?v=_eRwjuIDJ2Y) | 5:08 |
| [The Net Ninja: Node JS Tutorial for Beginners #23 - Introduction to Express](https://www.youtube.com/watch?v=9TSBKO59u0Y) | 8:18 |
| [The Net Ninja: Node JS Tutorial for Beginners #24 - Express Route Params](https://www.youtube.com/watch?v=MuMs1pLuT7I) | 5:07 |
| [The Net Ninja: Node JS Tutorial for Beginners #25 - Template Engines](https://www.youtube.com/watch?v=oZGmHNZv7Sc) | 11:38 |
| [The Net Ninja: Node JS Tutorial for Beginners #26 - Template Engines ( part 2 )](https://www.youtube.com/watch?v=RczQp3zCPXs) | 4:37 |
| [The Net Ninja: Node JS Tutorial for Beginners #28 - Middleware & Static Files](https://www.youtube.com/watch?v=-lRgL9kj_h0) | 8:34 |
| [The Net Ninja: Node JS Tutorial for Beginners #29 - Query Strings](https://www.youtube.com/watch?v=QTAYRmMsVCI) | 9:25 |
| [The Net Ninja: Node JS Tutorial for Beginners #30 - Handling POST Requests](https://www.youtube.com/watch?v=rin7gb9kdpk) | 12:39 |
| [The Net Ninja: Node JS Tutorial for Beginners #31 - Making a To-do App (part 1)](https://www.youtube.com/watch?v=edOmvng5IQc) | 3:45 |
| [The Net Ninja: Node JS Tutorial for Beginners #32 - Making a To-do App (part 2)](https://www.youtube.com/watch?v=nleI7IbpGhc) | 11:45 |

## Material Review
- client
- server
- HTTP request
- request
- response
- socket
- port
- packet
- content-type
- status
- npm
- package.json
- express
- Routes
- Route params
- Views / Templates (ejs)
- query string
- GET, POST, PUT, DELETE
- Run a webserver with node
- curl

## Workshop

### Echo server with date
```javascript
var server = http.createServer(function(req, res) {
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end('Hey! How are you?');
});


server.listen(3000, '127.0.0.1');
```

#### Excercise
Create a webserver that can receive any request to any path.
It should respond the path name, the request methos and the current time.

### Rewrite it with express
```javascript
var app = express();

app.get('/', function(req, res) {
  res.send('Hey! How are you?');
});

app.listen(3000);
```

#### Excercise
Please rewrite the last example with express

### Todo app

#### Routes

All routes expects and returns JSON documents.

##### `GET /todos`

List all todo items.

    $ curl localhost:3000/todos/ -s | python -m json.tool
    [
        {
            "completed": false,
            "id": 1,
            "text": "Buy milk"
        },
        {
            "completed": false,
            "id": 2,
            "text": "Make dinner"
        },
        {
            "completed": false,
            "id": 3,
            "text": "Save the world"
        }
    ]

##### `GET /todod/:id`

Get a single todo item.

    $ curl localhost:3000/todos/1 -s | python -m json.tool
    {
        "completed": false,
        "id": 1,
        "text": "Buy milk"
    }

##### `POST /todos`

Create a new todo item. Use the body of the POST request. The request must have
the `Content-Type` header set to `application/json`.

The body of the request should be a JSON document:

    {
        "text": "Description of the item",
        "completed": false
    }

The `completed` field is optional and it will default to `false`.

Example:

    $ curl localhost:3000/todos -d '{"text": "Buy eggs"}' -H'Content-Type: application/json' -s | python3 -m json.tool
    {
        "id": 4,
        "text": "Buy eggs",
        "completed": false
    }

##### `PUT /todos/:id`

Update a todo item.

Similarly to the `POST /todos` request `Content-Type` must be set to `application/json` and the body of the request must be a JSON document.

    {
        "text": "Description of the item",
        "completed": false
    }

Every field is required.

Example:

    $ curl localhost:3000/todos/4 -d '{"text": "Buy eggs and sugar", "completed": true}' -H'Content-Type: application/json' -s -XPUT | python3 -m json.tool
    {
        "id": 4,
        "text": "Buy eggs and sugar",
        "completed": true
    }

##### `DELETE /todos/:id`

Delete a todo item.

    $ curl localhost:3000/todos/4 -XDELETE -s | python3 -m json.tool
    {
        "id": 4,
        "text": "Buy eggs and sugar",
        "completed": true,
        "destroyed": true
    }

##### Errors

If a todo item is not found `404` is returned

    $ curl localhost:3000/todos/42 -i
    HTTP/1.1 404 Not Found
    X-Powered-By: Express
    Content-Type: application/json; charset=utf-8
    Content-Length: 26
    ETag: W/"1a-k6qNFtmn7O8atwPHaaY6DA"
    Date: Sat, 09 Jan 2016 18:29:55 GMT
    Connection: keep-alive

##### Frontend

Connect the application with your frontend, by serving the applications html
on: `localhost:3000/index.html`

##### Filter `GET /todos`

List only the completed todo items.

    $ curl localhost:3000/todos/?completed=true -s | python -m json.tool
    [
        {
            "completed": true,
            "id": 2,
            "text": "Make dinner"
        },
        {
            "completed": true,
            "id": 3,
            "text": "Save the world"
        }
    ]
