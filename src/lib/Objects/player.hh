#pragma once

#include "../vector2d.hh"
#include <string>

class Player
{
private:
  std::string spriteID;

  float speed = 2.0f;

public:
  Vector2D pos;
  Vector2D vel;

  Player();
  Player(std::string nSpriteID);

  void changeColor();
  void update();
  void draw();
};