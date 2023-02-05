/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** window
*/
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "macros.h"
#include "protos.h"

int close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (SUCCESS_EPITECH);
    }
}

int analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(window, event);
            return SUCCESS_EPITECH;
        }
    }
}
