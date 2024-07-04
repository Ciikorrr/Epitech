/*
** EPITECH PROJECT, 2024
** nibbler
** File description:
** displaySDL
*/

#include "../../Game/IGameModule.hpp"
#include "../../Menu/SDL2Menu.hpp"


std::array<int, 18> YConverterNibbler = {
        100, 150, 200, 250, 300, 350,
        400, 450, 500, 550, 600, 650,
        700, 750, 800, 850, 900, 950
    };

std::array<int, 18> XConverterNibbler = {
    510, 560, 610, 660, 710, 760,
    810, 860, 910, 960, 1010, 1060,
    1110, 1160, 1210, 1260, 1310, 1360
};

void drawNibblerMap(IGameModule &nibbler)
{
    SDL_Rect rect;
    int tmpX;
    int tmpY;
    std::pair<int, int> size;

    for (auto elem : nibbler.getWalls()) {
        size = std::make_pair(50, 50);
        if (elem.first == -1) {
            tmpX = 485;
            size = std::make_pair(25, 50);
        } else if (elem.first == 18) {
            tmpX = 1410;
            size = std::make_pair(25, 50);
        } else
            tmpX = XConverterNibbler[elem.first];
        if (elem.second == -1) {
            tmpY = 75;
            size = std::make_pair(50, 25);
        } else if (elem.second == 18) {
            tmpY = 1000;
            size = std::make_pair(50, 25);
        } else
            tmpY = YConverterNibbler[elem.second];
        rect = {tmpX, tmpY, size.first, size.second};
        SDL_SetRenderDrawColor(nibbler.getRenderer(), 102, 0, 102, 255);
        SDL_RenderFillRect(nibbler.getRenderer(), &rect);
    }
}

void drawFruitNibbler(IGameModule &nibbler)
{
    for (auto elem : nibbler.getFruitsCoords()) {
        if (!elem.second)
            continue;
        SDL_Rect rect = {XConverterNibbler[elem.first.first], YConverterNibbler[elem.first.second], 50, 50};
        SDL_SetRenderDrawColor(nibbler.getRenderer(), 0, 200, 0, 255);
        SDL_RenderFillRect(nibbler.getRenderer(), &rect);
    }
}

void drawNibblerTimer(IGameModule &snake)
{
    TextSDL2 Score(("Time : " + to_string(snake.getTime())).c_str(), 50, {150, 500}, snake.getRenderer(), PATH_FONT_SCORE);
}

void drawNibblerTitle(IGameModule &nibbler)
{
    TextSDL2 Nibbler("NIBBLER", 50, {860, 30}, nibbler.getRenderer());
}

void drawNibblerUsage(IGameModule &nibbler)
{
    TextSDL2 Up("Arrow UP to go UP", 20, {1500, 600}, nibbler.getRenderer());
    TextSDL2 Down("Arrow DOWN to go DOWN", 20, {1500, 630}, nibbler.getRenderer());
    TextSDL2 Left("Arrow LEFT to go LEFT", 20, {1500, 660}, nibbler.getRenderer());
    TextSDL2 Right("Arrow RIGHT to go RIGHT", 20, {1500, 690}, nibbler.getRenderer());
}

void drawNibbler(IGameModule &nibbler)
{
    size_t lengthTmp = nibbler.getSnakeSize();
    SDL_Rect rect = {XConverterNibbler[nibbler.getHeadCoords().first], YConverterNibbler[nibbler.getHeadCoords().second], 50, 50};

    SDL_SetRenderDrawColor(nibbler.getRenderer(), 200, 0, 0, 255);
    SDL_RenderFillRect(nibbler.getRenderer(), &rect);
    if (nibbler.isEating() && nibbler.getSnakeSize() > 1)
        lengthTmp -= 1;
    for (size_t i = 0; i < lengthTmp; i += 1) {
        rect = {XConverterNibbler[nibbler.getTailCoords(i).first], YConverterNibbler[nibbler.getTailCoords(i).second], 50, 50};
        SDL_SetRenderDrawColor(nibbler.getRenderer(), 200, 0, 0, 255);
        SDL_RenderFillRect(nibbler.getRenderer(), &rect);
    }
}

extern "C" void drawMapSDLNibbler(IGameModule &nibbler)
{
    SDL_Rect rect = { 510, 100, 900, 900 };

    SDL_SetRenderDrawColor(nibbler.getRenderer(), 50, 50, 50, 255);
    SDL_RenderClear(nibbler.getRenderer());
    SDL_SetRenderDrawColor(nibbler.getRenderer(), 0, 0, 0, 255);
    SDL_RenderFillRect(nibbler.getRenderer(), &rect);
    drawFruitNibbler(nibbler);
    drawNibbler(nibbler);
    drawNibblerMap(nibbler);
    drawNibblerTitle(nibbler);
    drawNibblerTimer(nibbler);
    drawNibblerUsage(nibbler);
    SDL_RenderPresent(nibbler.getRenderer());
}