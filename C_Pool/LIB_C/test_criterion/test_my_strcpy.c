/*
** EPITECH PROJECT, 2022
** test_strcy
** File description:
** test strcpy
** You can have a mulitple lines if you want !
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test (my_strcpy, copy_the_word)
{
    char dest[6];

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest,"Hello");
}
