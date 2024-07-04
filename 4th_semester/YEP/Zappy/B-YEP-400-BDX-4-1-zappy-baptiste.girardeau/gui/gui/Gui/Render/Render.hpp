/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Render
*/

#pragma once

#include <SFML/Graphics/Drawable.hpp>
namespace zizi::gui {

struct GuiState;  // forward declaration

class GuiRenderer final : public sf::Drawable {
   public:
    GuiRenderer(GuiState &state) : _state(&state) {}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   private:
    GuiState *_state;
};

}  // namespace zizi::gui
