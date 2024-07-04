/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Render
*/

#include "Render.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "gui/Gui/Gui.hpp"
#include "gui/Gui/Render/Map.hpp"
#include "gui/Gui/Render/Player.hpp"
#include "gui/Gui/Render/Egg.hpp"

namespace zizi::gui {

void GuiRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(render::Map(_state->clientState.map, _state->selectedTile), states);

    for (const auto &[_, egg] : _state->clientState.eggs) {
        target.draw(render::Egg(egg), states);
    }
    for (const auto &[_, player] : _state->clientState.players) {
        target.draw(render::Player(player), states);
    }
}

}  // namespace zizi::gui
