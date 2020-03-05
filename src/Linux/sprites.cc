#include "../lib/sprites.hh"
#include "../lib/Managers/textureManager.hh"
#include "../lib/util.hh"
#include "../lib/logger.hh"

Animation::Animation(int nIndex, int nFrames, int nSpeed)
{
  index = nIndex;
  frames = nFrames;
  speed = nSpeed;
}

Sprite::Sprite(int w, int h, int scale, bool nAnimated)
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
  Animation* animation = new Animation(nIndex, nFrames, nSpeed);
  animations.emplace(id, animation);
}

void Sprite::playAnimation(std::string id)
{
  index = animations[id]->index;
  frames = animations[id]->frames;
  speed = animations[id]->speed;
}

void Sprite::update()
{
  if(animated)
  {
    src.x = src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    src.y = index * src.h;
  }
}

void Sprite::draw()
{
  TextureManager::draw(texture, src, dst);
}