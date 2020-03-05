#pragma once

class Vector2D
{
public:
  float x;
  float y;

  Vector2D();
  Vector2D(const float x, const float y);

  Vector2D& set(const float x, const float y);
  Vector2D& scale(const float& scalar);

  Vector2D& add(const Vector2D& vec);
  Vector2D& sub(const Vector2D& vec);
  Vector2D& mul(const Vector2D& vec);
  Vector2D& div(const Vector2D& vec);

  friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

  Vector2D& operator+=(const Vector2D& vec);
  Vector2D& operator-=(const Vector2D& vec);
  Vector2D& operator*=(const Vector2D& vec);
  Vector2D& operator/=(const Vector2D& vec);

  Vector2D& operator*(const float& i);
};