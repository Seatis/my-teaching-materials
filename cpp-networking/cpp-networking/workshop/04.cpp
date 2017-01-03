// Rewrite Your amoeba app so, that Your network implementations 
// actually implement the abstract classes You defined in the previous
// exercise. Use these to enabe communication between two client applications
// through a separate server application. If You devised Your Abstract class based on the
// prototype client and server You created before this will be way easier.
//
// Basically rewrite Your amoeba app to be a neworked multiplayer game.
//
// If You start the application with the modifier: '-c' You should be able from the console like before.
// If You start the application with the modifier: '-n <IP-Address> <player-id>' You should be able to¤
// play with someone over the network. Connecting to a server at <ip-adderss> and connecting to the
// nearest avalable <player-id> that hasn't been paired yet. Basically just pair everyone with the next
// player that connects to the server.
//
// You have some choices to make:
//   - Design the language for the amoeba app - like which messages are transmitted and what do they mean?
//   - What will be the design of the client and the server?
//     - Client can be a separate app and server can be a separate app. (Separate executable file.)
//     - The same executable can be run in client mode and server mode depending on argv arguments.
//       - When run in server mode should the player be able to play on that instance or whould they
//         run a new one to play with? (Example: Quake 3 can e run in server mdoe and still be played with :)
