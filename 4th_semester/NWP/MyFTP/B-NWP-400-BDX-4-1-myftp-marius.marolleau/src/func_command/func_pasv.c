/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_pasv
*/

#include "myftp.h"
#include "macros.h"
#include <netinet/in.h>

static int pasv_mod(myftp_t *myftp, int idx_clt, struct sockaddr_in *data_clt)
{
    int ip[4];
    int l_port = data_clt->sin_port % 256;
    int h_port = data_clt->sin_port / 256;

    myftp->tab_clt[idx_clt]->pasv_mode = true;
    ip[3] = (data_clt->sin_addr.s_addr >> 24) & 0xFF;
    ip[2] = (data_clt->sin_addr.s_addr >> 16) & 0xFF;
    ip[1] = (data_clt->sin_addr.s_addr >> 8) & 0xFF;
    ip[0] = (data_clt->sin_addr.s_addr) & 0xFF;
    dprintf(myftp->tab_clt[idx_clt]->fd_client,
    "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\r\n", ip[0], ip[1],
    ip[2], ip[3], l_port, h_port);
    return SUCCESS;
}

static int init_data(myftp_t *myftp, int i, struct sockaddr_in *data_clt)
{
    socklen_t addrlen = sizeof(struct sockaddr_in);

    myftp->tab_clt[i]->pasv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (myftp->tab_clt[i]->pasv_fd == -1)
        return ERROR;
    data_clt->sin_family = AF_INET;
    data_clt->sin_port = ntohs(0);
    data_clt->sin_addr.s_addr = inet_addr
    (inet_ntoa(myftp->tab_clt[i]->client.sin_addr));
    bind(myftp->tab_clt[i]->pasv_fd, (struct sockaddr *)data_clt,
    sizeof(struct sockaddr_in));
    listen(myftp->tab_clt[i]->pasv_fd, 1);
    getsockname(myftp->tab_clt[i]->pasv_fd, (struct sockaddr *)data_clt,
    &addrlen);
    return SUCCESS;
}

int func_pasv(myftp_t *myftp, char **tab_cmd, int i)
{
    struct sockaddr_in data_clt;

    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (tab_cmd[1]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    if (init_data(myftp, i, &data_clt) == ERROR)
        return ERROR;
    if (pasv_mod(myftp, i, &data_clt) == ERROR)
        return ERROR;
    return 0;
}
