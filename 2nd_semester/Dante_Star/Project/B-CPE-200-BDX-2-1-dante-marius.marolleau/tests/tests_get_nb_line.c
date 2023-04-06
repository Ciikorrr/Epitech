/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"
#include "macros_errors.h"

Test (get_nb_line_true, test1) {
    int result = get_nb_line("tests/map_for_tests.txt");
    cr_assert_eq(result, 4);
}

Test (get_nb_line_empty_file, test1) {
    int result = get_nb_line("tests/map_for_tests_empty_file.txt");
    cr_assert_eq(result, -1);
}

Test (get_nb_line_folder, test1) {
    int result = get_nb_line("tests/");
    cr_assert_eq(result, -1);
}

Test (get_nb_line_false, test1) {
    int result = get_nb_line(NULL);
    cr_assert_eq(result, -1);
}

Test (get_nb_line_wrong_path, test1) {
    int result = get_nb_line("wrong path");
    cr_assert_eq(result, -1);
}
