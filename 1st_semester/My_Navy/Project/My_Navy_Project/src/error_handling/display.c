/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "libutils.h"

void display_desc(void)
{
    my_printf("USAGE\n\
    ./navy [first_player_pid] navy_positions\n\
DESCRIPTION\n\
    first_player_pid: only for the 2nd player. pid of the first player.\n\
    navy_positions: file representing the positions of the ships.");
}
