/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH3-baptiste.girardeau
** File description:
** Cpu
*/

#include "Cpu.hpp"

#include <iostream>
#include <optional>
#include <sstream>

#include "../../Parse/FileParser.hpp"
#include "../../Parse/ValueParser.hpp"

constexpr const char* CPU_INFOS_FILE = "/proc/cpuinfo";
constexpr const char* CPU_STAT_FILE = "/proc/stat";

Module::Cpu::Cpu(bool enabled)
    : BaseModule(enabled), _usageGraph("CPU Usage") {}

void Module::Cpu::update() {
    if (!_modelName.has_value() || !_coreCount.has_value() ||
        !_threadCount.has_value()) {
        updateCpuInfo();
    }

    updateCpuStat();
}

WidgetStack Module::Cpu::getWidgets() {
    WidgetStack stack("CPU Information", this->getIdentifier());

    stack.registerWidget(std::make_unique<TextWidget>(
        "Model Name", _modelName.value_or("Unknown"),
        TextWidget::colorFrom(_modelName)));

    std::string coreCountDisplay = "Unknown";
    if (_coreCount.has_value()) {
        coreCountDisplay = std::to_string(_coreCount.value());
    }
    stack.registerWidget(
        std::make_unique<TextWidget>("Number of cores", coreCountDisplay,
                                     TextWidget::colorFrom(_coreCount)));

    std::string threadCountDisplay = "Unknown";
    if (_threadCount.has_value()) {
        threadCountDisplay = std::to_string(_threadCount.value());
    }
    stack.registerWidget(
        std::make_unique<TextWidget>("Number of threads", threadCountDisplay,
                                     TextWidget::colorFrom(_threadCount)));

    std::string cpuUsageDisplay = "Calculating...";
    std::optional<double> cpuUsage = _usageGraph.getLastValue();
    if (cpuUsage.has_value()) {
        cpuUsageDisplay = std::to_string(cpuUsage.value() * 100) + "%";
    }
    _usageGraph.setColor(
        HistogramWidget::colorFrom(cpuUsage, HistogramWidget::Color::WARNING));
    _usageGraph.setText(cpuUsageDisplay);
    stack.registerWidget(std::make_unique<HistogramWidget>(_usageGraph));

    return stack;
}

void Module::Cpu::updateCpuInfo() {
    FileParser cpuInfo =
        FileParserBuilder(CPU_INFOS_FILE).setDelimiter(':').parse();

    _modelName = cpuInfo.get("model name");
    _coreCount = cpuInfo.get<int>("cpu cores", ValueParser::toInt);
    _threadCount = cpuInfo.get<int>("siblings", ValueParser::toInt);
}

void Module::Cpu::updateCpuStat() {
    FileParser cpuStat =
        FileParserBuilder(CPU_STAT_FILE).setDelimiter(' ').parse();

    std::optional<std::string> cpuLine = cpuStat.get("cpu");

    if (cpuLine.has_value()) {
        size_t totalUser = 0;
        size_t totalUserLow = 0;
        size_t totalSys = 0;
        size_t totalIdle = 0;

        std::istringstream stream(cpuLine.value());
        stream >> totalUser >> totalUserLow >> totalSys >> totalIdle;
        size_t totalActive = totalUser + totalUserLow + totalSys;

        if (_lastTotalActive.has_value() && _lastTotalIdle.has_value()) {
            size_t diffTotalActive = totalActive - _lastTotalActive.value();
            size_t diffTotalIdle = totalIdle - _lastTotalIdle.value();

            float percent = static_cast<float>(diffTotalActive) /
                            static_cast<float>(diffTotalActive + diffTotalIdle);
            _usageGraph.pushValue(percent);
        }

        _lastTotalActive = totalActive;
        _lastTotalIdle = totalIdle;
    }
}

std::string Module::Cpu::getIdentifier() const { return "cpu"; }

std::string Module::Cpu::getDisplayName() const { return "CPU Information"; }
