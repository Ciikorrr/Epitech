/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Sdl2Module
*/

#include "Sdl2Module.hpp"
#include "../../Error/Error.hpp"

Sdl2Module::Sdl2Module(std::string game, std::string lib)
{
    if ((this->libFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore(dlerror());

    if (game == "arcade_snake.so")
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawMapSDLSnake"));
    else
        this->displayMap = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "drawMapSDLNibbler"));
    this->init = reinterpret_cast<void (*)(IGameModule &)>(dlsym(this->libFd, "initWindowSDL"));
    this->handleInputSnake = reinterpret_cast<std::string (*)(IGameModule &)>(dlsym(this->libFd, "userInputSDL"));
    this->menuDisplayer =  reinterpret_cast<std::pair<std::string, std::string> (*)(IDisplayModule &)>(dlsym(this->libFd, "displayMenuSDL2"));
    if (!displayMap || !init || !handleInputSnake || !menuDisplayer)
        throw ErrorCore("Invalid function.");
}

void Sdl2Module::initWindow(IGameModule &snake)
{
    if (this->init)
        init(snake);
}

void Sdl2Module::display(IGameModule &snake)
{
    if (this->displayMap)
        displayMap(snake);
}

std::string Sdl2Module::handleInput(IGameModule &snake)
{
    if (this->handleInputSnake)
        return handleInputSnake(snake);
    return "";
}

void Sdl2Module::setDelay(void)
{
    SDL_Delay(100);
}

std::pair<std::string, std::string> Sdl2Module::displayMenu(IDisplayModule &menu)
{
    if (this->menuDisplayer)
        return menuDisplayer(menu);
    return {"", ""};
}

void Sdl2Module::quitWindow(IGameModule &game [[maybe_unused]])
{
    SDL_Quit();
}

void *Sdl2Module::getLibFd(void)
{
    return this->libFd;
}