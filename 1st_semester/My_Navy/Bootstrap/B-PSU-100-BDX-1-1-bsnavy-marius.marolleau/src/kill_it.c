/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <signal.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    __pid_t pid = argv[1];
    kill(pid, SIGSEGV);
}
