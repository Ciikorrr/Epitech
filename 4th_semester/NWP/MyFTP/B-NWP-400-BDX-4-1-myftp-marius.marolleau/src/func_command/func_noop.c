/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_noop
*/

#include "myftp.h"

int func_noop(myftp_t *myftp, char **tab_cmd, int i)
{
    (void)tab_cmd;
    dprintf(myftp->tab_clt[i]->fd_client, "200 Command okay.\r\n");
    return 0;
}
