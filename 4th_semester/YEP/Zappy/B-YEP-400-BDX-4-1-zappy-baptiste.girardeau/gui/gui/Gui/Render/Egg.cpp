/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Egg
*/

#include "Egg.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "gui/Gui/Res/Assets.hpp"

namespace zizi::gui::render {

void Egg::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    const sf::Sprite egg(gui::res::Assets::Egg());

    states.transform =
        sf::Transform{states.transform}
            .translate(
                0.2f + static_cast<float>(_egg->position.x),
                0.2f + static_cast<float>(_egg->position.y)
            )
            .scale(0.6f / egg.getLocalBounds().width, 0.6f / egg.getLocalBounds().height);

    target.draw(egg, states);
}
}  // namespace zizi::gui::render
