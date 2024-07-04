/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** protos_srv
*/

#ifndef PROTOS_SRV_H_
    #define PROTOS_SRV_H_

    #include <stdlib.h>
    #include <string.h>
    #include "../../include/server.h"

int check_args_srv(int argc, char **argv);
int string_is_num(char const *str);
void set_struct(my_teams_t *my_teams, int port);
int bind_listen(my_teams_t *teams);
char **my_str_to_word_array_separator(char const *str, char const *separator);
char **my_str_to_word_array_separator_q(char const *str, char const *sep);
int client_handler(my_teams_t *my_teams);
char *my_strcat_dup(char *dest, char *src, char *third);
int command_handler(my_teams_t *teams, char **cmd, client_t *client);
int find_index_chat(my_teams_t *teams, char *uuid, int index);
int find_user_index(my_teams_t *teams, char *uuid);
bool is_user_exists(my_teams_t *teams, char *uuid);
int add_to_my_teams(my_teams_t *teams, char **cmd, uuid_t uuid_team);
int add_to_my_teams_channel
(my_teams_t *teams, char **cmd, uuid_t uuid, int it);
int add_to_my_teams_thread
(my_teams_t *teams, char **cmd, uuid_t uuid, int *id);
char **command_parser(char *str, char const *separator);
int add_to_teams_comment(my_teams_t *teams, char **cmd, int *id, uuid_t uuidu);
int find_idx_channel(my_teams_t *teams, int idx_tc, uuid_t to_find);
int find_idx_tms(my_teams_t *teams, uuid_t to_find);
int find_idx_thread
(my_teams_t *teams, int idx_tc, int idx_chl, uuid_t to_find);
int create_team(my_teams_t *teams, char **cmd, client_t *client);
int create_channel(my_teams_t *teams, char **cmd, client_t *client);
int create_comment(my_teams_t *teams, char **cmd, client_t *client);
int create_thread(my_teams_t *teams, char **cmd, client_t *client);
char *int_to_string(int num);
#endif /* !PROTOS_SRV_H_ */
