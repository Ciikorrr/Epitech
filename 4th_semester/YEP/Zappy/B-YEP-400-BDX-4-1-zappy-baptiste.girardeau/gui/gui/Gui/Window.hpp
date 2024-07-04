/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "gui/Gui/DetailsWindow.hpp"
#include "gui/Gui/Render/Render.hpp"

namespace zizi::gui {

struct GuiState;  // forward declaration

class Window final {
    sf::Color BACKGROUND_COLOR{0, 0, 0};

   public:
    Window(GuiState &state);
    ~Window();

    void render(GuiRenderer &renderer, DetailsWindow &detailsWindow, sf::Time elapsed);
    [[nodiscard]] bool isOpen() const;

    void updateView();
    void updateView(sf::Vector2u size);

   private:
    GuiState *_state;
    sf::RenderWindow _window;

    /* Event handlers */
    void _handleSfmlEvent();
    void _handleResize(const sf::Event::SizeEvent &event);
    void _handleScroll(const sf::Event::MouseWheelScrollEvent &event);
    void _handleKeyPressed(const sf::Event::KeyEvent &event);
    void _handleMouseButtonPressed(const sf::Event::MouseButtonEvent &event);
    void _handleKeyPressedRealtime();
};
}  // namespace zizi::gui
