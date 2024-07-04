/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** test
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (test_all, test0)
{
    string_t s;
    string_t ap;
    char const *ptr = NULL;

    string_init(&s, "Hello");
    string_init(&ap, "Vorld");
    s.clear(&s);
    cr_assert_str_eq(s.str, "");
    s.assign_c(&s, "World");
    cr_assert_eq(s.length(&s), 5);
    s.clear(NULL);
    cr_assert_str_eq(s.str, "World");
    cr_assert_eq(s.length(NULL), -1);
    cr_assert_eq(s.compare_c(&s, "World"), 0);
    cr_assert_eq(s.compare_s(&s, &ap), 1);
    ptr = s.c_str(&s);
    cr_assert_str_eq(ptr, "World");
    ptr = s.c_str(NULL);
    cr_assert_null(ptr);
    cr_assert_eq(s.empty(&s), 1);
    ap.clear(&ap);
    cr_assert_eq(ap.empty(&ap), 0);
    cr_assert_eq(ap.empty(NULL), 0);
    s.clear(&s);
    s.assign_c(&s, "667");
    cr_assert_eq(s.to_int(&s), 667);
    s.clear(&s);
    s.assign_c(&s, "TOTOTATA");
    cr_assert_eq(s.find_c(&s, "TA", 0), 4);
    cr_assert_eq(s.find_c(NULL, "TA", 0), -1);
    cr_assert_eq(s.find_c(&s, NULL, 0), -1);
    ap.assign_c(&ap, "TA");
    cr_assert_eq(s.find_s(&s, &ap, 0), 4);
    string_destroy(&s);
    string_destroy(&ap);
}

/*-------- init ---------*/

Test (test_init, test1)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

Test (test_init_null_value, test1)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_null(s.str);
    string_destroy(&s);
}

Test (test_init_null_value_bis, test1)
{
    string_t s;

    string_init(NULL, "TOTO");
    cr_assert_null(s.str);
    string_destroy(&s);
}

Test (test_destroy_null_value, test1)
{
    string_t s;

    string_init(&s, "hello");
    string_destroy(NULL);
    cr_assert_str_eq(s.str, "hello");
}

/*-------- assign_c ---------*/

Test (test_assign_c, test2)
{
    string_t s;

    string_init(&s, "");
    s.assign_c(&s, "World");
    cr_assert_str_eq(s.str, "World");
    string_destroy(&s);
}

Test (test_assign_c_null_value, test2)
{
    string_t s;

    string_init(&s, "Hello");
    s.assign_c(&s, NULL);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

Test (test_assign_c_null_value_bis, test2)
{
    string_t s;

    string_init(&s, "Hello");
    s.assign_c(NULL, "TOTO");
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

/*-------- assign_s ---------*/

Test (test_assign_s, test3)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello");
    string_init(&ap, "World");
    s.assign_s(&s, &ap);
    cr_assert_str_eq(s.str, "World");
    string_destroy(&s);
    string_destroy(&ap);
}

Test (test_assign_s_null_value, test3)
{
    string_t s;

    string_init(&s, "Hello");
    s.assign_s(&s, NULL);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

Test (test_assign_s_null_value_bis, test3)
{
    string_t s;

    string_init(&s, "Hello");
    s.assign_s(NULL, &s);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

/*-------- append_c ---------*/

Test (test_append_c, test4)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(&s, " world");
    cr_assert_str_eq(s.str, "Hello world");
    string_destroy(&s);
}

Test (test_append_c_null_value, test4)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(&s, NULL);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

Test (test_append_c_null_value_bis, test4)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(NULL, "TOTO");
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
}

/*-------- append_s ---------*/

Test (test_append_s, test5)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello");
    string_init(&ap, "World");
    s.append_s(&s, &ap);
    cr_assert_str_eq(s.str, "HelloWorld");
    string_destroy(&s);
    string_destroy(&ap);
}

Test (test_append_s_null_value, test5)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello");
    string_init(&ap, "World");
    s.append_s(&s, NULL);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
    string_destroy(&ap);
}

Test (test_append_s_null_value_bis, test5)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello");
    string_init(&ap, "World");
    s.append_s(NULL, &s);
    cr_assert_str_eq(s.str, "Hello");
    string_destroy(&s);
    string_destroy(&ap);
}

/*-------- at ---------*/

Test (test_do_at, test6)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.at(&s, 1), 'e');
    string_destroy(&s);
}

Test (test_do_at_invalid_args, test7)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.at(&s, 40), -1);
    string_destroy(&s);
}

Test (test_do_at_null_args, test7)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.at(NULL, 40), -1);
    string_destroy(&s);
}

/*-------- insert_c ---------*/

Test (test_insert_c, test)
{
    string_t s;

    string_init(&s, "Hello");
    s.insert_c(&s, 50, "TOTO");
    cr_assert_str_eq(s.str, "HelloTOTO");
}

Test (test_insert_c_2, test)
{
    string_t s;

    string_init(&s, "Hello");
    s.insert_c(&s, 0, "TOTO");
    cr_assert_str_eq(s.str, "TOTOHello");
}

Test (test_insert_c_3, test)
{
    string_t s;

    string_init(&s, "Hello");
    s.insert_c(&s, 1, "TOTO");
    cr_assert_str_eq(s.str, "HTOTOello");
}

Test (test_insert_c_null_value, test)
{
    string_t s;

    string_init(&s, "Hello");
    s.insert_c(NULL, 1, "TOTO");
    cr_assert_str_eq(s.str, "Hello");
}

Test (test_insert_c_null_value_2, test)
{
    string_t s;

    string_init(&s, "Hello");
    s.insert_c(&s, 1, NULL);
    cr_assert_str_eq(s.str, "Hello");
}

/*-------- insert_c ---------*/

Test (test_insert_s, test)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello");
    string_init(&ap, "TOTO");
    s.insert_s(&s, 50, &ap);
    cr_assert_str_eq(s.str, "HelloTOTO");
}

/*-------- print ---------*/

Test (test_print, test, .init=redirect_all_std)
{
    string_t s;

    string_init(&s, "Hello World");
    s.print(&s);
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello World");
    string_destroy(&s);
}

/*-------- split ---------*/

Test (test_split_c, test)
{
    string_t s;
    char *array[4] = {"Hello", "World", "Marius", NULL};

    string_init(&s, "Hello World Marius");
    char **tab = s.split_c(&s, ' ');
    for (int i = 0; array[i] != NULL; i++)
        cr_assert_str_eq(array[i], tab[i]);
    string_destroy(&s);
}

/*-------- copy ---------*/

Test (test_copy, test, .init=redirect_all_std)
{
    string_t s;
    char *str = strdup("COCO");

    string_init(&s, "Hello");
    s.copy(&s, str, 2, 2);
    cr_assert_str_eq(str, "llCO");
    string_destroy(&s);
    free(str);
}

Test (test_copy_null_value, test, .init=redirect_all_std)
{
    string_t s;
    char *str = strdup("COCO");

    string_init(&s, "Hello");
    s.copy(NULL, str, 2, 2);
    cr_assert_str_eq(str, "COCO");
    string_destroy(&s);
    free(str);
}

Test (test_copy_null_value_2, test, .init=redirect_all_std)
{
    string_t s;
    char *str = NULL;

    string_init(&s, "Hello");
    s.copy(&s, str, 2, 2);
    cr_assert_null(str);
    string_destroy(&s);
    free(str);
}
