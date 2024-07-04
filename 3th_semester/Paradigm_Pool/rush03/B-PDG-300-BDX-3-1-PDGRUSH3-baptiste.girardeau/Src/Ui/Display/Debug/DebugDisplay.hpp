/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Display
*/

#pragma once

#include "../../../Core/Core.hpp"
#include "../../../Krell.hpp"

class DebugDisplay final : public Krell::IDisplay {
   public:
    void renderLoop(Krell::Core &core) override;

   private:
    void drawWidget(const Widget *widget);
    void drawStack(const WidgetStack &stack);
    void drawText(const TextWidget *widget);
    void drawHistogram(const HistogramWidget *widget);
};
