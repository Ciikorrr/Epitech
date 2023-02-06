/*
** EPITECH PROJECT, 2022
** Projet
** File description:
** set_position
*/

#include "protos.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

void draw_sprite(game_t *game)
{
    int check = 0;
    for (int i = 0; game->tab_plane[i] != NULL; i += 1) {
        if (game->tab_plane[i]->second <= 0) {
            game->tab_plane[i]->check = 1;
        }
        if (game->tab_plane[i]->check == 0) {
            game = draw_plane(game, i);
        }
    }
    game = draw_tower(game);
}

int check_collision(sfRectangleShape *plane1, sfRectangleShape *plane2)
{
    sfVector2f coo_plane1 = sfRectangleShape_getPosition(plane1);
    sfVector2f coo_plane2 = sfRectangleShape_getPosition(plane2);
    if ((coo_plane1.x < coo_plane2.x + 20 &&
    coo_plane1.x + 20 > coo_plane2.x && coo_plane1.y < coo_plane2.y + 20 &&
    20 + coo_plane1.y > coo_plane2.y)) {
        return -1;
    }
    return 0;
}

void compare(game_t *game, int i, int j)
{
    int res = 0;
    int control;
    if (j != i && game->tab_plane[i]->check != 1 &&
    game->tab_plane[j]->check != 1) {
        res = check_collision(game->tab_plane[i]->rect,
        game->tab_plane[j]->rect);
        control = is_controled(game, i);
    }
    if (res == -1 && control == 0) {
        game->tab_plane[i]->check = 1;
        game->tab_plane[j]->check = 1;
        return;
    }
}

void all_check_collisions(game_t *game)
{
    for (int i = 0; game->tab_plane[i] != NULL; i += 1) {
        for (int j = 0; game->tab_plane[j] != NULL; j += 1) {
            compare(game, i, j);
        }
    }
    return;
}
