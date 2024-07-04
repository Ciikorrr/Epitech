/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** displaySnakeSFML
*/

#include "../../Game/IGameModule.hpp"
#include "../../IDisplayModule.hpp"
#include "../textSFML.hpp"


std::array<int, 18> YConverterSnakeSFML = {
        100, 150, 200, 250, 300, 350,
        400, 450, 500, 550, 600, 650,
        700, 750, 800, 850, 900, 950
    };

std::array<int, 18> XConverterSnakeSFML = {
    510, 560, 610, 660, 710, 760,
    810, 860, 910, 960, 1010, 1060,
    1110, 1160, 1210, 1260, 1310, 1360
};

void drawSnakeRectangleSFML(IGameModule &snake)
{
    sf::RectangleShape rect(sf::Vector2f(900, 900));
    rect.setFillColor(sf::Color(0, 0, 0, 170));
    rect.setPosition(510, 100);
    snake.getWindowSFML()->draw(rect);
}

void drawFruitSnakeSFML(IGameModule &snake)
{
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(XConverterSnakeSFML[snake.getFruitCoords(true)], YConverterSnakeSFML[snake.getFruitCoords(false)]);
    snake.getWindowSFML()->draw(rect);
}

void drawSnakeSFMLTitle(IGameModule &snake)
{
    textSFML Snake(860, 30, 200 , 50, "SNAKE", snake.getSFMLWindow(), 90);
}

void drawSnakeSFMLScore(IGameModule &snake)
{
    textSFML Nibbler(200, 500, 200 , 50, ("Score : " + to_string(snake.getScore())), snake.getSFMLWindow(), 50, PATH_FONT_SCORE);
}

void drawSnakeSFMLUsage(IGameModule &snake)
{
    textSFML Up(1550, 500, 200 , 50, "Arrow UP to go UP", snake.getSFMLWindow(), 20);
    textSFML Down(1550, 550, 200 , 50, "Arrow Down to go DOWN", snake.getSFMLWindow(), 20);
    textSFML Left(1550, 600, 200 , 50, "Arrow Left to go LEFT", snake.getSFMLWindow(), 20);
    textSFML Right(1550, 650, 200 , 50, "Arrow Right to go RIGHT", snake.getSFMLWindow(), 20);
}

void drawSnakeSFML(IGameModule &snake)
{
    size_t lengthTmp = snake.getSnakeSize();
    sf::RectangleShape head(sf::Vector2f(50, 50));

    head.setFillColor(sf::Color::Green);
    head.setPosition(XConverterSnakeSFML[snake.getHeadCoords(true)], YConverterSnakeSFML[snake.getHeadCoords(false)]);
    snake.getWindowSFML()->draw(head);
    if (snake.isEating() && snake.getSnakeSize() > 1)
        lengthTmp -= 1;
    for (size_t i = 0; i < lengthTmp; i += 1) {
        sf::RectangleShape tail(sf::Vector2f(50, 50));
        tail.setFillColor(sf::Color::Green);
        tail.setPosition(XConverterSnakeSFML[snake.getTailCoords(i).first], YConverterSnakeSFML[snake.getTailCoords(i).second]);
        snake.getWindowSFML()->draw(tail);
    }
}

extern "C" void drawMapSFMLSnake(IGameModule &snake)
{
    snake.getWindowSFML()->clear(sf::Color::Blue);
    sf::Sprite background(snake.getTexture());
    background.setPosition(0, 0);
    snake.getWindowSFML()->draw(background);
    drawSnakeRectangleSFML(snake);
    drawFruitSnakeSFML(snake);
    drawSnakeSFML(snake);
    drawSnakeSFMLTitle(snake);
    drawSnakeSFMLScore(snake);
    drawSnakeSFMLUsage(snake);
    snake.getWindowSFML()->display();
}