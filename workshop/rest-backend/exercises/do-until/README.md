# Do until
- Create a dynamic `POST /dountil/{what}` endpoint
- That receives a number in a json object:
```json
{
  "until": 15
}
```
- and responds with sum or multiplication of all elements until that number:
  - eg. `/dountil/sum` with `{"until": 5}` will respond `{"result": 15}`
  - eg. `/dountil/factor` with `{"until": 5}` will respond `{"result": 120}`
- if no number is provided:
```json
{
  "error": "Please provide a number!"
}
```
