/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Assets
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "incbin.h"

namespace zizi::gui::res {

namespace data {
extern "C" {
INCBIN_EXTERN(Egg);
}
}  // namespace data

class Assets final {
   public:
    Assets()
    {
        _egg.loadFromMemory(data::gEggData, data::gEggSize);
    }

    static const sf::Texture &Egg()
    {
        return _getInstance()._egg;
    }

   private:
    static const Assets &_getInstance()
    {
        static Assets instance;
        return instance;
    }

    sf::Texture _egg;
};

};  // namespace zizi::render::res
