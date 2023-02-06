/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/
#include "protos_struct.h"

#ifndef LIBNAVY_H_
    #define LIBNAVY_H_
    int end_game(navy_t *navy);
    int game_loop_two(navy_t *navy);
    int game_loop_one(navy_t *navy);
    int player_two(navy_t *navy, char **argv);
    int player_one(navy_t *navy, char **argv);
    int launch_game_loop(int argc, char **argv);
    int compare_char_for_lose(navy_t *navy, int count, int i, int j);
    navy_t *check_lose(navy_t *navy);
    int compare_char_for_win(navy_t *navy, int count, int i, int j);
    navy_t *check_win(navy_t *navy);

#endif /* LIBNAVY_H_*/
