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

Test (error_handling_wrong_char, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests_wrong_char.txt"};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_not_enough_on_a_line, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests_lines.txt"};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_wrong_start, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests_wrong_start.txt"};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_NULL_argv_1, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", NULL};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_NULL_argv_2, test1, .init = redirect_all_std) {
    char *argv[2] = {NULL, NULL};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_NULL_argv, test1, .init = redirect_all_std) {
    char **argv = NULL;
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (error_handling_too_many_args, test1, .init = redirect_all_std) {
    char *argv[3] = {"./solver", "WRONG", "ARGV"};
    char **map = NULL;
    int result = error_handling(3, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (compare_wrong_char, test1, .init = redirect_all_std) {
    char **map = file_to_tab("tests/map_for_tests_wrong_char.txt");
    int result = compare(map, 1);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (compare_correct_char, test1, .init = redirect_all_std) {
    char **map = file_to_tab("tests/map_for_tests_wrong_char.txt");
    int result = compare(map, 2);
    cr_assert_eq(result, SUCCESS_EPITECH);
}

Test (compare_NULL_argv, test1, .init = redirect_all_std) {
    char **map = file_to_tab(NULL);
    int result = compare(map, 2);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (check_map_NULL_argv, test1, .init = redirect_all_std) {
    char **map = file_to_tab(NULL);
    int result = check_map(map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (check_map_not_enough_char_on_a_line, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests_lines.txt"};
    char **map = file_to_tab(argv[1]);
    int result = check_map(map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (check_map_wrong_start, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests_wrong_start.txt"};
    char **map = file_to_tab(argv[1]);
    int result = check_map(map);
    cr_assert_eq(result, ERROR_EPITECH);
}

Test (check_map_all_is_good, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests.txt"};
    char **map = file_to_tab(argv[1]);
    int result = check_map(map);
    cr_assert_eq(result, SUCCESS_EPITECH);
}

Test (error_handling_all_is_good, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "tests/map_for_tests.txt"};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, SUCCESS_EPITECH);
}

Test (error_handling_wrong_path, test1, .init = redirect_all_std) {
    char *argv[2] = {"./solver", "wrong_path.txt"};
    char **map = NULL;
    int result = error_handling(2, argv, &map);
    cr_assert_eq(result, ERROR_EPITECH);
}
