/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** SfmlModule
*/

#ifndef SFMLMODULE_HPP_
#define SFMLMODULE_HPP_

#include "../ADisplayModule.hpp"

class SfmlModule : public ADisplayModule {
    public:
        SfmlModule(std::string game, std::string lib);
        ~SfmlModule() = default;

        void (*displayMap)(IGameModule &snake);
        void (*init)(IGameModule &snake);
        std::string (*handleInputSnake)(IGameModule &snake);
        std::pair<std::string, std::string> (*menuDisplayer)(IDisplayModule &menu);

        void initWindow(IGameModule &snake) override;
        void display(IGameModule &snake) override;
        std::string handleInput(IGameModule &snake) override;
        void setDelay() override;
        std::pair<std::string, std::string> displayMenu(IDisplayModule &menu) override;
        void quitWindow(IGameModule &game) override;
        void *getLibFd() override;
    protected:
    private:
        void *libFd;
};

#endif /* !SFMLMODULE_HPP_ */
