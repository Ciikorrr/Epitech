/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
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

void score(game_t *game_start, player_t *player)
{
    game_start->text = sfText_create();
    game_start->font = sfFont_createFromFile
    ("ressources/nasalization-rg.otf");
    sfText_setFont(game_start->text, game_start->font);
    sfText_setString(game_start->text, "Score :");
    sfText_setCharacterSize(game_start->text, 80);
    sfText_setColor(game_start->text, sfBlack);
    sfText_setPosition(game_start->text, game_start->pos_text);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

void respawn(game_t *game_start, bird_t *bird, player_t *player)
{
    bird->pos = sfSprite_getPosition(bird->sprite);
    if (bird->pos.x == 1280) {
        bird->pos.x = -110;
        bird->pos.y = rand() % 740;
        player->life -= 1;
        if (player->life <= 0) {
            finish(player, game_start, bird);
        }
        sfSprite_setPosition(bird->sprite, bird->pos);
    }
}

void display_window(game_t *game_start, bird_t *bird, player_t *player)
{
    while (sfRenderWindow_isOpen(game_start->window)) {
        clock_sprite(game_start, bird);
        sfSprite_setTextureRect(bird->sprite, game_start->rect);
        sfRenderWindow_drawSprite(game_start->window, game_start->sprite, NULL);
        sfRenderWindow_drawSprite(game_start->window, bird->sprite, NULL);
        sfRenderWindow_drawSprite(game_start->window,
        game_start->sprite_coeur, NULL);
        sfSprite_setPosition(game_start->sprite_coeur, game_start->pos_coeur);
        score(game_start, player);
        num(game_start, player);
        sfRenderWindow_drawText(game_start->window, game_start->text, NULL);
        sfRenderWindow_drawText(game_start->window,game_start->text_score,NULL);
        life(game_start, player);
        sfRenderWindow_drawText(game_start->window,game_start->text_coeur,NULL);
        sfRenderWindow_display(game_start->window);
        sfSprite_move(bird->sprite, bird->offset);
        respawn(game_start, bird, player);
        sfRenderWindow_clear(game_start->window, sfBlack);
        analyse_events(game_start, game_start->event, bird, player);
    }
}
