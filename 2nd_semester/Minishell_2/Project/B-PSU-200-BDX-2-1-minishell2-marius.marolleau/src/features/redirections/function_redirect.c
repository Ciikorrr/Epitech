/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "macros.h"
#include "utils.h"
#include <errno.h>
#include "protos.h"

int compare(char **tab, int i, int last)
{
    if (my_strncmp(">", tab[i], 1) == 0) {
        if (display_error_redirection(tab, i, last) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    if (my_strncmp("<", tab[i], 1) == 0) {
        if (display_error_redirection(tab, i, -1) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int error_redirection(char **tab, int last)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        if (compare(tab, i, last) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int check_open(int fd, char *command, msh_t *minish)
{
    if (fd == -1) {
        if (errno == 2) {
            write(2, command, my_strlen(command));
            write(2, ": No such file or directory.\n", 29);
        }
        if (errno == 13) {
            write(2, command, my_strlen(command));
            write(2, ": Permission denied.\n", 21);
        }
        if (errno == 21) {
            write(2, command, my_strlen(command));
            write(2, ": Is a directory.\n", 19);
        }
        minish->result = 1;
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int double_rediction(msh_t *minish, int i)
{
    if (my_strcmp(">>", minish->tab_command[i]) == 0) {
        if ((minish->fd_output = get_fd(minish, REDIRECT_R2, i + 1)) == -1)
            return ERROR_EPITECH;
        return SUCCESS_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int simple_rediction(msh_t *minish, int i)
{
    if (my_strcmp(">", minish->tab_command[i]) == 0){
        if ((minish->fd_output = get_fd(minish, REDIRECT_R1, i + 1)) == -1)
            return ERROR_EPITECH;
        return SUCCESS_EPITECH;
    }
    return SUCCESS_EPITECH;
}
