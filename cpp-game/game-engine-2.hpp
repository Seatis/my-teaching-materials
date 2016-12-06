#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "SDL2/SDL.h"

#include <map>
#include <string>

#define ARROW_UP 0
#define ARROW_RIGHT 1
#define ARROW_DOWN 2
#define ARROW_LEFT 3
#define SPACE 4

class GameContext {
private:
  SDL_Window* screen;
  SDL_Renderer* renderer;
  std::map<std::string, SDL_Surface*> sprites;
  bool keys[5];
public:
  GameContext(unsigned int screen_width, unsigned int screen_height) {
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_CreateWindow("My Game Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_width, screen_height,
                              0);
    renderer = SDL_CreateRenderer(screen, -1, 0);
    reset_keys();
  }
  ~GameContext() {
    for (std::map<std::string, SDL_Surface*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
      SDL_FreeSurface(it->second);
    }
    SDL_Quit();
  }
  void load_file(std::string name) {
    SDL_Surface* result = SDL_LoadBMP(name.c_str());
    SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(screen)), 0xFF, 0, 0xFF));
    sprites[name] = result;
  }
  void draw_sprite(std::string name, int x, int y) {
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, sprites[name]);
    SDL_Rect temp;
    temp.x = x;
    temp.y = y;
    temp.w = 72;
    temp.h = 72;
    SDL_RenderCopy(renderer, texture, NULL, &temp);
  }
  void render() {
    SDL_RenderPresent(renderer);
  }
  void reset_keys() {
    for (unsigned int i = 0; i < 5; ++i) {
      keys[i] = false;
    }
  }
  void on_key_down(unsigned int key_code) {
    keys[key_code] = true;
  }
  bool was_key_pressed(unsigned int key_code) {
    return keys[key_code];
  }
};

class Game {
public:
  virtual void init(GameContext& context) = 0;
  virtual void render(GameContext& context) = 0;
};

class GameEngine {
private:
  GameContext* context;
  Game* game;
public:
  GameEngine(Game* g, unsigned int screen_width, unsigned int screen_height) {
    context = new GameContext(screen_width, screen_height);
    game = g;
    game->init(*context);
  }
  ~GameEngine() {
    delete context;
  } 
  void run() {
    SDL_Event event;
    int gameover = 0;
    while (!gameover) {
      context->reset_keys();
      if (SDL_PollEvent(&event)) {
        switch (event.type) {
          case SDL_QUIT:
            gameover = 1;
            break;
          case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
              case SDLK_ESCAPE:
              case SDLK_q:
                gameover = 1;
                break;
              case SDLK_LEFT:
                context->on_key_down(ARROW_LEFT);
                break;
              case SDLK_RIGHT:
                context->on_key_down(ARROW_RIGHT);
                break;
              case SDLK_UP:
                context->on_key_down(ARROW_UP);
                break;
              case SDLK_DOWN:
                context->on_key_down(ARROW_DOWN);
                break;
              case SDLK_SPACE:
                context->on_key_down(SPACE);
                break;
            }
            break;
        }
      }
      game->render(*context);
    }
  }
};
#endif
