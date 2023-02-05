/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "main.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
{
    framebuffer_t framebuffer = malloc(sizeof(framebuffer_t));
    return framebuffer;
}

void put_pixel(t_framebuffer *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    //sfUint32 *pixel = array[800][600];
    unsigned int x;
    unsigned int y;
}

int main(void)
{
    sfEvent event;
    sfFont* font;
    sfTexture* texture;
    sfSprite* sprite;
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    put_pixel(framebuffer, 10, 10);
    put_pixel(framebuffer, 100, 100);
    put_pixel(framebuffer, 250, 400);
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
