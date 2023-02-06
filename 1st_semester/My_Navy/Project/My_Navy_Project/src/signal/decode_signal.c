/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include "protos_struct.h"
#include "info_class.h"
#include "protos_game.h"
#include "protos.h"

extern info_t game;

navy_t *decode_signal(navy_t *navy)
{
    game.hit = 0;
    char *coord = receive_signal();
    char letter[4] = {coord[0], coord[1], coord[2], '\0'};
    char num[4] = {coord[3], coord[4], coord[5], '\0'};
    int letter1 = bin_to_dec(letter);
    int num1 = bin_to_dec(num);

    if (navy->map[num1][letter1] >= '2' && navy->map[num1][letter1] <= '5') {
        navy->map[num1][letter1] = 'x';
        game.hit = 1;
    } else {
        navy->map[num1][letter1] = 'o';
        game.hit = 0;
    }
    display(letter1, num1);
    hit_or_not();
    navy->attack = malloc(sizeof(char) * 2);
    navy->attack[0] = (letter1 + 65);
    navy->attack[1] = num1 + '1';
    navy->attack[2] = '\0';
    return navy;
}
