/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** macros
*/
#include "struct_mnishell.h"
#include "linked_list.h"

#ifndef PROTOS_H_
    #define PROTOS_H_

    char *get_input(void);
    int get_error(int argc, char **env);
    msh_t *do_command(char *str, msh_t *minish);
    msh_t *mysh(msh_t *minish);
    int check_status(int status, char *command);
    void error_exe(char *argv);
    char *find_path(char **env, char *path, char *command);
    char *check_access(char **tab, char *path, char *command);
    char *get_path(char **env);
    int check_error_setenv(int length_argv, list *env_list, msh_t *minish);
    int check_error_cd(msh_t *minish);
    list *do_setenv(msh_t *minish, list *env_list);
    int env_already_exist(list *env_list, char **tab);
    int setenv_two_argument(list *env_list, char **tab);
    int get_index_already_exist(list *env_list, char **tab);
    int setenv_one_argument(list *env_list, char **tab);
    void env_exist(msh_t *minish, list *env_list);
    int check_errno(char *command);
    int get_index_env(char **env);
    int check_absolut_path(msh_t *minish);
    int fork_function(char **tab, char **env, char *command);
    void add_new_env_var(list *env_list, char *argument, char *arg);
    void change_env_list(int index, list *env_list, char *argument, char *arg);
    void fct_env(msh_t *minish);

#endif /* PROTOS_H_ */
