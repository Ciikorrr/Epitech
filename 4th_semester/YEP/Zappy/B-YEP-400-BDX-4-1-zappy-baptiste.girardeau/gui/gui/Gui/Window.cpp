/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Window
*/

#include "Window.hpp"

#include <cmath>
#include <imgui-SFML.h>
#include <imgui.h>

#include "gui/Gui/Gui.hpp"
#include "gui/Gui/Res/Font.hpp"

namespace zizi::gui {

Window::Window(GuiState &state) : _state(&state)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    _window.create(sf::VideoMode::getFullscreenModes()[0], "Zappy", sf::Style::Default, settings);
    _window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(_window, false)) {
        throw std::runtime_error("failed to initialize imgui");
    }

    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable;
    io.IniFilename = nullptr;

    io.Fonts->AddFontFromMemoryCompressedBase85TTF(res::ComicMono_compressed_data_base85, 20.0f);
    if (!ImGui::SFML::UpdateFontTexture()) {
        throw std::runtime_error("failed to update font texture");
    }
}

Window::~Window()
{
    ImGui::SFML::Shutdown();
}

bool Window::isOpen() const
{
    return _window.isOpen();
}

void Window::render(GuiRenderer &renderer, DetailsWindow &detailsWindow, sf::Time elapsed)
{
    _handleSfmlEvent();

    ImGui::SFML::Update(_window, elapsed);
    detailsWindow.renderWindow();

    _window.clear(BACKGROUND_COLOR);
    _window.draw(renderer);

    ImGui::SFML::Render(_window);
    _window.display();
}

/* Event handlers */

void Window::_handleSfmlEvent()
{
    sf::Event event{};

    while (_window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(_window, event);

        if (event.type == sf::Event::Closed) {
            _window.close();
        }
        if (event.type == sf::Event::Resized) {
            _handleResize(event.size);
        }
        if (event.type == sf::Event::MouseWheelScrolled) {
            _handleScroll(event.mouseWheelScroll);
        }
        if (event.type == sf::Event::KeyPressed) {
            _handleKeyPressed(event.key);
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            _handleMouseButtonPressed(event.mouseButton);
        }
    }

    _handleKeyPressedRealtime();
}

void Window::_handleResize(const sf::Event::SizeEvent &event)
{
    updateView({event.width, event.height});
}

void Window::_handleScroll(const sf::Event::MouseWheelScrollEvent &event)
{
    auto io = ImGui::GetIO();
    if (io.WantCaptureMouse) {
        return;
    }

    _state->cameraScale = std::clamp(_state->cameraScale + event.delta / 100, 0.05f, 1.5f);
    updateView();
}

void Window::_handleKeyPressed(const sf::Event::KeyEvent &event)
{
    if (event.code == sf::Keyboard::Escape) {
        _window.close();
    }
}

void Window::_handleMouseButtonPressed(const sf::Event::MouseButtonEvent &event)
{
    auto io = ImGui::GetIO();
    if (event.button != sf::Mouse::Left || io.WantCaptureMouse) {
        return;
    }

    auto coords = _window.mapPixelToCoords({event.x, event.y});
    auto selectedTile = sf::Vector2u(std::floor(coords.x), std::floor(coords.y));

    if (selectedTile.x < 0 || selectedTile.y < 0 ||
        selectedTile.x >= _state->clientState.map.size.x ||
        selectedTile.y >= _state->clientState.map.size.y)
    {
        _state->selectedTile = std::nullopt;
    } else {
        _state->selectedTile = selectedTile;
    }
}

void Window::_handleKeyPressedRealtime()
{
    sf::Vector2f moveDelta;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        moveDelta.y -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveDelta.y += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveDelta.x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveDelta.x += 1;
    }

    if (moveDelta != sf::Vector2f{0, 0}) {
        _state->cameraPos += moveDelta * (_state->cameraScale / 2);
        updateView();
    }
}

void Window::updateView(sf::Vector2u size)
{
    auto width = (static_cast<float>(size.x) * (_state->cameraScale / 32));
    auto height = (static_cast<float>(size.y) * (_state->cameraScale / 32));

    _window.setView(sf::View(_state->cameraPos, {width, height}));
}

void Window::updateView()
{
    updateView(_window.getSize());
}

}  // namespace zizi::gui
