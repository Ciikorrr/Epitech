/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH3-baptiste.girardeau
** File description:
** Battery
*/

#pragma once

#include <optional>
#include <string>

#include "../Module.hpp"

class Module::Battery final : public BaseModule {
   public:
    Battery(bool enabled) : BaseModule(enabled){};
    ~Battery() = default;

    void update() override;
    WidgetStack getWidgets() override;

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    std::optional<int> _currentCapacity = std::nullopt;
    std::optional<std::string> _batteryStatus = std::nullopt;
    std::optional<std::string> _batteryModelName = std::nullopt;
};
