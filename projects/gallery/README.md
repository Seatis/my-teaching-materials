# JavaScript image slider

## Project
Create a fully functional image gallery using HTML, CSS and JavaScript

### Outline and purpose

| **Input Skills** | **Output Skills** |  
|:----------|-----------:|  
| Some HTML and CSS experience | More experience in recreating an exact, given design |  
| Javascript basic expressions | Some experience in writing more complex JS code from the basic building blocks |  
| Javascript basic datastructures | Ability to manipulate DOM with JS code |  
| Some experience with DOM | Interacitve websites: Query selectors and event listeners |  
| Understand user stories and break them down to small development tasks | Try to keep JS code clean |  
| Use of kanban board/plan and manage your own work | More experience in alone project management |  


## Design

![Gallery mockup](slider.png)

[Arrow asset](slider.png)

## User stories

### Layout/ Design   
  - As it is an image gallery, it should look nice, the design should be very similar to the example above. Plus, it should have a title as well.   
  - It should be in the middle of the screen, with fixed size.
  - The image side ratio should be 16:9
  - The gallery's content should be divided into two main parts: to the photo viewer and to the thumbnails.
  - The photo viewer block should contain the two arrow buttons on the sides and the currently chosen photo in the middle.
  - The thumbnails part should contain - as its name says - the small thumbnails, under the photo viewer block.
  - The currently showed photo should have a half transparent description block on the bottom, with the photo's title and story.  
  - As we open the gallery the first picture from our collection should appear in the photo viewer area
  - The related (first) thumbnail should be marked as active as well (outline, border.. etc.)

**Extras**
  - If you hover any of the thumbnails the cursor should be a pointer.
  - If you hover any of the thumbnail, a pop-up should appear whith the title of the picture.

### Navigation/Interaction  
  - As we open the gallery the first picture from our collection should appear in the photo viewer area
  - The related (first) thumbnail should be marked as active as well (outline, border.. etc.)
  - By clicking on the arrow buttons on the sides, the content of the viewer block (so the photo and its description) chould change to the next's or the previous' of our collection.
  - At the same time, the current thumbnail's outline/box-shadow should change depending on the currently picked photo.
  - If the gallery displays the first image, pressing the previous button should show the last one.
  - If the gallery displays the last image, pressing the next button should show the first one.
  - By clicking on a thumbnail, the user the related photo need to be shown in the viewer are.
  - So, the arrow buttons, the viewer area's content, and the thumbnail's outline/border should work syncronously.

**Extras**
  - The gallery can be controlled by the arrow keys.  
  - The gallery should handle "infinite amount" of images, so the thumbnails sould be scrollable to (implementaion is up to you)


## How to do dis?

### Plan ALL the things!
- Imagine what you have to do
- Create sketch-up(s) to help plan your HTML and CSS
- Figure out gallery data structure
- Design your code, what will be where
- Plan your functions and variables
- Prepare your user events

### Create your own stories
- Not necessarily in gitub projects, but its a nice thing to do on a board
- Break down the functions to simple ones, like:
    - Show the main image
    - Replace the main image with js
    - ...
