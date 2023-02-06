/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stddef.h>
#include <stdio.h>
#include "protos_struct.h"
#include "macros_error.h"

int compare_char_for_lose(navy_t *navy, int count, int i, int j)
{
    if (navy->map[i][j] >= '2' && navy->map[i][j] <= '5') {
        count += 1;
    }
    return count;
}

navy_t *check_lose(navy_t *navy)
{
    int count = 0;

    for (int i = 0; navy->map[i] != NULL; i += 1) {
        for (int j = 0; navy->map[i][j] != '\0'; j += 1) {
            count = compare_char_for_lose(navy, count,i, j);
        }
    }
    if (count > 0) {
        navy->win = -1;
    } else {
        navy->win = 0;
    }
    return navy;
}

int compare_char_for_win(navy_t *navy, int count, int i, int j)
{
    if (navy->enemy_map[i][j] == 'x')
        count += 1;
    return count;
}

navy_t *check_win(navy_t *navy)
{
    int count = 0;

    for (int i = 0; navy->enemy_map[i] != NULL; i += 1) {
        for (int j = 0; navy->enemy_map[i][j] != '\0'; j += 1) {
            count = compare_char_for_win(navy, count, i, j);
        }
    }
    if (count == 14)
        navy->win = 1;
    return navy;
}
