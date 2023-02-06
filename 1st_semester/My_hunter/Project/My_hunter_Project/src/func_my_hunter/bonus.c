/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** bootstrap
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include "event.h"
#include "game.h"
#include "display.h"

void manage_mouse_click(sfMouseButtonEvent event, bird_t *bird,
player_t *player, game_t *game_start)
{
    game_start->pos_play = sfSprite_getPosition(bird->sprite);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.x <= bird->pos.x + 120 && event.x >= bird->pos.x
        && event.y <= bird->pos.y + 120 && event.y >= bird->pos.y) {
            bird->pos.x = -110;
            bird->pos.y = rand() % 740;
            player->score += 1;
            sfSprite_setPosition(bird->sprite, bird->pos);
        } else {
            player->life -= 1;
            finish(player, game_start, bird);
        }
    }
}

void manage_mouse_click_menu(sfMouseButtonEvent event, bird_t *bird,
player_t *player, game_t *game_start)
{
    game_start->pos_play = sfSprite_getPosition(game_start->sprite_play);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.x <= game_start->pos_play.x + 300 &&
        event.x >= game_start->pos_play.x - 100
        && event.y <= game_start->pos_play.y + 190 &&
        event.y >= game_start->pos_play.y + 100) {
            game_start->etat = 1;
        }
        if (game_start->etat == 1) {
            display_window(game_start, bird, player);
        }
    }
}

int close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (SUCCESS_EPITECH);
    }
}

int analyse_events(game_t *game_start, sfEvent event,
bird_t *bird, player_t *player)
{
    while (sfRenderWindow_pollEvent(game_start->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            manage_mouse_click(event.mouseButton, bird, player, game_start);
        }
        if (event.type == sfEvtClosed) {
            close_window(game_start->window, event);
            return (SUCCESS_EPITECH);
        }
    }
}

int finish(player_t *player, game_t *game_start, bird_t *bird)
{
    if (player->life <= 0) {
        while (sfRenderWindow_isOpen(game_start->window)) {
            sfRenderWindow_drawSprite
            (game_start->window, game_start->sprite, NULL);
            sfRenderWindow_drawSprite
            (game_start->window, player->game_over, NULL);
            sfSprite_setPosition(player->game_over, player->pos_over);
            sfRenderWindow_display(game_start->window);
            analyse_events(game_start, game_start->event, bird, player);
        }
    }
    return (SUCCESS_EPITECH);
}
