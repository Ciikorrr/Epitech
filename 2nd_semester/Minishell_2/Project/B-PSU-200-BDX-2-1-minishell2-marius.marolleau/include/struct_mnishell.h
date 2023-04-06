/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef STRUCT_MINISHELL_H_
    #define STRUCT_MINISHELL_H_

    typedef struct list_command_s {
        char **tab;
        char *redirect;
        struct list_command_s *next;
    }list_command_t;

    typedef struct minishell_s {
        char **env;
        char **tab_command;
        list_command_t *command;
        int nb_command;
        int result;
        int exit;
        int fd;
        int pipe_fd[2];
        int do_read;
        int fd_output;
        int fd_input;
        int error_code;
    } msh_t;

    #define REDIRECT_R2 1
    #define REDIRECT_R1 2
    #define REDIRECT_L1 3
    #define REDIRECT_L2 4
#endif /* STRUCT_MINISHELL_H_ */
