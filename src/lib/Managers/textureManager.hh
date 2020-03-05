#pragma once

#include "../game.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct TextureManager
{
  static SDL_Texture* loadTexture(std::string path);
  static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
};
