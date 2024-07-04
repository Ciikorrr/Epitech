/*
** EPITECH PROJECT, 2024
** C++
** File description:
** Sdl2Module
*/

#ifndef SDL2MODULE_HPP_
#define SDL2MODULE_HPP_
#include "../ADisplayModule.hpp"

using namespace std;

class Sdl2Module : public ADisplayModule {
    public:
        Sdl2Module(std::string game, std::string lib);
        ~Sdl2Module() = default;

        void (*displayMap)(IGameModule &snake);
        void (*init)(IGameModule &snake);
        std::string (*handleInputSnake)(IGameModule &snake);
        std::pair<std::string, std::string> (*menuDisplayer)(IDisplayModule &menu);

        void initWindow(IGameModule &snake) override;
        void display(IGameModule &snake) override;
        std::string handleInput(IGameModule &snake) override;
        void setDelay() override;
        std::pair<std::string, std::string> displayMenu(IDisplayModule &menu) override;
        void quitWindow(IGameModule &game [[maybe_unused]]) override;
        void *getLibFd() override;
    protected:
    private:
        void *libFd;
};

#endif /* !SDL2MODULE_HPP_ */
