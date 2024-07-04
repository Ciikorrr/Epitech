/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** ImguiDisplay
*/

#pragma once
#ifdef IMGUI_BACKEND

#include "../../../Krell.hpp"
#include <GLFW/glfw3.h>

class ImguiDisplay : public Krell::IDisplay {
public:
    ImguiDisplay();
    ~ImguiDisplay() override;

    void renderLoop(Krell::Core &core) override;

    private:
        void renderMenuBar();

        void drawStack(const WidgetStack &stack);
        void drawWidget(const Widget *widget);
        void drawText(const TextWidget *widget);
        void drawHistogram(const HistogramWidget *widget);

        GLFWwindow *_window;
        Krell::Core *_core;
        bool _modulesReordering = false;
};

#endif
