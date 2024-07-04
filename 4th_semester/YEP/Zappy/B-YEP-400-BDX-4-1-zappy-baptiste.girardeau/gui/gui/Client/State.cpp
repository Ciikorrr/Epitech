/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** State
*/

#include "State.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace zizi::client {

void State::initMap(const sf::Vector2u size)
{
    map.size = size;
    map.tiles = std::vector<Tile>(static_cast<size_t>(size.x) * size.y);
    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            map.tiles[x + y * size.x].position = {x, y};
        }
    }
}

std::vector<const Player *> State::playersAt(const Position position) const
{
    std::vector<const Player *> result;

    for (auto &[id, player] : players) {
        if (player.position == position) {
            result.push_back(&player);
        }
    }
    return result;
}

std::vector<const Egg *> State::eggsAt(const Position position) const
{
    std::vector<const Egg *> result;

    for (auto &[id, egg] : eggs) {
        if (egg.position == position) {
            result.push_back(&egg);
        }
    }
    return result;
}

bool Map::hasTile(const Position position) const
{
    return position.x < size.x && position.y < size.y;
}

Tile &Map::tile(const Position position)
{
    if (position.x >= size.x || position.y >= size.y) {
        throw std::out_of_range("Invalid tile position");
    }

    return tiles.at(position.x + position.y * size.x);
}

const Tile &Map::tile(const Position position) const
{
    if (position.x >= size.x || position.y >= size.y) {
        throw std::out_of_range("Invalid tile position");
    }

    return tiles.at(position.x + position.y * size.x);
}

Inventory Map::getTotalResources() const
{
    Inventory total{};
    for (const auto &tile : tiles) {
        for (size_t i = 0; i < tile.resources.size(); i += 1) {
            total[i] += tile.resources[i];
        }
    }

    return total;
}

std::istream &operator>>(std::istream &input, Player::Orientation &orientation)
{
    std::uint8_t value{};
    input >> value;
    orientation = static_cast<Player::Orientation>(value);
    return input;
}

}  // namespace zizi::client
