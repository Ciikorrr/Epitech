/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
        class Captain;
        class Ensign;
    };
    class Ship;
};

namespace Borg {
    class Ship {
            public:
                Ship(int weaponFrequency = 0, short repair = 0);
                void setupCore(WarpSystem::Core *Core);
                void checkCore();
                bool move(int warp, Destination d);
                bool move(int  warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getWeaponFrequency();
                void setWeaponFrequency(int frequency);
                short getRepair();
                void setRepair(short repair);
                void fire(Federation::Starfleet::Ship *target);
                void fire(Federation::Ship *target);
                void repair();
            private:
                int _side;
                short _maxWarp;
                int _shield;
                int _weaponFrequency;
                short _repair;
                Destination _location;
                Destination _home = UNICOMPLEX;
                WarpSystem::Core *Core;
    };
    class BorgQueen {
        public:
            BorgQueen();
            bool (Borg::Ship::*movePtr)(Destination d);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *ship);
            void (Borg::Ship::*destroyPtr)(Federation::Ship *ship);
            bool move(Borg::Ship *ship, Destination dest);
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
            void destroy(Borg::Ship *ship, Federation::Ship *target);
        private:
    };
};

#endif /* !BORG_HPP_ */
