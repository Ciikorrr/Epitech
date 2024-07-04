/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_user
*/
#include "myftp.h"
#include "macros.h"
#include <string.h>

int func_user(myftp_t *myftp, char **tab_cmd, int i)
{
    if (myftp->tab_clt[i]->user) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "230 User logged in, proceed.\r\n");
        return SUCCESS;
    }
    if (tab_cmd[2]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    if (my_strcmp(tab_cmd[1], "Anonymous\r\n") == 0) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "331 User name okay, need password.\r\n");
        myftp->tab_clt[i]->user = true;
        free_tab(tab_cmd);
    } else {
        free_tab(tab_cmd);
        dprintf(myftp->tab_clt[i]->fd_client, "331 Need password.\n\r");
    }
    return SUCCESS;
}
