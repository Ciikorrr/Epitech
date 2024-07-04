/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** State
*/

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace zizi::client {

using PlayerId = std::uint32_t;
using EggId = std::uint32_t;
using TeamId = std::string;

using Position = sf::Vector2u;

struct Team {
    TeamId name;
    sf::Color color;
    unsigned playerCount;
};

enum class Ressource : uint8_t {
    Food = 0,
    Linemate = 1,
    Deraumere = 2,
    Siblur = 3,
    Phiras = 4,
    Mendiane = 5,
    Thystam = 6,
    SIZE = 7,
};

using Inventory = std::array<unsigned, static_cast<size_t>(Ressource::SIZE)>;

struct Player {
    using Level = int;

    PlayerId id;
    TeamId team;
    Position position;
    Level level;
    Inventory inventory;

    enum class Orientation : std::uint8_t {
        N = 1,
        E = 2,
        S = 3,
        W = 4,
    } orientation;

    enum class State : std::uint8_t {
        Alive,  /// Do not set only for comparison
        Idle,
        Incanting,
        LayingEgg,
        Dropping,
        Dead,  /// Do not set only for comparison
        // Expulsed,
    };
};

struct Egg {
    EggId id;
    Position position;
    std::optional<PlayerId> parent;

    enum class Status : std::uint8_t {
        Egg,
        HatchedEgg,
        DeadEgg,
    } status;
};

struct Tile {
    Position position;
    Inventory resources;
};

struct Map {
    sf::Vector2u size;
    std::vector<Tile> tiles;

    [[nodiscard]] bool hasTile(const Position pos) const;
    [[nodiscard]] Tile &tile(const Position pos);
    [[nodiscard]] const Tile &tile(const Position pos) const;

    [[nodiscard]] Inventory getTotalResources() const;
};

struct State {
    Map map;
    unsigned timeUnit;

    std::unordered_map<TeamId, Team> teams;
    std::unordered_map<PlayerId, Player> players;
    std::unordered_map<EggId, Egg> eggs;

    void initMap(const sf::Vector2u size);
    [[nodiscard]] std::vector<const Player *> playersAt(const Position pos) const;
    [[nodiscard]] std::vector<const Egg *> eggsAt(const Position pos) const;
};

std::istream &operator>>(std::istream &input, Player::Orientation &orientation);

const static std::array RESSOURCE_COLORS = {
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Yellow,
    sf::Color::Magenta,
    sf::Color::Cyan,
    sf::Color::White
};

constexpr static std::array RESSOURCE_NAMES = {
    "Food",
    "Linemate",
    "Deraumere",
    "Siblur",
    "Phiras",
    "Mendiane",
    "Thystam",
};

}  // namespace zizi::client
