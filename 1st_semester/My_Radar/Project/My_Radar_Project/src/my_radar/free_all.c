/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** free
*/
#include "protos.h"

void free_plane(game_t *game)
{
    for (int i = 0; game->tab_plane[i] != NULL; i += 1) {
        sfSprite_destroy(game->tab_plane[i]->aircraft);
        sfTexture_destroy(game->tab_plane[i]->plane);
        sfRectangleShape_destroy(game->tab_plane[i]->rect);
    }
}

void free_tower(game_t *game)
{
    for (int i = 0; game->tab_tower[i] != NULL; i += 1) {
        sfSprite_destroy(game->tab_tower[i]->control);
        sfTexture_destroy(game->tab_tower[i]->towers);
        sfCircleShape_destroy(game->tab_tower[i]->circle);
    }
}

void free_tab(game_t *game)
{
    for (int i = 0; game->tab_plane[i] != NULL; i += 1) {
        free(game->tab_plane[i]);
    }
    for (int j = 0; game->tab_tower[j] != NULL; j += 1) {
        free(game->tab_tower[j]);
    }
}

void free_struct(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    sfSprite_destroy(game->background);
    sfTexture_destroy(game->map);
    free(game->tab_plane);
    free(game->tab_tower);
}

void free_all(game_t *game)
{
    free_plane(game);
    free_tower(game);
    free_tab(game);
    free_struct(game);
    free(game);
}
