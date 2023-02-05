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

typedef struct radar {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
}radar_t;

#endif /* !STRUCT_H_ */
