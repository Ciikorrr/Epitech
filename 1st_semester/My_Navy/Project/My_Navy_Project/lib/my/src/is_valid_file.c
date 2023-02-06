/*
** EPITECH PROJECT, 2022
** is valid file
** File description:
** ouais
*/

#include <fcntl.h>
#include <sys/stat.h>

int is_valid_file(char *filepath)
{
    int fd = open(filepath, 0);
    if (fd == -1)
        return -1;
    return fd;
}
