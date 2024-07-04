/*
** EPITECH PROJECT, 2024
** C++
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_
#include <string>
#include <iostream>
#include <dlfcn.h>
#include "../Game/IGameModule.hpp"
#include <vector>
#include <map>
#include "SFML/textSFML.hpp"

#define PATH_FONT "assets/ReadyPlayerOne.ttf"
#define PATH_FONT_SCORE "assets/comics_sans_ms.ttf"

using namespace std;

class Core;

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        virtual pair<std::map<std::string, std::string>, map<std::string, std::string>> &getAvailableLibs() = 0;
        virtual pair<std::map<std::string, std::string>, map<std::string, std::string>> getLibs() const = 0;
        virtual pair<int, int> &getIdxLibs() = 0;
        virtual SDL_Window *getWindow() const = 0;
        virtual std::string getUser() const = 0;
        virtual SDL_Renderer *getRenderer() const = 0;
        virtual void setAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs) = 0;
        virtual void setRenderer(SDL_Renderer *render) = 0;
        virtual void setWindow(SDL_Window *win) = 0;
        virtual void *getLibFd() = 0;
        virtual sf::Texture getBackground() = 0;
        virtual sf::Sprite getBackSprite() = 0;
        virtual unique_ptr<sf::RenderWindow>& getWindowSFML() = 0;
        virtual void setWindowSFML(void) = 0;
        virtual pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> &getAvailabletextSFMLs() = 0;
        virtual void setAvailabletextSFMLs(pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> newAvailabletextSFMLs) = 0;

        virtual void initWindow(IGameModule &snake) = 0;
        virtual void display(IGameModule &snake) = 0;
        virtual std::string handleInput(IGameModule &snake) = 0;
        virtual std::pair<std::string, std::string> displayMenu(IDisplayModule &menu) = 0;
        virtual void setDelay() = 0;
        virtual void quitWindow(IGameModule &game) = 0;
    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
