/*
** EPITECH PROJECT, 2022
** test_my_strncpy
** File description:
** criterion
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};
    my_strncpy(dest,"HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
    
}

Test(my_strncpy, copy_negative_number_of_characters_in_empty_array)
{
    char dest[6] = {0};
    my_strncpy(dest,"HelloWorld", -1);
    cr_assert_str_eq(dest, "");

}
