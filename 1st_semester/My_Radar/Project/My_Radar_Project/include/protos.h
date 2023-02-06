/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** protos
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "macros.h"
#include "my.h"

#ifndef PROTOS_H_
    #define PROTOS_H_

/* Protos init radar */

    sfSprite *create_sprite(sfTexture *texture);
    game_t *init_game(game_t *game);
    game_t *get_info(int argc, char **argv, game_t *game);
    plane_t *fill_plane(char **tab, int i);
    tower_t *fill_tower(char **tab, int i);
    game_t *fill_tab(char **tab, game_t *game);
    plane_t *set_all_plane(game_t *game, int i);
    tower_t *set_all_tower(game_t *game, int i);
    char *file_to_str(char const *filepath);
    int biggest_line(char const *str);
    int next_index(char const *str, int i);
    int nb_char(char const *str, int index);
    int get_line(char const *file);
    int get_col(char const *file);
    char **my_str_to_word_array(char *str);

/* Protos action during radar*/

    game_t *draw_plane(game_t *game, int i);
    game_t *draw_tower(game_t *game);
    int start_radar(game_t *game);
    void draw_sprite(game_t *game);
    void all_check_collisions(game_t *game);
    int check_collision(sfRectangleShape *plane1, sfRectangleShape *plane2);
    int close_window(sfRenderWindow *window, sfEvent event);
    void clock_sprite(game_t *game);
    int my_getnbr(char const *str);
    int hide_sprite(game_t *game, sfEvent event);
    int hide_hitbox(game_t *game, sfEvent event);
    int is_controled(game_t *game, int i);
    int analyse_events(sfRenderWindow *window, sfEvent event, game_t *game);
    int event_button_pressed(game_t *game, sfEvent event);
    int check_finish(game_t *game);
    void free_all(game_t *game);

/* Protos error handling*/

    int error_handling(const char *const *env);
    int description(int argc, char **argv);
    int check_assets(game_t *game);
    int check_arg(int argc, char **argv, const char *const *env);
    int check_char_plane(char **tab, int i, int res);
    int check_char_tower(char **tab, int i, int res);
    int check_script(char **argv);
#endif /* !PROTOS_H_ */
