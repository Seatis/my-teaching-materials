# Greeter
- Create a `GET /greeter` endpoint
- that receives a query parameter `name=Petike&title=student`
- and responds with an awesome greeting json object:
```json
{
  "welcome_message": "Oh, hi there Petike, my dear student!"
}
```
- if e.g. no name (or title) is provided:
```json
{
  "error": "Please provide a name!"
}
```
