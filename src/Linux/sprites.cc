#include "../lib/sprites.hh"
#include "../lib/Managers/textureManager.hh"
#include "../lib/util.hh"

Animation::Animation(int nIndex, int nFrames, int nSpeed)
{
  index = nIndex;
  frames = nFrames;
  speed = nSpeed;
}

Sprite::Sprite(int w, int h, int scale, bool nAnimated = false)
{
  src = Util::iSDL_Rect(0, 0, w, h);
  dst = Util::iSDL_Rect(0, 0, w * scale, h * scale);

  animated = nAnimated;
}

void Sprite::loadTexture(std::string path)
{
  texture = TextureManager::loadTexture(path);
}

void Sprite::defineAnimation(std::string id, int nIndex, int nFrames, int nSpeed)
{
  animations.emplace(id, Animation(nIndex, nFrames, nSpeed));
}

void Sprite::playAnimation(std::string id)
{
  index = animations[id]->index;
  frames = animations[id]->frames;
  speed = animations[id]->speed;
}

void Sprite::update()
{
  src.x = src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
  src.y = index * dst.h;
}

void Sprite::draw()
{
  TextureManager::draw(texture, src, dst);
}