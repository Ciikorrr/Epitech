/*
** EPITECH PROJECT, 2024
** test_SFML
** File description:
** Button
*/

#include "../textSFML.hpp"
#include "../../IDisplayModule.hpp"
#include "../../ADisplayModule.hpp"
#include <memory>
#include <unordered_set>

textSFML::textSFML(int x, int y, float width, float height, std::string text, unique_ptr<sf::RenderWindow> &window, int textSize)
{
    font.loadFromFile(PATH_FONT);

    libText.setString(text);
    libText.setFont(font);
    libText.setCharacterSize(textSize);
    libText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = libText.getLocalBounds();
    libText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    libText.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
    window.get()->draw(libText);
}

textSFML::textSFML(int x, int y, float width, float height, std::string text, unique_ptr<sf::RenderWindow> &window, int textSize, const char *pathFont)
{
    font.loadFromFile(pathFont);

    libText.setString(text);
    libText.setFont(font);
    libText.setCharacterSize(textSize);
    libText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = libText.getLocalBounds();
    libText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    libText.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
    window.get()->draw(libText);
}

std::pair<std::string, std::string> getFinalLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<int, int> idxLibs)
{
    auto iteFst = availableLibs.first.begin();
    std::advance(iteFst, idxLibs.first);
    auto iteSnd = availableLibs.second.begin();
    std::advance(iteSnd, idxLibs.second);

    if (availableLibs.first.size() == 0 || availableLibs.second.size() == 0 || idxLibs.second == -1 || idxLibs.first == -1)
        return {"",""};
    return {iteFst->second.substr(iteFst->second.find("lib/") + 4), iteSnd->second.substr(iteSnd->second.find("lib/") + 4)};
}

void clear(IDisplayModule &menu)
{
    menu.getWindowSFML()->clear();
    menu.getWindowSFML().reset(nullptr);
}

void handleEvents(bool &next, bool &isRunning, std::size_t &end, std::pair<int, int>& idxLibs, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, unique_ptr<sf::RenderWindow> &window)
{
    sf::Event event;
    std::unordered_set<sf::Keyboard::Key> pressedKeys;

    window.get()->pollEvent(event);
    switch (event.type) {
        case (sf::Event::Closed):
            isRunning = false;
            idxLibs.first = -1;
        case (sf::Event::MouseMoved):
            break;
        case (sf::Event::MouseButtonPressed):
            break;
        case (sf::Event::MouseButtonReleased):
            break;
        case (sf::Event::KeyPressed):
            if (!next) {
                switch (event.key.code) {
                    case (sf::Keyboard::Up):
                        if (idxLibs.first > 0)
                            idxLibs.first -= 1;
                        break;
                    case (sf::Keyboard::Down):
                        if (idxLibs.first < availableLibs.first.size() - 1)
                            idxLibs.first += 1;
                        break;
                    case (sf::Keyboard::Return):
                        next = true;
                        end += 1;
                        break;
                }
                return;
            }
            switch (event.key.code) {
                case (sf::Keyboard::Up):
                    if (idxLibs.second > 0)
                        idxLibs.second -= 1;
                    break;
                case (sf::Keyboard::Down):
                    if (idxLibs.second < availableLibs.second.size() - 1)
                        idxLibs.second += 1;
                    break;
                case (sf::Keyboard::Return):
                    end += 1;
                    break;
            }
    }
    return;
}

void displayGame(std::pair<std::size_t, std::size_t> centers, unique_ptr<sf::RenderWindow> &windowSFML, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<std::size_t, std::size_t> idxLibs)
{
    std::pair<std::size_t, std::size_t> newPos = {centers.first + 200, centers.second + 100};
    textSFML libTitle(newPos.first, newPos.second, 200, 50, "Game Libs :", windowSFML, 90);
    std::size_t i = 0;

    newPos.second += 100;
    if (availableLibs.first.size() == 0) {
        textSFML noLib(newPos.first, newPos.second, 200, 50, "No game library found !", windowSFML, 40);
        return;
    }
    for (auto it = availableLibs.first.begin(); it != availableLibs.first.end(); it++, i++) {
        if (i == idxLibs.first)
            textSFML libFound(newPos.first, newPos.second, 200, 50, it->first.c_str(), windowSFML, 50);
        else
            textSFML libFound(newPos.first, newPos.second, 200, 50, it->first.c_str(), windowSFML, 30);
        newPos.second += 100;
    }
}

pair<std::map<std::string, std::string>, map<std::string, std::string>> checkAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs)
{
    pair<std::map<std::string, std::string>, map<std::string, std::string>> newAvailableLibs = {};

    for (auto elem : libs.first)
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.first.insert(elem);

    for (auto elem : libs.second)
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.second.insert(elem);
    return newAvailableLibs;
}

void displayGraphic(std::pair<int, int> centers, unique_ptr<sf::RenderWindow> &windowSFML, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<std::size_t, std::size_t> idxLibs)
{
    std::pair<std::size_t, std::size_t> newPos = {centers.first + 200, centers.second + 100};
    textSFML libTitle(newPos.first, newPos.second, 200 , 50, "Graphic libs :", windowSFML, 90);
    std::size_t i = 0;

    newPos.second += 100;
    if (availableLibs.second.size() == 0) {
        textSFML noLib(newPos.first, newPos.second, 200, 50, "No graphical library found !", windowSFML, 40);
        return;
    }
    for (auto it = availableLibs.second.begin();  it != availableLibs.second.end(); it++, i++) {
        if (i == idxLibs.second)
            textSFML libFound(newPos.first, newPos.second, 200, 50, it->first.c_str(), windowSFML, 50);
        else
            textSFML libFound(newPos.first, newPos.second, 200, 50, it->first.c_str(), windowSFML, 30);
        newPos.second += 100;
    }
}

void displayArcadeTitle(std::pair<int, int>centers, unique_ptr<sf::RenderWindow> &window)
{
    textSFML arcade(centers.first + 200, centers.second + 100, 200, 50, "Arcade", window, 70);
}

void displayBackground(IDisplayModule &menu)
{
    menu.getWindowSFML().get()->draw(menu.getBackSprite());
}

void displayUser(IDisplayModule &menu)
{
    textSFML user(20, 10, 200, 50, "USERNAME " + menu.getUser(), menu.getWindowSFML(), 20);
}

void displayAll(bool next, std::pair<std::size_t, std::size_t> centers, IDisplayModule &menu)
{
    displayBackground(menu);
    displayUser(menu);
    if (next)
        displayGraphic(centers, menu.getWindowSFML(), menu.getAvailableLibs(), menu.getIdxLibs());
    else
        displayGame(centers, menu.getWindowSFML(), menu.getAvailableLibs(), menu.getIdxLibs());
    menu.getWindowSFML().get()->display();
    menu.getWindowSFML().get()->clear();
}

extern "C" std::pair<std::string, std::string> displayMenuSFML(IDisplayModule &menu)
{
    bool next = false;
    bool isRunning = true;
    std::size_t end = 0;
    std::pair<std::size_t, std::size_t> centers = {1920 / 2.8, 1080 / 5};
    menu.setWindowSFML();

    while (isRunning) {
        if (end == 2)
            isRunning = false;
        menu.setAvailableLibs(checkAvailableLibs(menu.getLibs()));
        handleEvents(next, isRunning, end, menu.getIdxLibs(), menu.getAvailableLibs(), menu.getWindowSFML());
        displayAll(next, centers, menu);
    }
    clear(menu);
    return getFinalLibs(menu.getAvailableLibs(), menu.getIdxLibs());
}
