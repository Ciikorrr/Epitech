/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** init_struct
*/
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include "protos.h"

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

game_t *init_game(game_t *game)
{
    game = malloc(sizeof(game_t));
    if (game == NULL)
        return NULL;
    game->clock = sfClock_create();
    game->mode.bitsPerPixel = 32;
    game->mode.width = 1920;
    game->mode.height = 1080;
    game->hide_sprite = 0;
    game->hide_hitbox = 0;
    game->window = sfRenderWindow_create(game->mode, "SFML Window"
    , sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->map = sfTexture_createFromFile("assets/map.jpg", NULL);
    if (game->map == NULL)
        return NULL;
    game->background = create_sprite(game->map);
    return game;
}

int event_button_pressed(game_t *game, sfEvent event)
{
    if (hide_hitbox(game, event) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    if (hide_sprite(game, event) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
}
