/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** displayNibblerSFML
*/

#include "../../Game/IGameModule.hpp"
#include "../textSFML.hpp"
#include "../../IDisplayModule.hpp"
#include <sstream>

std::array<int, 18> YConverterNibblerSFML = {
        100, 150, 200, 250, 300, 350,
        400, 450, 500, 550, 600, 650,
        700, 750, 800, 850, 900, 950
    };

std::array<int, 18> XConverterNibblerSFML = {
    510, 560, 610, 660, 710, 760,
    810, 860, 910, 960, 1010, 1060,
    1110, 1160, 1210, 1260, 1310, 1360
};

void drawNibblerRectangleSFML(IGameModule &nibbler)
{
    sf::RectangleShape rect(sf::Vector2f(900, 900));
    rect.setFillColor(sf::Color(0, 0, 0, 100));
    rect.setPosition(510, 100);
    nibbler.getWindowSFML()->draw(rect);
}

void drawFruitsNibblerSFML(IGameModule &nibbler)
{
    for (auto elem : nibbler.getFruitsCoords()) {
        if (!elem.second)
            continue;
        sf::RectangleShape rect(sf::Vector2f(50, 50));
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(XConverterNibblerSFML[elem.first.first], YConverterNibblerSFML[elem.first.second]);
        nibbler.getWindowSFML()->draw(rect);
    }
}

void drawNibblerSFML(IGameModule &nibbler)
{
    size_t lengthTmp = nibbler.getSnakeSize();
    sf::RectangleShape head(sf::Vector2f(50, 50));

    head.setFillColor(sf::Color::Green);
    head.setPosition(XConverterNibblerSFML[nibbler.getHeadCoords(true)], YConverterNibblerSFML[nibbler.getHeadCoords(false)]);
    nibbler.getWindowSFML()->draw(head);
    if (nibbler.isEating() && nibbler.getSnakeSize() > 1)
        lengthTmp -= 1;
    for (size_t i = 0; i < lengthTmp; i += 1) {
        sf::RectangleShape tail(sf::Vector2f(50, 50));
        tail.setFillColor(sf::Color::Green);
        tail.setPosition(XConverterNibblerSFML[nibbler.getTailCoords(i).first], YConverterNibblerSFML[nibbler.getTailCoords(i).second]);
        nibbler.getWindowSFML()->draw(tail);
    }
}

void drawNibblerSFMLUsage(IGameModule &nibbler)
{
    textSFML Up(1550, 500, 200 , 50, "Arrow UP to go UP", nibbler.getSFMLWindow(), 20);
    textSFML Down(1550, 550, 200 , 50, "Arrow Down to go DOWN", nibbler.getSFMLWindow(), 20);
    textSFML Left(1550, 600, 200 , 50, "Arrow Left to go LEFT", nibbler.getSFMLWindow(), 20);
    textSFML Right(1550, 650, 200 , 50, "Arrow Right to go RIGHT", nibbler.getSFMLWindow(), 20);
}

void drawNibblerSFMLTitle(IGameModule &nibbler)
{
    textSFML Nibbler(860, 30, 200 , 50, "NIBBLER", nibbler.getSFMLWindow(), 90);
}

void drawNibblerSFMLTimer(IGameModule &nibbler)
{
    textSFML Nibbler(200, 500, 200 , 50, ("Timer : " + to_string(nibbler.getTime())), nibbler.getSFMLWindow(), 50, PATH_FONT_SCORE);
}

void drawNibblerMapSFML(IGameModule &nibbler)
{
    int tmpX;
    int tmpY;
    std::pair<int, int> size;

    for (auto elem : nibbler.getWalls()) {
        size = std::make_pair(50, 50);
        if (elem.first == -1) {
            tmpX = 485;
            size = std::make_pair(25, 50);
        } else if (elem.first == 18) {
            tmpX = 1410;
            size = std::make_pair(25, 50);
        } else
            tmpX = XConverterNibblerSFML[elem.first];
        if (elem.second == -1) {
            tmpY = 75;
            size = std::make_pair(50, 25);
        } else if (elem.second == 18) {
            tmpY = 1000;
            size = std::make_pair(50, 25);
        } else
            tmpY = YConverterNibblerSFML[elem.second];
        sf::RectangleShape rect(sf::Vector2f(size.first, size.second));
        rect.setFillColor(sf::Color(40, 40, 40, 255));
        rect.setPosition(tmpX, tmpY);
        nibbler.getWindowSFML()->draw(rect);
    }
}


extern "C" void drawMapSFMLNibbler(IGameModule &nibbler)
{
    nibbler.getWindowSFML()->clear(sf::Color::Blue);
    sf::Sprite background(nibbler.getTexture());
    background.setPosition(0, 0);
    nibbler.getWindowSFML()->draw(background);
    drawNibblerRectangleSFML(nibbler);
    drawFruitsNibblerSFML(nibbler);
    drawNibblerSFML(nibbler);
    drawNibblerMapSFML(nibbler);
    drawNibblerSFMLTitle(nibbler);
    drawNibblerSFMLTimer(nibbler);
    drawNibblerSFMLUsage(nibbler);
    nibbler.getWindowSFML()->display();
}