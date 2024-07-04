/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** utils
*/

#pragma once
#include <stdbool.h>
#include <stdio.h>

bool my_str_isnum(char const *str);
char **my_str_to_word_array_separator(char const *str, char const *separator);
char *my_strcat_dup(char *dest, char *src, char *third);
void init_ressources(int *ressources);
void push_back_task
(client_t *client, time_t time,
    Ressources_t r, void(*func)(zappy_t *zappy, client_t *client));
tasks_t *pop_front_task(client_t *client);
void pop_node(client_t *client, int id);
int random_number(int min, int max);
long get_user_id(char *str);
void decrement_food(zappy_t *zappy);
void level_one_exec(zappy_t *zappy, client_t *client);
void level_two_exec(zappy_t *zappy, client_t *client);
void level_three_exec(zappy_t *zappy, client_t *client);
void level_four_exec(zappy_t *zappy, client_t *client);
void level_five_exec(zappy_t *zappy, client_t *client);
void level_six_exec(zappy_t *zappy, client_t *client);
void level_seven_exec(zappy_t *zappy, client_t *client);
void push_back_player(zappy_t *zappy, client_t *client);
void pop_player(zappy_t *zappy, client_t *client);
int number_of_users(int level, tile_t *tile);
int tasks_len(tasks_t *tasks);
void increment_level(zappy_t *zappy, client_t *client, vector_t pos);
void content_tiles(zappy_t *zappy, char **cmd);
void print_teams(zappy_t *zappy, char **cmd);
int convert(int x, int max);
void send_message_east(zappy_t *zappy, char *msg, client_t *cli, vector_t pos);
void send_message_north
(zappy_t *zappy, char *msg, client_t *cli, vector_t pos);
void send_message_south
(zappy_t *zappy, char *msg, client_t *cli, vector_t pos);
void send_message_west(zappy_t *zappy, char *msg, client_t *cli, vector_t pos);
void free_map(zappy_t *zappy);
void free_zappy(zappy_t *zappy);
char **free_tab(char **tab);
egg_t *pop_egg(team_t *team, int id);
egg_t *push_egg_back
(zappy_t *zappy, team_t *team, vector_t pos, int id_player);
egg_t *pop_front_egg(team_t *team);
void create_eggs_per_teams(zappy_t *zappy, team_t *team);
void print_eggs(zappy_t *zappy);
void print_egg(zappy_t *zappy, egg_t *egg);
void free_eggs(team_t *team);
bool is_winning(zappy_t *zappy);
