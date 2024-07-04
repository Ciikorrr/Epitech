/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Krell
*/

#pragma once

#include "Ui/Widgets/WidgetStack.hpp"

namespace Krell {
class Core;

class IModule {
   public:
    virtual ~IModule() = default;

    virtual void setEnabled(bool enabled) = 0;
    virtual bool isEnabled() const = 0;

    virtual std::string getIdentifier() const = 0;
    virtual std::string getDisplayName() const = 0;

    virtual std::optional<WidgetStack> render() = 0;
};

class IDisplay {
   public:
    IDisplay() = default;
    virtual ~IDisplay() = default;

    virtual void renderLoop(Krell::Core &core) = 0;
};
}  // namespace Krell
