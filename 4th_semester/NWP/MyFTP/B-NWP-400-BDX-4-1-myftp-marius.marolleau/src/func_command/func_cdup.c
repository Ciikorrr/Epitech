/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_cdup
*/

#include "../../include/myftp.h"
#include "macros.h"

int func_cdup(myftp_t *myftp, char **tab_cmd, int i)
{
    char *path = realpath(my_strcat_dup(myftp->tab_clt[i]->path,
    "/", ".."), NULL);

    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        free(path);
        return SUCCESS;
    }
    if (tab_cmd[1]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        free(path);
        return SUCCESS;
    }
    free(myftp->tab_clt[i]->path);
    myftp->tab_clt[i]->path = path;
    dprintf(myftp->tab_clt[i]->fd_client, "200 Command okay.\r\n");
    return 0;
}
