/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Egg
*/

#pragma once

#include <SFML/Graphics/Drawable.hpp>

#include "gui/Client/State.hpp"

namespace zizi::gui::render {

class Egg : public sf::Drawable {
   public:
    explicit Egg(const client::Egg &egg) : _egg(&egg) {}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   private:
    const client::Egg *_egg;
};

}  // namespace zizi::gui::render
