/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (length_map_true, test1) {
    char *map[5] = {"**X*X*", "*X****", "*X****", "*X****", NULL};
    int result = length_map(map);
    cr_assert_eq(result, 4);
}

Test (length_map_false, test1) {
    int result = length_map(NULL);
    cr_assert_eq(result, -1);
}
