/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Event
*/

#pragma once

#include <mutex>
#include <variant>

#include "gui/Client/State.hpp"

namespace zizi::client {

enum class EventType {
    MapSize,
    MapContent,
    TeamCreated,
    PlayerCreated,
    PlayerDestroyed,
    PlayerMoved,
    PlayerLevelUp,
    PlayerInventory,
    PlayerExpulsed,
    PlayerBroadcast,
    IncantationStart,
    IncantationEnd,
    ResourceDrop,
    ResourceCollect,
    EggCreated,
    EggLaying,
    EggMature,
    EggDestroyed,
    EggPlayerConnection,
    GameEnd,
    ServerMessage,
    SIZE,
};

struct Event {
    struct MapSize {
        sf::Vector2u size;
    };

    struct MapContent {};

    struct TeamCreated {
        TeamId name;
    };

    struct PlayerCreated {
        PlayerId id;
    };

    struct PlayerDestroyed {
        PlayerId id;
    };

    struct PlayerMoved {
        PlayerId id;
        Position position;
    };

    struct PlayerLevelUp {
        PlayerId id;
        Player::Level level;
    };

    struct PlayerInventory {
        PlayerId id;
    };

    struct PlayerExpulsed {
        PlayerId id;
    };

    struct PlayerBroadcast {
        PlayerId id;
        std::string message;
    };

    struct IncantationStart {
        PlayerId id;
        Player::Level level;
        Position position;
    };

    struct IncantationEnd {
        Position position;
    };

    struct ResourceDrop {
        PlayerId id;
        Ressource resource;
    };

    struct ResourceCollect {
        PlayerId id;
        Ressource resource;
    };

    struct EggCreated {
        EggId id;
    };

    struct EggLaying {
        PlayerId id;
    };

    struct EggMature {
        EggId id;
    };

    struct EggDestroyed {
        EggId id;
    };

    struct EggPlayerConnection {
        EggId id;
    };

    struct GameEnd {
        TeamId teamId;
    };

    struct ServerMessage {
        std::string message;
    };

    EventType type;
    std::variant<
        MapSize,
        MapContent,
        TeamCreated,
        PlayerCreated,
        PlayerDestroyed,
        PlayerMoved,
        PlayerLevelUp,
        PlayerInventory,
        PlayerExpulsed,
        PlayerBroadcast,
        IncantationStart,
        IncantationEnd,
        ResourceDrop,
        ResourceCollect,
        EggCreated,
        EggLaying,
        EggMature,
        EggDestroyed,
        EggPlayerConnection,
        GameEnd,
        ServerMessage>
        inner;
};

template <typename T>
class EventQueue final {
   public:
    void push(T event)
    {
        std::lock_guard lock(_mutex);
        _events.push_back(std::move(event));
    }

    std::vector<T> clear()
    {
        std::lock_guard lock(_mutex);
        std::vector<T> events = std::move(_events);
        _events.clear();
        return events;
    }

   private:
    std::vector<T> _events;
    std::mutex _mutex;
};

}  // namespace zizi::client
