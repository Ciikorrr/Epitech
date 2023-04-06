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

Test (print_tab, test1, .init = redirect_all_std) {
    char  *map[5] = {"**X*X*", "*X****", "***XX*", "*X**X*", NULL};
    int result = print_tab(map);
    cr_assert_eq(result, 0);
}

Test (print_tab_NULL_pointeur, test1, .init = redirect_all_std) {
    cr_assert_eq(print_tab(NULL), ERROR_EPITECH);
}
