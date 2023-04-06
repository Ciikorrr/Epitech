/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#ifndef PROTOS_H_
    #define PROTOS_H_

    #include "linked_list.h"
    int error_handling(int argc, char **argv, char ***map);
    int do_solver(char **argv);
    int get_next(sol_t *solver);
    void go_back(sol_t *solver);
    void free_all(sol_t *solver);
    int my_strlen(char const *str);
    void fill_tab(sol_t *solver);
    void decrypte_map(sol_t *solver);
    int go_other_movement(sol_t *solver, int res);
    void replace_char(sol_t *solver, int i, int j);
    void decrypte_map(sol_t *solver);
    int init_solver(sol_t *solver, char **map);

#endif /* !PROTOS_H_ */
