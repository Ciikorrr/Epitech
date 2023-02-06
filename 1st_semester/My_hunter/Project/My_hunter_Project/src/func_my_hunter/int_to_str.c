/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-marius.marolleau
** File description:
** test
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "struct.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>
#include "event.h"
#include "game.h"
#include "display.h"

char *int_to_str(int nb)
{
    int count = nb;
    int temp = nb;
    int len = 0;
    while (count > 0) {
        count = count / 10;
        len += 1;
    }
    char *c = malloc(sizeof(char) * len + 1);
    int i = len - 1;
    while (nb > 0) {
        temp = temp % 10;
        nb = nb / 10;
        c[i] = temp + 48;
        i -= 1;
        temp = nb;
    }
    c[len] = '\0';
    return c;
}

void num(game_t *game_start, player_t *player)
{
    char *score = int_to_str(player->score);
    game_start->text_score = sfText_create();
    sfText_setFont(game_start->text_score, game_start->font);
    sfText_setString(game_start->text_score, score);
    sfText_setCharacterSize(game_start->text_score, 80);
    sfText_setColor(game_start->text_score, sfBlack);
    sfText_setPosition(game_start->text_score, game_start->pos_score);
}

void life(game_t *game_start, player_t *player)
{
    char *coeur = int_to_str(player->life);
    game_start->text_coeur = sfText_create();
    sfText_setFont(game_start->text_coeur, game_start->font);
    sfText_setString(game_start->text_coeur, coeur);
    sfText_setCharacterSize(game_start->text_coeur, 80);
    sfText_setColor(game_start->text_coeur, sfBlack);
    sfText_setPosition(game_start->text_coeur, game_start->pos_heal);
}

void clock_sprite(game_t *game_start, bird_t *bird)
{
    game_start->time = sfClock_getElapsedTime(game_start->clock);
        game_start->seconde = game_start->time.microseconds / 1000000.0;
        if (game_start->seconde > 0.2) {
            move_rect(&game_start->rect, 110, 330);
            sfClock_restart(game_start->clock);
        }
}
