# GiTinder API specification
- [Project description](README.md)
- [Model descriptions](models.md)

## Login

### `POST /login`
Creates and/or logs in the user.

#### Request parameters (all required)
- `username` [String]
- `accessToken` [String]

e.g.:
```json
{
  "username" : "Bond",
  "accessToken" : "abcd1234"
}
```
#### Response
- if all required parameters provided, returns a `HTTP 200` status with an "ok" status and the "abc123" token (later this will be the application generated unique id (String) as a token of the user):

```json
{
  "status" : "ok",
  "token" : "abc123"
}
```
- if a required parameter is missing, returns a HTTP 400 status with the following message:
```json
{
  "status" : "error",
  "message" : "Missing parameter(s): username!"
}
```

## Profile

### `GET /profile`

#### Request header parameter

- X-GiTinder-token [String]


#### Response

- if X-GiTinder-token header parameter is provided and not empty, return with a mock `Profile` object:

```json
{
  "login" : "kondfox",
  "avatarUrl" : "https://avatars1.githubusercontent.com/u/26329189?v=3",
  "repos" : [
    "repo 1",
    "repo 2"
  ],
  "languages" : [
    "Java",
    "Javascript"
  ],
  "snippets": [
    "https://raw-snippet-url-1",
    "https://raw-snippet-url-2",
    "https://raw-snippet-url-3"
  ]
}
```
- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:
```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

## List of GiTinderers

### `GET /available/{page}`

#### Request header parameter
- X-GiTinder-token [String]

#### Request url parameter
- Page [integer, optional]

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with a list of `Profile` objects (the same as the `GET /profile` endpoint returns)
- a `count` field that shows how many profiles are in the returned list
- an `all` field that shows how many profiles are available
- if `page` is not provided the list should contain the first 10 profiles
- if `page` is provided, than the list should contain the `page`-th 10 profiles

```json
{
  "profiles": [
    <Profile Object 1>,
    <Profile Object 2>
    <Profile Object 3>,
    <Profile Object 4>
    <Profile Object 5>,
    <Profile Object 6>
    <Profile Object 7>,
    <Profile Object 8>
    <Profile Object 9>,
    <Profile Object 10>
  ],
  "count": 10,
  "all": 39
}
```

- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:

```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

- if we don't have new profiles for the given page parameter, returns a HTTP 204 status with the following message:

```json
{
  "status" : "ok",
  "message" : "No more available profiles for you!"
}
```

## Swiping

### `PUT /profiles/{username}/{direction}`

#### Request header parameter
- X-GiTinder-token [String]

#### Request url parameter
- username [String]
- direction [enum]: `left` or `right`

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with a status object:
  - where the `match` object is sent if that is a match already or not
```json
{
  "status" : "ok",
  "message" : "success",
  "match": {
    "username": "jondoe",
    "matched_at": 123456789,
    "messages": []
  }
}
```

- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:

```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

## Matches

### `GET /matches`

#### Request header parameter
- X-GiTinder-token [String]

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with a matches list:
```json
{
  "matches": [
    {
      "username": "jondoe",
      "avatar_url": "http://avatar.url",
      "matched_at": 123456789,
      "messages": []
    },
    {
      "username": "jondoe2",
      "avatar_url": "http://avatar2.url",
      "matched_at": 123456789,
      "messages": []
    }
  ]
}
```

- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:

```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

## Settings

### `GET /settings`

#### Request header parameter
- X-GiTinder-token [String]

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with the user's settings:
```json
{
  "enable_notifications": true,
  "enable_background_sync": true,
  "max_distance": 100,
  "preferred_languages": [
    "Java",
    "Python",
    "Javascript"
  ]
}
```

- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:

```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

### `PUT /settings`

#### Request header parameter
- X-GiTinder-token [String]

#### Request body
- a JSON object containing a subset of the possible setting fields (none of the fields are required), e.g.:
```json
{
  "max_distance": 100,
  "enable_notifications": true
}
```

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with the user's settings:
```json
{
  "enable_notifications": true,
  "enable_background_sync": true,
  "max_distance": 100,
  "preferred_languages": [
    "Java",
    "Python",
    "Javascript"
  ]
}
```

- if the header parameter is missing or empty, returns a HTTP 403 status with the following message:

```json
{
  "status" : "error",
  "message" : "Unauthorized request!"
}
```

## Messages

### `GET /messages`

#### Request header parameter
- X-GiTinder-token [String]

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with the user's settings:
```json
{
  "messages": [
    {
      "from": `<username>`,
      "to": `<username>`,
      "created_at": `<timestamp>`,
      "message": `<String>`
    }
  ]
}
```

### `POST /messages`

#### Request header parameter
- X-GiTinder-token [String]

#### Request body
- a JSON object containing a subset of the possible setting fields (none of the fields are required), e.g.:
```json
{
  "to": `<username>`,
  "message": `<String>`
}
```

#### Response
- if X-GiTinder-token header parameter is provided and not empty, return with the user's settings:
```json
{
  "status" : "ok",
  "message":
    {
      "from": `<username>`,
      "to": `<username>`,
      "created_at": `<timestamp>`,
      "message": `<String>`
    }
}
```
