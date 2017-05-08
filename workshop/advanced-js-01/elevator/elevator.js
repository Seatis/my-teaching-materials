'use strict';

var buttons = document.querySelectorAll('button');
var peopleNumber = 0;
var storey = 0;

function eventHandler(button){
  console.log(button.className);
}

buttons.forEach(function(button){
  button.addEventListener('click', function(){
    eventHandler(button);
  });
});

// Create an elevator controller object
// It should take an user input by listening to user input
// List of commands:
//
//  - Move elevator up
//  - Move elevator down
//  - Add people
//  - Remove people
//
//  Features to implement:
//   - [ x ] is the elevator. X means it has at least 1 person inside
//   - Moving floors should take time
//   - don't move beyond limits

// Create an "elevator" class
// The class should track the following things:
//  - elevator position
//  - elevator direction
//  - people in the elevator
//  - add people
//  - remove people
