/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** main
*/

#include "server.h"

int main(int argc, char **argv)
{
    zappy_t zappy = {0};

    if (setup_zappy(argc, argv, &zappy) == ERROR)
        return ERROR;
    return launch_zappy_server(&zappy);
}
