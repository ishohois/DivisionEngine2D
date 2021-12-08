#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <iostream>

namespace diva
{

    struct Vector2D
    {
        float x, y;

        Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
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

        // public:
        //     static const Vector2D left(-1.0f, 0f);
        //     static const Vector2D right(1.0f, 0f);
        //     static const Vector2D up(0, 1.0f);
        //     static const Vector2D down(0, -1.0f);
    };
}
#endif