/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** commandList
*/

#ifndef COMMANDLIST_H_
    #define COMMANDLIST_H_

    #include "../../include/server.h"

int login_client(my_teams_t *teams, char **cmd, client_t *client);
int logout_client(my_teams_t *teams, char **cmd, client_t *client);
int get_user(my_teams_t *team, char **cmd, client_t *client);
int get_users(my_teams_t *team, char **cmd, client_t *client);
int send_to_user(my_teams_t *teams, char **cmd, client_t *client);
int get_help(my_teams_t *teams, char **cmd, client_t *client);
int get_messages(my_teams_t *team, char **cmd, client_t *client);
int use_context(my_teams_t *team, char **cmd, client_t *client);
int get_infos(my_teams_t *team, char **cmd, client_t *client);
int create(my_teams_t *teams, char **cmd, client_t *client);
int get_list(my_teams_t *team, char **cmd, client_t *client);
int list_subscribed(my_teams_t *team, char **cmd, client_t *client);
int subscribe(my_teams_t *teams, char **cmd, client_t *clt);
int unsubscribe(my_teams_t *teams, char **cmd, client_t *clt);


typedef struct my_flags_s {
    char const *flag;
    int (*func)(my_teams_t *teams, char **tab, client_t *client);
} my_flags_t;

const my_flags_t FLAGS[] = {
    {"/login", &login_client},
    {"/logout", &logout_client},
    {"/users", &get_users},
    {"/send", &send_to_user},
    {"/user", &get_user},
    {"/help", &get_help},
    {"/messages", &get_messages},
    {"/use", &use_context},
    {"/info", &get_infos},
    {"/create", &create},
    {"/list", &get_list},
    {"/subscribed", &list_subscribed},
    {"/subscribe", &subscribe},
    {"/unsubscribe", &unsubscribe},
};


#endif /* !COMMANDLIST_H_ */
