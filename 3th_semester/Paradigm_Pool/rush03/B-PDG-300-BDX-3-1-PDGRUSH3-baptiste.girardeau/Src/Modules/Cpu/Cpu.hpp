/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH3-baptiste.girardeau
** File description:
** Cpu
*/

#pragma once

#include <cstddef>
#include <optional>
#include <string>

#include "../Module.hpp"

class Module::Cpu final : public BaseModule {
   public:
    Cpu(bool enabled);
    ~Cpu() = default;

    void update() override;
    WidgetStack getWidgets() override;

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    void updateCpuInfo();
    void updateCpuStat();

    std::optional<std::string> _modelName = std::nullopt;
    std::optional<int> _coreCount = std::nullopt;
    std::optional<int> _threadCount = std::nullopt;

    std::optional<size_t> _lastTotalActive = std::nullopt;
    std::optional<size_t> _lastTotalIdle = std::nullopt;
    HistogramWidget _usageGraph;
};
