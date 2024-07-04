/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** main
*/

#include <algorithm>
#include <iostream>
#include <memory>

#include "Krell.hpp"
#include "Modules/Battery/Battery.hpp"
#include "Modules/Cpu/Cpu.hpp"
#include "Modules/Memory/Memory.hpp"
#include "Modules/OS/DateTime.hpp"
#include "Modules/OS/Host.hpp"
#include "Modules/OS/Os.hpp"
#include "Ui/Display/Debug/DebugDisplay.hpp"
#include "Ui/Display/Ncurses/NcursesDisplay.hpp"
#include "Ui/Display/SFML/SfmlDisplay.hpp"

#ifdef IMGUI_BACKEND
#include "Ui/Display/Imgui/ImguiDisplay.hpp"

constexpr const std::string DEFAULT_DISPLAY_MODE = "imgui";
#endif

#ifndef IMGUI_BACKEND
constexpr const std::string DEFAULT_DISPLAY_MODE = "ncurses";
#endif

static std::string parse_display_mode(int argc, char** argv) {
    std::string mode = DEFAULT_DISPLAY_MODE;

    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i]) == "--display" && i + 1 < argc) {
            mode = argv[i + 1];
            break;
        }
    }

    return mode;
}

static std::optional<std::vector<std::string>> parse_modules(int argc,
                                                             char** argv) {
    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i]) == "--modules" && i + 1 < argc) {
            std::vector<std::string> modules;
            std::string modulesStr = argv[i + 1];

            std::replace(modulesStr.begin(), modulesStr.end(), ',', ' ');
            std::istringstream iss(modulesStr);

            for (std::string module; iss >> module;) {
                modules.push_back(module);
            }

            return modules;
        }
    }

    return std::nullopt;
}

static bool is_module_enabled(
    const std::string& module,
    const std::optional<std::vector<std::string>>& enabledModules) {
    if (enabledModules == std::nullopt) {
        return true;
    }

    return std::ranges::find(*enabledModules, module) != enabledModules->end();
}

int main(int argc, char** argv) {
    std::string displayMode = parse_display_mode(argc, argv);
    std::optional<std::vector<std::string>> enabledModules =
        parse_modules(argc, argv);

    Krell::Core core;
    std::unique_ptr<Krell::IDisplay> display;

    core.registerModule(std::make_unique<Module::Host>(
        is_module_enabled("host", enabledModules)));
    core.registerModule(
        std::make_unique<Module::OS>(is_module_enabled("os", enabledModules)));
    core.registerModule(std::make_unique<Module::DateTime>(
        is_module_enabled("datetime", enabledModules)));
    core.registerModule(std::make_unique<Module::Cpu>(
        is_module_enabled("cpu", enabledModules)));
    core.registerModule(std::make_unique<Module::Memory>(
        is_module_enabled("memory", enabledModules)));
    core.registerModule(std::make_unique<Module::Battery>(
        is_module_enabled("battery", enabledModules)));

    if (displayMode == "debug") {
        display = std::make_unique<DebugDisplay>();
    } else if (displayMode == "ncurses") {
        display = std::make_unique<NcursesDisplay>();
    } else if (displayMode == "sfml") {
        display = std::make_unique<SFMLDisplay>();
    }
#ifdef IMGUI_BACKEND
    else if (displayMode == "imgui") {
        display = std::make_unique<ImguiDisplay>();
    }
#endif

    if (display == nullptr) {
        std::cerr << "Invalid display mode: " << displayMode << '\n';
        return 84;
    }

    display->renderLoop(core);
    return 0;
}
