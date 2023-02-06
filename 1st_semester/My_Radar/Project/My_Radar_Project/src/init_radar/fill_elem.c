/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** fill_tab
*/

#include "protos.h"

plane_t *fill_coo(plane_t *aircraft, char **tab, int i)
{
    aircraft->start.x = my_getnbr(tab[i + 1]);
    aircraft->start.y = my_getnbr(tab[i + 2]);
    aircraft->landing.x = my_getnbr(tab[i + 3]);
    aircraft->landing.y = my_getnbr(tab[i + 4]);
    aircraft->speed = my_getnbr(tab[i + 5]);
    aircraft->delay = my_getnbr(tab[i + 6]);
    return aircraft;
}

plane_t *fill_plane(char **tab, int i)
{
    plane_t *aircraft = malloc(sizeof(plane_t));
    aircraft->plane = sfTexture_createFromFile("assets/plane.png", NULL);
    aircraft->aircraft = create_sprite(aircraft->plane);
    aircraft = fill_coo(aircraft, tab, i);
    aircraft->check = 0;
    aircraft->heigth_rec = 20;
    aircraft->width_rec = 20;
    aircraft->alpha = atan2f((aircraft->landing.y - aircraft->start.y),
    (aircraft->landing.x - aircraft->start.x));
    aircraft->offset.x = aircraft->landing.x - aircraft->start.x;
    aircraft->offset.y = aircraft->landing.y - aircraft->start.y;
    aircraft->distance = sqrtf(aircraft->offset.x * aircraft->offset.x +
    aircraft->offset.y * aircraft->offset.y);
    aircraft->second = aircraft->distance / aircraft->speed * 60;
    aircraft->movement.x = aircraft->offset.x / aircraft->second;
    aircraft->movement.y = aircraft->offset.y / aircraft->second;
    return aircraft;
}

tower_t *fill_tower(char **tab, int i)
{
    tower_t *tower = malloc(sizeof(tower_t));
    tower->towers = sfTexture_createFromFile("assets/tower.png", NULL);
    tower->control = create_sprite(tower->towers);
    tower->pos.x = my_getnbr(tab[i + 1]);
    tower->pos.y = my_getnbr(tab[i + 2]);
    tower->radius = my_getnbr(tab[i + 3]);
    return tower;
}

game_t *fill_tab(char **tab, game_t *game)
{
    int p = 0;
    int t = 0;
    for (int i = 0; tab[i] != NULL; i += 1) {
        if (tab[i][0] == 'A') {
            game->tab_plane[p] = fill_plane(tab, i);
            game->tab_plane[p] = set_all_plane(game, p);
            game->tab_plane[p + 1] = NULL;
            p += 1;
        }
        if (tab[i][0] == 'T') {
            game->tab_tower[t] = fill_tower(tab, i);
            game->tab_tower[t] = set_all_tower(game, t);
            game->tab_tower[t + 1] = NULL;
            t += 1;
        }
    }
    return game;
}
