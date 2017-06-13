# Tribes of Lagopus API specification
- [Project description](https://github.com/greenfox-academy/teaching-materials/tree/master/team-project/tribes-of-lagopus)
- [Model descriptions](https://github.com/greenfox-academy/teaching-materials/tree/master/team-project/tribes_models.md)

## Registration

### `POST /register`
Creates a new User.

#### Request parameters
- `username` [String]
- `password` [String, optional]
- `kingdom` [String, optional, defaults to "`username`'s kingdom"]


e.g.:
```json
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

- if all required parameter provided, but username equals "occupiedUserName", it returns a `HTTP 409` status and the following error message:
```json
{
  "status" : "error",
  "error" : "Username already taken, please choose an other one."
}
```

- if a required parameter is missing, returns a `HTTP 400` status with the following message:
```json
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
```json
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
```json
{
  "status" : "error",
  "message" : "No such user: <username>!"
}
```

- if all parameters are provided and password doesn't equals "password123", it returns a `HTTP 401` status with the following message:
```json
{
  "status" : "error",
  "message" : "Wrong password!"
}
```

- if a required parameter is missing, returns a `HTTP 400` status with the following message:
```json
{
  "status" : "error",
  "message" : "Missing parameter(s): <comma separated list of missing parameters>!"
}
```

## Kingdom

### `GET /[userId]/kingdom`
Gets all data of a kingdom.

#### Response
- if userId is an existing userId, it returns a `HTTP 200` status with a mock `Kingdom` object:
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
  "location": {
    "x": 1,
    "y": 1
  }
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```

### `PUT /[userId]/kingdom`
Modifies data of a kingdom.

#### Request parameters (all optional)
- `name` [String]
- `locationX` [int]
- `locationY` [int]


e.g.: 
```json
{
  "name" : "MI5"
}
```

#### Response
- if userId is an existing userId, it returns a `HTTP 200` status with a mock `Kingdom` object:
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
  "resources": [{
      "type" : "food",
      "amount": 1,
      "generation": 1
    }, {
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
  "location": {
    "x": 1,
    "y": 1
  }
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```

## Buildings

### `GET /[userId]/kingdom/buildings`
Get the list of buildings of the kingdom

#### Response
- if userId is an existing userId, it returns a `HTTP 200` status with a mock list of `Building` objects:
```json
{
  "buildings" : [{
      "id" : 1,
      "type" : "townhall",
      "level": 1,
      "hp": 1
    }, {
      "id" : 2,
      "type" : "farm",
      "level": 1,
      "hp": 1
    }
  ]
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```

### `GET /[userId]/kingdom/buildings/[buildingId]`
Get the details of the certain building

#### Response

- if userId and buildingId are existing ids, it returns a `HTTP 200` status with a mock `Building` object:
```json
{
  "id" : 1,
  "type" : "townhall",
  "level": 1,
  "hp": 1
}
```

- if userId and/or buildingId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "<id> not found"
}
```

### POST /[userId]/kingdom/buildings
Creates a new building in the kingdom

#### Request parameters
- `type` [String, farm|mine|barracks]

e.g.:
```json
{
  "type" : "farm"
}
```

#### Response

- if type parameter is provided and it's a valid building type (farm|mine|barracks), it returns a `HTTP 200` response with a mock `Building` object:
```json
{
  "id" : 2,
  "type" : "farm",
  "level": 1,
  "hp": 1
}
```

- if type parameter is provided, but it's not a valid building type (farm|mine|barracks), it returns a `HTTP 400` response with the following error message:
```json
{
  "status" : "error",
  "message" : "Invalid building type!"
}
```

- if type parameter is missing, it returns a `HTTP 400` status and the following error message:
```json
{
  "status" : "error",
  "message" : "Missing parameter(s): type!"
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```


### PUT /[userId]/kingdom/buildings/[buildingId]
Upgrades or downgrades a building in the kingdom to a certain level

#### Request parameters
- `level` [int]

#### Response

- if level parameter is provided and it's more than 0 and the user has enough money for the upgrade, it returns a `HTTP 200` response with a mock `Building` object:
```json
{
  "id" : 2,
  "type" : "farm",
  "level": 1,
  "hp": 1
}
```

- if level parameter is provided and it's more than 0 BUT the user doesn't have enough money for the upgrade, it returns a `HTTP 400` response with the following error message:
```json
{
  "status" : "error",
  "message" : "Not enough gold!"
}
```


- if level parameter is provided, but it's less then 0 or not integer, it returns a `HTTP 400` response with the following error message:
```json
{
  "status" : "error",
  "message" : "Invalid building level!"
}
```

- if level parameter is missing, it returns a `HTTP 400` status and the following error message:
```json
{
  "status" : "error",
  "message" : "Missing parameter(s): type!"
}
```

- if userId and/or buildingId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "<id> not found"
}
```


## Resources

### `GET /[userId]/kingdom/resources`
Get the list of resources of the kingdom

#### Response
- if userId is an existing userId, it returns a `HTTP 200` status with a mock list of `Resource` objects:
```json
{
  "resources": [{
      "type" : "food",
      "amount": 1,
      "generation": 1
    }, {
      "type" : "gold",
      "amount": 1,
      "generation": 1
    }
  ]
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```

### GET /[userId]/kingdom/resources/[resourceType]
Get the details of a certain resource type

#### Response

- if userId is an existing id and resourceType is a valid resource type, it returns a `HTTP 200` status with a mock `Resource` object:
```json
{
  "type" : "gold",
  "amount": 1,
  "generation": 1
}
```

- if userId and/or resource type doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "<parameter> not found"
}
```

## Troops

### `GET /[userId]/kingdom/troops`
Get the list of troops in the kingdom

#### Response
- if userId is an existing userId, it returns a `HTTP 200` status with a mock list of `Troop` objects:
```json
{
  "troops": [
    {
      "id": 1,
      "level": 1,
      "hp": 1,
      "attack": 1,
      "defence": 1
    }, {
      "id": 2,
      "level": 1,
      "hp": 1,
      "attack": 1,
      "defence": 1
    }
  ]
}
```

- if userId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "UserId not found"
}
```


### GET /[userId]/kingdom/troops/[troopId]
Get the detail of a certain troop

#### Response

- if userId and troopId are existing ids, it returns a `HTTP 200` status with a mock `Troop` object:
```json
{
  "id": 1,
  "level": 1,
  "hp": 1,
  "attack": 1,
  "defence": 1
}
```

- if userId and/or troopId doesn't exist, it returns a `HTTP 404` status and the following error message:
```json
{
  "status" : "error",
  "message" : "<id> not found"
}
```
