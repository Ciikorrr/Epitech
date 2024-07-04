/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_dele
*/
#include "myftp.h"
#include <stdio.h>
#include "macros.h"
#include <string.h>
#include <fcntl.h>

static int do_dele(client_tab_t *clt, char *path)
{
    if (!clt)
        return ERROR;
    if (remove(path) == -1) {
        dprintf(clt->fd_client, "550 Requested action not taken.\r\n");
        return SUCCESS;
    }
    dprintf(clt->fd_client, "250 Requested file action okay, completed.\r\n");
    return SUCCESS;
}

static char *check_absolut(client_tab_t *clt, char **tab_cmd)
{
    char *path = NULL;

    if (tab_cmd[1][0] == '/')
        path = tab_cmd[1];
    else
        path = realpath(my_strcat_dup(clt->path,
        "/", tab_cmd[1]), NULL);
    return path;
}

int func_dele(myftp_t *myftp, char **tab_cmd, int i)
{
    char *path = NULL;

    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (tab_cmd[2]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
    path = check_absolut(myftp->tab_clt[i], tab_cmd);
    if (!path) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "550 Requested action not taken.\r\n");
        return SUCCESS;
    }
    return do_dele(myftp->tab_clt[i], path) == ERROR;
}
