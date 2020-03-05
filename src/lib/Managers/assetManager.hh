#pragma once

#include <map>
#include <SDL2/SDL.h>
#include "animationManager.hh"

class AssetManager
{
private:
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, AnimationManager*> animationManagers;

public:
  //Texture Management
  void addTexture(std::string id, std::string path);
  SDL_Texture* getTexture(std::string id);

  //Animation Management
  void addAnimationManager(std::string animationManagerID, std::string textureID, int w, int h, int scale);
  void defineAnimation(std::string animationManagerID, std::string animationID, int nIndex, int nFrames, int nSpeed);
  void playAnimation(std::string animationManagerID, std::string animationID);
  AnimationManager* getAnimationManager(std::string id);
};