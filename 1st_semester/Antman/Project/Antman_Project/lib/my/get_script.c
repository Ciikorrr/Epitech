/*
** EPITECH PROJECT, 2023
** get_script
** File description:
** ouais
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int is_valid_file(char *filepath);
char *file_to_buffer(char *filepath, int fd);

char *get_script(char *filepath)
{
    int fd = is_valid_file(filepath);
    if (fd == -1)
        return NULL;
    char *buffer = file_to_buffer(filepath, fd);
    return buffer;
}
