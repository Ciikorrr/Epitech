/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** EventLog
*/

#include "EventLog.hpp"

#include <format>
#include <iomanip>

namespace zizi::gui {

std::string getCurrentTime()
{
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    return oss.str();
}

void EventLog::pushEvent(const client::Event &event)
{
    if (_events.size() >= 2000) {
        _events.pop_back();
    }

    auto message = eventMessage(event);

    if (!message.empty()) {
        const auto &eventDisplay = EVENT_DISPLAYS.at(event.type);

        _events.push_front(EventLogEntry{
            event.type,
            eventDisplay.color,
            std::format("{} [{}] {}", getCurrentTime(), eventDisplay.name, eventMessage(event))
        });
    }
}

const std::deque<EventLogEntry> &EventLog::entries() const
{
    return _events;
}

std::string EventLog::eventMessage(const client::Event &event)
{
    return std::visit([this](auto &&arg) { return eventMessage(arg); }, event.inner);
}

std::string EventLog::eventMessage(const client::Event::MapSize &event)
{
    return std::format("received map size: {}x{}", event.size.x, event.size.y);
}

std::string EventLog::eventMessage(const client::Event::MapContent &event)
{
    return "";  // not displayed
}

std::string EventLog::eventMessage(const client::Event::TeamCreated &event)
{
    return std::format("new team created: {}", event.name);
}

std::string EventLog::eventMessage(const client::Event::PlayerCreated &event)
{
    return std::format("new player created: {}", event.id);
}

std::string EventLog::eventMessage(const client::Event::PlayerDestroyed &event)
{
    return std::format("player destroyed: {}", event.id);
}

std::string EventLog::eventMessage(const client::Event::PlayerMoved &event)
{
    return std::format("player {} moved to ({}, {})", event.id, event.position.x, event.position.y);
}

std::string EventLog::eventMessage(const client::Event::PlayerLevelUp &event)
{
    return std::format("player {} level up to {}", event.id, event.level);
}

std::string EventLog::eventMessage(const client::Event::PlayerInventory &event)
{
    return std::format("updated player {} inventory", event.id);
}

std::string EventLog::eventMessage(const client::Event::PlayerExpulsed &event)
{
    return std::format("player {} expulsed", event.id);
}

std::string EventLog::eventMessage(const client::Event::PlayerBroadcast &event)
{
    return std::format("from player {}: {}", event.id, event.message);
}

std::string EventLog::eventMessage(const client::Event::IncantationStart &event)
{
    return std::format("incantation started by player {} at ({}, {})", event.id, event.position.x, event.position.y);
}

std::string EventLog::eventMessage(const client::Event::IncantationEnd &event)
{
    return std::format("incantation ended at ({}, {})", event.position.x, event.position.y);
}

std::string EventLog::eventMessage(const client::Event::ResourceDrop &event)
{
    return std::format("{} dropped by player {}", client::RESSOURCE_NAMES.at(static_cast<int>(event.resource)), event.id);
}

std::string EventLog::eventMessage(const client::Event::ResourceCollect &event)
{
    return std::format("{} collected by player {}", client::RESSOURCE_NAMES.at(static_cast<int>(event.resource)), event.id);
}

std::string EventLog::eventMessage(const client::Event::EggCreated &event)
{
    return std::format("new egg created: {}", event.id);
}

std::string EventLog::eventMessage(const client::Event::EggLaying &event)
{
    return std::format("egg laying by player {}", event.id);
}

std::string EventLog::eventMessage(const client::Event::EggMature &event)
{
    return std::format("egg {} is mature", event.id);
}

std::string EventLog::eventMessage(const client::Event::EggDestroyed &event)
{
    return std::format("egg {} destroyed", event.id);
}

std::string EventLog::eventMessage(const client::Event::EggPlayerConnection &event)
{
    return std::format("player connected from egg {}", event.id);
}

std::string EventLog::eventMessage(const client::Event::GameEnd &event)
{
    return std::format("game won by team {}", event.teamId);
}

std::string EventLog::eventMessage(const client::Event::ServerMessage &event)
{
    return std::format("server message: {}", event.message);
}

}  // namespace zizi::gui
