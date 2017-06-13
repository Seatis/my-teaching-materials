# Tribes of Lagopus API specification
[Project description](https://github.com/greenfox-academy/teaching-materials/tree/master/team-project/tribes-of-lagopus)

## Registration

### `POST /register`
Creates a new User.

#### Request parameters
- `username` [String]
- `password` [String, optional]
- `kingdom` [String, optional, defaults to "`username`'s kingdom"]


e.g.:
```
{
  "username" : "Bond",
  "password" : "password123",
  "kingdom" : "MI6"
}

```

#### Response
- if all required parameters provided, returns a `HTTP 200` status with a mock `User` object:
```json
{
  "id" : 1,
  "username" : "Bond",
  "kingdomId" : 1
}
```

- if a required parameter is missing, returns a `HTTP 400` status with the following message:
```
{
  "status" : "error",
  "message" : "Missing parameter(s): username!"
}
```

## Login
Authenticates a user.

### `POST /login`

#### Request parameters
- `username` [String]
- `password` [String, optional]


e.g.:
```
{
  "username" : "Bond",
  "password" : "password123"
}
```

#### Response
- if all parameters are provided and username equals "Bond", it returns a `HTTP 200` status with a mock `User` object:
```json
{
  "id" : 1,
  "username" : "Bond",
  "kingdomId" : 1
}
```

- if all parameters are provided and username doesn't equals "Bond", it returns a `HTTP 401` status with the following message:
```
{
  "status" : "error",
  "message" : "No such user: <username>!"
}
```

- if all parameters are provided and password doesn't equals "password123", it returns a `HTTP 401` status with the following message:
```
{
  "status" : "error",
  "message" : "Wrong password!"
}
```

- if a required parameter is missing, returns a `HTTP 400` status with the following message:
```
{
  "status" : "error",
  "message" : "Missing parameter(s): <comma separated list of missing parameters>!"
}
```

## Kingdom

### `GET /[userId]/kingdom`
Gets all data of a kingdom.

#### Response
- `HTTP 200` status with a mock `Kingdom` object:
```json
{
  "id" : 1,
  "name" : "London",
  "userId" : 1,
  "buildings": [
    {
      "id" : 1,
      "type" : "townhall",
      "level": 1,
      "hp": 1
    }
  ],
  "resources": [
    {
      "type" : "food",
      "amount": 1,
      "generation": 1
    },
    {
      "type" : "gold",
      "amount": 1,
      "generation": 1
    }
  ],
  "troops": [
    {
      "id": 1,
      "level": 1,
      "hp": 1,
      "attack": 1,
      "defence": 1
    }
  ],
  "location": [1, 1]
}
```

### `PUT /[userId]/kingdom`
Modifies data of a kingdom.

#### Request parameters (all optional)
- `name` [String]
- `locationX` [int]
- `locationY` [int]


e.g.: 
```
{
  "name" : "MI5"
}
```

#### Response
- `HTTP 200` status with a mock `Kingdom` object:
```json
{
  "id" : 1,
  "name" : "London",
  "userId" : 1,
  "buildings": [
    {
      "id" : 1,
      "type" : "townhall",
      "level": 1,
      "hp": 1
    }
  ],
  "resources": [
    {
      "type" : "food",
      "amount": 1,
      "generation": 1
    },
    {
      "type" : "gold",
      "amount": 1,
      "generation": 1
    }
  ],
  "troops": [
    {
      "id": 1,
      "level": 1,
      "hp": 1,
      "attack": 1,
      "defence": 1
    }
  ],
  "location": [1, 1]
}
```
