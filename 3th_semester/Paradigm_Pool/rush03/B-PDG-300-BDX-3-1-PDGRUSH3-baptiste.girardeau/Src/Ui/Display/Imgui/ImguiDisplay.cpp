/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** ImguiDisplay
*/

#ifdef IMGUI_BACKEND

#include "ImguiDisplay.hpp"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <string>

#include "../../../Core/Core.hpp"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/imgui.h"

ImguiDisplay::ImguiDisplay() {
    glfwInit();
    _window = glfwCreateWindow(525, 900, "MyGKrellm", nullptr, nullptr);
    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);  // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.IniFilename = nullptr;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(_window, true);
    ImGui_ImplOpenGL3_Init();
}

ImguiDisplay::~ImguiDisplay() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}

void ImguiDisplay::renderLoop(Krell::Core &core) {
    _core = &core;

    while (!glfwWindowShouldClose(_window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        core.updateStacks();
        ImGui::SetNextWindowPos(ImVec2(60, 60), ImGuiCond_Always);
        for (const auto &stack : core.getStacks()) {
            drawStack(stack);
        }
        renderMenuBar();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(_window);
    }
}

void ImguiDisplay::renderMenuBar() {
    bool hostEnabled = _core->isModuleEnabled("host");
    bool osEnabled = _core->isModuleEnabled("os");
    bool dateTimeEnabled = _core->isModuleEnabled("datetime");
    bool cpuEnabled = _core->isModuleEnabled("cpu");
    bool memoryEnabled = _core->isModuleEnabled("memory");
    bool batteryEnabled = _core->isModuleEnabled("battery");

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Modules")) {
            if (ImGui::MenuItem("Host", nullptr, &hostEnabled)) {
                _core->toggleModule("host");
                _core->updateStacks(true);
            }
            if (ImGui::MenuItem("OS", nullptr, &osEnabled)) {
                _core->toggleModule("os");
                _core->updateStacks(true);
            }
            if (ImGui::MenuItem("Date & Time", nullptr, &dateTimeEnabled)) {
                _core->toggleModule("datetime");
                _core->updateStacks(true);
            }
            if (ImGui::MenuItem("CPU", nullptr, &cpuEnabled)) {
                _core->toggleModule("cpu");
                _core->updateStacks(true);
            }
            if (ImGui::MenuItem("Memory", nullptr, &memoryEnabled)) {
                _core->toggleModule("memory");
                _core->updateStacks(true);
            }
            if (ImGui::MenuItem("Battery", nullptr, &batteryEnabled)) {
                _core->toggleModule("battery");
                _core->updateStacks(true);
            }
            ImGui::EndMenu();
        }

        ImGui::MenuItem("Reorder", nullptr, &_modulesReordering);

        std::chrono::seconds refreshRate = _core->getRefreshRate();
        std::string refreshRateString = std::to_string(refreshRate.count());
        std::string refreshRateLabel =
            "Refresh rate: " + refreshRateString + "s";

        bool isRefreshRate1 = refreshRate.count() == 1;
        bool isRefreshRate2 = refreshRate.count() == 2;
        bool isRefreshRate5 = refreshRate.count() == 5;
        bool isRefreshRate10 = refreshRate.count() == 10;

        if (ImGui::BeginMenu(refreshRateLabel.c_str())) {
            if (ImGui::MenuItem("1 second", nullptr, &isRefreshRate1)) {
                _core->setRefreshRate(std::chrono::seconds(1));
            }
            if (ImGui::MenuItem("2 seconds", nullptr, &isRefreshRate2)) {
                _core->setRefreshRate(std::chrono::seconds(2));
            }
            if (ImGui::MenuItem("5 seconds", nullptr, &isRefreshRate5)) {
                _core->setRefreshRate(std::chrono::seconds(5));
            }
            if (ImGui::MenuItem("10 seconds", nullptr, &isRefreshRate10)) {
                _core->setRefreshRate(std::chrono::seconds(10));
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void ImguiDisplay::drawStack(const WidgetStack &stack) {
    ImGui::Begin(stack.getTitle().c_str(), nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowSize(ImVec2(400, 0), ImGuiCond_Always);

    for (const auto &widget : stack.getWidgets()) {
        drawWidget(widget);
    }

    if (_modulesReordering) {
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
        if (ImGui::Button("Up")) {
            _core->moveModuleUp(stack.getIdentifier());
            _core->updateStacks(true);
        }
        ImGui::SameLine();
        if (ImGui::Button("Down")) {
            _core->moveModuleDown(stack.getIdentifier());
            _core->updateStacks(true);
        }
    }

    ImVec2 pos = ImGui::GetWindowPos();
    ImVec2 size = ImGui::GetWindowSize();
    ImGui::End();
    ImGui::SetNextWindowPos(ImVec2(pos.x, pos.y + size.y + 10));
}

void ImguiDisplay::drawWidget(const Widget *widget) {
    if (auto histogramWidget = dynamic_cast<const HistogramWidget *>(widget)) {
        drawHistogram(histogramWidget);
    } else if (auto textWidget = dynamic_cast<const TextWidget *>(widget)) {
        drawText(textWidget);
    }
}

void ImguiDisplay::drawText(const TextWidget *widget) {
    ImGui::Text("%s", widget->getTitle().c_str());
    ImGui::SameLine();

    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 window_padding = ImGui::GetStyle().WindowPadding;
    ImVec2 text_size = ImGui::CalcTextSize(widget->getText().c_str());
    ImGui::SetCursorPosX(window_size.x - text_size.x - window_padding.x);

    switch (widget->getColor()) {
        case TextWidget::Color::INFO:
            ImGui::PushStyleColor(ImGuiCol_Text,
                                  ImVec4(0.7f, 0.7f, 0.7f, 1.0f));
            break;
        case TextWidget::Color::SUCCESS:
            ImGui::PushStyleColor(ImGuiCol_Text,
                                  ImVec4(0.0f, 0.9f, 0.0f, 1.0f));
            break;
        case TextWidget::Color::WARNING:
            ImGui::PushStyleColor(ImGuiCol_Text,
                                  ImVec4(0.9f, 0.7f, 0.0f, 1.0f));
            break;
        case TextWidget::Color::ERROR:
            ImGui::PushStyleColor(ImGuiCol_Text,
                                  ImVec4(0.9f, 0.0f, 0.0f, 1.0f));
            break;
    }

    ImGui::Text("%s", widget->getText().c_str());
    ImGui::PopStyleColor();
}

void ImguiDisplay::drawHistogram(const HistogramWidget *widget) {
    drawText(widget);

    std::deque<float> values = widget->getValues();
    float *valuesArray = &values[0];

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
    ImGui::PlotHistogram("", valuesArray, static_cast<int>(values.size()), 0,
                         widget->getTitle().c_str(), 0.0f, 1.0f,
                         ImVec2(380, 80));
}

#endif
