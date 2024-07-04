/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** DateTime
*/

#pragma once

#include <ctime>

#include "../Module.hpp"

class Module::DateTime final : public BaseModule {
   public:
    DateTime(bool enabled): BaseModule(enabled) {};
    ~DateTime() override = default;

    void update() override;
    WidgetStack getWidgets() override;

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    std::time_t getDateTime() const;

    std::time_t _now{};
};
