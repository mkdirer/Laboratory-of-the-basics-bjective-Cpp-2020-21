#pragma once

class Vector2D {
public:
    Vector2D(const double x, const double y);
    Vector2D(const Vector2D &old_obj);
    static Vector2D fromCarthesian(const double x, const double y);
    static Vector2D fromPolar(const double r, const double phi);
    void print(const std::string& word) const;
    static int number_vertices();
    double dot(const Vector2D& vec) const;
    Vector2D add(const Vector2D& vec) const;
    ~Vector2D();
private:
    static int number;
    double _x;
    double _y;
};