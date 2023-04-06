/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_strlen_original, test1) {
    int result = my_strlen("haha");
    cr_assert_eq(result, 4);
}

Test (my_strlen_mod, test1) {
    int result = my_strlen_bis("hah\na");
    cr_assert_eq(result, 3);
}

Test (my_strncmp_false, test1) {
    int result = my_strncmp("haha", "hbhb", 4);
    cr_assert_eq(result, -1);
}

Test (my_strncmp_false_bis, test1) {
    int result = my_strncmp("hbhb", "haha", 4);
    cr_assert_eq(result, -1);
}

Test (my_strncmp_true, test1) {
    int result = my_strncmp("haha", "hahi", 3);
    cr_assert_eq(result, 0);
}

Test (my_strdup, test1) {
    char *result = NULL;
    char src[] = "Hello World !";
    result = my_strdup(src);
    cr_assert_str_eq(result, "Hello World !");
}

Test (length_tab, test1) {
    char *tab[4] = {"Hello", "World", "EPITECH", NULL};
    int result = length_tab(tab);
    cr_assert_eq(result, 3);
}

Test (my_str_isalpha_false, test1) {
    char *str = "Hello World";
    int result = my_str_isalpha(str);
    cr_assert_eq(result, 0);
}

Test (my_str_isalpha_true, test1) {
    char *str = "HelloWorld";
    int result = my_str_isalpha(str);
    cr_assert_eq(result, 1);
}

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

Test (my_putchar, test1, .init = redirect_all_std) {
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test (my_putstr, test1, .init = redirect_all_std) {
    my_putstr("HELLO");
    cr_assert_stdout_eq_str("HELLO");
}

Test (my_put_nbr, test1, .init = redirect_all_std) {
    my_put_nbr(42);
    cr_assert_stdout_eq_str("42");
}

Test (my_put_nbr_overflow, test1, .init = redirect_all_std) {
    my_put_nbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test (my_put_nbr_negative, test1, .init = redirect_all_std) {
    my_put_nbr(-42);
    cr_assert_stdout_eq_str("-42");
}

Test (my_strlen_index, test1) {
    int result = my_strlen_index("Marius Marolleau", 0);
    cr_assert_eq(result, 6);
}

Test (my_nbr_mot_bis, test1) {
    int result = my_nbr_mot("  Marius Marolleau");
    cr_assert_eq(result, 2);
}

Test (nbr_word_separator, test1) {
    int result = nbr_word_separator("       Epitech Bordeaux   2027", " \t");
    cr_assert_eq(result, 3);
}

Test (my_strcat_dup, test1) {
    char *src = malloc(sizeof(char) * 6);
    char *dest = malloc(sizeof(char) * 5);
    src = my_strdup("Hello ");
    dest = my_strdup("World");
    char *result = strcat_dup(src, dest);
    cr_assert_str_eq(result, "Hello World");
}

Test (find_index_separator, test1) {
    int result = find_index_separator("       Epitech Bordeaux   2027", 0, " ");
    cr_assert_eq(result, 7);
}

Test (my_str_to_word_array_separator, test1) {
    char **tab = my_str_to_word_array_separator("EPITECH EPITECH", " \t");
    for (int i = 0; tab[i] != NULL; i += 1) {
        cr_assert_str_eq(tab[i], "EPITECH");
    }
}

Test (my_str_to_word_array_separator_bis, test1) {
    char **tab = my_str_to_word_array_separator("\t   EPITECH EPITECH", " \t");
    for (int i = 0; tab[i] != NULL; i += 1) {
        cr_assert_str_eq(tab[i], "EPITECH");
    }
}
