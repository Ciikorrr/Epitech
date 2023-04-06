/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (do_width_true, test1) {
    int result = do_width("**XX*X*X*X*");
    cr_assert_eq(result, 11);
}

Test (do_width_false, test1) {
    int result = do_width(NULL);
    cr_assert_eq(result, -1);
}
