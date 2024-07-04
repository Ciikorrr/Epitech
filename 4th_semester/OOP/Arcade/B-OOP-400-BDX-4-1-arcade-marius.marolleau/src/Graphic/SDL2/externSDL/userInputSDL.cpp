/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** userInputSDL
*/

#include "../../Game/IGameModule.hpp"
#include "../../../Core/Core.hpp"

extern "C" std::string userInputSDL(Core &core, IGameModule &snake)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                snake.setGameOver(true);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_N:
                    return "arcade_ncurses.so";
                case SDL_SCANCODE_F:
                    return "arcade_sfml.so";
                case SDL_SCANCODE_ESCAPE:
                    return "EXIT_GAME";
                case SDL_SCANCODE_BACKSPACE:
                    return "SHUTDOWN";
                case SDL_SCANCODE_UP:
                    if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == DOWN)
                        break;
                    snake.setSnakeDir(UP);
                    break;
                case SDL_SCANCODE_LEFT:
                    if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == RIGHT)
                        break;
                    snake.setSnakeDir(LEFT);
                    break;
                case SDL_SCANCODE_DOWN:
                    if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == UP)
                        break;
                    snake.setSnakeDir(DOWN);
                    break;
                case SDL_SCANCODE_RIGHT:
                    if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == LEFT)
                        break;
                    snake.setSnakeDir(RIGHT);
                    break;
                default:
                    break;
                }
        }
    }
    return "";
}
