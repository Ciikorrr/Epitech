/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** displaySDL
*/

#include "../../Game/IGameModule.hpp"
#include "../../IDisplayModule.hpp"
#include <SDL2/SDL_image.h>
#include "../../Menu/SDL2Menu.hpp"
#include "../Sdl2Module.hpp"
#include <sstream>

std::array<int, 18> YConverterSnake = {
        100, 150, 200, 250, 300, 350,
        400, 450, 500, 550, 600, 650,
        700, 750, 800, 850, 900, 950
    };

std::array<int, 18> XConverterSnake = {
    510, 560, 610, 660, 710, 760,
    810, 860, 910, 960, 1010, 1060,
    1110, 1160, 1210, 1260, 1310, 1360
};

void drawSnakeMap(IGameModule &snake)
{
    SDL_Rect rect = { 510, 100, 900, 900 };
    SDL_SetRenderDrawBlendMode(snake.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(snake.getRenderer(), 0, 0, 0, 0x80);
    SDL_RenderFillRect(snake.getRenderer(), &rect);
}

void drawFruitSnake(IGameModule &snake)
{
    SDL_Rect rect = {XConverterSnake[snake.getFruitCoords(true)], YConverterSnake[snake.getFruitCoords(false)], 50, 50};
    SDL_SetRenderDrawColor(snake.getRenderer(), 200, 0, 0, 255);
    SDL_RenderFillRect(snake.getRenderer(), &rect);
}

std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void drawSnakeScore(IGameModule &snake)
{
    TextSDL2 Score(("Score : " + to_string(snake.getScore())).c_str(), 50, {150, 500}, snake.getRenderer(), PATH_FONT_SCORE);
}

void drawSnakeUsage(IGameModule &snake)
{
    TextSDL2 Up("Arrow UP to go UP", 20, {1500, 600}, snake.getRenderer());
    TextSDL2 Down("Arrow DOWN to go DOWN", 20, {1500, 630}, snake.getRenderer());
    TextSDL2 Left("Arrow LEFT to go LEFT", 20, {1500, 660}, snake.getRenderer());
    TextSDL2 Right("Arrow RIGHT to go RIGHT", 20, {1500, 690}, snake.getRenderer());
}

void drawSnakeTitle(IGameModule &snake)
{
    TextSDL2 Score("SNAKE", 50, {860, 50}, snake.getRenderer());
}

void drawSnake(IGameModule &snake)
{
    size_t lengthTmp = snake.getSnakeSize();
    SDL_Rect rect = {XConverterSnake[snake.getHeadCoords(true)], YConverterSnake[snake.getHeadCoords(false)], 50, 50};

    SDL_SetRenderDrawColor(snake.getRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(snake.getRenderer(), &rect);
    if (snake.isEating() && snake.getSnakeSize() > 1)
        lengthTmp -= 1;
    for (size_t i = 0; i < lengthTmp; i += 1) {
        rect = {XConverterSnake[snake.getTailCoords(i).first], YConverterSnake[snake.getTailCoords(i).second], 50, 50};
        SDL_SetRenderDrawColor(snake.getRenderer(), 0, 255, 0, 255);
        SDL_RenderFillRect(snake.getRenderer(), &rect);
    }
}

extern "C" void drawMapSDLSnake(IGameModule &snake)
{
    SDL_RenderClear(snake.getRenderer());
    SDL_Texture *backTexture = SDL_CreateTextureFromSurface(snake.getRenderer(), snake.getBackground());
    SDL_RenderCopy(snake.getRenderer(), backTexture, NULL, NULL);
    drawSnakeMap(snake);
    drawFruitSnake(snake);
    drawSnake(snake);
    drawSnakeTitle(snake);
    drawSnakeScore(snake);
    drawSnakeUsage(snake);
    SDL_RenderPresent(snake.getRenderer());
}