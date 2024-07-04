/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"
#include "../../Error/Error.hpp"
#include <unistd.h>

SfmlModule::SfmlModule(std::string game, std::string lib)
{
    if ((this->libFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore("dlopen failed.");

    if (game == "arcade_snake.so")
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawMapSFMLSnake"));
    else
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawMapSFMLNibbler"));
    this->init = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "initWindowSFML"));
    this->handleInputSnake = reinterpret_cast<std::string (*)(IGameModule &)>(dlsym(this->libFd, "handleInputSFML"));
    this->menuDisplayer =  reinterpret_cast<std::pair<std::string, std::string> (*)(IDisplayModule &)>(dlsym(this->libFd, "displayMenuSFML"));
    if (!displayMap || !init || !handleInputSnake || !menuDisplayer)
        throw ErrorCore("Invalid function.");
}

void SfmlModule::initWindow(IGameModule &snake)
{
    if (this->init)
        init(snake);
}

void SfmlModule::display(IGameModule &snake)
{
    if (this->displayMap)
        displayMap(snake);
}

std::string SfmlModule::handleInput(IGameModule &snake)
{
    if (this->handleInputSnake)
        return handleInputSnake(snake);
    return "";
}

std::pair<std::string, std::string> SfmlModule::displayMenu(IDisplayModule &menu)
{
    if (this->menuDisplayer)
        return menuDisplayer(menu);
    return {"", ""};
}

void SfmlModule::setDelay(void)
{
    usleep(100000);
}

void SfmlModule::quitWindow(IGameModule &game)
{
    game.getWindowPtr().reset(nullptr);
}

void *SfmlModule::getLibFd(void)
{
    return this->libFd;
}