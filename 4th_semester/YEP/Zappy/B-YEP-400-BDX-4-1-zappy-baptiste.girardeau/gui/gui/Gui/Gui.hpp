/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Gui
*/

#pragma once

#include <SFML/System/Clock.hpp>

#include "gui/Client/Event.hpp"
#include "gui/Client/State.hpp"
#include "gui/Gui/DetailsWindow.hpp"
#include "gui/Gui/EventLog.hpp"
#include "gui/Gui/Render/Render.hpp"
#include "gui/Gui/Window.hpp"

namespace zizi::gui {

struct GuiState {
    GuiState()
    {
        std::fill(eventFilter.begin(), eventFilter.end(), true);
    }

    client::State clientState;
    EventLog eventLog;
    std::array<bool, static_cast<size_t>(client::EventType::SIZE)> eventFilter;

    std::optional<client::Position> selectedTile;
    std::optional<client::PlayerId> focusedPlayer;

    sf::Clock deltaClock;
    float cameraScale = 1;
    sf::Vector2f cameraPos = {0, 0};
};

class Gui final {
   public:
    Gui() : _window(_state), _renderer(_state), _detailsWindow(_state) {}

    void render(client::State clientState, const std::vector<client::Event> &events);
    [[nodiscard]] bool isOpen() const;

   private:
    void handleEvents(const std::vector<client::Event> &events);
    void clientEvent(const client::Event::MapSize &event);

    GuiState _state;

    Window _window;
    GuiRenderer _renderer;
    DetailsWindow _detailsWindow;
};
}  // namespace zizi::gui
