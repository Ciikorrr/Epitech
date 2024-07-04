/*
** EPITECH PROJECT, 2024
** test_sdl2
** File description:
** Display
*/

#include "../../Menu/SDL2Menu.hpp"
#include "../Sdl2Module.hpp"
#include <cstring>

TextSDL2::~TextSDL2()
{
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(textFont);
}

TextSDL2::TextSDL2(const char *text, std::size_t textSize, std::pair<int, int>centers, SDL_Renderer *renderer)
{
    textFont = TTF_OpenFont(PATH_FONT, textSize);
    textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, text, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    textRect.x = centers.first - strlen(text);
    textRect.y = centers.second;
    textRect.h = textSurface->h;
    textRect.w = textSurface->w;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
}

TextSDL2::TextSDL2(const char *text, std::size_t textSize, std::pair<int, int>centers, SDL_Renderer *renderer, const char *fontPath)
{
    textFont = TTF_OpenFont(fontPath, textSize);
    textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, text, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    textRect.x = centers.first - strlen(text);
    textRect.y = centers.second;
    textRect.h = textSurface->h;
    textRect.w = textSurface->w;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
}

std::pair<std::string, std::string> getFinalLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<int, int> idxLibs)
{
    auto iteFst = availableLibs.first.begin();
    std::advance(iteFst, idxLibs.first);
    auto iteSnd = availableLibs.second.begin();
    std::advance(iteSnd, idxLibs.second);

    if (availableLibs.first.size() == 0 || availableLibs.second.size() == 0 || idxLibs.second == -1 || idxLibs.first == -1)
        return {"",""};
    return {iteFst->second.substr(iteFst->second.find("lib/") + 4), iteSnd->second.substr(iteSnd->second.find("lib/") + 4)};
}

void clear(IDisplayModule &menu)
{
    SDL_DestroyRenderer(menu.getRenderer());
    SDL_DestroyWindow(menu.getWindow());
    SDL_Quit();
}

void handleEvents(bool &next, bool &isRunning, std::size_t &end, std::pair<int, int> &idxLibs, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (!next) {
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
                if (idxLibs.first > 0)
                    idxLibs.first -= 1;
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                if (idxLibs.first < availableLibs.first.size() - 1)
                    idxLibs.first += 1;
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                next = true;
                end += 1;
            }
        }
        if (event.type == SDL_QUIT) {
            idxLibs.first = -1;
            isRunning = false;
        }
        return;
    }

    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
            if (idxLibs.second > 0)
                idxLibs.second -= 1;
        }
        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
            if (idxLibs.second < availableLibs.second.size() - 1)
                idxLibs.second += 1;
        }
        if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
            end += 1;
        }
    }
    if (event.type == SDL_QUIT) {
        idxLibs.second = -1;
        isRunning = false;
    }
}

void displayGame(std::pair<std::size_t, std::size_t> centers, SDL_Renderer *renderer, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<int, int> idxLibs)
{
    std::pair<std::size_t, std::size_t> newPos = {centers.first + 50, centers.second + 200};
    TextSDL2 libTitle("Game libs :", 50, newPos, renderer);
    std::size_t i = 0;

    newPos.second += 100;
    if (availableLibs.first.size() == 0) {
        TextSDL2 noLib("No game library found !", 40, newPos, renderer);
        return;
    }
    for (auto it = availableLibs.first.begin(); it != availableLibs.first.end(); it++, i++) {
        if (i == idxLibs.first)
            TextSDL2 libFound(it->first.c_str(), 50, newPos, renderer);
        else
            TextSDL2 libFound(it->first.c_str(), 30, newPos, renderer);
        newPos.second += 100;
    }
}

pair<std::map<std::string, std::string>, map<std::string, std::string>> checkAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs)
{
    pair<std::map<std::string, std::string>, map<std::string, std::string>> newAvailableLibs = {};

    for (auto elem : libs.first)
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.first.insert(elem);

    for (auto elem : libs.second)
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.second.insert(elem);
    return newAvailableLibs;
}

void displayGraphic(std::pair<std::size_t, std::size_t> centers, SDL_Renderer *renderer, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<int, int> idxLibs)
{
    std::pair<std::size_t, std::size_t> newPos = {centers.first + 50, centers.second + 200};
    TextSDL2 libTitle("Graphic libs :", 50, newPos, renderer);
    std::size_t i = 0;

    newPos.second += 100;
    if (availableLibs.second.size() == 0) {
        TextSDL2 noLib("No graphical library found !", 40, newPos, renderer);
        return;
    }
    for (auto it = availableLibs.second.begin();  it != availableLibs.second.end(); it++, i++) {
        if (i == idxLibs.second)
            TextSDL2 libFound(it->first.c_str(), 50, newPos, renderer);
        else
            TextSDL2 libFound(it->first.c_str(), 30, newPos, renderer);
        newPos.second += 100;
    }
}

void displayArcadeTitle(std::pair<std::size_t, std::size_t>centers, SDL_Renderer *renderer)
{
    TextSDL2 arcade("Arcade", 100, centers, renderer);
}

void displayUser(IDisplayModule &menu)
{
    TextSDL2 user(("USERNAME " + menu.getUser()).c_str(), 20, {100,100}, menu.getRenderer());
}

void displayBackground(IDisplayModule &menu)
{
    SDL_Surface *background = IMG_Load(PATH_BACKGND);
    SDL_Texture *backTexture = SDL_CreateTextureFromSurface(menu.getRenderer(), background);
    SDL_FreeSurface(background);
    SDL_RenderCopy(menu.getRenderer(), backTexture, NULL, NULL);
    SDL_DestroyTexture(backTexture);
}

void displayAll(bool next, std::pair<std::size_t, std::size_t> centers, IDisplayModule &menu)
{
    displayBackground(menu);
    if (next)
        displayGraphic(centers, menu.getRenderer(), menu.getAvailableLibs(), menu.getIdxLibs());
    else
        displayGame(centers, menu.getRenderer(), menu.getAvailableLibs(), menu.getIdxLibs());
    displayArcadeTitle(centers, menu.getRenderer());
    displayUser(menu);
    SDL_RenderPresent(menu.getRenderer());
    SDL_RenderClear(menu.getRenderer());
}

void initSDL(IDisplayModule &menu, bool &isRunning)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        menu.setWindow(SDL_CreateWindow("ARCADE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false));
        menu.setRenderer(SDL_CreateRenderer(menu.getWindow(), -1, SDL_RENDERER_ACCELERATED));
        SDL_Surface *background = IMG_Load(PATH_BACKGND);
        SDL_Texture *backTexture = SDL_CreateTextureFromSurface(menu.getRenderer(), background);
        SDL_FreeSurface(background);
        SDL_RenderCopy(menu.getRenderer(), backTexture, NULL, NULL);
        SDL_DestroyTexture(backTexture);
        SDL_RenderPresent(menu.getRenderer());
        SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
        SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_DISABLE);
        SDL_EventState(SDL_MOUSEBUTTONUP, SDL_DISABLE);
        if (TTF_Init() == -1)
            isRunning = false;
        else
            isRunning = true;
    } else
        isRunning = false;
}

extern "C" std::pair<std::string, std::string> displayMenuSDL2(IDisplayModule &menu)
{
    bool next = false;
    bool isRunning = false;
    std::size_t end = 0;
    std::pair<std::size_t, std::size_t> centers = {1920 / 2.8, 1080 / 5};

    initSDL(menu, isRunning);
    while (isRunning) {
        if (end == 2)
            isRunning = false;
        menu.setAvailableLibs(checkAvailableLibs(menu.getLibs()));
        handleEvents(next, isRunning, end, menu.getIdxLibs(), menu.getAvailableLibs());
        displayAll(next, centers, menu);
    }
    clear(menu);
    return getFinalLibs(menu.getAvailableLibs(), menu.getIdxLibs());
}
