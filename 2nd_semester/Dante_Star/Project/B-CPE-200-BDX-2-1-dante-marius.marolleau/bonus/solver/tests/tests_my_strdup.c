/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test (my_strdup_true, test1) {
    char *result = NULL;
    char src[] = "Hello World !";
    result = my_strdup(src);
    cr_assert_str_eq(result, "Hello World !");
}

Test (my_strdup_false, test1) {
    cr_assert_eq(my_strdup(NULL), NULL);
}
