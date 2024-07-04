/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** initWindowNcurses
*/

#include <ncurses.h>
#include "../../Game/IGameModule.hpp"

extern "C" void initWindowNcurses(IGameModule &snake)
{
    (void)snake;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    refresh();
}