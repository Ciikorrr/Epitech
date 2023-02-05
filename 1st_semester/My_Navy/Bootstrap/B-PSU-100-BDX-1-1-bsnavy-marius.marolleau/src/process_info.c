/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>

int main(void)
{
    int pid = getpid();
    int ppid = getppid();
    int pgid = getpgrp();
    printf("PID = %d\n", pid);
    printf("PPID = %d\n", ppid);
    printf("PGID = %d\n", pgid);
    return 0;
}
