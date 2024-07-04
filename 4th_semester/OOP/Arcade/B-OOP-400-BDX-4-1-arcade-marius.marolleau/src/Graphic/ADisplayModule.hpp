/*
** EPITECH PROJECT, 2024
** C++
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_
#include "IDisplayModule.hpp"
#include "SFML/textSFML.hpp"
#include <map>
#include <memory>

#define PATHBCKGND "assets/retro.jpg"
#define PATHBCKGND2 "assets/retro3.jpg"
#define PATH_FONT_SCORE "assets/comics_sans_ms.ttf"

class ADisplayModule : public IDisplayModule {
    public:
        ADisplayModule();
        ~ADisplayModule() = default;

        pair<std::map<std::string, std::string>, map<std::string, std::string>> &getAvailableLibs() override;
        pair<std::map<std::string, std::string>, map<std::string, std::string>> getLibs() const override;
        pair<int, int> &getIdxLibs() override;
        SDL_Window *getWindow() const override;
        std::string getUser() const override;
        SDL_Renderer *getRenderer() const override;
        void setAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs) override;
        void setRenderer(SDL_Renderer *render) override;
        void setWindow(SDL_Window *win) override;
        sf::Texture getBackground() override;
        sf::Sprite getBackSprite() override;
        unique_ptr<sf::RenderWindow>& getWindowSFML() override;
        virtual void *getLibFd() = 0;
        void setWindowSFML(void) override;
        pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> &getAvailabletextSFMLs() override;
        void setAvailabletextSFMLs(pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> newAvailabletextSFMLs) override;

        virtual void display(IGameModule &snake) = 0;
        virtual void initWindow(IGameModule &snake) = 0;
        virtual std::string handleInput(IGameModule &snake) = 0;
        virtual std::pair<std::string, std::string> displayMenu(IDisplayModule &menu) = 0;
        virtual void setDelay() = 0;
        virtual void quitWindow(IGameModule &game) = 0;
    protected:
        SDL_Renderer *renderer;
        SDL_Window *window;
    private:
        pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs;
        pair<std::map<std::string, std::string>, std::map<std::string, std::string>> libs;
        pair<int, int> idxLibs;
        pair<std::map<std::string, textSFML>, std::map<std::string, textSFML>> availabletextSFMLs;
        sf::Texture background;
        sf::Sprite backSprite;
        unique_ptr<sf::RenderWindow> windowSFML;
        std::string user;
};

#endif /* !ADISPLAYMODULE_HPP_ */
