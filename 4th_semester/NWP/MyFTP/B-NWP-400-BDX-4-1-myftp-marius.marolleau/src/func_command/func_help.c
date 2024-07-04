/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_help
*/
#include "myftp.h"
#include "tab_func.h"
#include "macros.h"
#include <string.h>

static void help_simple(myftp_t *myftp, int idx)
{
    for (int i = 0; i < TAB_SIZE; i++)
        dprintf(myftp->tab_clt[idx]->fd_client, "%s\t:\t%s\r\n",
        tab_func[i].command, tab_func[i].help);
    dprintf(myftp->tab_clt[idx]->fd_client, "214 Help message.\r\n");
    return;
}

int func_help(myftp_t *myftp, char **tab_cmd, int idx)
{
    if (tab_cmd[2]) {
        dprintf(myftp->tab_clt[idx]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    if (!tab_cmd[1]) {
        help_simple(myftp, idx);
        return SUCCESS;
    }
    tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
    for (int i = 0; i < TAB_SIZE; i++) {
        if (strcmp(tab_cmd[1], tab_func[i].command) == 0) {
            dprintf(myftp->tab_clt[idx]->fd_client, "%s\t:\t%s\r\n",
            tab_func[i].command, tab_func[i].help);
            return SUCCESS;
        }
    }
    dprintf(myftp->tab_clt[idx]->fd_client, "214 Help message.\r\n");
    return SUCCESS;
}
