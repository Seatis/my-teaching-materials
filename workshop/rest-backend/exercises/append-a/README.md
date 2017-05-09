# AppendA
- Create a dynamic `GET /appenda/{appendable}` endpoint
- that responds with the appended `a`:
  - eg. `/appenda/kuty`
- responds with:
```json
{
  "appended": "kutya"
}
```
- if no appendable is provided, thats a different endpoint
- so the server should respond with `404`
