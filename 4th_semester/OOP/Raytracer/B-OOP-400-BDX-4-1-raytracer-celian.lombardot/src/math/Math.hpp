/*
** EPITECH PROJECT, 2024
** math
** File description:
** Math
*/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include <ostream>

namespace math {
class Color final
{
   public:
    Color() : r(0), g(0), b(0), a(0) {}
    Color(double p_r, double p_g, double p_b) : r(p_r), g(p_g), b(p_b), a(0) {}
    Color(Color &&) = default;
    Color(const Color &) = default;
    Color &operator=(Color &&) = default;
    Color &operator=(const Color &) = default;
    ~Color() = default;

    Color &operator+=(const Color &item);
    Color operator+(const Color &item) const;
    Color &operator-=(const Color &item);
    Color operator-(const Color &item) const;
    Color &operator*=(const Color &item);
    Color operator*(const Color &item) const;
    Color &operator/=(const Color &item);
    Color operator/(const Color &item) const;

    Color operator*(const double &item) const;
    Color &operator*=(const double &item);
    Color &operator/=(const double &item);
    Color operator/(const double &item) const;
    Color operator+(const double &v) const;
    Color operator-(const double &v) const;

    static Color mixColor(const Color &a, const Color &b);
    void mixColor(const Color &col);
    void writeColor(std::ostream &out) const;
    [[nodiscard]] uint8_t asUint() const;
    [[nodiscard]] sf::Color asSfColor() const;

    double r;
    double g;
    double b;
    double a;

   private:
};

class Vec3 final
{
   public:
    Vec3() : x(0), y(0), z(0) {}
    Vec3(double p_x, double p_y, double p_z) : x(p_x), y(p_y), z(p_z) {}
    Vec3(Vec3 &&) = default;
    Vec3(const Vec3 &) = default;
    Vec3 &operator=(Vec3 &&) = default;
    Vec3 &operator=(const Vec3 &) = default;
    ~Vec3() = default;

    Vec3 &operator+=(const Vec3 &item);
    Vec3 operator+(const Vec3 &item) const;
    Vec3 &operator-=(const Vec3 &item);
    Vec3 operator-(const Vec3 &item) const;
    Vec3 operator-() const;
    Vec3 &operator*=(const Vec3 &item);
    Vec3 operator*(const Vec3 &item) const;
    Vec3 &operator/=(const Vec3 &item);
    Vec3 operator/(const Vec3 &item) const;

    Vec3 operator*(const double &item) const;
    Vec3 &operator*=(const double &item);
    Vec3 operator/(const double &item) const;
    Vec3 &operator/=(const double &item);

    [[nodiscard]] double length() const;
    [[nodiscard]] double length2() const;
    [[nodiscard]] double angle(const Vec3 &) const;
    [[nodiscard]] Vec3 reflect(const Vec3 &n) const;

    double x;
    double y;
    double z;

   private:
};

using Point3 = Vec3;

double dot(const Vec3 &u, const Vec3 &v);
Vec3 cross(const Vec3 &u, const Vec3 &v);
Vec3 unitVector(const Vec3 &v);
Vec3 rotatePoint(
    const math::Point3 &pointToRotate, const math::Point3 &rotationCenter,
    double horizontalAngle, double verticalAngle);

int PCGHash(uint seed);
}  // namespace math
