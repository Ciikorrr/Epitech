/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_port
*/

#include "myftp.h"
#include "macros.h"
#include <string.h>

static int init_data(myftp_t *myftp, int i, char **tab)
{
    struct sockaddr_in data_clt;
    char *ip_addr = my_strcat_dup(my_strcat_dup(my_strcat_dup
    (tab[0], ".", tab[1]), ".", tab[2]), ".", tab[3]);

    data_clt.sin_family = AF_INET;
    data_clt.sin_port = htons((atoi(tab[4]) * 256 + atoi(tab[5])));
    inet_pton(AF_INET, ip_addr, &data_clt.sin_addr);
    myftp->tab_clt[i]->data_stct = data_clt;
    return SUCCESS;
}

int func_port(myftp_t *myftp, char **tab_cmd, int i)
{
    char **tab = NULL;

    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    } else {
        tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
        tab = my_str_to_word_array_separator(tab_cmd[1], ",");
        if (!tab || !tab[0] || !tab[1] || !tab[2] || !tab[3])
            return ERROR;
        if (init_data(myftp, i, tab) == ERROR)
            return ERROR;
        myftp->tab_clt[i]->actv_mode = true;
    }
    dprintf(myftp->tab_clt[i]->fd_client, "200 Command okay.\r\n");
    return SUCCESS;
}
