#pragma once

#include <SDL2/SDL.h>

class Util
{
public:
  static SDL_Rect iSDL_Rect(int x, int y, int w, int h)
  {
    SDL_Rect rect = {x, y, w, h};
    return rect;
  }

  static void iSDL_SetRenderDrawColor(SDL_Renderer* renderer, SDL_Color color)
  {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  }
};