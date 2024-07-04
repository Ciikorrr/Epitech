/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Map
*/

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <optional>

#include "gui/Client/State.hpp"

namespace zizi::gui::render {

class Map final : public sf::Drawable {
   public:
    explicit Map(const client::Map &map, std::optional<client::Position> selectedTile)
        : _map(&map), _selectedTile(selectedTile)
    {}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   private:
    const client::Map *_map;
    std::optional<client::Position> _selectedTile;
};

class Tile final : public sf::Drawable {
   public:
    Tile(const client::Tile &tile, bool dark, bool selected)
        : _tile(&tile), _dark(dark), _selected(selected)
    {}

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

   private:
    const client::Tile *_tile;
    bool _dark;
    bool _selected;
};

}  // namespace zizi::gui::render
