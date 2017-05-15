# Rora's Cargo

- Rocket is loading the ship with ammunitions!
- Create a `GET /rocket` endpoint
- That responds with the list of our actual cargo like below:
```json
{
  "caliber25": 0,
  "caliber30": 0,
  "caliber50": 0,
  "shipstatus": "empty",
  "ready": false
}
```
- Create a `GET /rocket/fill` endpoint
- That receives a query parameter: `caliber=.50&amount=5000`
- And responds with a status json object like below:
```json
{
  "received": ".50",
  "amount": 5000,
  "shipstatus": "40%",
  "ready": false
}
```
- The ship can hold a maximum of 12500 amount
- If your cargo is full, you are ready to fly
- Write a test where you check:
  - The overall status of the ship
  - The status when you fill some items
  - That the shipstatus is:
    - "empty" when its 0%
    - "40%" when its 40%
    - "full" when its 100%
    - "overloaded" when its above 100%
  - That `ready` is true, when shipstatus is "full",
  - else its false
  - That without giving a parameter the status is not ok,
  - and the given error respone is the same as expected

  [![](assets/rocket.jpg)](https://www.youtube.com/watch?v=8XnOeLcKhIk)