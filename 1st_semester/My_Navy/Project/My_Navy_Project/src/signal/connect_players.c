/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "macros_error.h"
#include "protos.h"
#include "info_class.h"
extern info_t game;

static void connect_one(int signo, siginfo_t *info, void *context)
{
    (void)signo;
    (void)info;
    (void)context;
    game.enemy_pid = info->si_pid;
    my_printf("enemy connected\n\n");
    game.launch = 1;
}

int connect_player_one(void)
{
    int pid = getpid();
    my_printf("my_pid: %d\n", pid);
    my_printf("waiting for enemy connection...\n\n");
    game.launch = 0;
    struct sigaction *act = malloc(sizeof(struct sigaction *));
    act->sa_flags = SA_SIGINFO;
    act->sa_sigaction = &connect_one;
    sigaction(SIGUSR1, act, NULL);
    while (game.launch == 0) {
    }
    return SUCCESS_EPITECH;
}

int connect_player_two(char *pid)
{
    int my_pid = getpid();
    int nb = my_getnbr(pid);
    game.enemy_pid = nb;
    if (kill(nb, SIGUSR1) == 0) {
        my_printf("my_pid: %d\nsuccessfully connected\n\n", my_pid);
        return SUCCESS_EPITECH;
    } else {
        my_printf("wrong pid\n");
        return ERROR_EPITECH;
    }
}
