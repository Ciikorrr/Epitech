/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Map
*/

#include "Map.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace zizi::gui::render {

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &tile : _map->tiles) {
        auto selected = _selectedTile == tile.position;
        auto dark = tile.position.x % 2 ^ tile.position.y % 2;
        target.draw(Tile(tile, dark, selected), states);
    }
}

static const sf::Color TILE_COLOR{170, 215, 81};
static const sf::Color TILE_DARK_COLOR{162, 209, 73};
static const sf::Color TILE_SELECTED_COLOR{129, 167, 58};
static sf::RectangleShape SHAPE{{1, 1}};

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform = sf::Transform{states.transform}.translate(
        static_cast<float>(_tile->position.x), static_cast<float>(_tile->position.y)
    );

    SHAPE.setFillColor(_selected ? TILE_SELECTED_COLOR : (_dark ? TILE_DARK_COLOR : TILE_COLOR));
    target.draw(SHAPE, states);

    for (int i = 0; i < static_cast<int>(client::Ressource::SIZE); ++i) {
        if (_tile->resources[i] == 0) {
            continue;
        }

        auto [quot, rem] = div(i, 3);
        auto resourceStates = states;
        resourceStates.transform =
            sf::Transform{resourceStates.transform}
                .translate(
                    static_cast<float>(1 + rem * 2) / 7, static_cast<float>(1 + quot * 2) / 7
                )
                .scale({1. / 7, 1. / 7});

        SHAPE.setFillColor(client::RESSOURCE_COLORS.at(i));
        target.draw(SHAPE, resourceStates);
    }
}

}  // namespace zizi::gui::render
