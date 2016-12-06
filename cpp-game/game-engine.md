# Game engine

## Setup
### Install SDL
Set up SDL on your computer
 - All: https://wiki.libsdl.org/Installation
 - Mac: http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/index.php
 - Windows: http://lazyfoo.net/SDL_tutorials/lesson01/windows/index.php
 - Ubuntu/Debian: http://lazyfoo.net/SDL_tutorials/lesson01/linux/index.php

### Try SDL
Try to create a basic application using SDL: http://lazyfoo.net/SDL_tutorials/lesson01/index2.php

### Set up your project
 - Create a new project
 - Copy this header file to your project: [game-engine.hpp](game-engine.hpp)

## Usage
Include the header file to your project
```cpp
#include "game-engine.hpp"
```

### Game class
There is a base class called game that you can inherit from to create your own games.
You must override it's pure virtual functions:

#### init
```cpp
virtual void init(GameContext& context)
```

This function is called when the game is stated, you can do anything that is needed
to initalize your game, eg.: loading the image files
It has one parameter called the game context, that is used to draw objects to the window 

#### render
```cpp
virtual void render(GameContext& context)
```
This function is called in the game loop in every few milliseconds.
It is responsible to render all the game objects to the window.
It has one parameter called the game context, that is used to draw objects to the window 

#### Example

This game draws a single image to the window called `image.bmp`

```cpp
class MyGame : public Game {
  MyGame() {}
  virtual void init(GameContext& context) {
    context.load_file("image.bmp");
  }
  virtual void render(GameContext& context) {
    context.draw_sprite("image.bmp", 0, 0);
  }
};
```

### GameContext class
This class is responsible for drawing anything to the window and handles user events
It has several usefull methods:

#### load_file
```cpp
void GameContext::load_file(std::string file_name);
```

This function loads an image file, without loading the file you can't draw the image later.
Load the files in the `init` method of your game.
It takes the path to the image as a string parameter.

#### draw_sprite
```cpp
void GameContext::draw_sprite(std::string file_name, unsigned int x, unsigned int y);
```

This function draws an image to the window. The image is must loaded before this method is used.
It takes the path as a string parameter and the coordinates on the window as integers.

#### was_key_pressed
```cpp
bool GameContext::was_key_pressed(unsigned int key_code);
```

It can request if a key has been pressed since the last call of the render function.
It returns a boolean, and takes a character code as a parameter.

There are predefined character constants:
`ARROW_UP`, `ARROW_RIGHT`, `ARROW_DOWN`, `ARROW_LEFT`, `SPACE`

##### Example
```cpp
if (context.was_key_pressed(ARROW_UP)) {
  // the "Up-Arrow"-key has been pressed
}
```


### GameEngine
This class is reponsible for running your game. You must create an instance in your main function
and pass a pointer to your game object and the size of the window.

#### constructor
```cpp
GameEngine(Game* game_ptr, unsigned int screen_width, unsigned int screen_height);
```

You have to pass a pointer to your game instance the size of the window as two integers.

#### run
```cpp
void GameEngine::run();
```

It runs your game. If the `q` key is pressed than the game quits.

#### Example
```cpp
int main(int argc, char* argv[]) {
  MyGame game;
  GameEngine engine(&game, 400, 300);
  engine.run();
  return 0;
}
```
