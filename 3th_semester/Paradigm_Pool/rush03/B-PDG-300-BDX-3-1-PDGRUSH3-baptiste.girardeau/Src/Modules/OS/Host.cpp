/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Host
*/

#include "Host.hpp"

#include <ctime>
#include <memory>
#include <optional>

#include "../../Parse/FileParser.hpp"
#include "../../Parse/ValueParser.hpp"
#include "../../Ui/Widgets/Widget.hpp"

constexpr const char* CPU_STAT_FILE = "/proc/stat";

void Module::Host::update() {
    if (!_hostname.has_value()) {
        _hostname = getHostname();
    }

    if (!_username.has_value()) {
        _username = getUsername();
    }

    _uptime = getUptime();
}

WidgetStack Module::Host::getWidgets() {
    WidgetStack stack("Host information", this->getIdentifier());

    stack.registerWidget(
        std::make_unique<TextWidget>("Hostname", _hostname.value_or("Unknown"),
                                     TextWidget::colorFrom(_hostname)));

    stack.registerWidget(
        std::make_unique<TextWidget>("Username", _username.value_or("Unknown"),
                                     TextWidget::colorFrom(_username)));

    std::string uptimeDisplay = "Unknown";
    if (_uptime.has_value()) {
        uptimeDisplay = std::ctime(&_uptime.value());
    }

    stack.registerWidget(std::make_unique<TextWidget>(
        "Boot time", uptimeDisplay, TextWidget::colorFrom(_uptime)));

    return stack;
}

std::optional<std::string> Module::Host::getHostname() {
    char hostname[1024];

    if (gethostname(hostname, 1024) == -1) {
        return std::nullopt;
    } else {
        return std::string(hostname);
    }
}

std::optional<std::string> Module::Host::getUsername() {
    char* username = getlogin();

    if (username == nullptr) {
        return std::nullopt;
    } else {
        return std::string(username);
    }
}

std::optional<std::time_t> Module::Host::getUptime() {
    FileParser cpuStat =
        FileParserBuilder(CPU_STAT_FILE).setDelimiter(' ').parse();

    return cpuStat.get<int>("btime", ValueParser::toInt);
}

std::string Module::Host::getIdentifier() const { return "host"; }

std::string Module::Host::getDisplayName() const { return "Host informations"; }
