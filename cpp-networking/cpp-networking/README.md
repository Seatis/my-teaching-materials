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
| [TCP: Transmission control protocol | Networking tutorial (12 of 13)](https://www.youtube.com/watch?v=4IMc3CaMhyY) (new) | 8:28 |
| [TCP connection walkthrough | Networking tutorial (13 of 13)](https://www.youtube.com/watch?v=F27PLin3TV0)(new) | 9:30 |
| [SDL tutorial 25 - networking with SDL_net (send and recv TCP packages)](https://www.youtube.com/watch?v=LNSqqxIKX_k&list=PL949B30C9A609DEE8&index=57) | 26:26 |
| [[SDL2 - Part 13] Multiplayer - TCP - headerphile](http://headerphile.com/sdl2/sdl2-part-13-multiplayer-tcp/)|Blogpost|
|:---------|-----:|
| [TCP and UDP](https://www.youtube.com/watch?v=TKrTnPz7gvk) (new)| 3:06 |
| [UDP and TCP: Comparison of Transport Protocols](https://www.youtube.com/watch?v=Vdc8TCESIg8) (new)| 11:34 |
| [What’s the Difference Between TCP and UDP?](http://www.howtogeek.com/190014/htg-explains-what-is-the-difference-between-tcp-and-udp/) (new)|Blogpost|



| Optional | Time |
|:---------|-----:|
| [FPS game (OpenGL,SDL,C++) tutorial 12 - multiplayer, networking, server](https://www.youtube.com/watch?v=iJfC4-yNnzY)|1:41:31 |

### Example Codes
Please add comments explanign what You do after each signficant goup of lines!
#### Server App
```c_cpp
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
```

#### Client App
```c_cpp
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
```

#### Serializing a Message
```c_cpp
#include <iostream>

using namespace std;

union Ptr {
        char* asChar;
        unsigned char* asUChar;
        int* asInt;
        unsigned int* asUInt;
        float* asFloat;
        double* asDouble;
        bool* asBool;
        void* asVoid;
};

int main() {
        char* text = "Elemes auto";
        int nk = 42;
        float ff = 123.78f;

        cout << text << " | " << nk << " | " << ff << endl;
        // Char so, I know how many bytes I have. This could be done in many different ways.
        char buffer[128];
        
        // Defining simplistic run-length encoding:
        // char = 'c'
        // unsigned char = 'x'
        // After char and uchar comes an int, denoting the length.
        // int = 'i'
        // unsigned int = 'u'
        // float = 'f'
        // double = 'd'
        // bool = 'b'
        // void = 'v'
        // end, there is no more data = 'q';
		// In the current case our message willbe like this: c|12|Elemes auto|i|42|f|123.78

        //Assembling message
        Ptr a;
        a.asChar = buffer;
        *a.asChar++ = 'c';
        *a.asInt++ = 12;
        for(int i=0;i<12;i++){
                *a.asChar++ = text[i];
        }
        *a.asChar++ = 'i';
        *a.asInt++ = nk;
        *a.asChar++ = 'f';
        *a.asFloat++ = ff;
        *a.asChar = 'q';
        
        // Decoding message. I'm cheating a bit here. I know what's in the message. Then again
        // most of the time You actually know - to some extent - what You want to send. So this is
        // cheting and not cheating at the same time.
        // The main point is, how I use the Ptr type and how I'm getting new variables with the same
        // values aftr that.
        Ptr b;
        b.asChar = buffer;
        char* text2;
        int cnt;
        int nk2;
        float ff2;
        while(*b.asChar != 'q'){
                if(*b.asChar == 'c'){
                        b.asChar++;
                        cnt = *b.asInt++;
                        text2 = new char[cnt];
                        for(int i=0; i<cnt; ++i){
                                text2[i] = *b.asChar++;
                        }
                } else if(*b.asChar == 'i'){
                        b.asChar++;
                        nk2 = *b.asInt++;
                } else if(*b.asChar == 'f'){
                        b.asChar++;
                        ff2 = *b.asFloat++;
                }
                if(*b.asChar == 'q'){
                        cout << "End fo transmitted data" << endl;
                }
        }
        // Priting for comparison...
        cout << text2 << " | " << nk2 << " | " << ff2 << endl;

        return 0;
}
```


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
Make sure to create tests for each exercise.
Also make sure to Comment each section in the code that does something significant!
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

