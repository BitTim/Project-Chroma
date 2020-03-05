#include "../lib/vector2d.hh"

Vector2D::Vector2D() { }
Vector2D::Vector2D(const float x, const float y) { set(x, y); }

Vector2D& Vector2D::set(const float x, const float y)
{
  this->x = x;
  this->y = y;

  return *this;
}

Vector2D& Vector2D::scale(const float& scalar)
{
  this->x *= scalar;
  this->y *= scalar;

  return *this;
}

Vector2D& Vector2D::add(const Vector2D& vec)
{
  this->x += vec.x;
  this->y += vec.y;

  return *this;
}

Vector2D& Vector2D::sub(const Vector2D& vec)
{
  this->x -= vec.x;
  this->y -= vec.y;

  return *this;
}

Vector2D& Vector2D::mul(const Vector2D& vec)
{
  this->x *= vec.x;
  this->y *= vec.y;

  return *this;
}

Vector2D& Vector2D::div(const Vector2D& vec)
{
  this->x /= vec.x;
  this->y /= vec.y;

  return *this;
}


Vector2D& operator+(Vector2D& v1, const Vector2D& v2) { return v1.add(v2); }
Vector2D& operator-(Vector2D& v1, const Vector2D& v2) { return v1.sub(v2); }
Vector2D& operator*(Vector2D& v1, const Vector2D& v2) { return v1.mul(v2); }
Vector2D& operator/(Vector2D& v1, const Vector2D& v2) { return v1.div(v2); }

Vector2D& Vector2D::operator+=(const Vector2D& vec) { return this->add(vec); }
Vector2D& Vector2D::operator-=(const Vector2D& vec) { return this->sub(vec); }
Vector2D& Vector2D::operator*=(const Vector2D& vec) { return this->mul(vec); }
Vector2D& Vector2D::operator/=(const Vector2D& vec) { return this->div(vec); }

Vector2D& Vector2D::operator*(const float& i) { return this->scale(i); }