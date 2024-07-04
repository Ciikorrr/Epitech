/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_syst
*/
#include "myftp.h"
#include "macros.h"

int func_syst(myftp_t *myftp, char **tab_cmd, int i)
{
    if (tab_cmd[1]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    dprintf(myftp->tab_clt[i]->fd_client, "215 UNIX\r\n");
    return 0;
}
