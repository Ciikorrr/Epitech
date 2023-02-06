/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <fcntl.h>
#include <unistd.h>
#include "macros_error.h"
#include "protos.h"

int check_file(char *str)
{
    char *buf;
    if (str == NULL)
        return ERROR_EPITECH;
    int fd = open(str, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return ERROR_EPITECH;
    }
    if (read(fd, &buf, 1) <= 0) {
        close(fd);
        return ERROR_EPITECH;
    }
    close(fd);
    return SUCCESS_EPITECH;
}

int check_file_bis(char *str)
{
    if (check_file(str) == ERROR_EPITECH)
        return ERROR_EPITECH;
    char *str2 = file_to_str(str);
    int len = 0;
    int back = 0;
    for (int i = 0; str2[i] != '\0'; i += 1) {
        len += 1;
        if (str2[i] == '\n')
            back += 1;
    }
    if (len > 29 && len < 35 && back >= 3)
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}

int check_pid(char *str)
{
    if (str == NULL)
        return ERROR_EPITECH;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9') {
            return ERROR_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}

int check_args(int argc, char **argv)
{
    if (argc == 2) {
        if (check_file_bis(argv[1]) == ERROR_EPITECH) {
            return ERROR_EPITECH;
        }
    }
    if (argc == 3) {
        if (check_file_bis(argv[2]) == ERROR_EPITECH)
            return ERROR_EPITECH;
        if (check_pid(argv[1]) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    if (argc != 2 && argc != 3)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int do_error_handling(int argc, char **argv)
{
    if (check_args(argc, argv) == ERROR_EPITECH) {
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
