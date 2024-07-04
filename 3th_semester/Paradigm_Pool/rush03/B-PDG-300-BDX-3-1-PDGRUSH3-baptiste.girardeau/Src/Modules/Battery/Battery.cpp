/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGRUSH3-baptiste.girardeau
** File description:
** Battery
*/

#include "Battery.hpp"

#include <memory>
#include <string>

#include "../../Parse/FileParser.hpp"
#include "../../Parse/ValueParser.hpp"

constexpr const char* BATTERY_FILE = "/sys/class/power_supply/BAT0/uevent";

void Module::Battery::update() {
    FileParser batteryInfo =
        FileParserBuilder(BATTERY_FILE).setDelimiter('=').parse();

    _batteryModelName = batteryInfo.get("POWER_SUPPLY_MODEL_NAME");
    _batteryStatus = batteryInfo.get("POWER_SUPPLY_STATUS");
    _currentCapacity =
        batteryInfo.get<int>("POWER_SUPPLY_CAPACITY", ValueParser::toInt);
}

WidgetStack Module::Battery::getWidgets() {
    WidgetStack stack("Battery Information", this->getIdentifier());

    stack.registerWidget(std::make_unique<TextWidget>(
        "Model Name", _batteryModelName.value_or("Unknown"),
        TextWidget::colorFrom(_batteryModelName)));

    TextWidget::Color batteryTextLevel = TextWidget::colorFrom(_batteryStatus);
    if (_batteryStatus.has_value() && _batteryStatus.value() == "Charging") {
        batteryTextLevel = TextWidget::Color::SUCCESS;
    }

    stack.registerWidget(std::make_unique<TextWidget>(
        "Status", _batteryStatus.value_or("Unknown"), batteryTextLevel));

    std::string capacityDisplay = "Unknown";
    if (_currentCapacity.has_value()) {
        capacityDisplay = std::to_string(_currentCapacity.value()) + "%";
    }

    stack.registerWidget(
        std::make_unique<TextWidget>("Percentage", capacityDisplay,
                                     TextWidget::colorFrom(_currentCapacity)));
    return stack;
}

std::string Module::Battery::getIdentifier() const { return "battery"; }

std::string Module::Battery::getDisplayName() const {
    return "Battery Information";
}
