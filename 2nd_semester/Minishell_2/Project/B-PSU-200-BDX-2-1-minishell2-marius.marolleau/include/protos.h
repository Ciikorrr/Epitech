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
    int check_status(int status);
    void error_exe(char *argv);
    char *find_path(char **env, char *command);
    char *check_access(char **tab, char *path, char *command);
    char *get_path(char **env);
    int check_error_setenv(int length_argv, list *env_list, msh_t *minish);
    int check_error_cd(msh_t *minish);
    list *do_setenv(msh_t *minish, list *env_list);
    int env_already_exist(list *env_list, char **tab);
    int setenv_two_argument(list *env_list, char **tab);
    int get_index_already_exist(list *env_list, char **tab);
    int setenv_one_argument(list *env_list, char **tab);
    void env_doesnt_exist(msh_t *minish, list *env_list);
    int check_errno(char *command);
    int get_index_env(char **env);
    int check_absolut_path(msh_t *minish);
    int fork_function(msh_t *minish, char *command, int last);
    void add_new_env_var(list *env_list, char *argument, char *arg);
    void change_env_list(int index, list *env_list, char *argument, char *arg);
    void fct_env(msh_t *minish);
    void setenv_too_many_arg(msh_t *minish);
    int parser(char *str, msh_t *minish);
    int check_for_builtin(msh_t *minish, char *command);
    int do_command_pipe(msh_t *minish, int i);
    int exec_binary(msh_t *minish);
    void read_fd(msh_t *minish);
    void action_on_fd(msh_t *minish, int last);
    int child_fork(char *command, int status, msh_t *minish, int last);
    int parent_fork(int res, int status, msh_t *minish, int last);
    char *concat_command(char **command2, char **new_path, char **test,
char **command);
    int access_and_free(char **path, char **new_path, char **test,
char **command2);
    char *check_cmd_exec(msh_t *minish);
    char *check_for_path(char *command);
    int fork_function_without_pipe(msh_t *minish, char *command);
    char *is_builtins(char *command);
    char *is_absolut(msh_t *minish, char *command);
    char *is_path(msh_t *minish, char *command);
    int check_for_redirection(char **tab);
    int error_redirection(char **tab, int last);
    int check_stat(char **tab, int i);
    int get_fd_redirect(msh_t *minish);
    int display_error_redirection(char **tab, int i, int last);
    int check_open(int fd, char *command, msh_t *minish);
    int double_rediction(msh_t *minish, int i);
    int simple_rediction(msh_t *minish, int i);
    int get_fd(msh_t *minish, int type_redirect, int i);
    int get_fd_input(msh_t *minish);
    int nb_pipe(char **tab);
    int remake_all_tab(msh_t *minish);
    int double_redirection_left(msh_t *minish, char *to_compare);
    int manage_redirection(msh_t *minish);

#endif /* PROTOS_H_ */
