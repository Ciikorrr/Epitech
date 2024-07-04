/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** NcursesMenu
*/

#include "../NcursesModule.hpp"
#include <dlfcn.h>
#include <ncurses.h>
#include <fstream>
#include <sstream>
#include <string.h>

void handleInput(bool &loop, bool &next, std::size_t &end, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, std::pair<int, int> &idxLibs)
{
    std::size_t key_pressed = getch();

    if (!next) {
        if (key_pressed == KEY_UP)
            if (idxLibs.first > 0)
                idxLibs.first -= 1;
        if (key_pressed == KEY_DOWN)
            if (idxLibs.first < availableLibs.first.size() - 1)
                idxLibs.first += 1;
        if (key_pressed == '\n') {
            next = true;
            end += 1;
        }
        if (key_pressed == 'q') {
            idxLibs.first = -1;
            loop = false;
        }
        return;
    }

    if (key_pressed == KEY_UP)
        if (idxLibs.second > 0)
            idxLibs.second -= 1;
    if (key_pressed == KEY_DOWN)
        if (idxLibs.second < availableLibs.second.size() - 1)
            idxLibs.second += 1;
    if (key_pressed == '\n') {
        end += 1;
    }
    if (key_pressed == 'q') {
        idxLibs.second = -1;
        loop = false;
    }
    return;
}

void displayGame(std::pair<std::size_t, std::size_t> centerwh, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, pair<int, int> idxLibs)
{
    std::size_t move = 1;
    std::string titlegame = "======= Game List: =======";
    string nolib = "No game library found !";
    std::size_t i = 0;

    mvwprintw(stdscr, centerwh.first, centerwh.second - titlegame.length() + 10, titlegame.c_str());
    if (availableLibs.first.size() == 0) {
        mvwprintw(stdscr, centerwh.first + 1, centerwh.second - nolib.length() + 10, nolib.c_str());
        wrefresh(stdscr);
        return;
    }

    for (auto it = availableLibs.first.begin(); it != availableLibs.first.end(); it++, i++) {
        if (i == idxLibs.first)
            mvwprintw(stdscr, centerwh.first + (1 * move), centerwh.second - titlegame.length() + 10," -> %s <-", it->first.c_str());
        else
            mvwprintw(stdscr, centerwh.first + (1 * move), centerwh.second - titlegame.length() + 10,"    %s    ", it->first.c_str());
        move++;
    }
    wrefresh(stdscr);
    return;
}

void displayGraphic(std::pair<std::size_t, std::size_t> centerwh, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs, pair<int, int> idxLibs)
{
    std::size_t move = 1;
    std::string titlegame = "======= Graphic List: =======";
    string nolib = "No graphic library found !";
    std::size_t i = 0;

    mvwprintw(stdscr, centerwh.first, centerwh.second - titlegame.length() + 10, titlegame.c_str());
    if (availableLibs.second.size() == 0) {
        mvwprintw(stdscr, centerwh.first + 1, centerwh.second - nolib.length() + 10, nolib.c_str());
        wrefresh(stdscr);
        return;
    }

    for (auto it = availableLibs.second.begin(); it != availableLibs.second.end(); it++, i++) {
        if (i == idxLibs.second)
            mvwprintw(stdscr, centerwh.first + (1 * move), centerwh.second - titlegame.length() + 10," -> %s <-", it->first.c_str());
        else
            mvwprintw(stdscr, centerwh.first + (1 * move), centerwh.second - titlegame.length() + 10,"    %s    ", it->first.c_str());
        move++;
    }
    wrefresh(stdscr);
    return;
}

void display_all(bool next, bool &isClr, std::pair<std::size_t, std::size_t> centerHW, std::pair<int, int> idxLibs, pair<std::map<std::string, std::string>, map<std::string, std::string>> availableLibs)
{
    if (next) {
        if (!isClr) {
            clear();
            box(stdscr, 0, 0);
            isClr = true;
        }
        displayGraphic(centerHW, availableLibs, idxLibs);
        return;
    }
    displayGame(centerHW, availableLibs, idxLibs);
}

void initWindowNcurses()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    box(stdscr, 0, 0);
    curs_set(0);
    refresh();
}

pair<std::map<std::string, std::string>, map<std::string, std::string>> checkAvailableLibs(pair<std::map<std::string, std::string>, map<std::string, std::string>> libs)
{
    pair<std::map<std::string, std::string>, map<std::string, std::string>> newAvailableLibs = {};

    for (auto elem : libs.first) {
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.first.insert(elem);
    }

    for (auto elem : libs.second) {
        if (dlopen(elem.second.c_str(), RTLD_LAZY) != nullptr)
            newAvailableLibs.second.insert(elem);
    }
    return newAvailableLibs;
}

void displayArcadeTitle(pair<size_t, size_t> centerWH)
{
    std::ifstream ifs(PATH_ASCII_ART);
    std::string line;
    size_t move = 1;

    if (!ifs.is_open())
        return;
    while (std::getline(ifs, line)) {
        mvwprintw(stdscr, 10 + (1 * move), centerWH.second - line.length() + 15, line.c_str());
        move++;
    }
    return;
}

void displayUser(IDisplayModule &menu)
{
    mvwprintw(stdscr, 1, 2, ("USERNAME " + menu.getUser()).c_str());
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

extern "C" pair<string, string> displayMenuNcurses(IDisplayModule &menu)
{
    pair<size_t, size_t> windowSize = {0,0};
    initWindowNcurses();
    getmaxyx(stdscr, windowSize.first, windowSize.second);

    size_t end = 0;
    bool loop = true;
    bool next = false;
    bool isClr = false;
    pair<size_t, size_t> centerWH = {windowSize.first / 2, windowSize.second / 2};

    while (loop) {
        box(stdscr, 0,0);
        getmaxyx(stdscr, windowSize.first, windowSize.second);
        wrefresh(stdscr);
        displayArcadeTitle(centerWH);
        displayUser(menu);
        menu.setAvailableLibs(checkAvailableLibs(menu.getLibs()));
        handleInput(loop, next, end, menu.getAvailableLibs(), menu.getIdxLibs());
        if (end == 2)
            break;
        display_all(next, isClr, centerWH, menu.getIdxLibs(), menu.getAvailableLibs());
    }
    endwin();

    return getFinalLibs(menu.getAvailableLibs(), menu.getIdxLibs());
}