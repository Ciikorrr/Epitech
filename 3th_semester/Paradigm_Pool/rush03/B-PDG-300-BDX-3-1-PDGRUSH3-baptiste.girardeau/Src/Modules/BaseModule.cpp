/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** BaseModule
*/

#include <optional>
#include "Module.hpp"

Module::BaseModule::BaseModule(bool enabled) : _enabled(enabled) {}

void Module::BaseModule::setEnabled(bool enabled) { _enabled = enabled; }
bool Module::BaseModule::isEnabled() const { return _enabled; }

std::optional<WidgetStack> Module::BaseModule::render() {
    if (_enabled) {
        update();
        return getWidgets();
    }

    return std::nullopt;
}
