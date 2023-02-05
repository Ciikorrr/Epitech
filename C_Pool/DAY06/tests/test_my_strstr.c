/*
** EPITECH PROJECT, 2022
** test_my_strstr
** File description:
** test my_strstr
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, basic_test)
{
    char str[] = "hello";
    char to_find[] = "";

    my_strstr(str, to_find);
    cr_assert_str_eq(my_strstr(str, to_find), "hello"); 
}

Test(my_strstr2, error)
{
    char str[] = "marius";
    char to_find[] = "abc";

    my_strstr(str, to_find);
    cr_assert_eq(my_strstr(str, to_find), NULL);
}

