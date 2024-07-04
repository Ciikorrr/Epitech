/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** HostModule
*/

#pragma once

#include <ctime>
#include <optional>
#include <string>

#include "../Module.hpp"
#include "../../Ui/Widgets/WidgetStack.hpp"

class Module::Host final : public BaseModule {
   public:
    Host(bool enabled): BaseModule(enabled) {};
    ~Host() override = default;

    void update() override;
    WidgetStack getWidgets() override;

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    std::optional<std::string> getHostname();
    std::optional<std::string> getUsername();
    std::optional<std::time_t> getUptime();

    std::optional<std::string> _hostname = std::nullopt;
    std::optional<std::string> _username = std::nullopt;
    std::optional<std::time_t> _uptime = std::nullopt;
};
