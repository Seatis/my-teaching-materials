
# Day 1: Build UI create experiments

## Stories

### Build the UI with HTML+CSS
- Center the app to the center of the page
- Use the assets from the `img` folder
- Responsivity is optional since it'll be a bit tricky to run this on mobile (yet)
- Connect the widgets from your experiments

Save your experiments in an `experiments` folder.

### The `<audio>` tag
- Learn about the <audio> tag:
	- https://www.sitepoint.com/essential-audio-and-video-events-for-html5/
	- https://developer.mozilla.org/en/docs/Web/Guide/Events/Media_events
	- https://www.w3.org/2010/05/video/mediaevents.html
- Create an Audio mockup in a separate HTML file
- Use this MP3 file: [Purple drift](music/Organoid_-_09_-_Purple_Drift.mp3)
- Add the following events: `loadstart`, `play`, `ended`, `progress`
- `console.log` the event name + "happened" to the console

## Optional features

Implementing these are not mandatory, but they can improve the app experience.

### Pick a slider library

It's okay to use the default `audio` tag's slider UI, you can skin that too.

 - https://stackoverflow.com/questions/35259242/css-style-audio

However you can have more contro if you connect the `audio` tag with a custom slider library.

- Use either:
	- https://refreshless.com/nouislider/examples/
	- https://github.com/Stryzhevskyi/rangeSlider
- Pick the one that you:
	- like the syntax more
	- think it's easier to modify
	- like the API better
- Style/skin it according to the design
- Create a separate HTML file to test out the slider
- You'll need to update the slider position programatically
- You'll use the slider to indicate the position of the track and set the volume

### Create a modal dialog

You can use standard components like `confirm()` and `prompt()` to interact with the user. 

- https://developer.mozilla.org/en-US/docs/Web/API/Window/confirm
- https://developer.mozilla.org/en-US/docs/Web/API/Window/prompt

However you can build your own solution or use a lib like VEX:

- Use the [VEX modal library](http://github.hubspot.com/vex/docs/welcome/) to display a <select> element with 3 options of your choice
- Add a "Save track" and a "Cancel" button to it
- The "Save track" should be the primary button (blue)
- If the user presses the "Save track", console.log the value of the <select> input
