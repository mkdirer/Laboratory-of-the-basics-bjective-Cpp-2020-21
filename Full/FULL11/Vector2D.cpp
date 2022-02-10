#include <iostream>
#include <cmath>
#include "Vector2D.h"

int Vector2D::number=0;

Vector2D::Vector2D(const double x, const double y): _x(x), _y(y) { number++; }

Vector2D::Vector2D(const Vector2D &old_obj): _x(old_obj._x), _y(old_obj._y) {
    old_obj.print("copying ");
    number++;
}

Vector2D Vector2D::fromCarthesian(const double x, const double y)
{ return Vector2D(x, y); }

Vector2D Vector2D::fromPolar(const double r, const double phi)
{ return Vector2D(r*std::cos((phi/180)*2*acos(0.0)), r*std::sin((phi/180)*2*acos(0.0))); }

void Vector2D::print(const std::string& word) const
{ std::cout << word << "(" << _x << ", " << _y << ")" << std::endl; }

int Vector2D::number_vertices() { return number; }

double Vector2D::dot(const Vector2D& vec) const { return _x*vec._x + _y*vec._y; }

Vector2D Vector2D::add(const Vector2D& vec) const {
    Vector2D new_vec = fromCarthesian(_x+vec._x, _y+vec._y);
    return new_vec;
}
Vector2D::~Vector2D() { number--; }