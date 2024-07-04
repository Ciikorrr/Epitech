/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Module
*/

#pragma once

#include "../Krell.hpp"

namespace Module {
class Memory;
class DateTime;
class Host;
class OS;
class Cpu;
class Battery;

class BaseModule : public Krell::IModule {
   public:
    BaseModule(bool enabled);

    virtual void update() = 0;
    virtual WidgetStack getWidgets() = 0;

    void setEnabled(bool enabled) override;
    bool isEnabled() const override;

    std::optional<WidgetStack> render() override;

   private:
    bool _enabled;
};
}  // namespace Module
