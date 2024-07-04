#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#include "Memory.hpp"

constexpr const char* MEMINFO_FILE = "/proc/meminfo";
constexpr const float GIGABYTE = 1024 * 1024;

std::optional<std::size_t> Module::Memory::getMemTotalKB() const {
    return this->_memTotalKB;
}

std::optional<std::size_t> Module::Memory::getMemFreeKB() const {
    return this->_memFreeKB;
}

std::optional<std::size_t> Module::Memory::getMemAvailableKB() const {
    return this->_memAvailableKB;
}

std::optional<std::size_t> Module::Memory::getSwapTotalKB() const {
    return this->_swapTotalKB;
}

std::optional<std::size_t> Module::Memory::getSwapFreeKB() const {
    return this->_swapFreeKB;
}

WidgetStack Module::Memory::getWidgets() {
    WidgetStack stack("Memory Information", this->getIdentifier());

    std::string memTotalDisplay = "Unknown";
    std::string memFreeDisplay = "Unknown";
    std::string memAvailableDisplay = "Unknown";
    std::string swapTotalDisplay = "Unknown";
    std::string swapFreeDisplay = "Unknown";

    if (_memTotalKB.has_value())
        memTotalDisplay = std::to_string(static_cast<float>(this->_memTotalKB.value()) / GIGABYTE) + " GB";
    if (_memFreeKB.has_value())
        memFreeDisplay = std::to_string(static_cast<float>(this->_memFreeKB.value()) / GIGABYTE) + " GB";
    if (_memAvailableKB.has_value())
        memAvailableDisplay = std::to_string(static_cast<float>(this->_memAvailableKB.value()) / GIGABYTE) + " GB";
    if (_swapTotalKB.has_value())
        swapTotalDisplay = std::to_string(static_cast<float>(this->_swapTotalKB.value()) / GIGABYTE) + " GB";
    if (_swapFreeKB.has_value())
        swapFreeDisplay = std::to_string(static_cast<float>(this->_swapFreeKB.value()) / GIGABYTE) + " GB";

    stack.registerWidget(
        std::make_unique<TextWidget>("Total memory", memTotalDisplay,
                                     TextWidget::colorFrom(this->_memTotalKB)));
    stack.registerWidget(
        std::make_unique<TextWidget>("Free memory", memFreeDisplay,
                                     TextWidget::colorFrom(this->_memFreeKB)));
    stack.registerWidget(
        std::make_unique<TextWidget>("Available memory", memAvailableDisplay,
                                     TextWidget::colorFrom(this->_memAvailableKB)));
    stack.registerWidget(
        std::make_unique<TextWidget>("Total swap", swapTotalDisplay,
                                     TextWidget::colorFrom(this->_swapTotalKB)));
    stack.registerWidget(
        std::make_unique<TextWidget>("Free swap", swapFreeDisplay,
                                     TextWidget::colorFrom(this->_swapFreeKB)));

    return stack;
}

void Module::Memory::retrieveMemoryInfos() {
    std::ifstream stream(MEMINFO_FILE);
    std::string line;
    while (stream) {
        std::getline(stream, line);
        this->_memeInfoContent.push_back(line);
    }
}

void Module::Memory::update() {
    this->retrieveMemoryInfos();
    for(auto& str : this->_memeInfoContent) {
        if (const size_t delimPos = str.find(' '); delimPos != std::string::npos) {
            const std::string key = str.substr(0, delimPos);
            if (key == "MemTotal:") {
                this->_memTotalKB = stringToSizeT(str.substr(delimPos + 1));
            }
            if (key == "MemFree:") {
                this->_memFreeKB = stringToSizeT(str.substr(delimPos + 1));
            }
            if (key == "MemAvailable:") {
                this->_memAvailableKB = stringToSizeT(str.substr(delimPos + 1));
            }
            if (key == "SwapTotal:") {
                this->_swapTotalKB = stringToSizeT(str.substr(delimPos + 1));
            }
            if (key == "SwapFree:") {
                this->_swapFreeKB = stringToSizeT(str.substr(delimPos + 1));
            }
        }
    }
}

void Module::Memory::printMemInfoList() const {
    for (auto const &i: this->_memeInfoContent) {
        std::cout << i << "\n";
    }
}

size_t Module::Memory::stringToSizeT(const std::string& str) {
    std::stringstream sstream(str);
    size_t result;
    sstream >> result;
    return result;
}


std::string Module::Memory::getIdentifier() const {
    return "memory";
}

std::string Module::Memory::getDisplayName() const {
    return "Memory informations";
}
