# Frontend
- First create a new nodejs project
- Add dependencies: express (dont forget `--save` option!)
- Download the `assets` folder from [here](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/rest-backend/exercises/frontend) and place it under your project
  - move the `index.html` out to the main folder
- Create a route for getting `/`
  - render the static `index.html` here:
```javascript
res.sendFile(__dirname + '/index.html');
```
- Add serving static assets to serve your `assets` folder
- Try to run your app and check the index page!
- If you see a nice page where you can test the next exercises, proceed to the next one.
