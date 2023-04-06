/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <fcntl.h>
#include "struct_mnishell.h"
#include "macros.h"
#include "protos.h"
#include "utils.h"

static int fd_input(msh_t *minish, int type_redirect, int i)
{
    int fd = 0;
    if (type_redirect == REDIRECT_L2) {
        fd = double_redirection_left(minish, minish->tab_command[i]);
        if (check_open(fd, minish->tab_command[i], minish) == ERROR_EPITECH)
            return -1;
        return fd;
    }
    if (type_redirect == REDIRECT_L1) {
        fd = open(minish->tab_command[i], O_RDWR);
        if (check_open(fd, minish->tab_command[i], minish) == ERROR_EPITECH)
            return -1;
        return fd;
    }
    return fd;
}

static int compare_fd(msh_t *minish, int i)
{
    if (my_strcmp("<", minish->tab_command[i]) == 0) {
        if ((minish->fd_input = fd_input(minish, REDIRECT_L1, i + 1)) == -1)
            return ERROR_EPITECH;
        return SUCCESS_EPITECH;
    }
    if (my_strcmp("<<", minish->tab_command[i]) == 0) {
        if ((minish->fd_input = fd_input(minish, REDIRECT_L2, i + 1)) == -1)
            return ERROR_EPITECH;
        return SUCCESS_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int get_fd_input(msh_t *minish)
{
    for (int i = 0; minish->tab_command[i] != NULL; i += 1) {
        if (compare_fd(minish, i) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int nb_pipe(char **tab)
{
    int nb_out = 0;
    int nb_in = 0;
    for (int i = 0; tab[i] != NULL;  i += 1) {
        if (my_strncmp(">", tab[i], 1) == 0)
            nb_out += 1;
        if (my_strncmp("<", tab[i], 1) == 0)
            nb_in += 1;
    }
    if (nb_in > 1)
        return 1;
    if (nb_out > 1)
        return 2;
    return SUCCESS_EPITECH;
}
