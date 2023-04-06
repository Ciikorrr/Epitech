/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "struct_mnishell.h"
#include "macros.h"
#include "protos.h"
#include "utils.h"

int remake_all_tab(msh_t *minish)
{
    minish->tab_command = remake_tab(minish->tab_command, ">");
    if (minish->tab_command[0] == NULL) {
        write(2, "Invalid null command.\n", 22);
        return ERROR_EPITECH;
    }
    minish->tab_command = remake_tab(minish->tab_command, "<");
    if (minish->tab_command[0] == NULL) {
        write(2, "Invalid null command.\n", 22);
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
