# Array handler
- Create a `POST /arrays` endpoint
- That receives a relatively complex json object:
```json
{
  "what": "sum",
  "numbers": [1, 2, 5, 10]
}
```
- `what` can be 3 things: sum, multiply, double
- and responds with sum or multiplication of all elements in the numbers or with another array with the doubled elements:
  - eg. `/arrays` with `{"what": "sum", "numbers": [1,2,5,10]}` will respond `{"result": 18}`
  - eg. `/arrays` with `{"what": "multiply", "numbers": [1,2,5,10]}` will respond `{"result": 100}`
  - eg. `/arrays` with `{"what": "double", "numbers": [1,2,5,10]}` will respond `{"result": [2,4,10,20]}`
- if no what (or numbers) is provided:
```json
{
  "error": "Please provide what to do with the numbers!"
}
```
