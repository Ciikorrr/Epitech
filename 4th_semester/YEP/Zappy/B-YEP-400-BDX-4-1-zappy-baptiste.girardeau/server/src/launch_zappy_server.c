/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** launch_zappy_server
*/

#include "server.h"
#include "utils.h"

bool loop;

static void execute_tasks(zappy_t *zappy, client_t *client)
{
    tasks_t *tmp;
    tasks_t *prev;
    time_t actual_time = time(NULL);

    if (!client->player)
        return;
    tmp = client->player->tasks;
    while (tmp) {
        if (tmp->time > actual_time)
            return;
        client->player->res_t_g = tmp->ress;
        tmp->func(zappy, client);
        tmp = pop_front_task(client);
    }
}

static bool time_manager(zappy_t *zappy)
{
    time_t current_time = time(NULL);

    if (zappy->time_to_eat <= current_time) {
        decrement_food(zappy);
        zappy->time_to_eat = current_time + 126 / zappy->freq;
    }
    if (zappy->refill_ressources <= current_time) {
        refill_ressources(zappy);
        zappy->refill_ressources = current_time + 20 / zappy->freq;
    }
    if (is_winning(zappy)) {
        printf("SIX PLAYERS HAVE WON !!!\n");
        return true;
    }
    return false;
}

static void add_client(zappy_t *zappy)
{
    struct sockaddr_in client_struct;

    zappy->server.acceptation = accept(
    zappy->server.socket_fd, (struct sockaddr *)&client_struct,
    &zappy->server.peer_addr_size);
    zappy->clients[zappy->server.nb_clients].client_socket =
    zappy->server.acceptation;
    zappy->clients[zappy->server.nb_clients].player = NULL;
    dprintf(zappy->clients[zappy->server.nb_clients].client_socket,
    "WELCOME\n");
    zappy->server.nb_clients += 1;
}

static void handle_gui(zappy_t *zappy)
{
    char line[BUFSIZ];
    size_t size;
    char **cmd = NULL;

    if (!FD_ISSET(zappy->gui->client_socket, &zappy->fdrw))
        return;
    size = read(zappy->gui->client_socket, line, BUFSIZ);
    if (size <= 0) {
        close(zappy->gui->client_socket);
        zappy->gui->client_socket = -1;
        free(zappy->gui);
        zappy->gui = NULL;
        return;
    }
    line[size] = '\0';
    cmd = my_str_to_word_array_separator(line, " \n");
    handle_command_gui(cmd, zappy);
    free_tab(cmd);
}

static void deconnect_client(zappy_t *zappy, client_t *client)
{
    close(client->client_socket);
    client->client_socket = -1;
    if (!client->player)
        return;
    if (zappy->gui)
        dprintf(zappy->gui->client_socket, "pdi %d\n", client->player->id);
    pop_player(zappy, client);
    client->player->team->free_slot += 1;
    free(client->player);
    client->player = NULL;
}

static void handle_clients(zappy_t *zappy)
{
    char line[BUFSIZ];
    size_t size;
    char **cmd = NULL;

    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (zappy->clients[i].client_socket < 0)
            continue;
        execute_tasks(zappy, &zappy->clients[i]);
        if (!FD_ISSET(zappy->clients[i].client_socket, &zappy->fdrw))
            continue;
        size = read(zappy->clients[i].client_socket, line, BUFSIZ);
        if (size <= 0) {
            deconnect_client(zappy, &zappy->clients[i]);
            continue;
        }
        line[size] = '\0';
        cmd = my_str_to_word_array_separator(line, " \n");
        handle_command(cmd, zappy, &zappy->clients[i]);
        cmd = free_tab(cmd);
    }
}

static int set_fds(zappy_t *zappy)
{
    int max_fd = zappy->server.socket_fd;

    FD_ZERO(&zappy->fdrw);
    FD_SET(zappy->server.socket_fd, &zappy->fdrw);
    if (zappy->gui) {
        FD_SET(zappy->gui->client_socket, &zappy->fdrw);
        max_fd = zappy->gui->client_socket;
    }
    for (int i = 0; i < zappy->server.nb_clients; i += 1) {
        if (zappy->clients[i].client_socket < 0)
            continue;
        FD_SET(zappy->clients[i].client_socket, &zappy->fdrw);
        if (zappy->clients[i].client_socket > max_fd)
            max_fd = zappy->clients[i].client_socket;
    }
    return max_fd;
}

static void slain_loop(int sigint)
{
    printf("\nServer shutting down.\n");
    loop = false;
}

int launch_zappy_server(zappy_t *zappy)
{
    int max_fd = 0;
    struct timeval time = {0, 1000};

    signal(SIGINT, slain_loop);
    signal(SIGPIPE, SIG_IGN);
    loop = true;
    while (loop) {
        max_fd = set_fds(zappy);
        if (select(max_fd + 1, &zappy->fdrw, NULL, NULL, &time) < 0)
            break;
        if (FD_ISSET(zappy->server.socket_fd, &zappy->fdrw))
            add_client(zappy);
        if (zappy->gui)
            handle_gui(zappy);
        handle_clients(zappy);
        if (time_manager(zappy))
            break;
    }
    free_zappy(zappy);
    return SUCCESS;
}
