# Tribes of Lagopus API specification
[Project description](https://github.com/greenfox-academy/teaching-materials/tree/master/team-project/tribes-of-lagopus)

## Registration

### `POST /register`

#### Request parameters
- `username` [String]
- `password` [String, optional]
- `kingdom` [String, optional, defaults to "`username`'s kingdom"]

#### Response
- a mock `User` object:
```
{
  "id" : 1,
  "username" : "Bond",
  "kingdomId" : 1
}
```

## Login

### `POST /login`

#### Request parameters
- `username` [String]
- `password` [String, optional]

#### Response
- a mock `User` object:
```
{
  "id" : 1,
  "username" : "Bond",
  "kingdomId" : 1
}
```

## Kingdom

### `GET /[userId]/kingdom`

#### Response
- a mock `Kingdom` object:
```
{
  "id" : 1,
  "name" : "London",
  "userId" : 1,
  "buildings": [],
  "resources": [],
  "troops": [],
  "location": [1, 1]
}
```

### `PUT /[userId]/kingdom`

#### Request parameters (all optional)
- `name` [String]
- `userId` [long]
- `locationX` [int]
- `locationY` [int]

#### Response
- a mock `Kingdom` object:
```
{
  "id" : 1,
  "name" : "London",
  "userId" : 1,
  "buildings": [],
  "resources": [],
  "troops": [],
  "location": [1, 1]
}
```


