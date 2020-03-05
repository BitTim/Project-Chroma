#include "../../lib/Managers/assetManager.hh"
#include "../../lib/Managers/textureManager.hh"

//Spritr Management
void AssetManager::addSprite(std::string id, std::string path, int w, int h, int scale, bool animated)
{
  Sprite* sprite = new Sprite(w, h, scale, animated);
  sprite->loadTexture(path);

  sprites.emplace(id, sprite);
}

void AssetManager::defineAnimation(std::string spriteID, std::string animationID, int nIndex, int nFrames, int nSpeed)
{
  sprites[spriteID]->defineAnimation(animationID, nIndex, nFrames, nSpeed);
}

void AssetManager::playAnimation(std::string spriteID, std::string animationID)
{
  sprites[spriteID]->playAnimation(animationID);
}

Sprite* AssetManager::getSprite(std::string id) { return sprites[id]; }