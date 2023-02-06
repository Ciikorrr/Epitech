/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** window
*/
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include "protos.h"

int close_window(sfRenderWindow *window, sfEvent event)
{
    sfRenderWindow_close(window);
    return (SUCCESS_EPITECH);
}

int hide_hitbox(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyS) {
        if (game->hide_hitbox == 0) {
            game->hide_hitbox = 1;
            return SUCCESS_EPITECH;
        }
        if (game->hide_hitbox == 1) {
            game->hide_hitbox = 0;
            return SUCCESS_EPITECH;
        }
    }
}

int hide_sprite(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyL) {
        if (game->hide_sprite == 0) {
            game->hide_sprite = 1;
            return SUCCESS_EPITECH;
        }
        if (game->hide_sprite == 1) {
            game->hide_sprite = 0;
            return SUCCESS_EPITECH;
        }
    }
}

int analyse_events(sfRenderWindow *window, sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyQ
        || event.key.code == sfKeyEscape) {
            close_window(window, event);
            return SUCCESS_EPITECH;
        }
        if (event.type == sfEvtKeyPressed) {
            event_button_pressed(game, event);
        }
    }
}

int start_radar(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        clock_sprite(game);
        all_check_collisions(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->background, NULL);
        draw_sprite(game);
        sfRenderWindow_display(game->window);
        analyse_events(game->window, game->event, game);
        if (check_finish(game) == SUCCESS_EPITECH) {
            free_all(game);
            return SUCCESS_EPITECH;
        }
    }
    return SUCCESS_EPITECH;
}
