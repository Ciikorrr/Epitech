/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main
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

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    if (player == NULL) {
        return NULL;
    }
    player->best_score = 0;
    player->life = 3;
    player->score = 0;
    player->texture_over = sfTexture_createFromFile
    ("ressources/game_over.png", NULL);
    if (player->texture_over == NULL) {
        return NULL;
    }
    player->game_over = create_sprite(player->texture_over);
    player->pos_over = (sfVector2f){525, 300};
    return player;
}

void init(game_t *game_start)
{
    game_start->pos_play = (sfVector2f){430, 450};
    game_start->pos_title = (sfVector2f){430, 100};
    game_start->pos_score = (sfVector2f){600, 800};
    game_start->pos_heal = (sfVector2f){140, 800};
    game_start->pos_coeur = (sfVector2f){10, 800};
}

game_t *init_game_start(void)
{
    game_t *game_start = malloc(sizeof(game_t));
    if (game_start == NULL)
        return NULL;
    init_window(game_start);
    game_start->texture = sfTexture_createFromFile(PAYSAGE, NULL);
    if (game_start->texture == NULL)
        return NULL;
    game_start->sprite = create_sprite(game_start->texture);
    game_start->pos_text = (sfVector2f){300, 800};
    game_start->texture_play = sfTexture_createFromFile(BUTTON, NULL);
    if (game_start->texture_play == NULL)
        return NULL;
    game_start->sprite_play = create_sprite(game_start->texture_play);
    game_start->texture_coeur = sfTexture_createFromFile(HEART, NULL);
    if (game_start->texture_coeur == NULL)
        return NULL;
    game_start->sprite_coeur = create_sprite(game_start->texture_coeur);
    init(game_start);
    game_start->etat = 0;
}

bird_t *init_bird(void)
{
    bird_t *bird = malloc(sizeof(bird_t));
    if (bird == NULL) {
        return NULL;
    }
    bird->texture = sfTexture_createFromFile("ressources/canard.png", NULL);
    if (bird->texture == NULL)
        return NULL;
    bird->sprite = create_sprite(bird->texture);
    bird->pos = (sfVector2f){0, 0};
    bird->offset.x = 0.5;
    return bird;
}

int main(int argc, char **argv, const char *const *env)
{
    int error = error_handling(env);
    if (error == 0)
        return ERROR_EPITECH;
    if (description(argc, argv) == 0)
        return SUCCESS_EPITECH;
    if (argc == 1) {
        game_t *game_start = init_game_start();
        if (game_start == NULL)
            return ERROR_EPITECH;
        bird_t *bird = init_bird();
        if (bird == NULL)
            return ERROR_EPITECH;
        player_t *player = init_player();
        if (player == NULL)
            return ERROR_EPITECH;
        etat_menu(game_start, bird, player);
    } else
        return (ERROR_EPITECH);
    return (SUCCESS_EPITECH);
}
