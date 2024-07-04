/*
** EPITECH PROJECT, 2024
** C++
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_
#include <iostream>
#include <dlfcn.h>
#include <vector>
#include <array>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SFML/Graphics.hpp>

#define PATH_RETRO "assets/retro2.jpg"

class SnakeModule;

using namespace std;

enum Direction {
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class IGameModule {
    public:
        IGameModule() = default;
        ~IGameModule() = default;
        virtual const std::size_t &getScore() const = 0;
        virtual const std::size_t &getTime() const = 0;
        virtual const int &getSnakeSize() const = 0;
        virtual Direction getSnakeDir() const = 0;
        virtual std::vector<std::pair<int, int>> getTailCoords() const = 0;
        virtual std::pair<int, int> getTailCoords(int index) const = 0;
        virtual std::pair<int, int> getHeadCoords() const = 0;
        virtual int getHeadCoords(bool first) const = 0;
        virtual int getFruitCoords(bool first) const = 0;
        virtual std::unique_ptr<sf::RenderWindow> &getWindowPtr() = 0;
        virtual std::vector<std::pair<std::pair<int, int>, bool>> getFruitsCoords() const = 0;
        virtual std::pair<std::pair<int, int>, bool> getFruitsCoords(int index) const = 0;
        virtual std::pair<int, int> getFruitCoords() const = 0;
        virtual SDL_Window *getWindow() const = 0;
        virtual unique_ptr<sf::RenderWindow> &getSFMLWindow() = 0;
        virtual sf::RenderWindow *getWindowSFML() const = 0;
        virtual SDL_Renderer *getRenderer() const = 0;
        virtual sf::Texture &getTexture() = 0;
        virtual SDL_Surface *getBackground() const = 0;
        virtual size_t getLoopLap() const = 0;
        virtual std::vector<std::pair<int, int>> getWalls() const = 0;
        virtual bool isGameOver() const = 0;
        virtual bool isEating() const = 0;
        virtual void setScore(std::size_t score) = 0;
        virtual void setTime(std::size_t time) = 0;
        virtual void setSnakeSize(int life) = 0;
        virtual void setSnakeDir(Direction dir) = 0;
        virtual void setEating(bool eating) = 0;
        virtual void setGameOver(bool over) = 0;
        virtual void setTailCoords(int index, std::pair<int, int>) = 0;
        virtual void setHeadCoords(int first, int second) = 0;
        virtual void setFruitCoords(int first, int second) = 0;
        virtual void setFruitVisible(int index, bool b) = 0;
        virtual void setRenderer(SDL_Renderer *render) = 0;
        virtual void setWindow(SDL_Window *win) = 0;
        virtual void setWindow() = 0;
        virtual void setLoopLap(size_t lap) = 0;
        virtual void setBackGround(SDL_Surface *surface) = 0;

        virtual int gameAlgorithm(IGameModule &snake) = 0;
    protected:
    private:
};

#endif /* !IGAMEMODULE_HPP_ */
