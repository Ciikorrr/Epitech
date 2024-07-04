/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** ADisplayModule
*/
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "ADisplayModule.hpp"

ADisplayModule::ADisplayModule()
{
    availableLibs = {};
    idxLibs = {0, 0};
    libs = {{{"SNAKE", "lib/arcade_snake.so"}, {"NIBBLER", "lib/arcade_nibbler.so"}}, {{"NCURSES", "lib/arcade_ncurses.so"}, {"SDL2", "lib/arcade_sdl2.so"}, {"SFML", "lib/arcade_sfml.so"}}};
    background.loadFromFile(PATHBCKGND2);
    backSprite = sf::Sprite(background);
    user = std::string(getenv("USERNAME"));
}

pair<std::map<std::string, std::string>, map<std::string, std::string>> &ADisplayModule::getAvailableLibs()
{
    return availableLibs;
}

void ADisplayModule::setAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs)
{
    availableLibs = libs;
}

SDL_Window *ADisplayModule::getWindow() const
{
    return this->window;
}

std::string ADisplayModule::getUser() const
{
    return user;
}

SDL_Renderer *ADisplayModule::getRenderer() const
{
    return this->renderer;
}

pair<std::map<std::string, std::string>, map<std::string, std::string>> ADisplayModule::getLibs() const
{
    return libs;
}

pair<int, int> &ADisplayModule::getIdxLibs()
{
    return idxLibs;
}

void ADisplayModule::setWindow(SDL_Window *win)
{
    this->window = win;
}

void ADisplayModule::setRenderer(SDL_Renderer *render)
{
    this->renderer = render;
}

sf::Texture ADisplayModule::getBackground()
{
    return this->background;
}

sf::Sprite ADisplayModule::getBackSprite()
{
    return this->backSprite;
}

pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> &ADisplayModule::getAvailabletextSFMLs()
{
    return availabletextSFMLs;
}

void ADisplayModule::setAvailabletextSFMLs(pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> newAvailabletextSFMLs)
{
    availabletextSFMLs = newAvailabletextSFMLs;
}

unique_ptr<sf::RenderWindow>& ADisplayModule::getWindowSFML()
{
    return windowSFML;
}

void ADisplayModule::setWindowSFML(void)
{
    windowSFML = make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "ARCADE");
}