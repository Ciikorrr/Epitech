/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-marius.marolleau
** File description:
** functions_divers
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "struct.h"
#include "macros.h"
#include <stdlib.h>
#include "event.h"
#include "my.h"
#include "game.h"
#include "display.h"

void display_desc(void)
{
    my_putstr("This game is Duck Hunt\n\n");
    my_putstr("Click on PLAY for play\n");
    my_putstr("You needs to click on the duck for kill him\n");
}

int error_handling(const char *const *env)
{
    int count = 0;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp("DISPLAY=", env[i], 7) == 0) {
            count += 1;
        }
    }
    return count;
}

void init_window(game_t *game_start)
{
    game_start->rect = (sfIntRect){0, 0, 110, 110};
    game_start->mode = (sfVideoMode){1280, 905, 32};
    game_start->clock = sfClock_create();
    game_start->window = sfRenderWindow_create
    (game_start->mode, "SFML Window", sfResize | sfClose, NULL);
}

void etat_menu(game_t *game_start, bird_t *bird, player_t *player)
{
    display_menu(game_start, bird, player);
    if (game_start->etat == 1)
        display_window(game_start, bird, player);
        destroy_all(game_start, bird, player);
        free(game_start); free(bird); free(player);
}

int description(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            display_desc();
            return (SUCCESS_EPITECH);
        }
    }
}
