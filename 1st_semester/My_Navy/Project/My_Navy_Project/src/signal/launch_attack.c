/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <signal.h>
#include <unistd.h>
#include "protos_struct.h"
#include <stdlib.h>
#include "info_class.h"
#include "protos.h"
#include "macros_error.h"

extern info_t game;

navy_t *shoot(navy_t *navy)
{
    for (int i = 0; i < 6; i += 1) {
        if (navy->attack[i] == '0') {
            kill(game.enemy_pid, SIGUSR1);
        } else {
            kill(game.enemy_pid, SIGUSR2);
        }
        usleep(100);
    }
    navy = receive_consequence(navy);
    return navy;
}

void display(int letter1, int num1)
{
    if (game.hit == 1) {
        my_printf("%c%d: hit\n", letter1 + 65, num1 + 1);
    } else {
        my_printf("%c%d: missed\n", letter1 + 65, num1 + 1);
    }
}
