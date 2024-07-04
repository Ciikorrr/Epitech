/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Commands
*/

#include "CommandHandler.hpp"

#include <functional>
#include <iostream>
#include <unordered_map>

#include "gui/Client/State.hpp"
#include "gui/Util.hpp"

namespace zizi::client {

void CommandHandler::handleCommand(std::string &name, std::istringstream &input)
{
    static const std::
        unordered_map<std::string, std::function<void(CommandHandler *, std::istringstream &)>>
            commands{
                {"msz", &CommandHandler::msz},
                {"bct", &CommandHandler::bct},
                {"tna", &CommandHandler::tna},
                {"sgt", &CommandHandler::sgt},
                {"enw", &CommandHandler::enw},
                {"pnw", &CommandHandler::pnw},
                {"pdi", &CommandHandler::pdi},
                {"ppo", &CommandHandler::ppo},
                {"plv", &CommandHandler::plv},
                {"pin", &CommandHandler::pin},
                {"pex", &CommandHandler::pex},
                {"pbc", &CommandHandler::pbc},
                {"pic", &CommandHandler::pic},
                {"pie", &CommandHandler::pie},
                {"pfk", &CommandHandler::pfk},
                {"pdr", &CommandHandler::pdr},
                {"pgt", &CommandHandler::pgt},
                {"eht", &CommandHandler::eht},
                {"ebo", &CommandHandler::ebo},
                {"edi", &CommandHandler::edi},
                {"seg", &CommandHandler::seg},
                {"smg", &CommandHandler::smg},
            };

    if (_state->map.size == sf::Vector2u{0, 0} && name != "msz") {
        util::debug("map not initialized, ignoring command {}", name);
        return;
    }
    if (!commands.contains(name)) {
        util::debug("unhandled: {}", name);
        return;
    }

    commands.at(name)(this, input);
}

// map size
void CommandHandler::msz(std::istringstream &input)
{
    unsigned x = 0, y = 0;
    input >> x >> y;

    _state->initMap({x, y});
    _events->push({EventType::MapSize, Event::MapSize{{x, y}}});
}

// content of the map (all the tiles)
void CommandHandler::bct(std::istringstream &input)
{
    unsigned x = 0, y = 0;
    input >> x >> y;

    if (!_state->map.hasTile({x, y})) {
        util::debug("bct: tile {} {} not found", x, y);
        return;
    }

    for (auto &resource : _state->map.tile({x, y}).resources) {
        input >> resource;
    }
    _events->push({EventType::MapContent, Event::MapContent{}});
}

// name of all the teams
void CommandHandler::tna(std::istringstream &input)
{
    Team team{
        .color = RESSOURCE_COLORS.at(_state->teams.size() % RESSOURCE_COLORS.size()),
    };
    input >> team.name;

    _state->teams.insert({team.name, team});
    _events->push({EventType::TeamCreated, Event::TeamCreated{team.name}});
}

// time unit request
void CommandHandler::sgt(std::istringstream &input)
{
    unsigned timeUnit = 0;
    input >> timeUnit;

    _state->timeUnit = timeUnit;
}

// connection of a new player
void CommandHandler::pnw(std::istringstream &input)
{
    Player player{};
    input >> player.id >> player.position.x >> player.position.y >> player.orientation >>
        player.level >> player.team;

    _state->players.insert({player.id, player});
    _events->push({EventType::PlayerCreated, Event::PlayerCreated{player.id}});

    if (_state->teams.contains(player.team)) {
        _state->teams.at(player.team).playerCount += 1;
    }
}

// player death
void CommandHandler::pdi(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    if (!_state->players.contains(id)) {
        util::debug("pdi: player {} not found", id);
        return;
    }

    auto playerTeam = _state->players.at(id).team;
    _state->players.erase(id);
    _events->push({EventType::PlayerDestroyed, Event::PlayerDestroyed{id}});

    if (_state->teams.contains(playerTeam)) {
        _state->teams.at(playerTeam).playerCount -= 1;
    }
}

// player's position
void CommandHandler::ppo(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    if (!_state->players.contains(id)) {
        util::debug("ppo: player {} not found", id);
        return;
    }

    auto &player = _state->players.at(id);
    input >> player.position.x >> player.position.y >> player.orientation;
    _events->push({EventType::PlayerMoved, Event::PlayerMoved{id, player.position}});
}

// player level
void CommandHandler::plv(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    if (!_state->players.contains(id)) {
        util::debug("plv: player {} not found", id);
        return;
    }

    auto &player = _state->players.at(id);
    input >> player.level;

    _events->push({EventType::PlayerLevelUp, Event::PlayerLevelUp{id, player.level}});
}

// player inventory
void CommandHandler::pin(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    if (!_state->players.contains(id)) {
        util::debug("pin: player {} not found", id);
        return;
    }

    for (auto &resource : _state->players.at(id).inventory) {
        input >> resource;
    }
    _events->push({EventType::PlayerInventory, Event::PlayerInventory{id}});
}

// explulsion
void CommandHandler::pex(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    _events->push({EventType::PlayerExpulsed, Event::PlayerExpulsed{id}});
}

// broadcast
void CommandHandler::pbc(std::istringstream &input)
{
    PlayerId id{};
    std::string message;

    input >> id >> message;
    _events->push({EventType::PlayerBroadcast, Event::PlayerBroadcast{id, message}});
}

// incantation start
void CommandHandler::pic(std::istringstream &input)
{
    Player::Level level{};
    Position position{};
    PlayerId id{};

    input >> position.x >> position.y >> level >> id;

    _events->push({EventType::IncantationStart, Event::IncantationStart{id, level, position}});

}

// incantation end
void CommandHandler::pie(std::istringstream &input)
{
    Position position{};

    input >> position.x >> position.y;
    _events->push({EventType::IncantationEnd, Event::IncantationEnd{position}});
}

// ressource dropping
void CommandHandler::pdr(std::istringstream &input)
{
    PlayerId id{};
    int resourceNumber{};
    input >> id >> resourceNumber;

    _events->push({EventType::ResourceDrop, Event::ResourceDrop{id, static_cast<Ressource>(resourceNumber)}});
}

// resource collecting
void CommandHandler::pgt(std::istringstream &input)
{
    PlayerId id{};
    int resourceNumber{};
    input >> id >> resourceNumber;

    _events->push({EventType::ResourceCollect, Event::ResourceCollect{id, static_cast<Ressource>(resourceNumber)}});
}

// egg laying by player
void CommandHandler::pfk(std::istringstream &input)
{
    PlayerId id{};
    input >> id;

    _events->push({EventType::EggLaying, Event::EggLaying{id}});
}

// an egg was laid by a player
void CommandHandler::enw(std::istringstream &input)
{
    int parent{};
    Egg egg{.status = Egg::Status::Egg};

    input >> egg.id >> parent >> egg.position.x >> egg.position.y;
    if (parent >= 0 && _state->players.contains(parent)) {
        egg.parent = _state->players.at(parent).id;
    }

    _state->eggs.insert({egg.id, egg});
    _events->push({EventType::EggCreated, Event::EggCreated{egg.id}});
}

// egg is mature
void CommandHandler::eht(std::istringstream &input)
{
    EggId eggId{};
    input >> eggId;
    _events->push({EventType::EggMature, Event::EggMature{eggId}});
}

// death of an egg
void CommandHandler::edi(std::istringstream &input)
{
    EggId eggId{};
    input >> eggId;

    if (!_state->eggs.contains(eggId)) {
        util::debug("ebo: egg {} not found", eggId);
        return;
    }

    _state->eggs.erase(eggId);
    _events->push({EventType::EggDestroyed, Event::EggDestroyed{eggId}});
}

// player connection from egg
void CommandHandler::ebo(std::istringstream &input)
{
    EggId eggId{};
    input >> eggId;

    _events->push({EventType::EggPlayerConnection, Event::EggPlayerConnection{eggId}});
}

// end of game
void CommandHandler::seg(std::istringstream &input)
{
    TeamId teamId{};
    input >> teamId;

    _events->push({EventType::GameEnd, Event::GameEnd{teamId}});
}

// message from server
void CommandHandler::smg(std::istringstream &input)
{
    std::string message{};
    input >> message;

    _events->push({EventType::ServerMessage, Event::ServerMessage{message}});
}

}  // namespace zizi::client
