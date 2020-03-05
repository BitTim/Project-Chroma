#pragma once

#include <map>
#include <SDL2/SDL.h>
#include "../sprites.hh"

class AssetManager
{
private:
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, Sprite*> sprites;

public:
  //Sprite Management
  void addSprite(std::string id, std::string path, int w, int h, int scale, bool animated = false);
  void defineAnimation(std::string spriteID, std::string animationID, int nIndex, int nFrames, int nSpeed);
  void playAnimation(std::string spriteID, std::string animationID);
  Sprite* getSprite(std::string id);
};