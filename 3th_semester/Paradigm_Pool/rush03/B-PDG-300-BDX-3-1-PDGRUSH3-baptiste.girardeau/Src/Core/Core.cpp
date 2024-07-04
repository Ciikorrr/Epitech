/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

void Krell::Core::registerModule(std::unique_ptr<IModule> module) {
    _modules.push_back(std::move(module));
}

void Krell::Core::toggleModule(const std::string &identifier) {
    for (auto &module : _modules) {
        if (module->getIdentifier() == identifier) {
            module->setEnabled(!module->isEnabled());
        }
    }
}

void Krell::Core::moveModuleUp(const std::string &identifier) {
    for (size_t i = 0; i < _modules.size(); i++) {
        if (_modules[i]->getIdentifier() == identifier && i > 0) {
            std::swap(_modules[i], _modules[i - 1]);
            return;
        }
    }
}

void Krell::Core::moveModuleDown(const std::string &identifier) {
    for (size_t i = 0; i < _modules.size(); i++) {
        if (_modules[i]->getIdentifier() == identifier &&
            i < _modules.size() - 1) {
            std::swap(_modules[i], _modules[i + 1]);
            return;
        }
    }
}

bool Krell::Core::isModuleEnabled(const std::string &identifier) const {
    for (const auto &module : _modules) {
        if (module->getIdentifier() == identifier) {
            return module->isEnabled();
        }
    }

    return false;
}

void Krell::Core::setRefreshRate(std::chrono::seconds refreshRate) {
    _updateRate = refreshRate;
}

bool Krell::Core::shouldUpdate() const {
    auto now = std::chrono::system_clock::now();
    auto diff = now - _lastUpdate;

    return diff >= _updateRate;
}

bool Krell::Core::updateStacks(bool updateNow) {
    if (!shouldUpdate() && !updateNow) {
        return false;
    }

    _stacks.clear();
    for (auto &module : _modules) {
        if (module->isEnabled()) {
            std::optional<WidgetStack> stack = module->render();

            if (stack.has_value()) {
                _stacks.push_back(std::move(stack.value()));
            }
        }
    }

    _lastUpdate = std::chrono::system_clock::now();
    return true;
}

const std::vector<WidgetStack> &Krell::Core::getStacks() const {
    return _stacks;
}

std::chrono::time_point<std::chrono::system_clock> Krell::Core::getLastRefresh()
    const {
    return _lastUpdate;
}

std::chrono::seconds Krell::Core::getRefreshRate() const {
    return _updateRate;
}
