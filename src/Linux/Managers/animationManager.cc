#include "../../lib/Managers/animationManager.hh"
#include "../../lib/game.hh"
#include "../../lib/util.hh"

Animation::Animation(int nIndex, int nFrames, int nSpeed)
{
  index = nIndex;
  frames = nFrames;
  speed = nSpeed;
}

void AnimationManager::attachManager(std::string textureID, int w, int h, int scale)
{
  texture = Game::assets->getTexture(textureID);
  src = Util::iSDL_Rect(0, 0, w, h);
  dst = Util::iSDL_Rect(0, 0, w * scale, h * scale);
}

void AnimationManager::defineAnimation(std::string id, int nIndex, int nFrames, int nSpeed)
{
  animations.emplace(id, Animation(nIndex, nFrames, nSpeed));
}

void AnimationManager::playAnimation(std::string id)
{
  index = animations[id]->index;
  frames = animations[id]->frames;
  speed = animations[id]->speed;
}

void AnimationManager::update(int x, int y)
{
  dst.x = x - Game::camera.x;
  dst.y = y - Game::camera.y;
  src.x = src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
  src.y = index * dst.h;
}

void AnimationManager::draw()
{
  TextureManager::draw(texture, src, dst);
}