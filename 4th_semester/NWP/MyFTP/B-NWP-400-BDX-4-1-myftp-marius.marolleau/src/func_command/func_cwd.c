/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_cwd
*/

#include "myftp.h"
#include "macros.h"
#include <string.h>

static int do_cwd(myftp_t *myftp, char **tab_cmd, int i)
{
    char *path = NULL;

    if (tab_cmd[1])
        tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
    else
        return ERROR;
    if (tab_cmd[1][0] == '/')
        path = tab_cmd[1];
    else
        path = realpath(my_strcat_dup(myftp->tab_clt[i]->path,
        "/", tab_cmd[1]), NULL);
    if (!path)
        return ERROR;
    if (access(path, F_OK) == -1)
        return ERROR;
    free(myftp->tab_clt[i]->path);
    myftp->tab_clt[i]->path = path;
    dprintf(myftp->tab_clt[i]->fd_client,
    "250 Requested file action okay, completed.\r\n");
    return SUCCESS;
}

int func_cwd(myftp_t *myftp, char **tab_cmd, int i)
{
    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (do_cwd(myftp, tab_cmd, i) == ERROR) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "550 Requested action not taken.\r\n");
        return SUCCESS;
    }
    return 0;
}
