/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** protos
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "struct.h"
    #include "macros.h"

void analyse_events_menu(game_t *game_start, sfEvent event,
bird_t *bird, player_t *player);
int analyse_events(game_t *game_start, sfEvent event,
bird_t *bird, player_t *player);
void manage_mouse_click(sfMouseButtonEvent event, bird_t *bird,
player_t *player, game_t *game_start);
void manage_mouse_click_menu(sfMouseButtonEvent event, bird_t *bird,
player_t *player, game_t *game_start);
int close_window(sfRenderWindow *window, sfEvent event);
void destroy_all(game_t *game_start, bird_t *bird, player_t *player);
void init_window(game_t *game_start);
void etat_menu(game_t *game_start, bird_t *bird, player_t *player);
int description(int argc, char **argv);


#endif /* !EVENT_H_ */
