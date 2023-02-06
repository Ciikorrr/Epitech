/*
** EPITECH PROJECT, 2023
** file_to_buffer
** File description:
** ouais
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

char *file_to_buffer(char *filepath, int fd)
{
    struct stat st;
    stat(filepath, &st);
    char *buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';
    read(fd, buffer, (st.st_size));
    return buffer;
}
