/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (file_to_tab_true, test1) {
    char **tab = file_to_tab("tests/map_for_tests.txt");
    char *map[5] = {"**X*X*", "*X****", "***XX*", "*X**X*", NULL};
    for (int i = 0; tab[i] != NULL || map[i] != NULL; i += 1) {
        cr_assert_str_eq(map[i], tab[i]);
    }
}

Test (file_to_tab_false, test1) {
    cr_assert_eq(file_to_tab(NULL), NULL);
}
