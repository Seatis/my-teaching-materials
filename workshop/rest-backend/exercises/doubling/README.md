# Doubling
- Create a `GET /doubling` endpoint
- That receives a query parameter: `input=15`
- And responds with a json object with the doubled amount of the input:
```json
{
  "received": 15,
  "result": 30
}
```
- if no input is provided:
```json
{
  "error": "Please provide an input!"
}
```
