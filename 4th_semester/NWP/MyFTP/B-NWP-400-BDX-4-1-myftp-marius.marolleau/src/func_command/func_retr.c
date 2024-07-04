/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_retr
*/

#include "myftp.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static int send_file_content(client_tab_t *clt, char *filepath)
{
    char buffer[BUFSIZ];
    int f = 0;
    size_t read_byte = 1;

    f = open(filepath, O_RDONLY, 0644);
    while (read_byte > 0) {
        read_byte = read(f, buffer, BUFSIZ);
        buffer[read_byte] = '\0';
        dprintf(clt->list_fd, "%s", buffer);
    }
    close(f);
    close(clt->list_fd);
    close(clt->pasv_fd);
    clt->pasv_mode = false;
    clt->actv_mode = false;
    dprintf(clt->fd_client, "226 Closing data connection.\r\n");
    return SUCCESS;
}

int check_file_exist(char *filepath, client_tab_t *clt)
{
    FILE *f = NULL;

    f = fopen(filepath, "r");
    if (f == NULL) {
        dprintf(clt->fd_client, "550 Requested action not taken.\r\n");
        return ERROR;
    }
    fclose(f);
    return SUCCESS;
}

int func_retr(myftp_t *myftp, char **tab_cmd, int i)
{
    if (!myftp || !tab_cmd || !tab_cmd[0] || !tab_cmd[1])
        return ERROR;
    tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (check_file_exist(tab_cmd[1], myftp->tab_clt[i]) == ERROR) {
        return SUCCESS;
    }
    if (!check_mode(myftp->tab_clt[i]) || !check_list_fd(myftp->tab_clt[i])) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "425 Can't open data connection.\r\n");
        return SUCCESS;
    }
    if (send_file_content(myftp->tab_clt[i], tab_cmd[1]) == ERROR)
        return ERROR;
    return SUCCESS;
}
