#include "../../lib/Managers/textureManager.hh"

SDL_Texture* TextureManager::loadTexture(std::string path)
{
  SDL_Surface* surface = IMG_Load(path.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  SDL_FreeSurface(surface);

  return texture;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{
  SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}