/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** WidgetStack
*/

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Widget.hpp"

class WidgetStack {
   public:
    WidgetStack(std::string title, std::string identifier);

    WidgetStack(const WidgetStack &) = delete;
    WidgetStack &operator=(const WidgetStack &) = delete;

    WidgetStack(WidgetStack &&) = default;
    WidgetStack &operator=(WidgetStack &&) = default;

    std::string getTitle() const;
    std::string getIdentifier() const;
    std::vector<Widget *> getWidgets() const;

    void registerWidget(std::unique_ptr<Widget> widget);

   private:
    std::string _title;
    std::string _identifier;
    std::vector<std::unique_ptr<Widget>> _widgets;
};
