/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Player
*/

#include "Player.hpp"

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Shape.hpp>

namespace zizi::gui::render {

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform = sf::Transform{states.transform}
                           .translate(
                               static_cast<float>(_player->position.x) + 0.5f,
                               static_cast<float>(_player->position.y) + 0.5f
                           )
                           .rotate((static_cast<float>(_player->orientation) - 1) * 90);

    sf::ConvexShape shape;
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f{0, -0.4});
    shape.setPoint(1, sf::Vector2f{-0.4, 0.4});
    shape.setPoint(2, sf::Vector2f{0.4, 0.4});
    shape.setOrigin(0, 0);
    shape.setFillColor(sf::Color::White);

    target.draw(shape, states);
}
}  // namespace zizi::gui::render
