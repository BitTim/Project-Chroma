#pragma once

#include <map>
#include <SDL2/SDL.h>

class AssetManager
{
public:
  //Texture Management
  void addTexture(std::string id, std::string path);
  SDL_Texture* getTexture(std::string id);

private:
  std::map<std::string, SDL_Texture*> textures;
};