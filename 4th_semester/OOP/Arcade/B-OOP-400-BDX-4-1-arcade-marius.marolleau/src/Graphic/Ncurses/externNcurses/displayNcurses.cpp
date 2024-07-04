/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** display
*/

#include <iomanip>
#include <iostream>
#include <ncurses.h>
#include "../../Game/IGameModule.hpp"

extern "C" {
    void drawSnakeMapNcurses(IGameModule &snake)
    {
        size_t lengthTmp = snake.getSnakeSize();

        if (snake.isEating() && snake.getSnakeSize() > 1)
            lengthTmp -= 1;
        clear();
        if (getmaxy(stdscr) <= 25) {
            printw("Please, resize your terminal in order to play to the game.");
            return;
        }
        for (int i = 0; i < 20; i += 1)
            printw("#");
        printw("\n");

        for (int i = 0; i < 18; i += 1) {
            printw("#");
            for (int k = 0; k < 18; k += 1) {
                if (snake.getHeadCoords().first == k && snake.getHeadCoords().second == i)
                    printw("O");
                else if (snake.getFruitCoords().first == k && snake.getFruitCoords().second == i)
                    printw("F");
                else {
                    bool printable = false;
                    for (int j = 0; j < lengthTmp; j += 1) {
                        if (snake.getTailCoords().at(j).first == k && snake.getTailCoords().at(j).second == i) {
                            printw("o");
                            printable = true;
                        }
                    }
                    if (!printable)
                        printw(" ");
                }
            }
            printw("#\n");
        }

        for (int i = 0; i < 20; i += 1)
            printw("#");
        printw("\n");
        printw("Score: %d\n", snake.getScore());
        refresh();
    }
}
