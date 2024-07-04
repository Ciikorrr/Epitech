/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** func_list
*/

#include "myftp.h"
#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "macros.h"
#include <string.h>

static int do_list(myftp_t *myftp, char **tab_cmd, int i)
{
    char *line = NULL;
    int temp = 0;

    if (!tab_cmd[1])
        line = my_strcat_dup("ls -l", " ", myftp->tab_clt[i]->path);
    else {
        tab_cmd[1][strlen(tab_cmd[1]) - 1] = '\0';
        line = my_strcat_dup("ls -l", " ",
        my_strcat_dup(myftp->tab_clt[i]->path, "/", tab_cmd[1]));
    }
    temp = dup(STDOUT_FILENO);
    dup2(myftp->tab_clt[i]->list_fd, STDOUT_FILENO);
    system(line);
    dup2(temp, STDOUT_FILENO);
    free(line);
    close(myftp->tab_clt[i]->list_fd);
    close(temp);
    myftp->tab_clt[i]->pasv_mode = false;
    myftp->tab_clt[i]->actv_mode = false;
    return SUCCESS;
}

int func_list(myftp_t *myftp, char **tab_cmd, int i)
{
    if (!myftp->tab_clt[i]->pass) {
        dprintf(myftp->tab_clt[i]->fd_client, "530 Not logged in.\r\n");
        return SUCCESS;
    }
    if (!check_mode(myftp->tab_clt[i])) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "425 Can't open data connection.\r\n");
        return SUCCESS;
    }
    if (!check_list_fd(myftp->tab_clt[i])) {
        dprintf(myftp->tab_clt[i]->fd_client,
        "226 Closing data connection.\r\n");
        return SUCCESS;
    }
    if (do_list(myftp, tab_cmd, i) == ERROR)
        return ERROR;
    close(myftp->tab_clt[i]->pasv_fd);
    dprintf(myftp->tab_clt[i]->fd_client, "226 Closing data connection.\r\n");
    return SUCCESS;
}
