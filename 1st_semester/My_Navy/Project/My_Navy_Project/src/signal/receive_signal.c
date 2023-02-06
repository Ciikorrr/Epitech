/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "info_class.h"

extern info_t game;

void signal_hanlder(int num, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    if (num == 10) {
        game.buffer[game.idx] = '0';
        game.idx += 1;
    }

    if (num == 12) {
        game.buffer[game.idx] = '1';
        game.idx += 1;
    }
}

char *receive_signal(void)
{
    game.idx = 0;
    game.buffer = malloc(sizeof(char) * 7);
    game.buffer[6] = '\0';
    for (int i = 0; i < 6; i += 1)
        game.buffer[i] = '.';
    struct sigaction sa;
    sa.sa_sigaction = signal_hanlder;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (game.idx < 6) {
        usleep(100);
    }
    return game.buffer;
}
