/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include <string>
#include <memory>
#include "../Graphic/IDisplayModule.hpp"
#include "../Game/IGameModule.hpp"
#define ERROR 84
#define SUCCESS 0

using namespace std;

class Core {
    public:
        Core(string lib);
        ~Core() = default;
        int arcade(void);
        void assignLib(pair<string, string> libs);
        void gameLoop();
        void changeLibrary(std::string library);

    protected:
    private:
        unique_ptr<IDisplayModule> _currentGameGraphicLib;
        unique_ptr<IGameModule> _currentGameLib;
        void *_currentGameGraphicLibFd;
        void *_currentGameLibFd;
        std::string game;
};

#endif /* !CORE_HPP_ */
