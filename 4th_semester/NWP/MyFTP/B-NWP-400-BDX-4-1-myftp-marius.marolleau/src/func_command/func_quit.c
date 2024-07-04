/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_quit
*/

#include "myftp.h"
#include "macros.h"
#include <string.h>

static void fill_struct(client_tab_t *tmp, client_tab_t *src)
{
    tmp->client = src->client;
    tmp->fd_client = src->fd_client;
    tmp->list_fd = src->list_fd;
    tmp->pass = src->pass;
    tmp->pasv_fd = src->pasv_fd;
    tmp->pasv_mode = src->pasv_mode;
    tmp->actv_mode = src->actv_mode;
    tmp->user = src->user;
    tmp->path = strdup(src->path);
    return;
}

static int client_quit(myftp_t *myftp, client_tab_t **tmp, int idx)
{
    int index = 0;

    for (int i = 0; myftp->tab_clt[i] != NULL; i++) {
        if (i == idx) {
            free(myftp->tab_clt[i]->path);
            close(myftp->tab_clt[i]->fd_client);
            free(myftp->tab_clt[i]);
            continue;
        }
        tmp[index] = malloc(sizeof(client_tab_t));
        if (!tmp[index])
            return ERROR;
        fill_struct(tmp[index], myftp->tab_clt[i]);
        free(myftp->tab_clt[i]);
        index++;
    }
    myftp->nb_client--;
    return SUCCESS;
}

int func_quit(myftp_t *myftp, char **tab_cmd, int i)
{
    client_tab_t **tmp = malloc(sizeof(client_tab_t *) * myftp->nb_client);

    if (tab_cmd[1]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "500 Syntax error, command unrecognized.\r\n");
        free(tmp);
        return SUCCESS;
    }
    tmp[myftp->nb_client - 1] = NULL;
    dprintf(myftp->tab_clt[i]->fd_client,
    "221 Service closing control connection.\r\n");
    if (client_quit(myftp, tmp, i) == ERROR)
        return ERROR;
    myftp->tab_clt = tmp;
    return 0;
}
