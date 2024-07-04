/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** user_input
*/

#include <ncurses.h>
#include "../../Game/IGameModule.hpp"
#include "../../../Core/Core.hpp"

extern "C" std::string userInputSnakeNcurses(IGameModule &snake)
{
    switch (getch()) {
        case 's':
            return "arcade_sdl2.so";
        case 'f':
            return "arcade_sfml.so";
        case 27:
            return "EXIT_GAME";
        case KEY_BACKSPACE:
            return "SHUTDOWN";
        case KEY_LEFT:
            if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == RIGHT)
                break;
            snake.setSnakeDir(LEFT);
            break;
        case KEY_UP:
            if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == DOWN)
                break;
            snake.setSnakeDir(UP);
            break;
        case KEY_RIGHT:
            if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == LEFT)
                break;
            snake.setSnakeDir(RIGHT);
            break;
        case KEY_DOWN:
            if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == UP)
                break;
            snake.setSnakeDir(DOWN);
            break;
    }
    return "";
}
