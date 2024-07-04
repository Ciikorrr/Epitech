#include "SfmlDisplay.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

#include "../../../Core/Core.hpp"

SFMLDisplay::SFMLDisplay() { createWindow(); }

void SFMLDisplay::renderLoop(Krell::Core &core) {
    while (_window->isOpen()) {
        _window->clear(sf::Color(26, 26, 26, 255));
        if (const eventType event = eventManager(); event == CLOSE_EVENT)
            _window->close();
        core.updateStacks();
        const std::vector<WidgetStack> &widgetStacks = core.getStacks();
        int stackIndex = 0;
        for (auto &stack : widgetStacks) {
            initDrawStack(stack, stackIndex);
            // penser à destroy;
            stackIndex++;
        }
        _window->display();
    }
}

void SFMLDisplay::initDrawStack(const WidgetStack &stack,
                                const int stackIndex) {
    Stack stackDisplay(stackIndex);
    stackDisplay.updateStack(stack);
    _window->draw(stackDisplay.Shape);
    _window->draw(stackDisplay.Title);
    for (const sf::Text &text : stackDisplay.Text) {
        _window->draw(text);
    }
}

void SFMLDisplay::createWindow() {
    this->_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MyGKrellm",
        sf::Style::Close);
}

SFMLDisplay::eventType SFMLDisplay::eventManager() {
    sf::Event event{};
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) return CLOSE_EVENT;
    }
    return NONE;
}
