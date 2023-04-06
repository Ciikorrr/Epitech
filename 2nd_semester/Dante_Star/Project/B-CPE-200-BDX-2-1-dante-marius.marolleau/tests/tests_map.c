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
#include "macros_bit.h"

Test (decrypte_map, test1) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests.txt");
    init_solver(&solver, map);
    solver.map[0][0] = LIBRE;
    solver.map[0][0] += PATH;
    solver.map[0][0] += EXPLORED;
    decrypte_map(&solver);
    cr_assert_str_eq(solver.map[0], "o*X*X*");
}

Test (go_other_movement, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    init_solver(&solver, map);
    go_other_movement(&solver, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("no solution found\n");
}

Test (go_back_west, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    init_solver(&solver, map);
    solver.map[0][1] += WEST << 2;
    solver.map[0][1] += PATH;
    solver.map[0][1] += EXPLORED;
    solver.pos_x += 1;
    go_other_movement(&solver, 84);
    cr_assert_eq(solver.pos_x, 0);
}

Test (go_back_south, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    init_solver(&solver, map);
    solver.map[2][0] += SOUTH << 2;
    solver.map[2][0] += PATH;
    solver.map[2][0] += EXPLORED;
    solver.pos_y = 2;
    go_other_movement(&solver, 84);
    cr_assert_eq(solver.pos_y, 3);
}

Test (go_back_east, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    init_solver(&solver, map);
    solver.map[0][1] += EAST << 2;
    solver.map[0][1] += PATH;
    solver.map[0][1] += EXPLORED;
    solver.pos_x = 1;
    go_other_movement(&solver, 84);
    cr_assert_eq(solver.pos_x, 2);
}

Test (go_back_north, test1, .init = redirect_all_std) {
    sol_t solver = {NULL, 0, 0, 0, 0};
    char **map = file_to_tab("tests/map_for_tests_no_solution.txt");
    init_solver(&solver, map);
    solver.map[1][0] += NORTH << 2;
    solver.map[1][0] += PATH;
    solver.map[1][0] += EXPLORED;
    solver.pos_y = 1;
    go_other_movement(&solver, 84);
    cr_assert_eq(solver.pos_x, 0);
}
