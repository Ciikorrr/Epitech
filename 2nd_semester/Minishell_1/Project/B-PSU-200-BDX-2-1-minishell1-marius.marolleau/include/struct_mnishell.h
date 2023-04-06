/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef STRUCT_MINISHELL_H_
    #define STRUCT_MINISHELL_H_

    typedef struct minishell_s {
        char **env;
        char **tab_command;
        int result;
        int exit;
    } msh_t;

#endif /* STRUCT_MINISHELL_H_ */
