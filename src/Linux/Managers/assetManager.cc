#include "../../lib/Managers/assetManager.hh"
#include "../../lib/Managers/textureManager.hh"

//Texture Management
void AssetManager::addTexture(std::string id, std::string path)
{
  textures.emplace(id, TextureManager::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id) { return textures[id]; }