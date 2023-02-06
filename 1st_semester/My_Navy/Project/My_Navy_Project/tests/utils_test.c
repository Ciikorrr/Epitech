/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "protos_map.h"
#include "libutils.h"
#include "my.h"

Test (bin_to_dec, test1) {
    int result = bin_to_dec("0101");
    cr_assert_eq(result, 5);
}

Test (my_revstr_bis, test1) {
    char *result = my_revstr_bis("haha");
    cr_assert_str_eq(result, "ahah");
}

Test (my_strlen, test1) {
    int result = my_strlen("haha");
    cr_assert_eq(result, 4);
}

Test (my_compute_power_rec, test1) {
    int result = my_compute_power_rec(10, -5);
    cr_assert_eq(result, 0);
}

Test (file_to_str, test1) {
    char *result = file_to_str("tests/adam1.txt");
    cr_assert_str_eq(result, "hello");
}

Test (file_to_str_failure, test1) {
    char *result = file_to_str("tests/adam.txt");
    cr_assert_null(result);
}
