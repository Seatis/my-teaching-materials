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
      "body": "little description of the post",
    	"timestamp": 1494339525,
    	"owner": null,
    	"score": 791
    },
    {
      "id": 74,
    	"title": "Crockford",
      "body": "lorem ipsum dolor sit amet",
    	"timestamp": 1494138425,
    	"owner": "kristof4",
    	"score": 567
    }
  ]
}
```

## `POST /posts`

### Request
Headers:
 - Accept: application/json
 - Content-Type: application/json

Body:
```json
{
  "title": "Crockford",
  "body": "lorem ipsum dolor sit amet",
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
  "timestamp": 1494138425,
  (Optional) "owner": "kristof4",
  "score": 0
}
```

## `PUT /posts/<id>/upvote`

### Request
Headers:
 - Accept: application/json

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 74,
  "title": "Crockford",
  "timestamp": 1494138425,
  (Optional) "owner": "kristof4",
  "score": 1
}
```

## `PUT /posts/<id>/downvote`

### Request
Headers:
 - Accept: application/json

### Response
Status Code: 200

Headers:
 - Content-Type: application/json

Body:
```json
{
  "id": 74,
  "title": "Crockford",
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

Body:
```json
{
  "id": 25,
  "title": "Dear JavaScript",
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

Body:
```json
{
  "title": "modified title"
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
  "timestamp": 1494339525,
  "owner": null,
  "score": 791
}
```
