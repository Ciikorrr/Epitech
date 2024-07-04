/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** new_client
*/
#include "../include/macros.h"
#include "../include/myftp.h"
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

static int add_new_client(struct sockaddr_in *to_add, myftp_t *myftp)
{
    myftp->tab_clt = reallocarray(myftp->tab_clt, myftp->nb_client + 2,
    sizeof(client_tab_t));
    if (!myftp->tab_clt)
        return ERROR;
    myftp->tab_clt[myftp->nb_client] = malloc(sizeof(client_tab_t));
    myftp->tab_clt[myftp->nb_client]->client = *to_add;
    myftp->tab_clt[myftp->nb_client]->fd_client = myftp->fd_clt;
    myftp->tab_clt[myftp->nb_client]->path = strdup(get_path(myftp->path));
    myftp->tab_clt[myftp->nb_client]->pasv_mode = false;
    myftp->tab_clt[myftp->nb_client]->actv_mode = false;
    myftp->tab_clt[myftp->nb_client]->pass = false;
    myftp->tab_clt[myftp->nb_client]->user = false;
    myftp->tab_clt[myftp->nb_client]->pasv_mode = false;
    memset(myftp->tab_clt[myftp->nb_client]->user_buf, '\0', BUFSIZ);
    myftp->tab_clt[myftp->nb_client + 1] = NULL;
    myftp->nb_client += 1;
    FD_SET(myftp->fd_clt, &myftp->tab_fd);
    dprintf(myftp->fd_clt, "220 Connection accepted !\r\n");
    return SUCCESS;
}

int test_new_client(myftp_t *myftp)
{
    socklen_t client_size = sizeof(struct sockaddr_in);
    struct sockaddr_in new_client;
    fd_set fdread;
    fd_set fdwrite;

    FD_ZERO(&fdwrite);
    FD_ZERO(&fdread);
    if (!myftp)
        return ERROR;
    FD_SET(myftp->server_fd, &fdread);
    FD_SET(myftp->server_fd, &fdwrite);
    if (select(myftp->server_fd + 1, &fdread, &fdwrite, NULL, &myftp->tv) <= 0)
        return SUCCESS;
    myftp->fd_clt = accept(myftp->server_fd, (struct sockaddr*)&new_client,
    &client_size);
    if (myftp->fd_clt == -1)
        return SUCCESS;
    if (add_new_client(&new_client, myftp) == ERROR)
        return ERROR;
    return SUCCESS;
}
