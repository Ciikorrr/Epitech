/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** bootstrap-initiation
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int open_window(void)
{
    sfTexture *texture;
    sfSprite *sprite =  sfSprite_create();
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        texture = sfTexture_createFromFile("image.png", NULL);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
}