/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "protos_struct.h"
#include "info_class.h"
#include "protos.h"
#include "macros_error.h"

extern info_t game;

void receive(int signo, siginfo_t *info, void *context)
{
    game.shoot = 0;
    (void)info;
    (void)context;
    if (signo == 12) {
        game.shoot = 1;
    }
    if (signo == 10) {
        game.shoot = 0;
    }
}

navy_t *receive_consequence(navy_t *navy)
{
    struct sigaction *hit = malloc(sizeof(struct sigatcion *));
    hit->sa_flags = SA_SIGINFO;
    hit->sa_sigaction = &receive;
    sigaction(SIGUSR2, hit, NULL);
    sigaction(SIGUSR1, hit, NULL);
    usleep(100);
    if (game.shoot == 1) {
        my_printf("%c%d: hit\n", navy->letter_attack + 65, navy->nb_attack + 1);
        navy->enemy_map[navy->nb_attack][navy->letter_attack] = 'x';
    } else {
        my_printf("%c%d: missed\n", navy->letter_attack + 65,
        navy->nb_attack + 1);
        navy->enemy_map[navy->nb_attack][navy->letter_attack] = 'o';
    }
    return navy;
}

int hit_or_not(void)
{
    if (game.hit == 1) {
        usleep(100);
        kill(game.enemy_pid, SIGUSR2);
    } else {
        usleep(100);
        kill(game.enemy_pid, SIGUSR1);
    }
    return SUCCESS_EPITECH;
}
