/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Core
*/

#include "Core.hpp"
#include "../Graphic/Ncurses/NcursesModule.hpp"
#include "../Graphic/SDL2/Sdl2Module.hpp"
#include "../Game/Snake/SnakeModule.hpp"
#include "../Game/Nibbler/NibblerModule.hpp"
#include "../Graphic/SFML/SfmlModule.hpp"
#include "../Error/Error.hpp"

Core::Core(string lib)
{
    if ((_currentGameGraphicLibFd = dlopen(lib.c_str(), RTLD_LAZY)) == nullptr)
        throw ErrorCore("dlopen failed.");
    if (lib.substr(lib.find("lib/") + 4) == "arcade_ncurses.so")
        _currentGameGraphicLib = make_unique<NcursesModule>("", lib);
    if (lib.substr(lib.find("lib/") + 4) == "arcade_sdl2.so")
        _currentGameGraphicLib = make_unique<Sdl2Module>("", lib);
    if (lib.substr(lib.find("lib/") + 4) == "arcade_sfml.so")
        _currentGameGraphicLib = make_unique<SfmlModule>("", lib);
}

void Core::assignLib(pair<string, string> libs)
{
    this->game = libs.first;
    dlclose(this->_currentGameGraphicLib.get()->getLibFd());
    if (libs.first == "arcade_snake.so")
        _currentGameLib = make_unique<SnakeModule>("lib/" + libs.first);
    if (libs.first == "arcade_nibbler.so")
        _currentGameLib = make_unique<NibblerModule>("lib/" + libs.first);
    if (libs.second == "arcade_ncurses.so")
        _currentGameGraphicLib = make_unique<NcursesModule>(libs.first, "lib/" + libs.second);
    if (libs.second == "arcade_sdl2.so")
        _currentGameGraphicLib = make_unique<Sdl2Module>(libs.first, "lib/" + libs.second);
    if (libs.second == "arcade_sfml.so")
        _currentGameGraphicLib = make_unique<SfmlModule>(libs.first, "lib/" + libs.second);
}

void Core::changeLibrary(std::string library)
{
    this->_currentGameGraphicLib.get()->quitWindow(*this->_currentGameLib.get());
    dlclose(this->_currentGameGraphicLib.get()->getLibFd());
    if (library == "arcade_ncurses.so")
        this->_currentGameGraphicLib = make_unique<NcursesModule>(this->game, "lib/" + library);
    if (library == "arcade_sdl2.so")
        this->_currentGameGraphicLib = make_unique<Sdl2Module>(this->game, "lib/" + library);
    if (library == "arcade_sfml.so")
        this->_currentGameGraphicLib = make_unique<SfmlModule>(this->game, "lib/" + library);
    this->_currentGameGraphicLib.get()->initWindow(*this->_currentGameLib.get());
}
