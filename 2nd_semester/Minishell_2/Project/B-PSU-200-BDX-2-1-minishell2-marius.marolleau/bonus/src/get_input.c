/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "opt_builtin.h"
#include "protos.h"
#include "macros.h"

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;
    int check = 0;
    while (check == 0) {
        if (getline(&line, &len, stdin) == -1) {
            my_putstr("exit");
            free(line);
            return NULL;
        }
        check = 1;
    }
    return line;
}
