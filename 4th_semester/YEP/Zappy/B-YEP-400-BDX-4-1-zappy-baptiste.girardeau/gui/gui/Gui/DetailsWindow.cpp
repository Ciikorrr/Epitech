/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DetailsWindow
*/

#include "DetailsWindow.hpp"

#include <algorithm>
#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <string>

#include "Gui.hpp"
#include "gui/Client/State.hpp"
#include "gui/Gui/EventLog.hpp"
#include "gui/Util.hpp"

namespace zizi::gui {

void DetailsWindow::renderWindow()
{
    auto window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground;

    ImGui::SetNextWindowSize({500, 700});
    ImGui::Begin("dock", nullptr, window_flags);

    auto dock = ImGui::DockSpace(ImGui::GetID("dock"));
    ImGui::DockBuilderDockWindow("Game", dock);
    ImGui::DockBuilderDockWindow("Tile", dock);
    ImGui::DockBuilderDockWindow("Player", dock);
    ImGui::DockBuilderDockWindow("Logs", dock);
    ImGui::DockBuilderFinish(dock);
    ImGui::End();

    renderGameWindow();
    renderTileWindow();
    renderPlayerWindow();
    renderLogWindow();
}

void DetailsWindow::renderGameWindow()
{
    ImGui::Begin("Game");
    ImGui::Text("Time unit: %d", _state->clientState.timeUnit);

    if (ImGui::CollapsingHeader("Teams", ImGuiTreeNodeFlags_DefaultOpen)) {
        for (const auto &[id, team] : _state->clientState.teams) {
            widget::Badge(team.color);
            ImGui::SameLine();
            ImGui::Text("%s (%d players)", id.c_str(), team.playerCount);
        }
    }

    if (ImGui::CollapsingHeader("Map resources", ImGuiTreeNodeFlags_DefaultOpen)) {
        widget::Inventory(_state->clientState.map.getTotalResources());
    }

    if (ImGui::CollapsingHeader("Players", ImGuiTreeNodeFlags_DefaultOpen)) {
        if (_state->clientState.players.empty()) {
            ImGui::Text("No player");
        }

        auto sortedPlayers = util::map_values(_state->clientState.players);
        std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const auto &a, const auto &b) {
            return (a.team == b.team) ? a.level > b.level : a.team < b.team;
        });

        for (const auto &player : sortedPlayers) {
            widget::Player(player, *_state);
        }
    }
    ImGui::End();
}

void DetailsWindow::renderTileWindow()
{
    ImGui::Begin("Tile");

    if (_state->selectedTile.has_value()) {
        auto tile = _state->clientState.map.tile(_state->selectedTile.value());
        ImGui::Text("Position: %d, %d", tile.position.x, tile.position.y);

        if (ImGui::CollapsingHeader("Resources", ImGuiTreeNodeFlags_DefaultOpen)) {
            widget::Inventory(tile.resources);
        }

        if (ImGui::CollapsingHeader("Eggs", ImGuiTreeNodeFlags_DefaultOpen)) {
            auto eggs = _state->clientState.eggsAt(tile.position);
            if (eggs.empty()) {
                ImGui::Text("No egg");
            } else {
                for (const auto &egg : eggs) {
                    auto parent = egg->parent ? std::to_string(static_cast<unsigned>(*egg->parent))
                                              : "server";
                    ImGui::Text("egg #%d (parent: %s)", egg->id, parent.c_str());
                }
            }
        }

        if (ImGui::CollapsingHeader("Players", ImGuiTreeNodeFlags_DefaultOpen)) {
            const auto &players = _state->clientState.playersAt(tile.position);
            if (players.empty()) {
                ImGui::Text("No player");
            } else {
                for (const auto &player : players) {
                    widget::Player(*player, *_state);
                }
            }
        }
    } else {
        ImGui::Text("No tile selected");
    }

    ImGui::End();
}

void DetailsWindow::renderPlayerWindow()
{
    ImGui::Begin("Player");
    if (!_state->focusedPlayer.has_value() && _state->selectedTile.has_value()) {
        auto currentTilePlayers = _state->clientState.playersAt(_state->selectedTile.value());
        if (!currentTilePlayers.empty()) {
            _state->focusedPlayer = currentTilePlayers.front()->id;
        }
    }

    if (_state->focusedPlayer.has_value()) {
        auto player = _state->clientState.players.at(*_state->focusedPlayer);

        widget::Player(player, *_state, false);
        ImGui::Text("Position: %d, %d", player.position.x, player.position.y);
        if (ImGui::CollapsingHeader("Inventory", ImGuiTreeNodeFlags_DefaultOpen)) {
            widget::Inventory(player.inventory);
        }
    } else {
        ImGui::Text("No player focused");
    }
    ImGui::End();
}

void DetailsWindow::renderLogWindow()
{
    ImGui::Begin("Logs");
    auto &eventLogs = _state->eventLog.entries();
    std::vector<EventLogEntry> filteredEvents;

    if (ImGui::CollapsingHeader("Filters")) {
        if (ImGui::Button("All")) {
            std::fill(_state->eventFilter.begin(), _state->eventFilter.end(), true);
        }
        ImGui::SameLine();
        if (ImGui::Button("None")) {
            std::fill(_state->eventFilter.begin(), _state->eventFilter.end(), false);
        }

        for (auto &[eventType, eventDisplay] : EVENT_DISPLAYS) {
            bool *checkbox = &_state->eventFilter[static_cast<int>(eventType)];
            ImGui::Checkbox(eventDisplay.name.c_str(), checkbox);
        }
        ImGui::NewLine();
    }

    int currentEventCount = 0;
    std::copy_if(
        eventLogs.begin(),
        eventLogs.end(),
        std::back_inserter(filteredEvents),
        [&](const auto &event) {
            if (currentEventCount < 200 && _state->eventFilter[static_cast<int>(event.type)]) {
                currentEventCount += 1;
                return true;
            }
            return false;
        }
    );

    ImGui::BeginChild("LogsScrollable", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
    ImGui::SetWindowFontScale(0.85f);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
    ImGuiListClipper clipper;
    clipper.Begin(static_cast<int>(filteredEvents.size()), ImGui::GetTextLineHeightWithSpacing());

    while (clipper.Step()) {
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
            const auto &event = filteredEvents.at(i);
            ImGui::PushStyleColor(ImGuiCol_Text, event.color);
            ImGui::Text("%s", event.message.c_str());
            ImGui::PopStyleColor();
        }
    }
    ImGui::PopStyleVar();
    ImGui::SetWindowFontScale(1.0f);

    clipper.End();
    ImGui::EndChild();

    ImGui::End();
}

namespace widget {
void Badge(const sf::Color color, const std::string &tooltip)
{
    ImGui::PushStyleColor(ImGuiCol_Button, color);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, color);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, color);
    ImGui::Button(" ");
    if (!tooltip.empty() && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
        ImGui::SetTooltip("%s", tooltip.c_str());
    }
    ImGui::PopStyleColor(3);
}

void Inventory(const client::Inventory &inventory)
{
    for (size_t i = 0; i < inventory.size(); i += 1) {
        Badge(client::RESSOURCE_COLORS.at(i));
        ImGui::SameLine();
        ImGui::Text("%d %s", inventory.at(i), client::RESSOURCE_NAMES.at(i));
    }
}

void Player(const client::Player &player, GuiState &state, bool focusButton)
{
    auto team = state.clientState.teams.at(player.team);
    widget::Badge(team.color, "Team: " + team.name);
    ImGui::SameLine();
    ImGui::Text("#%u (level %d)", player.id, player.level);
    if (focusButton) {
        ImGui::SameLine();
        if (ImGui::Button("focus")) {
            state.focusedPlayer = player.id;
            ImGui::SetWindowFocus("Player");
        }
    }
}
}  // namespace widget

}  // namespace zizi::gui
