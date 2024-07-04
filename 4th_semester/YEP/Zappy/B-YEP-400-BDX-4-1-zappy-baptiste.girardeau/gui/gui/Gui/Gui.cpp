/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Gui
*/

#include "Gui.hpp"

namespace zizi::gui {

void Gui::render(client::State clientState, const std::vector<client::Event> &events)
{
    _state.clientState = std::move(clientState);
    auto elapsed = _state.deltaClock.restart();

    handleEvents(events);
    _window.render(_renderer, _detailsWindow, elapsed);
}

void Gui::handleEvents(const std::vector<client::Event> &events)
{
    for (const auto &event : events) {
        _state.eventLog.pushEvent(event);

        std::visit(
            [this](auto &&arg) {
                using T = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<T, client::Event::MapSize>) {
                    clientEvent(arg);
                }
            },
            event.inner
        );
    }
}

void Gui::clientEvent(const client::Event::MapSize &event)
{
    _state.cameraPos = {static_cast<float>(event.size.x) / 2, static_cast<float>(event.size.y) / 2};
    _window.updateView();
}

bool Gui::isOpen() const
{
    return _window.isOpen();
}

}  // namespace zizi::gui
