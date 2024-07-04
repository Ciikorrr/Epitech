/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_pass
*/
#include "myftp.h"
#include "macros.h"
#include <string.h>

int func_pass(myftp_t *myftp, char **tab_cmd, int i)
{
    if (myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "230 User logged in, proceed.\r\n");
        return SUCCESS;
    }
    if (myftp->tab_clt[i]->user == true && (!tab_cmd[1] ||
    strcmp(tab_cmd[1], "\r") == 0)) {
        myftp->tab_clt[i]->pass = true;
        dprintf(myftp->tab_clt[i]->fd_client,
        "230 User logged in, proceed.\r\n");
    } else {
        if (strcmp(tab_cmd[1], "\r\n") == 0) {
            dprintf(myftp->tab_clt[i]->fd_client,
            "332 Need account for login.\r\n");
        } else {
            dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        }
    }
    free_tab(tab_cmd);
    return SUCCESS;
}
