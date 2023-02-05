/*
** EPITECH PROJECT, 2022
** test_my_revstr
** File description:
** test 
*/

#include <criterion/criterion.h>
char *my_strcapitalize(char *str);

Test(my_strcapitalize1, test)
{
    char dest[] = " hello world world";
    char *res = my_strcapitalize(dest);
    cr_assert_str_eq(res, "Hello World World");
}

Test(my_strcapitalize2, test)
{
    char dest[] = "helloworld";
    char *res = my_strcapitalize(dest);
    cr_assert_str_eq(res, "Helloworld");
}

Test(my_strcapitalize3, test)
{
    char dest[] = "Hello#world@today";
    char *res = my_strcapitalize(dest);
    cr_assert_str_eq(res, "Hello#world@today");
}

Test(my_strcapitalize4, test)
{
    char dest[] = "hello world!";
    char *res = my_strcapitalize(dest);
    cr_assert_str_eq(res, "Hello World!");
}
