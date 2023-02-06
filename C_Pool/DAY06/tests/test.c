/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libday06.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_revstr, test1) {
    char *result = my_revstr("haha");
    cr_assert_str_eq(result, "ahah");
}

Test (my_str_isalpha, test1) {
    int result = my_str_isalpha("haha");
    cr_assert_eq(result, 1);
}

Test (my_str_isalpha_bis, test1) {
    int result = my_str_isalpha("haha1");
    cr_assert_eq(result, 0);
}

Test (my_str_islower, test1) {
    int result = my_str_islower("haha");
    cr_assert_eq(result, 1);
}

Test (my_str_islower_bis, test1) {
    int result = my_str_islower("haHa");
    cr_assert_eq(result, 0);
}

Test (my_str_isupper, test1) {
    int result = my_str_isupper("HAHA");
    cr_assert_eq(result, 1);
}

Test (my_str_isupper_bis, test1) {
    int result = my_str_islower("haHa");
    cr_assert_eq(result, 0);
}

Test (my_str_isprintable, test1) {
    int result = my_str_isprintable("haHa");
    cr_assert_eq(result, 1);
}

Test (my_str_isprintable_bis, test1) {
    int result = my_str_isprintable("haHa\t");
    cr_assert_eq(result, 0);
}

Test (my_strcmp, test1) {
    int result = my_strcmp("haha", "haha");
    cr_assert_eq(result, 0);
}

Test (my_strcmp_2, test1) {
    int result = my_strcmp("haha", "hbha");
    cr_assert_eq(result, -1);
}

Test (my_strcmp_3, test1) {
    int result = my_strcmp("hbha", "haha");
    cr_assert_eq(result, 1);
}

Test (my_str_isnum, test1) {
    int result = my_str_isnum("hbha1");
    cr_assert_eq(result, 0);
}

Test (my_str_isnum_bis, test1) {
    int result = my_str_isnum("42");
    cr_assert_eq(result, 1);
}

Test (my_strlowcase, test1) {
    char str[] = "EPITECH";
    char *result = my_strlowcase(str);
    cr_assert_str_eq(result, "epitech");
}

Test (my_strupcase, test1) {
    char str[] = "epitech";
    char *result = my_strupcase(str);
    cr_assert_str_eq(result, "EPITECH");
}

Test (my_strcpy, test1) {
    char str[] = "epitech";
    char str1[] = "EPITECH";
    char *result = my_strcpy(str1, str);
    cr_assert_str_eq(result, "epitech");
}

Test (my_strncpy, test1) {
    char str[] = "epitech";
    char str1[] = "EPITECH";
    char *result = my_strncpy(str1, str, 5);
    cr_assert_str_eq(result, "epiteCH");
}

Test (my_strncmp, test1) {
    int result = my_strncmp("haha", "haha", 3);
    cr_assert_eq(result, 0);
}

Test (my_strncmp_2, test1) {
    int result = my_strncmp("haha", "hbha", 4);
    cr_assert_eq(result, -1);
}

Test (my_strncmp_3, test1) {
    int result = my_strncmp("hbha", "haha", 2);
    cr_assert_eq(result, 1);
}
