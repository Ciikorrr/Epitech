/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"
#include "linked_list.h"
#include "protos.h"

Test (init_solver_true, test1) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests.txt");
    init_solver(&solver, map);
    cr_assert_eq(solver.height_max, 3);
    cr_assert_eq(solver.width_max, 5);
    cr_assert_eq(solver.pos_x, 0);
    cr_assert_eq(solver.pos_y, 0);
}

Test (init_solver, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_valid.txt");
    do_solver(map);
    fflush(stdout);
    cr_assert_stdout_eq_str("o*XXoooo\noXoooXXo\noooX**Xo\nX*XX*X*o\nXX***XXo");
}

Test (init_solver_no_solution, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    do_solver(map);
    fflush(stdout);
    cr_assert_stdout_eq_str("no solution found\n");
}
