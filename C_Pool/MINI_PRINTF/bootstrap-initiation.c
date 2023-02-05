/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** bootstrap-initiation
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "main.h"

int main(void)
{
    sfEvent event;
    sfTexture* texture;
    sfSprite* sprite;
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return "EXIT_FAILURE";
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
}