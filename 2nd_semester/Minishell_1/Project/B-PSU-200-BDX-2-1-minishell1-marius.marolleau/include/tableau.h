/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdarg.h>
#include "opt_builtin.h"
#include "struct_mnishell.h"

#ifndef TABLEAU_H_
    #define TABLEAU_H_

    typedef struct tab_option {
        char *opt;
        void (*function)(msh_t *minish);
    }opt_t;

opt_t tab_builtin[] = {
{"cd", &fct_cd},
{"exit", &fct_exit},
{"setenv", &fct_setenv},
{"unsetenv", &fct_unsetenv},
{"env", &fct_env}
};
    #define TAB_SIZE 5
#endif /* TABLEAU_H_ */
