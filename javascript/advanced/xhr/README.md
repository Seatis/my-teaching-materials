# XHR
Talking to a server

## Objectives
 - Learn how to talk to a server
 - Make use of async calls
 - Play with API-s
 - Progress on weekly project's API

### Training
| Material | Time |
|:---------|-----:|
| [AJAX Tutorial - 1 - Introduction to AJAX](https://www.youtube.com/watch?v=tp3Gw-oWs2k) | 4:45 |
| [AJAX Tutorial - 2 - Some Examples of AJAX](https://www.youtube.com/watch?v=-1RLW7a8Gr4) | 3:43 |
| [Asynchronous JavaScript #2 - AJAX Requests](https://www.youtube.com/watch?v=h0ZUpPiV1ac) | 13:19 |
| [Fetch API by Google developers](https://www.youtube.com/watch?v=g6-ZwZmRncs) | 5:26 |

#### Reading

 - https://developer.mozilla.org/en-US/docs/AJAX/Getting_Started
 - https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest ( till Submitting forms and uploading files )
 - https://developer.mozilla.org/en/docs/Web/API/Fetch_API

## Material Review

 - XMLHttpRequest
 - Blocking / non-blocking
 - Callbacks
 - status codes
 - headers
 - XML
 - JSON
 - Fetch API 
 - Can I fetch today?
 - Cross domain

## Workshop


### Try it out

```javascript
let httpRequest = new XMLHttpRequest();
httpRequest.open('GET', 'https://sheetsu.com/apis/v1.0/7654fbe24554', true); // Also try http://444.hu/feed
httpRequest.send(null);
httpRequest.onreadystatechange = console.log;
```

Design of user interface is not important, don't spend more than 5 minutes making it look pretty.


### Giphy API

https://github.com/Giphy/GiphyAPI

 - Find the images in the API
 - Display the list of the first 16 results's static thumbnail
 - If the user clicks on the thumbnail, display the animated GIF


### New York Times API

http://developer.nytimes.com/

Ask your local mentor for the API key or request your own. Use `localhost` as the website.

 - Use the [Article Search API](http://developer.nytimes.com/article_search_v2.json)
 - Find articles about the moon landing by Apollo 11
 - Display the following fields in a list
    - Headline
    - Snippet 
    - Publication date
 - Create a permalink to that article


### Movie spreadsheet via Sheetsu

Let's crowdsource a list of good movies supplied by you.

#### Check the spreadsheet here: 

https://docs.google.com/spreadsheets/d/1DsBUc4dZhp3_Sgn4IW2P0tnJB7bmIdV6BSYuKts15bU/edit#gid=0

You'll have to send data to this spreadsheet:

API endpoint: `https://sheetsu.com/apis/v1.0/7654fbe24554`

By requesting the above URL it will return the contents of the spreadsheet.

Read the documentation on how to post data: `https://sheetsu.com/docs/beta#post`

 - Create a list of the submitted movies with all the data returned by the API
 - Create a form that sends data to Sheetsu (use your own code, don't use the jQuery example)
 - If the request was successful, reset the form and display a success message
 - If the request failed, display the error

### Todo project backend communication

Check the documentation of the [Todo project's backend](https://todo-docs.herokuapp.com/docs/#!/default/todosGET)

 - Try to implement all methods without connecting them to you UI
