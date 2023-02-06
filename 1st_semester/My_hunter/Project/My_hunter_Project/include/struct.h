/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define PAYSAGE "ressources/paysage.jpg"
    #define BUTTON "ressources/play_button.png"
    #define HEART "ressources/coeur.png"

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfIntRect rect;
    sfVideoMode mode;
    sfClock *clock;
    sfTime time;
    sfTexture *texture;
    sfTexture *texture_play;
    sfTexture *texture_coeur;
    sfSprite *sprite;
    sfSprite *sprite_play;
    sfSprite *sprite_coeur;
    sfFont *font;
    sfText *text;
    sfText *text_title;
    sfText *text_coeur;
    sfText *text_score;
    sfVector2f pos_title;
    sfVector2f pos_coeur;
    sfVector2f pos_score;
    sfVector2f pos_heal;
    sfVector2f pos_text;
    sfVector2f pos_play;
    float seconde;
    char *score;
    int etat;
}game_t;

typedef struct Player {
    int life;
    int score;
    int best_score;
    sfTexture *texture_over;
    sfSprite *game_over;
    sfVector2f pos_over;
    sfTime sleep;
}player_t;

typedef struct Bird {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f offset;
}bird_t;

#endif /* !STRUCT_H_ */
