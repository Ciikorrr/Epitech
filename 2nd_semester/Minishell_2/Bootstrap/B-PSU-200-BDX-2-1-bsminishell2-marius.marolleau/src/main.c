/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "unistd.h"
#include "struct.h"
char **my_str_to_word_array_separator(char *str, char *separator);

void parser(int argc, char **argv, all_args *all_info)
{
    all_info->all_command = malloc(sizeof(command *) * (argc - 1));
    for (int i = 1; i < argc; i += 1) {
        all_info->all_command[i - 1].tab_command =
        my_str_to_word_array_separator(argv[i], " ");
    }
    return;
}

int pipe_function(int fd, char **tab, char **env)
{
    int pipe_fd[2];
    int pid = 0;
    if (pipe(pipe_fd) == -1)
        return ERROR_EPITECH;
    dup2(pipe_fd[1], STDOUT_FILENO);
    dup2(fd, STDIN_FILENO);
    pid = fork();
    if (pid == -1)
        return ERROR_EPITECH;
    if (pid == 0) {
        close(pipe_fd[0]);
        execve(tab[0], tab, env);
        exit(0);
    } else {
        close(pipe_fd[1]);
        return pipe_fd[0];
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc < 2)
        return ERROR_EPITECH;
    all_args all_info = {NULL, NULL};
    int fd = 0;
    char buffer;
    all_info.env = env;
    parser(argc, argv, &all_info);
    for (int i = 0; i < (argc - 1); i += 1) {
        fd = pipe_function(fd, all_info.all_command[i].tab_command, env );
    }
    while ((read(fd, &buffer, 1)) > 0) {
        write(1, &buffer, 1);
    }
    return 0;
}
