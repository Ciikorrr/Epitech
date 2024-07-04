/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** AGameModule
*/

#include "AGameModule.hpp"
#include <string>

const std::size_t &AGameModule::getScore() const
{
    return this->score;
}

const std::size_t &AGameModule::getTime() const
{
    return this->_time;
}

const int &AGameModule::getSnakeSize() const
{
    return this->lengthTail;
}

Direction AGameModule::getSnakeDir(void) const
{
    return this->dir;
}

std::vector<std::pair<int, int>> AGameModule::getTailCoords() const
{
    return this->tailCoords;
}

std::pair<int, int> AGameModule::getTailCoords(int index) const
{
    return this->tailCoords.at(index);
}

std::pair<int, int> AGameModule::getHeadCoords() const
{
    return this->headCoords;
}

int AGameModule::getHeadCoords(bool first) const
{
    if (first)
        return this->headCoords.first;
    return this->headCoords.second;
}

SDL_Window *AGameModule::getWindow() const
{
    return this->window;
}

SDL_Renderer *AGameModule::getRenderer() const
{
    return this->renderer;
}

sf::RenderWindow *AGameModule::getWindowSFML() const
{
    return this->windowSFML.get();
}

std::unique_ptr<sf::RenderWindow> &AGameModule::getSFMLWindow()
{
    return windowSFML;
}

std::unique_ptr<sf::RenderWindow> &AGameModule::getWindowPtr(void)
{
    return this->windowSFML;
}

SDL_Surface *AGameModule::getBackground() const
{
    return this->backgroundSDL;
}

bool AGameModule::isEating(void) const
{
    return this->eat;
}

bool AGameModule::isGameOver(void) const
{
    return this->gameOver;
}

void AGameModule::setScore(std::size_t score)
{
    this->score = score;
}

void AGameModule::setTime(std::size_t time)
{
    this->_time = time;
}

void AGameModule::setSnakeSize(int snakesize)
{
    this->lengthTail = snakesize;
}

void AGameModule::setSnakeDir(Direction dir)
{
    this->dir = dir;
}

void AGameModule::setEating(bool eating)
{
    this->eat = eating;
}

void AGameModule::setGameOver(bool over)
{
    this->gameOver = over;
}

void AGameModule::setTailCoords(int index, std::pair<int, int> pair)
{
    if (index == -1) {
        this->tailCoords.front() = pair;
        return;
    }
    this->tailCoords.at(index) = pair;
}

void AGameModule::setHeadCoords(int first, int second)
{
    if (first != -84)
        this->headCoords.first = first;
    if (second != -84)
        this->headCoords.second = second;
}

void AGameModule::setWindow(SDL_Window *win)
{
    this->window = win;
}

void AGameModule::setRenderer(SDL_Renderer *render)
{
    this->renderer = render;
}

void AGameModule::setWindow(void)
{
    this->windowSFML = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "SFML Window", sf::Style::Close);
    this->windowSFML.get()->setFramerateLimit(20);
    this->background.loadFromFile(PATH_RETRO);
}

sf::Texture &AGameModule::getTexture()
{
    return this->background;
}

void AGameModule::setLoopLap(size_t lap)
{
    this->loopLap = lap;
}

size_t AGameModule::getLoopLap(void) const
{
    return this->loopLap;
}

void AGameModule::setBackGround(SDL_Surface *surface)
{
    this->backgroundSDL = surface;
}