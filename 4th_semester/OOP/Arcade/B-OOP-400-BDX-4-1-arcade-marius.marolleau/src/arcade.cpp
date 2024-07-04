/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** arcade
*/
#include "Error/Error.hpp"
#include "Core/Core.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

void Core::gameLoop(void)
{
    std::string command;

    this->_currentGameGraphicLib.get()->initWindow(*this->_currentGameLib.get());
    while (!this->_currentGameLib.get()->isGameOver()) {
        command = "";
        command = this->_currentGameGraphicLib.get()->handleInput(*_currentGameLib.get());
        if (command == "EXIT_GAME" || command == "SHUTDOWN")
            break;
        if (command != "")
            this->changeLibrary(command);
        if (this->_currentGameLib.get()->gameAlgorithm(*_currentGameLib.get()) == ERROR)
            break;
        this->_currentGameGraphicLib.get()->display(*_currentGameLib.get());
        this->_currentGameGraphicLib.get()->setDelay();
    }
    this->_currentGameGraphicLib.get()->quitWindow(*this->_currentGameLib.get());
    if (command != "SHUTDOWN")
        this->arcade();
}

int Core::arcade(void)
{
    try {
        std::pair<std::string, std::string> libselected = this->_currentGameGraphicLib.get()->displayMenu(*this->_currentGameGraphicLib.get());
        if (libselected.first == "")
            return SUCCESS;
        assignLib(libselected);
        gameLoop();
    } catch (const ErrorCore &e) {
        std::cout << e.what() << std::endl;
        return ERROR;
    }
    return SUCCESS;
}