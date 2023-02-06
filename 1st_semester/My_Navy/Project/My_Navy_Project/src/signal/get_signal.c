/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "protos_struct.h"
#include "info_class.h"
#include "macros_error.h"
#include "protos.h"

extern info_t game;

navy_t *verif_input(char *line, navy_t *navy)
{
    char letter[] = "xxx";
    char nb[] = "aaa";
    if ((line[0] >= 'A' && line[0] <= 'H') &&
    (line[1] >= '1' && line[1] <= '8') && (line[2] == '\n')) {
        navy->letter_attack = line[0] - 65;
        navy->nb_attack = line[1] - '1';
        int_to_binary_string(navy->letter_attack, letter);
        int_to_binary_string(navy->nb_attack, nb);
        navy->attack = strcat_bis(letter, nb);
        navy->recive = 1;
    } else {
        my_printf("Wrong position");
    }
    return navy;
}

navy_t *recup_input(navy_t *navy)
{
    char *line;
    size_t len = 0;
    ssize_t nread;
    if ((nread = (getline(&line, &len, stdin) != -1))) {
        navy = verif_input(line, navy);
    }
    return navy;
}

navy_t *launch_attack(navy_t *navy)
{
    navy->recive = 0;
    while (navy->recive == 0) {
        my_printf("\nattack: ");
        navy = recup_input(navy);
    }
    navy = shoot(navy);
    return navy;
}
