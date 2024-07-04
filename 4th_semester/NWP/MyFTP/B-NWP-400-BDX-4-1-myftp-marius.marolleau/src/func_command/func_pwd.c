/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_pwd
*/

#include "myftp.h"
#include "macros.h"

int func_pwd(myftp_t *myftp, char **tab_cmd, int i)
{
    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (tab_cmd[1] != NULL) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    dprintf(myftp->tab_clt[i]->fd_client, "257 %s\r\n",
    myftp->tab_clt[i]->path);
    return SUCCESS;
}
