/*
** EPITECH PROJECT, 2024
** C++
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_
#include <vector>
#include "IGameModule.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule() = default;
        ~AGameModule() = default;

        const std::size_t &getScore() const override;
        const std::size_t &getTime() const override;
        const int &getSnakeSize() const override;
        Direction getSnakeDir() const override;
        std::vector<std::pair<int, int>> getTailCoords() const override;
        std::pair<int, int> getTailCoords(int index) const override;
        std::pair<int, int> getHeadCoords() const override;
        int getHeadCoords(bool first) const override;
        virtual int getFruitCoords(bool first) const = 0;
        virtual std::pair<int, int> getFruitCoords() const = 0;
        SDL_Window *getWindow() const override;
        SDL_Renderer *getRenderer() const override;
        sf::Texture &getTexture() override;
        std::unique_ptr<sf::RenderWindow> &getWindowPtr() override;
        sf::RenderWindow *getWindowSFML() const override;
        unique_ptr<sf::RenderWindow> &getSFMLWindow() override;
        size_t getLoopLap() const override;
        virtual std::vector<std::pair<int, int>> getWalls() const = 0;
        virtual std::vector<std::pair<std::pair<int, int>, bool>> getFruitsCoords() const = 0;
        virtual std::pair<std::pair<int, int>, bool> getFruitsCoords(int index) const = 0;
        SDL_Surface *getBackground() const override;
        bool isGameOver() const override;
        bool isEating() const override;
        void setScore(std::size_t score) override;
        void setTime(std::size_t time) override;
        void setSnakeSize(int life) override;
        void setSnakeDir(Direction dir) override;
        void setEating(bool eating) override;
        void setGameOver(bool over) override;
        void setTailCoords(int index, std::pair<int, int>) override;
        void setHeadCoords(int first, int second) override;
        virtual void setFruitCoords(int first, int second) = 0;
        virtual void setFruitVisible(int index, bool b) = 0;
        void setRenderer(SDL_Renderer *render) override;
        void setWindow(SDL_Window *win) override;
        void setWindow() override;
        void setLoopLap(size_t lap) override;
        void setBackGround(SDL_Surface *surface) override;

        virtual int gameAlgorithm(IGameModule &snake) = 0;

    protected:
        void *libFd;
        bool gameOver;
        std::pair<int, int> headCoords;
        std::vector<std::pair<int, int>> tailCoords;
        int lengthTail;
        Direction dir;
        bool eat;
        std::size_t score;
        std::size_t _time;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *backgroundSDL;
        sf::Texture background;
        std::unique_ptr<sf::RenderWindow> windowSFML;
        size_t loopLap;
    private:
};

#endif /* !AGAMEMODULE_HPP_ */
