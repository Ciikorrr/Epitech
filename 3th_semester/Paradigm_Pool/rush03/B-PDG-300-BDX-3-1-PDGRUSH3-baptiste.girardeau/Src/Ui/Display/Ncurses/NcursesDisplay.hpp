/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH3-baptiste.girardeau
** File description:
** Display
*/

#pragma once

#include <ncurses.h>

#include "../../../Krell.hpp"

class NcursesDisplay : public Krell::IDisplay {
   public:
    NcursesDisplay();
    ~NcursesDisplay() override;

    void renderLoop(Krell::Core &core) override;

   private:
    void drawStacks(Krell::Core &core);
    void drawStack(const WidgetStack &stack, WINDOW *window);
    void drawWidget(const Widget *widget, WINDOW *window, int *yPosition);
    void drawText(const TextWidget *widget, WINDOW *window, int *yPosition);
    void drawHistogram(const HistogramWidget *widget, WINDOW *window, int *yPosition);

    WINDOW *_mainWindow;
    int _terminalWidth;
    int _terminalHeight;
};
