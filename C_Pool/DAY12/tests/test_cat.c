/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
int my_cat(int argc, char **argv);
void control(int argc, int buf);


Test(my_cat, reproduce_the_fonction_cat)
{
    char s1[] = "cat";
    char s2[] = "test";
    char *array = {s1, s2};
    int rest = main(2, *array);
    cr_assert_eq(rest, 0);
}
