/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DetailsWindow
*/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include "gui/Client/State.hpp"

namespace zizi::gui {

struct GuiState;  // forward declaration

class DetailsWindow final {
   public:
    explicit DetailsWindow(GuiState &state) : _state(&state) {}

    void renderWindow();

   private:
    void renderGameWindow();
    void renderTileWindow();
    void renderPlayerWindow();
    void renderLogWindow();

    GuiState *_state;
};

namespace widget {
void Badge(const sf::Color color, const std::string &tooltip = "");
void Inventory(const client::Inventory &inventory);
void Player(const client::Player &player, GuiState &state, bool focusButton = true);
}  // namespace widget

}  // namespace zizi::gui
