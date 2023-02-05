/*
** EPITECH PROJECT, 2022
** test_my_revstr
** File description:
** test 
*/

#include <criterion/criterion.h>
char *my_revstr(char *str);

Test(my_revstr1, reverse_characters)
{
    char dest[] = "hello";
    my_revstr(dest);
    cr_assert_str_eq(dest, "olleh");
}

Test(my_revstr2, reverse_characters)
{
    char dest[] = "a1b2c3";
    my_revstr(dest);
    cr_assert_str_eq(dest, "3c2b1a");
}

Test(my_revstr3, reverse_characters)
{
    char dest[] = "123456789";
    my_revstr(dest);
    cr_assert_str_eq(dest, "987654321");
}
    
