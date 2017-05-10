# XHR
Talking to a server

## Objectives  

 -  Learn how to talk to a server
 -  Make use of async calls
 -  Play with API-s
 -  Progress on weekly project's API

## Outline & Purpose  

| *Input Skills* | *Output Skills* |  
|:---------------|----------------:|  
| HTML, CSS, experience with DOM manipulation | Some experience in work with APIs |  
| Experience with JS building blocks, more complex functions | Experience in creating httpRequests |  
| Little experience with async functions (setTimeout, callbacks) | Understanding AJAX |  
| Little knowledge with object orientation in JS | Experience in DOM manipulation depending request response |  

## Materials & Resources  

| Material | Time |
|:---------|-----:|
| [AJAX Tutorial - 1 - Introduction to AJAX](https://www.youtube.com/watch?v=tp3Gw-oWs2k) | 4:45 |
| [AJAX Tutorial - 2 - Some Examples of AJAX](https://www.youtube.com/watch?v=-1RLW7a8Gr4) | 3:43 |
| [Asynchronous JavaScript #2 - AJAX Requests](https://www.youtube.com/watch?v=h0ZUpPiV1ac) | 13:19 |  
| [What is an API](https://www.youtube.com/watch?v=s7wmiS2mSXY) | 3:24 |  
| [Fetch API by Google developers](https://www.youtube.com/watch?v=g6-ZwZmRncs) | 5:26 |  
| [AJAX - Getting Started](https://developer.mozilla.org/en-US/docs/AJAX/Getting_Started) | reading |  
| [AJAX - API - Use of XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest)(till Submitting forms and uploading files ) | reading |  
| [Fetch API](https://developer.mozilla.org/en/docs/Web/API/Fetch_API) | reading |  

## Material Review

 -  XMLHttpRequest
 -  request methods  
     -  `.open`
     -  `.send`
     -  `.setRequestHeader`
     -  `.onreadystatechange`
     -  [status codes](https://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html)
     -  `.readyState`
     -  `.response`
 -  Blocking / non-blocking
 -  Callbacks
 -  XML
 -  JSON
 -  Fetch API
 -  Cross domain

## Workshop


### Example

```javascript
let httpRequest = new XMLHttpRequest();
httpRequest.open('GET', 'https://sheetsu.com/apis/v1.0/7654fbe24554', true); // Also try http://444.hu/feed
httpRequest.send(null);
httpRequest.onreadystatechange = console.log;
```

Design of user interface is not important, don't spend more than 5 minutes making it look pretty.


### Task 1 : Giphy API

Display gifs of a cute/funny topic using:
https://github.com/Giphy/GiphyAPI

 -  Search/Find the images in the API
 -  Display the list of the first 16 results's static thumbnail
 -  If the user clicks on the thumbnail, display the animated GIF


### Task 2 : New York Times API

Search interesting articles on:
http://developer.nytimes.com/

Ask your local mentor for the API key or request your own. Use `localhost` as the website.

 -  Use the [Article Search API](http://developer.nytimes.com/article_search_v2.json)
 -  Find articles about the moon landing by Apollo 11
 -  Display the following fields in a list
     -  Headline
     -  Snippet
     -  Publication date
 -  Create a permalink to that article


### Task 3 :  Get Position

Get your input city's position using this API:
https://market.mashape.com/dev132/city-geo-location-lookup  

Ask your local mentor for the API key or request your own. Use `localhost` as the website.  

 -  Create a very simple HTML:
     -  it should have a label
     -  an input field (text)  for the name of city
     -  and a button
 -  The request should be sent to the API by clicking the button
 -  If you get the response, you should display your city's coordinates: latitude, longitude
 -  Mark the city on a map, using [Google Maps API](https://developers.google.com/maps/documentation/embed/guide)

### Task (_optional_) : Yoda Say

 Rewrite your own sentence in yoda-style, using the given API:
 https://market.mashape.com/ismaelc/yoda-speak

 -  Create a very simple HTML:
     -  it should have a label
     -  an input field (text)
     -  and a button
 -  The request should be sent to the API by clicking the button
 -  If you get the response, you should display your sentence in yoda-style on the screen


<!-- ### Reddit backend communication

Check the documentation of the [Reddit project's backend](https://todo-docs.herokuapp.com/docs/#!/default/todosGET)

 - Try to implement all methods without connecting them to you UI -->
