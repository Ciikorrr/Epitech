/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
int my_printf(char const *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf1, string, .init = redirect_all_std) {


    my_printf("Hello World %s", "test");
    cr_assert_stdout_eq_str("Hello World test");
}

Test(my_printf2, character, .init = redirect_all_std) {
    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}
Test(my_printf3, character, .init = redirect_all_std) {
    my_printf("%s %s %s%%", "je", "suis", "Marius");
    cr_assert_stdout_eq_str("je suis Marius%");
}

Test(my_printf4, character, .init = redirect_all_std) {
    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}

Test(my_printf5, numbercharacters, .init = redirect_all_std) {
    int res = my_printf("abcd%n");
    cr_assert_eq(res, 4);
}

Test(my_printf6, numbercharacters, .init = redirect_all_std) {
    my_printf("test%n\n%s ca marche pas", "dommage");
    cr_assert_stdout_eq_str("test\ndommage ca marche pas");
}

Test(my_printf7, numbers, .init = redirect_all_std) {
    my_printf("%d", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf8, numbers_and_letters_and_float, .init = redirect_all_std) {
    my_printf("%s%d", "test", 10);
    cr_assert_stdout_eq_str("test10");
}

Test(my_printf9, numbers_and_letters, .init = redirect_all_std) {
    my_printf("%s%d %.2f", "test", 10, 14.85);
    cr_assert_stdout_eq_str("test10 14.85");
}

Test(my_printf10, numbers_and_letters_and_float, .init = redirect_all_std) {
    my_printf("%s%d %f", "test", 10, 14.850000);
    cr_assert_stdout_eq_str("test10 14.850000");
}

Test(my_printf11, floatnum, .init = redirect_all_std) {
    my_printf("%.8f", 19.845236698);
    cr_assert_stdout_eq_str("19.84523669");
}

Test(my_printf12, octal, .init = redirect_all_std) {
    my_printf("%o", 1000);
    cr_assert_stdout_eq_str("1750");
}

Test(my_printf13, octal_precision, .init = redirect_all_std) {
    my_printf("%.9o", 1000);
    cr_assert_stdout_eq_str("000001750");
}

Test(my_printf14, octal_precision, .init = redirect_all_std) {
    my_printf("%x", 1000);
    cr_assert_stdout_eq_str("3e8");
}

Test(my_printf15, octal_precision, .init = redirect_all_std) {
    my_printf("%.6x", 1000);
    cr_assert_stdout_eq_str("0003e8");
}

Test(my_printf16, octal_precision, .init = redirect_all_std) {
    my_printf("%.6X", 1000);
    cr_assert_stdout_eq_str("0003E8");
}

Test(my_printf17, float_numbers_maj, .init = redirect_all_std) {
    my_printf("%F", 1745.2563);
    cr_assert_stdout_eq_str("1745.256300");
}

Test(my_printf18, binary_test, .init = redirect_all_std) {
    my_printf("%b", 10);
    cr_assert_stdout_eq_str("1010");
}

Test(my_printf19, general_test, .init = redirect_all_std) {
    my_printf("%b %s %.01f %x", 10, "Bonjour", 14.256, 1000);
    cr_assert_stdout_eq_str("1010 Bonjour 14.2 3e8");
}

Test(my_printf20, scientifique, .init = redirect_all_std) {
    my_printf("%e", 14.523);
    cr_assert_stdout_eq_str("1,4e+01");
}

Test(my_printf21, general_test2, .init = redirect_all_std) {
    my_printf("The word %%%s%% has %d characters.", "epitech", 7);
    cr_assert_stdout_eq_str("The word %epitech% has 7 characters.");
}

Test(my_printf22, scientifique2, .init = redirect_all_std) {
    my_printf("%E", 21.58);
    cr_assert_stdout_eq_str("2,1E+01");
}

Test(my_printf23, scientifique3, .init = redirect_all_std) {
    my_printf("%E", 0.00054);
    cr_assert_stdout_eq_str("5,4000E-04");
}

Test(my_printf24, general_test3, .init = redirect_all_std) {
    my_printf("%%%i%%%d%%", 2, 1);
    cr_assert_stdout_eq_str("%2%1%");
}

Test(my_printf25, general_test4, .init = redirect_all_std) {
    my_printf("%%%i%%%d%%%s%%%f%%", 2, 1, "lol", 1.1);
    cr_assert_stdout_eq_str("%2%1%lol%1.100000%");
}
