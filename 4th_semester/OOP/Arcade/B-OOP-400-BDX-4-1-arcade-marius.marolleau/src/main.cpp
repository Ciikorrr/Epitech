/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** main
*/

#include <stdio.h>
#include "Parser/Parser.hpp"
#include "Core/Core.hpp"

int main(const int argc, char **argv)
{
    if (!argv || !argv[0] || !argv[1])
        return ERROR;
    if (!checkArgs(argc, argv))
        return ERROR;
    string lib(argv[1]);
    Core coreGame(lib);
    return coreGame.arcade();
}