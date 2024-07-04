/*
** EPITECH PROJECT, 2024
** C++
** File description:
** NcursesModule
*/

#ifndef NCURSESMODULE_HPP_
#define NCURSESMODULE_HPP_
#include <memory>
#include "../ADisplayModule.hpp"
#include "../Ncurses/NcursesModule.hpp"
#define PATH_ASCII_ART "assets/ArcadeAsciiArt"

using namespace std;

class NcursesModule : public ADisplayModule {
    public:
        NcursesModule(std::string game, std::string lib);
        ~NcursesModule() = default;

        void (*displayMap)(IGameModule &snake);
        void (*init)(IGameModule &snake);
        std::string (*handleInputSnake)(IGameModule &snake);
        std::pair<std::string, std::string> (*menuDisplayer)(IDisplayModule &menu);

        void initWindow(IGameModule &snake);
        void display(IGameModule &snake) override;
        std::string handleInput(IGameModule &snake) override;
        std::pair<std::string, std::string> displayMenu(IDisplayModule &menu) override;
        void setDelay() override;
        void quitWindow(IGameModule &game [[maybe_unused]]) override;
        void *getLibFd() override;
    protected:
    private:
        void *libFd;
};


#endif /* !NCURSESMODULE_HPP_ */
