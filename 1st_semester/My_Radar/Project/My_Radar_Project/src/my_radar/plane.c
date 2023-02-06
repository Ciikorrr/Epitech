/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** plane
*/
#include "protos.h"
#include <math.h>
game_t *draw_plane(game_t *game, int i)
{
    if (game->second >= game->tab_plane[i]->delay) {
        sfSprite_move(game->tab_plane[i]->aircraft,
        game->tab_plane[i]->movement);
        game->tab_plane[i]->second -= 1;
        sfRectangleShape_move(game->tab_plane[i]->rect,
        game->tab_plane[i]->movement);
        if (game->hide_sprite == 0)
            sfRenderWindow_drawSprite(game->window,
            game->tab_plane[i]->aircraft, NULL);
        if (game->hide_hitbox == 0)
            sfRenderWindow_drawRectangleShape(game->window,
            game->tab_plane[i]->rect, NULL);
    }
    return game;
}

plane_t *set_all_plane(game_t *game, int i)
{
    game->tab_plane[i]->rect = sfRectangleShape_create();
    sfSprite_scale(game->tab_plane[i]->aircraft, (sfVector2f){0.07, 0.078});
    sfSprite_setOrigin(game->tab_plane[i]->aircraft,
    (sfVector2f){285 / 2, 285 / 2});
    sfSprite_setPosition(game->tab_plane[i]->aircraft,
    game->tab_plane[i]->start);

    sfRectangleShape_setFillColor(game->tab_plane[i]->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(game->tab_plane[i]->rect, sfRed);
    sfRectangleShape_setOutlineThickness(game->tab_plane[i]->rect, 1.0);
    sfRectangleShape_setOrigin(game->tab_plane[i]->rect, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(game->tab_plane[i]->rect,
    game->tab_plane[i]->start);
    sfSprite_setRotation(game->tab_plane[i]->aircraft,
    (game->tab_plane[i]->alpha * 180 / M_PI));
    sfRectangleShape_setSize(game->tab_plane[i]->rect, (sfVector2f){20, 20});
    return game->tab_plane[i];
}

int check_finish(game_t *game)
{
    int count = 0;
    for (int i = 0; game->tab_plane[i] != NULL; i += 1) {
        if (game->tab_plane[i]->check == 1) {
            count += 1;
        }
    }
    if (count == game->nb_plane)
        return SUCCESS_EPITECH;
}

void clock_sprite(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds / 1000000.0;
}
