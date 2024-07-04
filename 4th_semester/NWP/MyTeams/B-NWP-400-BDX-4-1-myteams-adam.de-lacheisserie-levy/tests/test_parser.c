/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** test_parser
*/
#include <criterion/criterion.h>
#include "../include/macros.h"
#include "../include/server.h"
#include "../include/client.h"
#include "../server/include/protos_srv.h"
#include "../client/include/protos_clt.h"

Test (my_check_args_srv_true, test1) {
    int argc = 2;
    char *argv[2] = {"./myteams_server", "4444"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, SUCCESS);
}

Test (my_check_args_srv_false_1, test1) {
    int argc = 2;
    char *argv[2] = {"./myteams_server", "100000"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_2, test1) {
    int argc = 3;
    char *argv[2] = {"./myteams_server", "4444"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_3, test1) {
    int argc = 2;
    char *argv[2] = {"./myteams_server", "80"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_4, test1) {
    int argc = 2;
    char *argv[2] = {"./myteams_server", "a"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_5, test1) {
    int argc = 2;
    char **argv = NULL;
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_6, test1) {
    int argc = 2;
    char *argv[1] = {"./myteams_server"};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (my_check_args_srv_false_7, test1) {
    int argc = 2;
    char *argv[1] = {NULL};
    int result = check_args_srv(argc, argv);

    cr_assert_eq(result, ERROR);
}

Test (string_is_num_true, test1) {
    int result = string_is_num("1234");

    cr_assert_eq(result, SUCCESS);
}


Test (string_is_num_false, test1) {
    int result = string_is_num("1a234");

    cr_assert_eq(result, ERROR);
}

Test (command_parser_true, test1) {
    char *tab[3] = {"marius", "toto", "hello world !"};
    char **tab2 = command_parser("\"marius\" toto \"hello world !\"", " \n");
    for (int i = 0; tab2[i]; i++) {
        cr_assert_str_eq(tab[i], tab2[i]);
    }
}

Test (command_parser_true_2, test1) {
    char *tab[3] = {"marius", "toto", "hello world !\n"};
    char **tab2 = command_parser("\"marius\" toto \"hello world !\"", " \n");
    for (int i = 0; tab2[i]; i++) {
        cr_assert_str_eq(tab[i], tab2[i]);
    }
}

Test (my_strcat_dup_true, test1) {
    char *result = my_strcat_dup("Hello", " ", "World");
    cr_assert_str_eq(result, "Hello World");
}

Test (my_strcat_dup_true_2, test1) {
    char *result = my_strcat_dup("Hello", " ", NULL);
    cr_assert_str_eq(result, "Hello ");
}

Test (my_strcat_dup_true_3, test1) {
    char *result = my_strcat_dup("Hello", NULL, NULL);
    cr_assert_str_eq(result, "Hello");
}

Test (my_strcat_dup_true_4, test1) {
    char *result = my_strcat_dup(NULL, "Hello", NULL);
    cr_assert_str_eq(result, "Hello");
}

Test (free_tab_false, test1) {
    cr_assert_eq(free_tab(NULL), 0);
}
