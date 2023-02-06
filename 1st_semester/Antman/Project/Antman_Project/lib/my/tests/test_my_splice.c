/*
** EPITECH PROJECT, 1999
** tests
** File description:
** f
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
//#include "my_redirect.h"
//#include "test.h"

char *my_slice(char *str, char *slice);

Test (my_slice, basic_slice) {
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *slice = "[5:]";
    char *result = my_slice(str, slice);
    char *expeted = "fghijklmnopqrstuvwxyz";

    cr_assert_str_eq(result, expeted);
}

Test (my_slice, basic_slice2) {
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *slice = "[:5]";
    char *result = my_slice(str, slice);
    char *expeted = "abcde";

    cr_assert_str_eq(result, expeted);
}

Test (my_slice, basic_slice3) {
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *slice = "[::-1]";
    char *result = my_slice(str, slice);
    char *expeted = "zyxwvutsrqponmlkjihgfedcba";

    cr_assert_str_eq(result, expeted);
}

Test (my_slice, basic_slice4) {
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *slice = "[8:2:-1]";
    char *result = my_slice(str, slice);
    char *expeted = "ihgfed";

    cr_assert_str_eq(result, expeted);
}
