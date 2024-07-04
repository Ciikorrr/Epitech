/*
** EPITECH PROJECT, 2024
** math
** File description:
** Vec3
*/

#include <sys/types.h>
#include <cmath>

#include "Math.hpp"
#include "Ray.hpp"

math::Vec3 &math::Vec3::operator+=(const math::Vec3 &item)
{
    x += item.x;
    y += item.y;
    z += item.z;
    return *this;
}

math::Vec3 math::Vec3::operator+(const math::Vec3 &item) const
{
    return Vec3{x + item.x, y + item.y, z + item.z};
}

math::Vec3 &math::Vec3::operator-=(const math::Vec3 &item)
{
    x -= item.x;
    y -= item.y;
    z -= item.z;
    return *this;
}

math::Vec3 math::Vec3::operator-() const
{
    return {-x, -y, -z};
}

math::Vec3 math::Vec3::operator-(const math::Vec3 &item) const
{
    return math::Vec3{x - item.x, y - item.y, z - item.z};
}

math::Vec3 &math::Vec3::operator*=(const math::Vec3 &item)
{
    x *= item.x;
    y *= item.y;
    z *= item.z;
    return *this;
}

math::Vec3 math::Vec3::operator*(const math::Vec3 &item) const
{
    return math::Vec3{x * item.x, y * item.y, z * item.z};
}

math::Vec3 &math::Vec3::operator/=(const math::Vec3 &item)
{
    x /= item.x;
    y /= item.y;
    z /= item.z;
    return *this;
}

math::Vec3 math::Vec3::operator/(const math::Vec3 &item) const
{
    return math::Vec3{x / item.x, y / item.y, z / item.z};
}

math::Vec3 math::Vec3::operator*(const double &item) const
{
    return math::Vec3{x * item, y * item, z * item};
}

math::Vec3 &math::Vec3::operator*=(const double &item)
{
    x *= item;
    y *= item;
    z *= item;
    return *this;
}

math::Vec3 &math::Vec3::operator/=(const double &item)
{
    x /= item;
    y /= item;
    z /= item;
    return *this;
}

math::Vec3 math::Vec3::operator/(const double &item) const
{
    return Vec3{x / item, y / item, z / item};
}

double math::Vec3::length() const
{
    return sqrt(x * x + y * y + z * z);
}

double math::Vec3::length2() const
{
    return x * x + y * y + z * z;
}

double math::dot(const Vec3 &u, const Vec3 &v)
{
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}

math::Vec3 math::unitVector(const Vec3 &v)
{
    return (v / v.length());
}

math::Vec3 math::cross(const math::Vec3 &u, const math::Vec3 &v)
{
    return {
        u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
}

double math::Vec3::angle(const Vec3 &v) const
{
    double num = dot(*this, v);
    double denum = this->length() * v.length();

    return acos(num / denum);
}

math::Vec3 math::Vec3::reflect(const Vec3 &n) const
{
    return n * dot(n, *this) * 2 - *this;
}

math::Vec3 math::rotatePoint(
    const math::Point3 &pointToRotate, const math::Point3 &rotationCenter,
    double horizontalAngle, double verticalAngle)
{
    // Translate the point and the rotation center to the origin
    math::Point3 pt = pointToRotate - rotationCenter;

    // Horizontal rotation around the Y-axis (yaw)
    double cosHorizontal = std::cos(horizontalAngle);
    double sinHorizontal = std::sin(horizontalAngle);
    double newX = pt.x * cosHorizontal + pt.z * sinHorizontal;
    double newZ = -pt.x * sinHorizontal + pt.z * cosHorizontal;

    // Vertical rotation around the X-axis (pitch)
    double cosVertical = std::cos(verticalAngle);
    double sinVertical = std::sin(verticalAngle);
    double newY = pt.y * cosVertical - newZ * sinVertical;
    newZ = pt.y * sinVertical + newZ * cosVertical;

    // Translate the rotated point back to its original position
    newX += rotationCenter.x;
    newY += rotationCenter.y;
    newZ += rotationCenter.z;

    return {newX, newY, newZ};
}

int math::PCGHash(uint seed)
{
    seed = seed * 747796405U + 2891336453U;
    uint state = seed;
    uint word = ((state >> ((state >> 28U) + 4U)) ^ state) * 277803737U;
    return static_cast<int>((word >> 22U) ^ word);
}
