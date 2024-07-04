/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Core
*/

#pragma once

#include <chrono>
#include <memory>
#include <vector>

#include "../Krell.hpp"

class Krell::Core {
   public:
    Core() = default;

    Core(const Core &) = delete;
    Core &operator=(const Core &) = delete;

    Core(Core &&) = delete;
    Core &operator=(Core &&) = delete;

    void registerModule(std::unique_ptr<Krell::IModule> module);

    void toggleModule(const std::string &identifier);
    void moveModuleUp(const std::string &identifier);
    void moveModuleDown(const std::string &identifier);
    void setRefreshRate(std::chrono::seconds refreshRate);

    bool shouldUpdate() const;
    bool updateStacks(bool updateNow = false);

    const std::vector<WidgetStack> &getStacks() const;
    std::chrono::time_point<std::chrono::system_clock> getLastRefresh() const;
    std::chrono::seconds getRefreshRate() const;
    bool isModuleEnabled(const std::string &identifier) const;

   private:
    std::chrono::seconds _updateRate = std::chrono::seconds(1);
    std::chrono::time_point<std::chrono::system_clock> _lastUpdate;

    std::vector<WidgetStack> _stacks;
    std::vector<std::unique_ptr<Krell::IModule>> _modules;
};
