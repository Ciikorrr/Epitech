/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** NcursesModule
*/

#include <ncurses.h>
#include <unistd.h>
#include "NcursesModule.hpp"
#include "../../Error/Error.hpp"

NcursesModule::NcursesModule(std::string game, std::string lib)
{
    if ((this->libFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore("dlopen failed.");

    if (game == "arcade_snake.so")
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawSnakeMapNcurses"));
    else
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawNibblerMapNcurses"));
    this->init = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "initWindowNcurses"));
    this->handleInputSnake = reinterpret_cast<std::string (*)(IGameModule &)>(dlsym(this->libFd, "userInputSnakeNcurses"));
    this->menuDisplayer =  reinterpret_cast<std::pair<std::string, std::string> (*)(IDisplayModule &)>(dlsym(this->libFd, "displayMenuNcurses"));
    if (!displayMap || !init || !handleInputSnake || !menuDisplayer)
        throw ErrorCore("Invalid function.");
}

void NcursesModule::initWindow(IGameModule &snake)
{
    if (this->init)
        init(snake);
}

void NcursesModule::display(IGameModule &snake)
{
    if (this->displayMap)
        displayMap(snake);
}

std::string NcursesModule::handleInput(IGameModule &snake)
{
    if (this->handleInputSnake)
        return handleInputSnake(snake);
    return "";
}

std::pair<std::string, std::string> NcursesModule::displayMenu(IDisplayModule &menu)
{
    if (this->menuDisplayer)
        return menuDisplayer(menu);
    return {"", ""};
}

void NcursesModule::setDelay(void)
{
    usleep(100000);
}

void NcursesModule::quitWindow(IGameModule &game [[maybe_unused]])
{
    clear();
    endwin();
}

void *NcursesModule::getLibFd(void)
{
    return this->libFd;
}