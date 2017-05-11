# Reddit Application API spec


## `GET /posts`

### Request
Headers:
 - Accept: application/json
 - (Optional) Username: username

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "posts": [
    {
      "id": 25,
      "title": "Dear JavaScript",
      "href": "http://9gag.com",
      "timestamp": 1494339525,
      "score": 791,
      (Optional) "owner": null,
      (Optional) "vote": 1
    },
    {
      "id": 74,
      "title": "Crockford",
      "href": "http://9gag.com",
      "timestamp": 1494138425,
      "score": 567,
      (Optional) "owner": "kristof4",
      (Optional) "vote": -1
    }
  ]
}
```

## `POST /posts`

### Request
Headers:
 - Accept: application/json
 - Content-Type: application/json
 - (Optional) Username: username

Body:
```json
{
  "title": "Crockford",
  "href": "http://9gag.com",
  (Optional) "owner": "Kristof4"
}
```

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 74,
  "title": "Crockford",
  "href": "http://9gag.com",
  "timestamp": 1494138425,
  (Optional) "owner": "kristof4",
  "score": 0
}
```

## `PUT /posts/<id>/upvote`

### Request
Headers:
 - Accept: application/json
 - (Optional) Username: username

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 74,
  "title": "Crockford",
  "href": "http://9gag.com",
  "timestamp": 1494138425,
  (Optional) "owner": "kristof4",
  "score": 1
}
```

## `PUT /posts/<id>/downvote`

### Request
Headers:
 - Accept: application/json
 - (Optional) Username: username

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 74,
  "title": "Crockford",
  "href": "http://9gag.com",
  "timestamp": 1494138425,
  (Optional) "owner": "kristof4",
  "score": -1
}
```
# Optional Feature endpoints

## `DELETE /posts/<id>`

### Request
Headers:
 - Accept: application/json

### Response
Status Code: 200

Headers:
 - Content-Type: application/json
 - Username: username

Body:
```json
{
  "id": 25,
  "title": "Dear JavaScript",
  "href": "http://9gag.com",
  "timestamp": 1494339525,
  "owner": null,
  "score": 791
}
```

## `PUT /posts/<id>`

### Request
Headers:
 - Accept: application/json
 - Content-Type: application/json
 - Username: username

Body:
```json
{
  "title": "modified title",
  "href": "http://facebook.com"
}
```

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 25,
  "title": "modified title",
  "href": "http://facebook.com",
  "timestamp": 1494339525,
  "owner": null,
  "score": 791
}
```
