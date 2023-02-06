/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct plane {
    sfVector2f movement;
    float second;
    sfVector2f offset;
    float distance;
    sfTexture *plane;
    sfSprite *aircraft;
    sfVector2f start;
    sfVector2f landing;
    sfRectangleShape *rect;
    int speed;
    int delay;
    int check;
    sfVector2f pos;
    int width_rec;
    int heigth_rec;
    float alpha;
}plane_t;

typedef struct tower {
    sfCircleShape *circle;
    sfTexture *towers;
    sfSprite *control;
    sfVector2f pos;
    int radius;
}tower_t;

typedef struct game {
    sfClock *clock;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *map;
    sfSprite *background;
    plane_t **tab_plane;
    tower_t **tab_tower;
    sfTime time;
    float second;
    int nb_plane;
    int hide_hitbox;
    int hide_sprite;
    float second_timer;
    sfFont *font;
    sfText *text;
    sfTexture *assets_map;
    sfTexture *assets_plane;
    sfTexture *assets_tower;
}game_t;

#endif /* !STRUCT_H_ */
