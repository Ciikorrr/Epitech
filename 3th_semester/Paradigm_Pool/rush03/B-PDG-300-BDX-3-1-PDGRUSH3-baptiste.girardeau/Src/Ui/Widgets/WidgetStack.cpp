/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** WidgetStack
*/

#include "WidgetStack.hpp"

WidgetStack::WidgetStack(std::string title, std::string identifier)
    : _title(std::move(title)), _identifier(std::move(identifier)) {}

std::string WidgetStack::getTitle() const { return _title; }
std::string WidgetStack::getIdentifier() const { return _identifier; }

std::vector<Widget *> WidgetStack::getWidgets() const {
    std::vector<Widget *> widgets;

    widgets.reserve(_widgets.size());
    for (const auto &widget : _widgets) {
        widgets.push_back(widget.get());
    }
    return widgets;
}

void WidgetStack::registerWidget(std::unique_ptr<Widget> widget) {
    _widgets.push_back(std::move(widget));
}
