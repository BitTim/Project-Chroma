#include "../../lib/Managers/assetManager.hh"
#include "../../lib/Managers/textureManager.hh"

//Texture Management
void AssetManager::addTexture(std::string id, std::string path)
{
  textures.emplace(id, TextureManager::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id) { return textures[id]; }

//Animation Management
void AssetManager::addAnimationManager(std::string animationManagerID, std::string textureID, int w, int h, int scale)
{
  AnimationManager animationManager;
  animationManager.attachManager(textureID, w, h, scale);

  animationManagers.emplace(animationManagerID, &animationManager);
}

void AssetManager::defineAnimation(std::string animationManagerID, std::string animationID, int nIndex, int nFrames, int nSpeed)
{
  animationManagers[animationManagerID]->defineAnimation(animationID, nIndex, nFrames, nSpeed);
}

void AssetManager::playAnimation(std::string animationManagerID, std::string animationID)
{
  animationManagers[animationManagerID]->playAnimation(animationID);
}

AnimationManager* AssetManager::getAnimationManager(std::string id) { return animationManagers[id]; }