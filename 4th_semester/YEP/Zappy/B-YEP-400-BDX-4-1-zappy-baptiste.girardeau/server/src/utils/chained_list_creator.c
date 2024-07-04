/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** chained_list_creator
*/

#include "server.h"

int tasks_len(tasks_t *tasks)
{
    tasks_t *tmp = tasks;
    int count = 0;

    while (tmp) {
        count += 1;
        tmp = tmp->next;
    }
    return count;
}

static tasks_t *create_task
(int id, time_t time, Ressources_t r,
    void(*func)(zappy_t *zappy, client_t *client))
{
    tasks_t *task = malloc(sizeof(tasks_t));

    if (!task)
        return NULL;
    task->id = id;
    task->func = func;
    task->time = time;
    task->ress = r;
    task->next = NULL;
    return task;
}

void push_back_task
(client_t *client, time_t time,
    Ressources_t r, void(*func)(zappy_t *zappy, client_t *client))
{
    tasks_t *tmp = client->player->tasks;

    if (tasks_len(tmp) >= 10)
        return;
    if (!tmp) {
        client->player->tasks =
        create_task(client->player->task_id, time, r, func);
        client->player->task_id += 1;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_task(client->player->task_id, time, r, func);
    client->player->task_id += 1;
}

tasks_t *pop_front_task(client_t *client)
{
    tasks_t *tmp = client->player->tasks;

    client->player->tasks = client->player->tasks->next;
    free(tmp);
    return client->player->tasks;
}

void pop_node(client_t *client, int id)
{
    tasks_t *tmp = client->player->tasks;
    tasks_t *prev;

    if (tmp && tmp->id == id) {
        pop_front_task(client);
        return;
    }
    while (tmp && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    prev->next = tmp->next;
    free(tmp);
}
