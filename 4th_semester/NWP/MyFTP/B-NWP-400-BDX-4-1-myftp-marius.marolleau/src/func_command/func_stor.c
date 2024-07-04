/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_stor
*/

#include "myftp.h"
#include "macros.h"
#include <string.h>
#include <fcntl.h>


bool check_mode(client_tab_t *clt)
{
    if (clt->pasv_mode || clt->actv_mode)
        return true;
    return false;
}

static bool pasv_handler(client_tab_t *clt)
{
    fd_set fdread;
    fd_set fdwrite;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 1000;
    FD_ZERO(&fdwrite);
    FD_ZERO(&fdread);
    FD_SET(clt->pasv_fd, &fdread);
    FD_SET(clt->pasv_fd, &fdwrite);
    if (select(clt->pasv_fd + 1, &fdread, &fdwrite, NULL, &tv) <= 0)
        return false;
    clt->list_fd = accept(clt->pasv_fd, NULL, NULL);
    if (clt->list_fd == -1)
        return false;
    dprintf(clt->fd_client,
    "150 File status okay; about to open data connection.\r\n");
    return true;
}

bool check_list_fd(client_tab_t *clt)
{
    if (clt->pasv_mode) {
        if (pasv_handler(clt) == false)
            return false;
    } else {
        clt->pasv_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (clt->pasv_fd == -1)
            return ERROR;
        connect(clt->pasv_fd,
        (const struct sockaddr*)&clt->data_stct, sizeof(struct sockaddr_in));
        clt->list_fd = dup(clt->pasv_fd);
        dprintf(clt->fd_client,
        "150 File status okay; about to open data connection.\r\n");
    }
    return true;
}

static int write_data(client_tab_t *clt, int f)
{
    size_t read_byte = 1;
    char buffer[BUFSIZ];

    while (read_byte > 0) {
        read_byte = read(clt->list_fd, buffer, BUFSIZ);
        buffer[read_byte] = '\0';
        dprintf(f, "%s", buffer);
    }
    dprintf(clt->fd_client, "226 Closing data connection.\r\n");
    close(f);
    close(clt->list_fd);
    close(clt->pasv_fd);
    clt->pasv_mode = false;
    clt->actv_mode = false;
    return SUCCESS;
}

static int do_stor(client_tab_t *clt, char *cmd)
{
    int f = 0;

    f = open(cmd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (f < 0) {
        close(f);
        dprintf(clt->fd_client, "550 Requested action not taken.\r\n");
        return SUCCESS;
    }
    return write_data(clt, f);
}

int func_stor(myftp_t *myftp, char **tab_cmd, int i)
{
    tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (tab_cmd[2]) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "501 Syntax error in parameters or arguments.\r\n");
        return SUCCESS;
    }
    if (!check_mode(myftp->tab_clt[i]) || !check_list_fd(myftp->tab_clt[i])) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "425 Can't open data connection.\r\n");
        return SUCCESS;
    }
    return do_stor(myftp->tab_clt[i], tab_cmd[1]);
}
