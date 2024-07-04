/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** protos_clt
*/

#ifndef PROTOS_H_
    #define PROTOS_H_
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

char **my_str_to_word_array_separator(char const *str, char const *separator);
char **my_str_to_word_array_separator_q
(char const *str, char const *separator);
int string_is_num(char const *str);
bool free_tab(char **tab);
int check_args_clt(int argc, char **argv);
int length_tab(char **tab);
int create_client(int port, char *address);
char **command_parser(char *str, char const *separator);
time_t convert_str_to_time(char *time_str);

#endif /* !PROTOS_H_ */
