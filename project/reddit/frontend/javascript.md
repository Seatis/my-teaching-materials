# The Reddit: Frontend

We'll create a simple reddit clone frontend, where the users can create posts,
upvote and downvote existing posts. Later on you can extend this with more
functionality.

Read the Reddit Application API documentation and you can also check out the
final version. Store the API's URL in a global variable because you'll have to
change it.

## Mandatory features

### List the posts

Create the HTML structure and the design of the main page using static data.
Remove the static data and fill the page with posts using the API.

#### Notes

 -  no other functionality should be added yet
 -  it's okay to display the elapsed time only in minutes
 -  if the post has no owner it's posted by anonymous
 -  numbering does not need to be in order by score

### Add post

Create the HTML structure and the design of the add post page. Add the
functionality. Add that nice top navigation bar to the main page.

#### Notes

 -  since you have no user handling yet post as anonymous is always on
 -  do not let the user post with empty fields
 -  redirection to the main page after a successful addition would be nice to
    have
 -  use your creativity and replace the page text
 -  that link above will show you a modified main page, make sure to check it

### Vote

Modify your main page so that those arrows can finally do something useful using
the API.

#### Notes

 -  the score should be updated
 -  the color should change


## Find a Backend partner

 -  At this point go to the Slack channel #reddit
 -  Find someone who is developing the backend part
 -  Make sure that you're on the A66 Guest network
 -  Get your partner's local IP address, and change the API's URL
 -  Test out each other's work

## Optional features

### Remove

Modify your main page so it is possible to remove a post using the API.

#### Notes

 -  anonymous posts can be removed by anyone
 -  a post with owner can be only removed by the owner
 -  if you have no rights to remove that post it should remain grey.
 -  but since it's not mandatory to handle the user you might just enable the
    remove feature for every post

### Modify

Create the HTML structure and the design of the modify post page. Add the
functionality. Modify your main page so it is possible the modify a post.

#### Notes

 -  use query parameters for identifying the post
 -  fields should be prefilled with the proper data

### Login

Create the HTML structure and the design of the login page. Add the
functionality. Add login link to your navigation bar and modify every request so
it uses the username.

#### Notes

 -  no authentication is required
 -  check out what localStorage is
 -  if username is set it should display **LOGGED IN AS `<username>`** otherwise
    **LOGIN »**

### Order by score

Modify the main page so the numbering is ordered by the scores.
