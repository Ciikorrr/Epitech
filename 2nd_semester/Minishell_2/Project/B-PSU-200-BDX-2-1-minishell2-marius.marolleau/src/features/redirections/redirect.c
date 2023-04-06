/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "protos.h"
#include "struct_mnishell.h"
#include "macros.h"
#include "utils.h"

int check_stat(char **tab, int i)
{
    struct stat file;
    if (stat(tab[i + 1], &file) != 0)
        return SUCCESS_EPITECH;
    if ((file.st_mode & __S_IFMT) == __S_IFDIR)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int get_fd(msh_t *minish, int type_redirect, int i)
{
    int fd = 1;
    if (type_redirect == REDIRECT_R2) {
        fd = open(minish->tab_command[i], O_CREAT | O_APPEND | O_RDWR, S_IRWXU);
        if (check_open(fd, minish->tab_command[i], minish) == ERROR_EPITECH)
            return -1;
        return fd;
    }
    if (type_redirect == REDIRECT_R1) {
        fd = open(minish->tab_command[i], O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
        if (check_open(fd, minish->tab_command[i], minish) == ERROR_EPITECH)
            return -1;
        return fd;
    }
    return fd;
}

int get_fd_redirect(msh_t *minish)
{
    if (error_redirection(minish->tab_command, 1) == ERROR_EPITECH) {
        minish->result = 1;
        return ERROR_EPITECH;
    }
    if (get_fd_input(minish) == ERROR_EPITECH)
        return ERROR_EPITECH;
    for (int i = 0; minish->tab_command[i] != NULL; i += 1) {
        if (double_rediction(minish, i) == ERROR_EPITECH)
            return ERROR_EPITECH;
        if (simple_rediction(minish, i) == ERROR_EPITECH)
            return ERROR_EPITECH;
    }
    if (remake_all_tab(minish) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

int search_error(char **tab, int i)
{
    if (my_strcmp(">>", tab[i]) != 0 && my_strcmp(">", tab[i]) != 0 &&
    my_strcmp("<<", tab[i]) != 0 && my_strcmp("<", tab[i]) != 0) {
        write(2, "Missing name for redirect.\n", 27);
        return ERROR_EPITECH;
    }
    if (tab[i] != NULL && tab[i + 1] == NULL) {
        write(2, "Missing name for redirect.\n", 27);
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}

int display_error_redirection(char **tab, int i, int last)
{
    if (search_error(tab, i) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (last == 0) {
        write(2, "Ambiguous output redirect.\n", 27);
        return ERROR_EPITECH;
    }
    if (nb_pipe(tab) == 2) {
        write(2, "Ambiguous output redirect.\n", 27);
        return ERROR_EPITECH;
    }
    if (nb_pipe(tab) == 1) {
        write(2, "Ambiguous input redirect.\n", 27);
        return ERROR_EPITECH;
    }
    return SUCCESS_EPITECH;
}
