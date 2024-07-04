/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/myftp.h"

int my_strcmp(char const *s1, char const *s2);


Test (my_strcmp_true, test1) {
    char *src = "HelloWorld";
    char *dest = "HelloWorld";
    int result = my_strcmp(src, dest);
    cr_assert_eq(result, 0);
}

Test (my_strcmp_false, test1) {
    char *src = "HelloWorld";
    char *dest = "HdlloWorld";
    int result = my_strcmp(src, dest);
    cr_assert_eq(result, 1);
}

Test (my_strcmp_false_bis, test1) {
    char *src = "HdlloWorld";
    char *dest = "HelloWorld";
    int result = my_strcmp(src, dest);
    cr_assert_eq(result, -1);
}

Test (my_strcmp_false_len, test1) {
    char *src = "Hdlld";
    char *dest = "HelloWorld";
    int result = my_strcmp(src, dest);
    cr_assert_eq(result, -1);
}
