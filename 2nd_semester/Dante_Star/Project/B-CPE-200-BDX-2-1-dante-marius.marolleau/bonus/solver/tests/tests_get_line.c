/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (get_line_true, test1) {
    int result = get_line("kcdjvff\ndjvifji\nojdivfj\nsodivhfb");
    cr_assert_eq(result, 4);
}

Test (get_line_false, test1) {
    int result = get_line(NULL);
    cr_assert_eq(result, -1);
}
