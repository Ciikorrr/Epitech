/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (my_strlen_true, test1) {
    int result = my_strlen("haha");
    cr_assert_eq(result, 4);
}

Test (my_strlen_false, test1) {
    int result = my_strlen(NULL);
    cr_assert_eq(result, -1);
}
