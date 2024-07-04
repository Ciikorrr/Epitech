/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Player
*/

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include "gui/Client/State.hpp"

namespace zizi::gui::render {

class Player : public sf::Drawable {
   public:
    explicit Player(const client::Player &player) : _player(&player) {}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   private:
    const client::Player *_player;
};

}  // namespace zizi::render
