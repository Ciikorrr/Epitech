/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-bsminishell2-marius.marolleau
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct command_s {
    char **tab_command;
}command;

typedef struct all_args_s {
    command *all_command;
    char **env;
}all_args;

#endif /* STRUCT_H_ */
