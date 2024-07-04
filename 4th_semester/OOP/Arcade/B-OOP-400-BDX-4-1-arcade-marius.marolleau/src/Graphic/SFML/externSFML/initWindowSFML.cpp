/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** initWindow
*/

#include "../../Game/IGameModule.hpp"

extern "C" void initWindowSFML(IGameModule &snake)
{
    snake.setWindow();
}