/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** circle
*/
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include <stdio.h>
#include "protos.h"

sfCircleShape **create_arr(int nb)
{
    srand(time(NULL));
    sfCircleShape **arr_circle = malloc(sizeof(sfCircleShape *) * (nb + 1));
    arr_circle[nb] = NULL;
    sfVector2f position = {0, 0};
    for (int i = 0; i < nb; i += 1) {
        position.x = rand() % 1900;
        position.y = rand() % 1080;
        arr_circle[i] = create_circle(position, 20);
    }
    return arr_circle;
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f position1 = sfCircleShape_getPosition(c1);
    sfVector2f position2 = sfCircleShape_getPosition(c2);
    float radius1 = sfCircleShape_getRadius(c1);
    float radius2 = sfCircleShape_getRadius(c2);
    sfVector2f circle1;
    circle1.x = position1.x + radius1;
    circle1.y=  position1.y + radius1;
    sfVector2f circle2;
    circle2.x = position2.x + radius2;
    circle2.y=  position2.y + radius2;
    if ((circle1.x - circle2.x) * (circle1.x - circle2.x) + (circle1.y - circle2.y) * (circle1.y - circle2.y) <= (radius1 + radius2) * (radius1 + radius2)) {
        sfCircleShape_setFillColor(c1, sfWhite);
        sfCircleShape_setFillColor(c2, sfWhite);
        return SUCCESS_EPITECH;
    } else {
        sfCircleShape_setFillColor(c1, sfTransparent);
    }
    return SUCCESS_EPITECH;
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    return circle;
}

void check_all_inter(sfCircleShape **array, radar_t *radar)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        for (int j = 0; array[j] != NULL; j += 1) {
            if (j != i) {
                is_intersecting_circles(array[i], array[j]);
                sfRenderWindow_drawCircleShape(radar->window, array[i], NULL);
                sfRenderWindow_drawCircleShape(radar->window, array[j], NULL);
            }
        }
    }
}

void move_circle(radar_t *radar, sfCircleShape **array)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        sfVector2f pos = {(rand() % 7) - 3, ((rand() % 7) - 3)};
        sfSprite_move(array[i], pos);
        sfRenderWindow_drawCircleShape(radar->window, array[i], NULL);
    }
}
