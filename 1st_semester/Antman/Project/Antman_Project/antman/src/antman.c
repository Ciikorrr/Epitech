/*
** EPITECH PROJECT, 2023
** antman
** File description:
** Program that compress files
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/antman_struct.h"
#include "../include/protos_compress.h"

int error_handling(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

void display_desc(void)
{
    char const *str = file_to_str("src/description.txt");
    int len = my_strlen(str);
    write(1, str, len);
}

int display_h(int argc, char **argv)
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        display_desc();
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int do_antman(int argc, char **argv)
{
    if (display_h(argc, argv) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    if (compress_file(argc, argv) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}
