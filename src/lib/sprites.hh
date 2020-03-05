#pragma once
#include <map>
#include <SDL2/SDL.h>

struct Animation
{
  int index;
  int frames;
  int speed;

  Animation() { }
  Animation(int nIndex, int nFrames, int nSpeed);
};

class Sprite
{
private:
  std::map<std::string, Animation*> animations;
  SDL_Texture* texture;
  bool animated = false;

  int index;
  int frames;
  int speed;

public:
  SDL_Rect src;
  SDL_Rect dst;

  Sprite() { }
  Sprite(int w, int h, int scale, bool nAnimated = false);

  void loadTexture(std::string path);
  void defineAnimation(std::string id, int nIndex, int nFrames, int nSpeed);
  void playAnimation(std::string id);
  
  void update();
  void draw();
};