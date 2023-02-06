/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** check_tower
*/
#include "protos.h"
game_t *draw_tower(game_t *game)
{
    for (int i = 0; game->tab_tower[i] != NULL; i += 1) {
        if (game->hide_sprite == 0)
            sfRenderWindow_drawSprite(game->window,
            game->tab_tower[i]->control, NULL);
        if (game->hide_hitbox == 0)
            sfRenderWindow_drawCircleShape(game->window,
            game->tab_tower[i]->circle, NULL);
    }
    return game;
}

tower_t *set_all_tower(game_t *game, int i)
{
    game->tab_tower[i]->circle = sfCircleShape_create();
    game->tab_tower[i]->radius = 1920 / 100 * game->tab_tower[i]->radius;
    sfCircleShape_setFillColor(game->tab_tower[i]->circle, sfTransparent);
    sfCircleShape_setRadius(game->tab_tower[i]->circle,
    game->tab_tower[i]->radius);
    sfCircleShape_setOrigin(game->tab_tower[i]->circle,
    (sfVector2f){game->tab_tower[i]->radius, game->tab_tower[i]->radius});
    sfCircleShape_setOutlineColor(game->tab_tower[i]->circle, sfGreen);
    sfCircleShape_setPosition(game->tab_tower[i]->circle,
    game->tab_tower[i]->pos);
    sfCircleShape_setOutlineThickness(game->tab_tower[i]->circle, 1.0);
    sfSprite_scale(game->tab_tower[i]->control, (sfVector2f){0.07, 0.078});
    sfSprite_setOrigin(game->tab_tower[i]->control,
    (sfVector2f){512 / 2, 512 / 2});
    sfSprite_setPosition(game->tab_tower[i]->control, game->tab_tower[i]->pos);
    return game->tab_tower[i];
}

int is_controled(game_t *game, int i)
{
    sfVector2f offset;
    float distance;
    game->tab_plane[i]->pos = sfRectangleShape_getPosition(
        game->tab_plane[i]->rect);
    for (int j = 0; game->tab_tower[j] != NULL; j += 1) {
        offset.x = game->tab_tower[j]->pos.x - game->tab_plane[i]->pos.x;
        offset.y = game->tab_tower[j]->pos.y - game->tab_plane[i]->pos.y;
        distance = sqrtf(offset.x * offset.x + offset.y * offset.y);
        if (distance < game->tab_tower[j]->radius) {
            return -1;
        }
    }
    return 0;
}
