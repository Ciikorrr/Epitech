/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** menu
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "struct.h"
#include "macros.h"
#include <stdlib.h>
#include "event.h"
#include "game.h"
#include "display.h"

void analyse_events_menu(game_t *game_start, sfEvent event,
bird_t *bird, player_t *player)
{
    while (sfRenderWindow_pollEvent(game_start->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            manage_mouse_click_menu(event.mouseButton, bird, player,
            game_start);
        }
        if (event.type == sfEvtClosed) {
            close_window(game_start->window, event);
        }
    }
}

void display_menu(game_t *game_start, bird_t *bird, player_t *player)
{
    while (sfRenderWindow_isOpen(game_start->window)) {
        game_start->text_title = sfText_create();
        game_start->font = sfFont_createFromFile
        ("ressources/nasalization-rg.otf");
        sfText_setFont(game_start->text_title, game_start->font);
        sfText_setString(game_start->text_title, "DUCK HUNT");
        sfText_setCharacterSize(game_start->text_title, 75);
        sfText_setColor(game_start->text_title, sfBlack);
        sfText_setPosition(game_start->text_title, game_start->pos_title);
        sfRenderWindow_drawSprite(game_start->window, game_start->sprite, NULL);
        sfRenderWindow_drawSprite
        (game_start->window, game_start->sprite_play, NULL);
        sfRenderWindow_drawText(game_start->window,
        game_start->text_title, NULL);
        sfSprite_setPosition(game_start->sprite_play, game_start->pos_play);
        sfRenderWindow_display(game_start->window);
        analyse_events_menu(game_start, game_start->event, bird, player);
    }
}
