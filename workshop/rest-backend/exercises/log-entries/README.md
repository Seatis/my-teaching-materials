# Log entries
- Create a log object which has the following fields:
  - createdAt - date and time
  - endpoint - string
  - data - string
- Create a database table for storing log objects
- Modify your previous endpoints to save a log object
  - where the createdAt will be the timestamp of the creation
  - the endpoint will be the name of the endpoint that was used when the object was created
  - the data will be received data (query params, received json data)
- Create a `GET /log` endpoint
- That responds with all the log entries from the database and the number of them:
```json
{
  "entries": [
    {
      "id": 1,
      "endpoint": "/doubling",
      "data": "input=15"
    },
    ...
  ],
  "entry_count": 11
}
```
