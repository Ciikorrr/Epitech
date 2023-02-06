/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libday07.h"

Test (my_strncat, test1) {
    char str[] = "Hello";
    char str1[] = " World";
    char *result = my_strcat(str, str1);
    cr_assert_str_eq(result, "Hello World");
}

Test (my_strcat, test1) {
    char str[] = "Hello";
    char str1[] = " World";
    char *result = my_strncat(str, str1, 3);
    cr_assert_str_eq(result, "Hello Wo");
}
