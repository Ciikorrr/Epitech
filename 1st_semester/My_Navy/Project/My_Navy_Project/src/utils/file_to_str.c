/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *file_to_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }
    char *str = malloc(sizeof(char) * (1000));
    str[999] = '\0';
    read(fd, str, 1000);
    return str;
}
