#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "Managers/assetManager.hh"

class Game
{
private:
  SDL_Window* window;
  
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
  static AssetManager* assets;
  static SDL_Rect camera;
};