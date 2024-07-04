/*
** EPITECH PROJECT, 2024
** test_sdl2
** File description:
** SDL2Menu
*/

#ifndef SDL2MENU_HPP_
#define SDL2MENU_HPP_

#include "SDL2/SDL.h"
#include "../SDL2/Sdl2Module.hpp"
#include <stdio.h>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <vector>
#include <iostream>
#include <dlfcn.h>


#define PATHLIB "../../../"
#define PATH_BACKGND "assets/retro.jpg"

class TextSDL2 {

    public:
        TextSDL2(const char *text, std::size_t textSize, std::pair<int, int>, SDL_Renderer *renderer);
        TextSDL2(const char *text, std::size_t textSize, std::pair<int, int>, SDL_Renderer *renderer, const char *fontPath);
        ~TextSDL2();
        SDL_Texture *getTextTexture()
        {
            return textTexture;
        }
    private:
        SDL_Rect textRect;
        SDL_Texture *textTexture;
        TTF_Font *textFont;
        SDL_Color textColor;
};

#endif /* !SDL2MENU_HPP_ */
