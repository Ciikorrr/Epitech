/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** initWindowSDL2
*/

#include "../../Game/IGameModule.hpp"

extern "C" void initWindowSDL(IGameModule &snake)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    snake.setWindow(SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0));
    snake.setRenderer(SDL_CreateRenderer(snake.getWindow(), -1, SDL_RENDERER_ACCELERATED));
    snake.setBackGround(IMG_Load("assets/retro3.jpg"));
}
