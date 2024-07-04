/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** select_client
*/
#include "macros.h"
#include "myftp.h"
#include "tab_func.h"
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

int remove_first_client(myftp_t *myftp)
{
    free(myftp->tab_clt[0]->path);
    close(myftp->tab_clt[0]->fd_client);
    free(myftp->tab_clt[0]);
    free(myftp->tab_clt);
    close(myftp->fd_clt);
    myftp->nb_client--;
    myftp->tab_clt = NULL;
    return SUCCESS;
}

static int remove_client(myftp_t *myftp, client_tab_t **tmp, int fd_to_remove)
{
    int index = 0;

    for (int i = 0; myftp->tab_clt[i] != NULL; i++) {
        if (myftp->tab_clt[i]->fd_client == fd_to_remove) {
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

int remove_a_client(myftp_t *myftp, int fd_to_remove)
{
    client_tab_t **tmp = NULL;

    if (myftp->nb_client == 0)
        return SUCCESS;
    if (myftp->nb_client == 1)
        return remove_first_client(myftp);
    tmp = malloc(sizeof(client_tab_t) * myftp->nb_client);
    if (!tmp)
        return ERROR;
    tmp[myftp->nb_client - 1] = NULL;
    if (remove_client(myftp, tmp, fd_to_remove) == ERROR)
        return ERROR;
    myftp->tab_clt = tmp;
    return SUCCESS;
}

static int handle_command(myftp_t *myftp, char *buffer, int index_clt)
{
    char **tab = my_str_to_word_array_separator(buffer, " \t");

    if (!tab)
        return ERROR;
    for (int i = 0; i < TAB_SIZE; i++) {
        if (my_strcmp(tab[0], tab_func[i].command) == 0)
            return tab_func[i].function(myftp, tab, index_clt);
    }
    free(tab);
    dprintf(myftp->tab_clt[index_clt]->fd_client,
    "500 Syntax error, command unrecognized.\r\n");
    return SUCCESS;
}

static void reset(myftp_t *myftp)
{
    myftp->tv.tv_usec = 1000;
    myftp->tv.tv_sec = 0;
    return;
}

static char *buf_management(client_tab_t *clt, char *command)
{
    int i = 0;
    int j = 0;

    while (clt->user_buf[i] && i < BUFSIZ - 1 &&
    !(clt->user_buf[i] == '\n'))
        i += 1;
    if (clt->user_buf[i] == '\0' || i >= BUFSIZ - 1)
        return NULL;
    strncpy(command, clt->user_buf, i);
    i += 1;
    for (; i < BUFSIZ - 1 && clt->user_buf[i]; j++) {
        clt->user_buf[j] = clt->user_buf[i];
        i++;
    }
    for (; j < BUFSIZ - 1; j++)
        clt->user_buf[j] = '\0';
    return command;
}

static int loop(myftp_t *myftp, int i)
{
    int read_byte = 0;
    char command[BUFSIZ] = {0};
    char buffer[BUFSIZ] = {0};

    read_byte = read(myftp->tab_clt[i]->fd_client, buffer, BUFSIZ);
    if (read_byte > 0)
        buffer[read_byte] = '\0';
    strcat(myftp->tab_clt[i]->user_buf, buffer);
    if (!buf_management(myftp->tab_clt[i], command))
        return SUCCESS;
    if (read_byte <= 0 || handle_command(myftp, command, i) == ERROR)
        return remove_a_client(myftp, myftp->tab_clt[i]->fd_client);
    return SUCCESS;
}

int select_client(myftp_t *myftp)
{
    fd_set fdread;

    FD_ZERO(&fdread);
    if (!myftp->tab_clt)
        return SUCCESS;
    for (int i = 0; myftp->tab_clt[i] != NULL; i++) {
        reset(myftp);
        FD_SET(myftp->tab_clt[i]->fd_client, &fdread);
        if (select(myftp->tab_clt[i]->fd_client + 1,
        &fdread, NULL, NULL, &myftp->tv) <= 0)
            continue;
        if (loop(myftp, i) == ERROR)
            return ERROR;
        FD_ZERO(&fdread);
        break;
    }
    return SUCCESS;
}
