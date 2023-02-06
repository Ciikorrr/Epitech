/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *file_to_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return NULL;
    struct stat file;
    stat(filepath, &file);
    char *str = malloc(sizeof(char) * (file.st_size + 1));
    if (str == NULL)
        return NULL;
    str[file.st_size] = '\0';
    int test = read(fd, str, file.st_size);
    if (test < 0)
        return NULL;
    return str;
}
