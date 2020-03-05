#pragma once

#include <SDL2/SDL.h>
#include <string>

class Game
{
public:
  Game() { }
  ~Game() { }

  void init(std::string title, int x, int y, int w, int h, bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void terminate();

  bool isRunning();

  static SDL_Renderer* renderer;
  static SDL_Event event;
  static bool running;

private:
  SDL_Window* window;
};