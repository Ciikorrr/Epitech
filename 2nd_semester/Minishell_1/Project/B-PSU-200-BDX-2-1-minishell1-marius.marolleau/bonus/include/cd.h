/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "struct_mnishell.h"

#ifndef CD_H_
    #define CD_H_

    char *get_old_pwd(char **env);
    int simple_cd(char **env, msh_t *minish);
    int replace_new_pwd(char *new_pwd, msh_t *minish);
    int replace_old_pwd(char *old_pwd, msh_t *minish);
    int check_status_cd(char *command);
    int check_error_cd(msh_t *minish);
    int cd_with_path(char *new_path, char **env, char **tab, msh_t *minish);
    char *get_path(char **env);
    char *fill_new_path(int env_index, int index, int len, char **env);
    int home_exist(char **env);
    int check_status_cd(char *command);
    int check_error_cd(msh_t *minish);
    void cd_basic(msh_t *minish);
    int cd_moins(char **env, msh_t *minish);
#endif /* CD_H_ */
