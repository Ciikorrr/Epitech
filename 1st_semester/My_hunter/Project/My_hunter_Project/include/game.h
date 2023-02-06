/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-marius.marolleau
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "struct.h"

void num(game_t *game_start, player_t *player);
void score(game_t *game_start, player_t *player);
void life(game_t *game_start, player_t *player);
void respawn(game_t *game_start, bird_t *bird, player_t *player);
int finish(player_t *player, game_t *game_start, bird_t *bird);
int error_handling(const char *const *env);
sfSprite *create_sprite(sfTexture *texture);
void move_rect(sfIntRect *rect, int offset, int max_value);
void clock_sprite(game_t *game_start, bird_t *bird);

#endif /* !GAME_H_ */
