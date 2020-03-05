#pragma once

#include <map>
#include <string>
#include "textureManager.hh"

class Animation
{
public:
  int index;
  int frames;
  int speed;

  Animation() { }
  Animation(int nIndex, int nFrames, int nSpeed);
};

class AnimationManager
{
private:
  std::map<std::string, Animation*> animations;
  SDL_Texture* texture;

  SDL_Rect src, dst;

  int index;
  int frames;
  int speed;

public:
  void attachManager(std::string textureID, int w, int h, int scale);
  void defineAnimation(std::string id, int nIndex, int nFrames, int nSpeed);
  void playAnimation(std::string id);

  void update(int x, int y);
  void draw();
};