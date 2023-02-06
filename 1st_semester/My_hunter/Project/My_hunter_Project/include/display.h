/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-marius.marolleau
** File description:
** display
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
        #include "struct.h"

void display_window(game_t *game_start, bird_t *bird, player_t *player);
void display_menu(game_t *game_start, bird_t *bird, player_t *player);
void display_desc(void);

#endif /* !DISPLAY_H_ */
