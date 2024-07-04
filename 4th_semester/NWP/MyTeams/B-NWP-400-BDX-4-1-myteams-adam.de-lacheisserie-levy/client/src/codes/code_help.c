/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code_help
*/

#include "../../include/macros.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int code_help(char **cmd)
{
    char buffer[1024];
    int fd = 0;
    int read_byte = 0;

    (void)cmd;
    fd = open("ressources/help.txt", O_RDONLY);
    read_byte = read(fd, buffer, 1024);
    write(1, buffer, read_byte);
    write(1, "\n", 1);
    return SUCCESS;
}
