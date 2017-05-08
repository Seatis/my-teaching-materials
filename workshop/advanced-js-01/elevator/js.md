# Elevator

Create an elevator simulator program using HTML, CSS and JavaScript.

It should have to work like these basic example:

![elevator](elevator.jpg)

## Specification

The program should have three objects: elevatorController, elevatorModel and elevatorView.

### elevatorController

The object should have a method which handling the events.
It invokes the elevatorModel's correct method to moving the elevator, add or remove people.

### elevatorModel

the object takes two parameters, the maximum floor and the maximum people.

The object should track the following things:
 - elevator position
 - elevator direction
 - people in the elevator
 - add people
 - remove people

It should have a method that check if the numbers of people or the floor are beyond the limits.

The object invokes the elevatorView.

### elevatorView

The object draw the elevator's state to the browser.

### Extra Features

 - Write the number of carried people at every floor
 - Can add, remove more people, floor
 - Moving floors should take time
 - Animate the moving of the elevator (CSS transform, transition)
