#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <iostream>

namespace diva
{

    struct Vector2D
    {
        float x, y;

        Vector2D() : x(0), y(0) {}
        Vector2D(float x, float y) : x(x), y(y) {}
        Vector2D(const Vector2D &other) : x(other.x), y(other.y) {}

        const Vector2D &operator=(const Vector2D other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        const Vector2D &operator+=(const Vector2D &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        const Vector2D operator+(const Vector2D &other) const
        {
            return Vector2D(*this) += other;
        }

        const Vector2D &operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        const Vector2D operator*(float scalar) const
        {
            return Vector2D(*this) *= scalar;
        }

        const Vector2D &operator-=(const Vector2D &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        const Vector2D operator-(const Vector2D &other) const
        {
            return Vector2D(*this) -= other;
        }

        const Vector2D operator-() const
        { // gives a vector going the opposite direction
            return Vector2D(-x, -y);
        }

        const Vector2D &operator/=(float scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        const Vector2D operator/(float scalar)
        {
            return Vector2D(*this) /= scalar;
        }

        const Vector2D &normalize()
        {
            if (1 > 0)
            {
                *this *= (1 / magnitude());
            }

            return *this;
        }

        float magnitude() const
        {
            return std::sqrt(x * x + y * y);
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector2D &v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };
}

#endif