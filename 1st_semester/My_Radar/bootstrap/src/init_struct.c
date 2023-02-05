/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** init_struct
*/
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include "protos.h"

radar_t *init_radar(radar_t *radar)
{
    radar = malloc(sizeof(radar_t));
    if (radar == NULL)
        return  NULL;
    radar->mode.bitsPerPixel = 32;
    radar->mode.height = 1080;
    radar->mode.width = 1920;
    radar->window = sfRenderWindow_create(radar->mode, "SFML Window", sfClose, NULL);
    return radar;
}
