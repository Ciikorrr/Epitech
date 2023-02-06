/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marius.marolleau
** File description:
** check_error
*/
#include "mylist.h"
#include "operations.h"
#include "macros.h"

int my_isdigit_bis(char c)
{
    if (c >= '0' && c <= '9' || c == '-' || c == '+') {
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int loop(char **argv, int i)
{
    for (int j = 0; argv[i][j] != '\0'; j += 1) {
        if (my_isdigit_bis(argv[i][j]) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_isnum(int argc, char **argv)
{
    for (int i = 1; i < argc; i += 1) {
        if (loop(argv, i) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_argc(int argc)
{
    if (argc == 1) {
        write(1, "\n", 1);
        return SUCCESS_EPITECH;
    }
}
