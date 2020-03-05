#pragma once

#include "../Managers/entityManager.hh"
#include "../vector2d.hh"

struct TransformComponent : public Component
{
  Vector2D pos;
  Vector2D vel;
  Vector2D size;

  int scale = 1;
  float speed = 2.0f;

  TransformComponent() { pos.set(0, 0); }
  TransformComponent(int nScale) { pos.set(0, 0); scale = nScale;}
  TransformComponent(float x, float y) { pos.set(x, y); }
  TransformComponent(float x, float y, float w, float h, int nScale) { pos.set(x, y); size.set(w, h); scale = nScale; }

  void init() override { vel.set(0, 0); }
  void update() override { pos += vel * speed; }
};