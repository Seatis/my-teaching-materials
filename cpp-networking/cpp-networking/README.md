# Networking
*Create simple programs that communicate through the network*

## Objectives
 - Learn the basics of networking
 - Be familiar with the vocabulary of networking
 - Extend and rewrite and existing App to anble networking
 - Try out stuff and have some experience before jumping into the deep end...

## Materials & Resources
### Training
| Material | Time |
|:---------|-----:|
| [The OSI Model Demystified](https://www.youtube.com/watch?v=HEEnLZV2wGI)| 18:40 |
| [SDL tutorial 25 - networking with SDL_net (send and recv TCP packages)](https://www.youtube.com/watch?v=LNSqqxIKX_k&list=PL949B30C9A609DEE8&index=57) | 26:26 |
| [FPS game (OpenGL,SDL,C++) tutorial 12 - multiplayer, networking, server](https://www.youtube.com/watch?v=iJfC4-yNnzY)|1:41:31 |


### Example Codes
Please add comments explanign what You do after each signficant goup of lines!
#### Server App
'''c_cpp
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	IPaddress ip;
	SDLNet_ResolveHost(&ip, NULL, 1234);
	TCPsocket server = SDLNet_TCP_Open(&ip);
	TCPsocket client;
	const char* text = "Alma";
	while (1) {
		client = SDLNet_TCP_Accept(server);
		if (client) {
			SDLNet_TCP_Send(client, text, 5);
			SDLNet_TCP_Close(client);
			break;
		}
	}
	SDL_Quit();
}
'''

#### Client App
'''c_cpp
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	IPaddress ip;
	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
	TCPsocket client = SDLNet_TCP_Open(&ip);
	char text[100];
	SDLNet_TCP_Recv(client, text, 100);
	std::cout << text;
	SDLNet_TCP_Close(client);
	SDL_Quit();
	}
'''

## Material Review
 - What are the OSI Layers?
 - What is a server?
 - What is a client?
 - What should be transmitted?
 - Which OSI layer does an SDL client and server use?
 - What is a message?
 - What makes a message UNIQUE?
 - What is the most important question to You after reading and listening to al this?




#### Excercises
 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
 - Are the allocated resources deleted when necessary?
 - Is there any potential memory leak?

