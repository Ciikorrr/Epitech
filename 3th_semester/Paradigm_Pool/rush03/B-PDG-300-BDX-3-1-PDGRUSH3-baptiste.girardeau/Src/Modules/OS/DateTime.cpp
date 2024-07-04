#include "DateTime.hpp"

#include <chrono>

void Module::DateTime::update() {
    _now =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

std::time_t Module::DateTime::getDateTime() const { return this->_now; }

WidgetStack Module::DateTime::getWidgets() {
    WidgetStack stack("Date and time", this->getIdentifier());

    struct tm *now = std::localtime(&this->_now);
    char date[80];
    char time[80];
    std::strftime(date, 80, "%F", now);
    std::strftime(time, 80, "%T", now);

    stack.registerWidget(std::make_unique<TextWidget>("Date", date));
    stack.registerWidget(std::make_unique<TextWidget>("Time", time));

    return stack;
}

std::string Module::DateTime::getIdentifier() const { return "datetime"; }

std::string Module::DateTime::getDisplayName() const { return "Date and time"; }
