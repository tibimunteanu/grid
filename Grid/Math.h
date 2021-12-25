#pragma once

#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

struct Vector2
{
    float x;
    float y;

    Vector2(float _x = 0.0f, float _y = 0.0f)
        : x(_x), y(_y)
    {
    }

    float MagnitudeSqr()
    {
        return x * x + y * y;
    }

    float Magnitude()
    {
        return (float)sqrt(x * x + y * y);
    }

    Vector2 Normalized()
    {
        float mag = Magnitude();

        return mag == 0.0f
            ? Vector2(0.0f, 0.0f)
            : Vector2(x / mag, y / mag);
    }

    Vector2& operator +=(const Vector2& offset)
    {
        x += offset.x;
        y += offset.y;

        return *this;
    }

    Vector2& operator -=(const Vector2& offset)
    {
        x -= offset.x;
        y -= offset.y;

        return *this;
    }

    Vector2& operator *=(const Vector2& offset)
    {
        x *= offset.x;
        y *= offset.y;

        return *this;
    }

    Vector2& operator /=(const Vector2& offset)
    {
        x /= offset.x;
        y /= offset.y;

        return *this;
    }

    Vector2& operator *=(float scalar)
    {
        x *= scalar;
        y *= scalar;

        return *this;
    }

    Vector2& operator /=(float scalar)
    {
        x /= scalar;
        y /= scalar;

        return *this;
    }
};

inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator *(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline Vector2 operator /(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline Vector2 operator *(const Vector2& lhs, float scalar)
{
    return Vector2(lhs.x * scalar, lhs.y * scalar);
}

inline Vector2 RotateVector(Vector2& vec, float angle)
{
    float radAngle = (float)(angle * DEG_TO_RAD);

    float sinRadAngle = sin(radAngle);
    float cosRadAngle = cos(radAngle);

    return Vector2((float)(vec.x * cosRadAngle - vec.y * sinRadAngle),
        (float)(vec.x * sinRadAngle + vec.y * cosRadAngle));
}

inline Vector2 Lerp(Vector2& start, Vector2& end, float t)
{
    if (t <= 0.0f)
    {
        return start;
    }
    if (t >= 1.0f)
    {
        return end;
    }

    Vector2 header = end - start;
    Vector2 mag = header.Magnitude();
    Vector2 dir = header / mag;

    return start + dir * mag * t;
}

const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
const Vector2 VEC2_ONE = { 1.0f, 1.0f };
const Vector2 VEC2_UP = { 0.0f, 1.0f };
const Vector2 VEC2_DOWN = { 0.0f, -1.0f };
const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };
const Vector2 VEC2_LEFT = { -1.0f, 0.0f };
