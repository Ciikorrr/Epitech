/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "protos_map.h"
#include "libmap.h"
#include "libnavy.h"
#include "libsignal.h"

/* TEST file */

Test (error_file_false_1, test1) {
    int result = check_file("tests/adam");
    cr_assert_eq(result, 84);
}

Test (error_file_false_2, test1) {
    int result = check_file("");
    cr_assert_eq(result, 84);
}

Test (error_file_false_3, test1) {
    int result = check_file("pos3");
    cr_assert_eq(result, 84);
}

Test (error_file_false_4, test1) {
    int result = check_file(NULL);
    cr_assert_eq(result, 84);
}

Test (error_file_false_5, test1) {
    int result = check_file_bis("tests/error");
    cr_assert_eq(result, 84);
}

/* TEST pid */

Test (error_pid_true, test1) {
    int result = check_pid("15522");
    cr_assert_eq(result, 0);
}

Test (error_pid_false, test1) {
    int result = check_pid("15A22");
    cr_assert_eq(result, 84);
}

Test (error_pid_false_2, test1) {
    int result = check_pid(NULL);
    cr_assert_eq(result, 84);
}

/* TEST check args */

Test (check_args_2, test1) {
    char *tab[2] = {"./a.out", "src/test_files/pos1"};
    int result = check_args(2, tab);
    cr_assert_eq(result, 0);
}

Test (check_args_2_bis, test1) {
    char *tab[2] = {"./a.out", "src/test_files/pos"};
    int result = check_args(2, tab);
    cr_assert_eq(result, 84);
}

Test (check_args_3, test1) {
    char *tab[3] = {"./a.out", "1524a", "src/test_files/pos1"};
    int result = check_args(3, tab);
    cr_assert_eq(result, 84);
}

Test (check_args_3_bis, test1) {
    char *tab[3] = {"./a.out", "15247", "src/test_files/pos1"};
    int result = check_args(3, tab);
    cr_assert_eq(result, 0);
}

Test (check_args_3_third, test1) {
    char *tab[3] = {"./a.out", "15247", "src/test_files/pos"};
    int result = check_args(3, tab);
    cr_assert_eq(result, 84);
}

Test (check_args_nb_argc, test1) {
    char *tab[3] = {"./a.out"};
    int result = check_args(1, tab);
    cr_assert_eq(result, 84);
}

/* TEST do_error_handling */

Test (do_error_handling_1, test1) {
    char *tab[3] = {"./a.out", "15247", "src/test_files/pos"};
    int result = do_error_handling(3, tab);
    cr_assert_eq(result, 84);
}

Test (do_error_handling_2, test1) {
    char *tab[3] = {"./a.out", "15247", "src/test_files/pos1"};
    int result = do_error_handling(3, tab);
    cr_assert_eq(result, 0);
}

/* TEST check_direction */

Test (check_direct_pos_1, test1) {
    int result = check_direction("2:C4:D4");
    cr_assert_eq(result, 1);
}

Test (check_direct_neg_1, test1) {
    int result = check_direction("2:D4:C4");
    cr_assert_eq(result, -1);
}

Test (check_direct_pos_2, test1) {
    int result = check_direction("2:D3:D4");
    cr_assert_eq(result, 1);
}

Test (check_direct_neg_2, test1) {
    int result = check_direction("2:D4:D3");
    cr_assert_eq(result, -1);
}

/*TEST on char*/

Test (num_char_false, test1) {
    int result = check_num("Marius", 1);
    cr_assert_eq(result, 84);
}

Test (num_char_true, test1) {
    int result = check_num("M1arius", 1);
    cr_assert_eq(result, 0);
}

Test (alpha_char_false, test1) {
    int result = check_alpha("M1arius", 1);
    cr_assert_eq(result, 84);
}

Test (alpha_char_true, test1) {
    int result = check_alpha("AABBCC", 4);
    cr_assert_eq(result, 0);
}

Test (special_char_false, test1) {
    int result = check_special_caracters("!:", 0);
    cr_assert_eq(result, 84);
}

Test (special_char_true, test1) {
    int result = check_special_caracters(":\n", 0);
    cr_assert_eq(result, 0);
}

/*TEST on script syntaxe*/

Test (syntaxe_true, test1) {
    int result = check_syntaxe("2:C1:C2");
    cr_assert_eq(result, 0);
}

Test (syntaxe_false1, test1) {
    int result = check_syntaxe("9:C1:C2");
    cr_assert_eq(result, 84);
}

Test (syntaxe_false2, test1) {
    int result = check_syntaxe("2:K1:C2");
    cr_assert_eq(result, 84);
}

Test (syntaxe_false3, test1) {
    int result = check_syntaxe("9)C1:C2");
    cr_assert_eq(result, 84);
}

Test (syntaxe_false4, test1) {
    int result = check_syntaxe("2:C1/C2");
    cr_assert_eq(result, 84);
}

/* TEST on the number of boat*/

Test (nb_boat_true_1, test1) {
    char *line = "2:C1:C2";
    int size = 1;
    int res = check_nb_boat(line, size);
    cr_assert_eq(res, 0);
}

Test (nb_boat_true_2, test1) {
    char *line = "6:C1:C2";
    int size = 1;
    int res = check_nb_boat(line, size);
    cr_assert_eq(res, 84);
}

/* TEST on the position*/

Test (check_position_false_hard_1, test1) {
    int result = check_position("2:C5:D8");
    cr_assert_eq(result, 84);
}

Test (check_position_false_hard_2, test1) {
    int result = check_position("2:C5:C5");
    cr_assert_eq(result, 84);
}

Test (check_position_false_pos_direction_len_boat_1, test1) {
    int result = check_position("2:C5:C9");
    cr_assert_eq(result, 84);
}

Test (check_position_false_neg_direction_len_boat_1, test1) {
    int result = check_position("2:C9:C5");
    cr_assert_eq(result, 84);
}

Test (check_position_false_neg_direction_len_boat_2, test1) {
    int result = check_position("2:H5:A5");
    cr_assert_eq(result, 84);
}

Test (check_position_false_pos_direction_len_boat_2, test1) {
    int result = check_position("2:A5:D5");
    cr_assert_eq(result, 84);
}

/* TEST on the function error script*/

Test (erro_script_all_is_good, test1) {
    int result = error_script("2:A5:B5", 1);
    cr_assert_eq(result, 0);
}

Test (error_script_error_on_the_syntaxe, test1) {
    int result = error_script("9:A5:D5", 1);
    cr_assert_eq(result, 84);
}

Test (error_script_error_on_the_nb_boat, test1) {
    int result = error_script("4:A5:D5", 1);
    cr_assert_eq(result, 84);
}

Test (error_script_error_on_the_position, test1) {
    int result = error_script("2:A5:D5", 1);
    cr_assert_eq(result, 84);
}

/* TEST on the function check_*/

Test (error_script_error_on_the_direction_1, test1) {
    int result = check_correct_position_pos("2:D2:D3");
    cr_assert_eq(result, 0);
}

Test (error_script_error_on_the_direction_2, test1) {
    int result = check_correct_position_pos("2:D2:D3");
    cr_assert_eq(result, 0);
}

Test (error_script_error_on_the_direction_3, test1) {
    int result = check_correct_position_neg("1:D5:D1");
    cr_assert_eq(result, 84);
}

Test (error_script_error_on_the_direction_4, test1) {
    int result = check_correct_position_neg("1:D2:C2");
    cr_assert_eq(result, 84);
}

Test (error_script_error_on_the_direction_5, test1) {
    int result = check_correct_position_neg("2:D2:C2");
    cr_assert_eq(result, 0);
}
