/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** protos
*/

#ifndef PROTOS_H_
    #define PROTOS_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    radar_t *init_radar(radar_t *radar);
    sfCircleShape **create_arr(int nb);
    int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);
    sfCircleShape *create_circle(sfVector2f position, float radius);
    int close_window(sfRenderWindow *window, sfEvent event);
    int analyse_events(sfRenderWindow *window, sfEvent event);
    void check_all_inter(sfCircleShape **array, radar_t *radar);
    void move_circle(radar_t *radar, sfCircleShape**array);
#endif /* !PROTOS_H_ */
