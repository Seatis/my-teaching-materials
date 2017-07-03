# The TOTORO graphic chat
*Create a graphic chat program*

## Objectives
- Form two-person groups
- Create a graphic chat program together

## Materials & Resources

| Material | Duration |
|:---------|---------:|
|[Passing a structure through Sockets in C](https://stackoverflow.com/questions/1577161/passing-a-structure-through-sockets-in-c)| - |

## Material review
- How to transfer a structure properly between two devices
  - Serialization needed if the two platforms may differ
  - You can transfer the whole structure as a byte array if the two platforms is the same

## Workshop
The goal is to make a graphic chat program with two STM32F746G-DISCOVERY boards.

Form two-person groups. One should write the server side program, the other
one should write the client side program.

### Client side
The client connects to the server with a TCP socket and sends touch screen
data to the server.

### Server side
The server accepts connection from the client and receives touch screen data
via TCP sockets. Based on the touch data it draws filled circles.

### How does it work?
If the user writes something on the client board, the drew messages appears on the server
board.

### Advanced tasks
#### Make it work back and forth
Every board should behave like a server and a client at the same time.

#### Define clear command
The user should be able to send clear screen commands (somehow) to the other board.

#### Color command
The user should be able to change the draw color on the other board.

### Highly Advanced task
The boards should detect each other on the network (the IP address is
detected automatically).

## Solution
[Solution](#)
