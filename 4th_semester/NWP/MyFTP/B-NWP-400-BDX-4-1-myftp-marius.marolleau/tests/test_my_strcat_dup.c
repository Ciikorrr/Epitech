/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** test_free_tab
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/myftp.h"

Test (my_strcat_dup, test1) {
    char *str1 = "Hello";
    char *str2 = " World";
    char *str3 = " !!!";
    char *res = my_strcat_dup(str1, str2, str3);

    cr_assert_str_eq(res, "Hello World !!!");
}

Test (my_strcat_dup2, test1) {
    char *str1 = "Hello";
    char *str2 = " World";
    char *res = my_strcat_dup(str1, str2, NULL);

    cr_assert_str_eq(res, "Hello World");
}

Test (my_strcat_dup3, test1) {
    char *str1 = "Hello";
    char *res = my_strcat_dup(str1, NULL, NULL);

    cr_assert_str_eq(res, "Hello");
}

Test (my_strcat_dup4, test1) {
    char *str1 = "Hello";
    char *res = my_strcat_dup(NULL, str1, NULL);

    cr_assert_str_eq(res, "Hello");
}

Test (my_strcat_dup5, test1) {
    char *str1 = "Hello";
    char *str2 = " World";
    char *res = my_strcat_dup(NULL, str1, str2);

    cr_assert_str_eq(res, "Hello World");
}

Test (my_strcat_dup6, test1) {
    char *str1 = "Hello";
    char *str2 = " World";
    char *res = my_strcat_dup(str1, NULL, str2);

    cr_assert_str_eq(res, "Hello World");
}
