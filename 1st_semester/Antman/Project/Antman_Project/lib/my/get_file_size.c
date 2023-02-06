/*
** EPITECH PROJECT, 2023
** get_file_size
** File description:
** the name is explicit
*/

#include <fcntl.h>
#include <unistd.h>

int get_file_size(char *filepath)
{
    int fd = open(filepath, 0);
    if (fd == -1)
        return -1;

    int len = 0;
    while (read(fd, filepath, 1) > 0)
        len += 1;
    return len;
}
