#Yondu's Arrow

- Create a `GET /yondu` endpoint
- That receives a query parameter: "distance=100.0&time=10.0"
- (Speed = Distance / Time)
- And responds with the calculated speed of the arrow:
```json
{
  "distance": 100.0,
  "time": 10.0,
  "speed": 10.0
}
```
- Try time with zero! Look what happens!
- Write a test where you check:
  - With giving a parameter the status is ok,
  - and the given respone is the same as expected
  - That without giving a parameter the status is not ok,
  - and the given error respone is the same as expected

  [![](assets/yondu.jpg)](https://www.youtube.com/watch?v=68ugkg9RePc)