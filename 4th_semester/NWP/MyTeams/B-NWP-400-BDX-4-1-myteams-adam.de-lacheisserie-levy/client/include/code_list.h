/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_list
*/

#ifndef CODE_LIST_H_
    #define CODE_LIST_H_

int code_login(char **cmd);
int code_logout(char **cmd);
int code_send(char **cmd);
int code_user(char **cmd);
int code_users(char **cmd);
int code_help(char **cmd);
int code_bad_args(char **cmd);
int code_unauthorized(char **cmd);
int code_bad_user(char **cmd);
int code_messages(char **cmd);
int code_unknown_team(char **cmd);
int code_unknown_channel(char **cmd);
int code_unknown_thread(char **cmd);
int code_info_team(char **cmd);
int code_info_channel(char **cmd);
int code_info_thread(char **cmd);
int code_create_team(char **cmd);
int code_create_channel(char **cmd);
int code_create_thread(char **cmd);
int code_create_comment(char **cmd);
int code_list_teams(char **cmd);
int code_list_channels(char **cmd);
int code_already_exists(char **cmd);
int code_print_create_team(char **cmd);
int code_print_create_channel(char **cmd);
int code_print_create_thread(char **cmd);
int code_subscribe(char **cmd);
int code_unsubscribe(char **cmd);
int code_print_create_comment(char **cmd);
int code_list_replies(char **cmd);
int code_list_thread(char **cmd);

typedef struct my_flags_s {
    char const *flag;
    int (*func)(char **);
} my_flags_t;

const my_flags_t CODE[] = {
    {flag : "0", func : &code_help},
    {flag : "10", func : &code_help},
    {flag : "100", func : &code_user},
    {flag : "110", func : &code_users},
    {flag : "120", func : &code_messages},
    {flag : "130", func : &code_info_team},
    {flag : "140", func : &code_info_channel},
    {flag : "150", func : &code_info_thread},
    {flag : "160", func : &code_create_team},
    {flag : "165", func : &code_print_create_team},
    {flag : "170", func : &code_create_channel},
    {flag : "175", func : &code_print_create_channel},
    {flag : "180", func : &code_create_thread},
    {flag : "185", func : &code_print_create_thread},
    {flag : "190", func : &code_create_comment},
    {flag : "195", func : &code_print_create_comment},
    {flag : "200", func : &code_subscribe},
    {flag : "205", func : &code_unsubscribe},
    {flag : "210", func : &code_login},
    {flag : "220", func : &code_logout},
    {flag : "300", func : &code_bad_args},
    {flag : "400", func : &code_bad_user},
    {flag : "410", func : &code_unknown_team},
    {flag : "420", func : &code_unknown_channel},
    {flag : "430", func : &code_unknown_thread},
    {flag : "500", func : &code_unauthorized},
    {flag : "510", func : &code_already_exists},
    {flag : "600", func : &code_list_teams},
    {flag : "610", func : &code_list_channels},
    {flag : "620", func : &code_list_thread},
    {flag : "630", func : &code_list_replies},
    {flag : "800", func : &code_send}
};

#endif /* !CODE_LIST_H_ */
