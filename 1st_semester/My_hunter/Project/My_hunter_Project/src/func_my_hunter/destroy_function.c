/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-marius.marolleau
** File description:
** destoy_function
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

void destroy_text(game_t *game_start, bird_t *bird, player_t *player)
{
    sfText_destroy(game_start->text);
    sfText_destroy(game_start->text_coeur);
    sfText_destroy(game_start->text_score);
    sfText_destroy(game_start->text_title);
}

void destroy_sprite(game_t *game_start, bird_t *bird, player_t *player)
{
    sfSprite_destroy(game_start->sprite);
    sfSprite_destroy(game_start->sprite_coeur);
    sfSprite_destroy(game_start->sprite_play);
    sfSprite_destroy(bird->sprite);
    sfSprite_destroy(player->game_over);
}

void destroy_texture(game_t *game_start, bird_t *bird, player_t *player)
{
    sfTexture_destroy(game_start->texture);
    sfTexture_destroy(game_start->texture_coeur);
    sfTexture_destroy(game_start->texture_play);
    sfTexture_destroy(bird->texture);
    sfTexture_destroy(player->texture_over);
}

void destroy_all(game_t *game_start, bird_t *bird, player_t *player)
{
    sfClock_destroy(game_start->clock);
    sfRenderWindow_destroy(game_start->window);
    destroy_sprite(game_start, bird, player);
    destroy_text(game_start, bird, player);
    destroy_texture(game_start, bird, player);
}
