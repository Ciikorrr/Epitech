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


bool isWall(std::pair<int, int> toFind, IGameModule &nibbler)
{
    for (auto elem : nibbler.getWalls())
        if (elem == toFind)
            return true;
    return false;
}

bool isFruit(std::pair<int, int> head, IGameModule &nibbler)
{
    for (auto elem : nibbler.getFruitsCoords())
        if (elem.first == head && elem.second)
            return true;
    return false;
}

extern "C" void drawNibblerMapNcurses(IGameModule &nibbler)
{
    size_t lengthTmp = nibbler.getSnakeSize();

    if (nibbler.isEating() && nibbler.getSnakeSize() > 1)
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
            if (nibbler.getHeadCoords().first == k && nibbler.getHeadCoords().second == i)
                printw("O");
            else if (isWall(std::make_pair(k, i), nibbler))
                printw("#");
            else if (isFruit(std::make_pair(k, i), nibbler))
                printw("F");
            else {
                bool printable = false;
                for (int j = 0; j < lengthTmp; j += 1) {
                    if (nibbler.getTailCoords(j).first == k && nibbler.getTailCoords(j).second == i) {
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
    printw("TIMER : %d", nibbler.getTime());
    refresh();
}
