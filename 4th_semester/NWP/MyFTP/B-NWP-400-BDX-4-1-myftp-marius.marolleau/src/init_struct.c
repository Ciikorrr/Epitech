/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** init_struct
*/
#include "../include/macros.h"
#include "../include/myftp.h"
#include <netinet/in.h>

int init_server_struct(char const *argv[], myftp_t *myftp)
{
    if (!argv || !argv[1] || !argv[2] || !myftp)
        return ERROR;
    myftp->path = argv[2];
    myftp->port_use = atoi(argv[1]);
    myftp->server_struct.sin_family = AF_INET;
    myftp->server_struct.sin_port = htons(myftp->port_use);
    myftp->server_struct.sin_addr.s_addr = htonl(INADDR_ANY);
    FD_ZERO(&myftp->tab_fd);
    myftp->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (myftp->server_fd == -1)
        return ERROR;
    myftp->tv.tv_sec = 0;
    myftp->tv.tv_sec = 1000;
    return SUCCESS;
}

int init_server(myftp_t *myftp)
{
    int var_bind = 0;
    int lst = 0;

    if (!myftp)
        return ERROR;
    var_bind = bind(myftp->server_fd,
    (struct sockaddr *)&myftp->server_struct,
    sizeof(struct sockaddr_in));
    if (var_bind == -1)
        return ERROR;
    lst = listen(myftp->server_fd, 10);
    if (lst == -1)
        return ERROR;
    return SUCCESS;
}
