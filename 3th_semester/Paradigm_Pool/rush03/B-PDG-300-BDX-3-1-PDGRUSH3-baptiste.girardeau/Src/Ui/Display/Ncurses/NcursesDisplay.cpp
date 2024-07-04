/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** NcursesDisplay
*/

#include "NcursesDisplay.hpp"

#include <ncurses.h>

#include "../../../Core/Core.hpp"

NcursesDisplay::NcursesDisplay() {
    _mainWindow = initscr();
    getmaxyx(_mainWindow, _terminalHeight, _terminalWidth);

    // Disable input and cursor
    cbreak();
    noecho();
    curs_set(0);
}

NcursesDisplay::~NcursesDisplay() { endwin(); }

void NcursesDisplay::renderLoop(Krell::Core &core) {
    while (true) {
        int newTerminalWidth, newTerminalHeight;
        getmaxyx(_mainWindow, newTerminalHeight, newTerminalWidth);

        bool shouldRender = core.updateStacks();

        if (newTerminalWidth != _terminalWidth ||
            newTerminalHeight != _terminalHeight) {
            _terminalWidth = newTerminalWidth;
            _terminalHeight = newTerminalHeight;
            shouldRender = true;
        }

        if (shouldRender) {
            clear();
            drawStacks(core);
        }
        usleep(100000);
    }
}

void NcursesDisplay::drawStacks(Krell::Core &core) {
    auto &stacks = core.getStacks();
    if (stacks.empty()) {
        return;
    }

    int winHeight = _terminalHeight / static_cast<int>(stacks.size());
    for (int i = 0; i < static_cast<int>(stacks.size()); i++) {
        WINDOW *node = newwin(winHeight, _terminalWidth, winHeight * i, 0);
        box(node, 0, 0);

        std::string title = " " + stacks[i].getTitle() + " ";
        int titleX =
            static_cast<int>((_terminalWidth / 2) - (title.length() / 2));
        mvwprintw(node, 0, titleX, "%s", title.c_str());
        drawStack(stacks[i], node);
        wrefresh(node);
        delwin(node);
    }
}

void NcursesDisplay::drawStack(const WidgetStack &stack, WINDOW *window) {
    int yPosition = 2;

    for (auto &widget : stack.getWidgets()) {
        drawWidget(widget, window, &yPosition);
    }
}
void NcursesDisplay::drawWidget(const Widget *widget, WINDOW *window,
                                int *yPosition) {
    if (auto histogramWidget = dynamic_cast<const HistogramWidget *>(widget)) {
        drawHistogram(histogramWidget, window, yPosition);
    } else if (auto textWidget = dynamic_cast<const TextWidget *>(widget)) {
        drawText(textWidget, window, yPosition);
    }
    *yPosition += 1;
}

void NcursesDisplay::drawText(const TextWidget *widget, WINDOW *window,
                              int *yPosition) {
    std::string title = widget->getTitle();
    std::string text = widget->getText();

    mvwprintw(window, *yPosition, 4, "%s : %s", title.c_str(), text.c_str());
}

void NcursesDisplay::drawHistogram(const HistogramWidget *widget,
                                   WINDOW *window, int *yPosition) {
    drawText(widget, window, yPosition);
    *yPosition += 1;

    int xPosition = 4;
    mvwprintw(window, *yPosition, xPosition, "[ ");
    xPosition += 2;
    for (int i = 0; i < 30; i++) {
        if (i <=
            static_cast<int>(widget->getLastValue().value_or(0) * 100 / 3)) {
            mvwprintw(window, *yPosition, xPosition, "|");
        } else {
            mvwprintw(window, *yPosition, xPosition, ".");
        }
        xPosition++;
    }
    mvwprintw(window, *yPosition, xPosition, " ]");
}
