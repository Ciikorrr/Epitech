/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/

#include "Math.hpp"
#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include <iostream>

math::Color &math::Color::operator+=(const Color &item)
{
    this->r += item.r;
    this->g += item.g;
    this->b += item.b;
    return *this;
}

math::Color math::Color::operator+(const Color &item) const
{
    return {this->r + item.r, this->g + item.g, this->b + item.b};
}

math::Color &math::Color::operator-=(const Color &item)
{
    this->r -= item.r;
    this->g -= item.g;
    this->b -= item.b;
    return *this;
}

math::Color math::Color::operator-(const Color &item) const
{
    return Color{this->r - item.r, this->g - item.g, this->b - item.b};
}

math::Color &math::Color::operator*=(const Color &item)
{
    this->r *= item.r;
    this->g *= item.g;
    this->b *= item.b;
    return *this;
}

math::Color math::Color::operator*(const Color &item) const
{
    Color vector(this->r * item.r, this->g * item.g, this->b * item.b);
    return vector;
}

math::Color &math::Color::operator/=(const Color &item)
{
    this->r /= item.r;
    this->g /= item.g;
    this->b /= item.b;
    return *this;
}

math::Color math::Color::operator/(const Color &item) const
{
    Color vector(this->r / item.r, this->g / item.g, this->b / item.b);
    return vector;
}

math::Color &math::Color::operator/=(const double &item)
{
    this->r /= item;
    this->g /= item;
    this->b /= item;
    return *this;
}

math::Color math::Color::operator/(const double &item) const
{
    return {this->r / item, this->g / item, this->b / item};
}

math::Color &math::Color::operator*=(const double &item)
{
    this->r *= item;
    this->g *= item;
    this->b *= item;
    return *this;
}

math::Color math::Color::operator*(const double &item) const
{
    return {this->r * item, this->g * item, this->b * item};
}

void math::Color::writeColor(std::ostream &out) const
{
    int ri = int((r > 1 ? 1 : r) * 255.999);
    int gi = int((g > 1 ? 1 : g) * 255.999);
    int bi = int((b > 1 ? 1 : b) * 255.999);

    out << ri << ' ' << gi << ' ' << bi << ' ' << '\n';
}

math::Color math::Color::operator+(const double &v) const
{
    return Color{this->r + v, this->g + v, this->b + v};
}

math::Color math::Color::operator-(const double &v) const
{
    return Color{this->r - v, this->g - v, this->b - v};
}

math::Color math::Color::mixColor(const Color &a, const Color &b)
{
    return {std::max(a.r, b.r), std::max(a.g, b.g), std::max(a.b, b.b)};
}

void math::Color::mixColor(const Color &col)
{
    this->r = std::max(r, col.r);
    this->g = std::max(g, col.g);
    this->b = std::max(b, col.b);
}

uint8_t math::Color::asUint() const
{
    auto ri = short((r > 1 ? 1 : r) * 255.999);
    auto gi = short((g > 1 ? 1 : g) * 255.999);
    auto bi = short((b > 1 ? 1 : b) * 255.999);
    return ri << 24 | gi << 16 | bi << 8 | 255;
}

sf::Color math::Color::asSfColor() const
{
    sf::Uint8 ri = short((r > 1 ? 1 : r) * 255.999);
    sf::Uint8 gi = short((g > 1 ? 1 : g) * 255.999);
    sf::Uint8 bi = short((b > 1 ? 1 : b) * 255.999);
    return {ri, gi, bi};
}
