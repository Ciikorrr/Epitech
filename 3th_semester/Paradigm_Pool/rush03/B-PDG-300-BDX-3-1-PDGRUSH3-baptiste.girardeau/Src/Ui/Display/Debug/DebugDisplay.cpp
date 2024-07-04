/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** DebugDisplay
*/

#include "DebugDisplay.hpp"

#include <chrono>
#include <iostream>
#include <thread>

void DebugDisplay::renderLoop(Krell::Core &core) {
    std::cout << ">>> RENDER LOOP\n";

    while (true) {
        if (core.updateStacks()) {
            std::cout << ">>> REFRESH\n";
            for (auto &stack : core.getStacks()) {
                drawStack(stack);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void DebugDisplay::drawStack(const WidgetStack &stack) {
    std::cout << "== STACK: " << stack.getTitle() << " ==\n";
    for (auto &widget : stack.getWidgets()) {
        drawWidget(widget);
    }
}

void DebugDisplay::drawWidget(const Widget *widget) {
    if (auto textWidget = dynamic_cast<const TextWidget *>(widget)) {
        drawText(textWidget);
    }

    if (auto histogramWidget = dynamic_cast<const HistogramWidget *>(widget)) {
        drawHistogram(histogramWidget);
    }
}

void DebugDisplay::drawText(const TextWidget *widget) {
    std::cout << "TEXT:\n";
    std::cout << "  title: " << widget->getTitle() << "\n";
    std::cout << "  text: " << widget->getText() << "\n";
    std::cout << "  color: " << widget->getColor() << "\n";
}

void DebugDisplay::drawHistogram(const HistogramWidget *widget) {
    std::cout << "HISTOGRAM:\n";
    std::cout << "  title: " << widget->getTitle() << "\n";
    std::cout << "  text: " << widget->getText() << "\n";
    std::cout << "  color: " << widget->getColor() << "\n";
    std::cout << "  values: ";
    for (auto &value : widget->getValues()) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
