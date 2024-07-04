/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** EventLog
*/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <deque>
#include <string>
#include <unordered_map>

#include "gui/Client/Event.hpp"

namespace zizi::gui {

struct EventDisplay {
    sf::Color color;
    std::string name;
};

static const std::unordered_map<client::EventType, EventDisplay> EVENT_DISPLAYS = {
    {client::EventType::MapSize, {sf::Color(253, 224, 71), "MapSize"}},
    {client::EventType::TeamCreated, {sf::Color(52, 211, 153), "TeamCreated"}},
    {client::EventType::PlayerCreated, {sf::Color(13, 148, 136), "PlayerCreated"}},
    {client::EventType::PlayerDestroyed, {sf::Color(79, 70, 229), "PlayerDestroyed"}},
    {client::EventType::PlayerMoved, {sf::Color(14, 165, 233), "PlayerMoved"}},
    {client::EventType::PlayerLevelUp, {sf::Color(79, 70, 229), "PlayerLevelUp"}},
    {client::EventType::PlayerInventory, {sf::Color(2, 132, 199), "PlayerInventory"}},
    {client::EventType::PlayerExpulsed, {sf::Color(79, 70, 229), "PlayerExpulsed"}},
    {client::EventType::PlayerBroadcast, {sf::Color(244, 114, 182), "PlayerBroadcast"}},
    {client::EventType::IncantationStart, {sf::Color(244, 63, 94), "IncantationStart"}},
    {client::EventType::IncantationEnd, {sf::Color(244, 63, 94), "IncantationEnd"}},
    {client::EventType::ResourceDrop, {sf::Color(253, 230, 138), "ResourceDrop"}},
    {client::EventType::ResourceCollect, {sf::Color(253, 230, 138), "ResourceCollect"}},
    {client::EventType::EggCreated, {sf::Color(251, 146, 60), "EggCreated"}},
    {client::EventType::EggLaying, {sf::Color(251, 146, 60), "EggLaying"}},
    {client::EventType::EggMature, {sf::Color(251, 146, 60), "EggMature"}},
    {client::EventType::EggDestroyed, {sf::Color(251, 146, 60), "EggDestroyed"}},
    {client::EventType::EggPlayerConnection, {sf::Color(251, 146, 60), "EggPlayerConnection"}},
    {client::EventType::GameEnd, {sf::Color(220, 38, 38), "GameEnd"}},
    {client::EventType::ServerMessage, {sf::Color(220, 38, 38), "ServerMessage"}},
};

struct EventLogEntry {
    client::EventType type;
    sf::Color color;
    std::string message;
};

class EventLog {
   public:
    void pushEvent(const client::Event &event);
    [[nodiscard]] const std::deque<EventLogEntry> &entries() const;

   private:
    std::string eventMessage(const client::Event &event);
    std::string eventMessage(const client::Event::MapSize &event);
    std::string eventMessage(const client::Event::MapContent &event);
    std::string eventMessage(const client::Event::TeamCreated &event);
    std::string eventMessage(const client::Event::PlayerCreated &event);
    std::string eventMessage(const client::Event::PlayerDestroyed &event);
    std::string eventMessage(const client::Event::PlayerMoved &event);
    std::string eventMessage(const client::Event::PlayerLevelUp &event);
    std::string eventMessage(const client::Event::PlayerInventory &event);
    std::string eventMessage(const client::Event::PlayerExpulsed &event);
    std::string eventMessage(const client::Event::PlayerBroadcast &event);
    std::string eventMessage(const client::Event::IncantationStart &event);
    std::string eventMessage(const client::Event::IncantationEnd &event);
    std::string eventMessage(const client::Event::ResourceDrop &event);
    std::string eventMessage(const client::Event::ResourceCollect &event);
    std::string eventMessage(const client::Event::EggCreated &event);
    std::string eventMessage(const client::Event::EggLaying &event);
    std::string eventMessage(const client::Event::EggMature &event);
    std::string eventMessage(const client::Event::EggDestroyed &event);
    std::string eventMessage(const client::Event::EggPlayerConnection &event);
    std::string eventMessage(const client::Event::GameEnd &event);
    std::string eventMessage(const client::Event::ServerMessage &event);

    std::deque<EventLogEntry> _events;
};

}  // namespace zizi::gui
