/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_
#include <string>
#include <sstream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string _name);
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                int _age;
                std::string _name;
        };
        class Ship {
            public:
                Ship(int length = 289, int width = 132, std::string name = "Enterprise", short maxWarp = 6, int torpedo = 0);
                void setupCore(WarpSystem::Core *Core);
                void checkCore();
                void promote(Federation::Starfleet::Captain *captain);
                bool move(int warp, Destination d);
                bool move(int  warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                int _length;
                int _width;
                int _shield;
                int _photonTorpedo;
                std::string _name;
                short _maxWarp;
                Destination _location;
                Destination _home = EARTH;
                WarpSystem::Core *Core;
                WarpSystem::QuantumReactor *quantumReactor;
                Federation::Starfleet::Captain *captain;
        };
        class Ensign {
            public:
                explicit Ensign(std::string _name);
            private:
                std::string _name;
        };
        class Admiral {
            public:
                Admiral(std::string name);
                bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *target);
                void fire(Federation::Starfleet::Ship *Ship, Borg::Ship *target);
                bool move(Federation::Starfleet::Ship *Ship, Destination dest);

            private:
                std::string _name;
        };
    }
    class Ship {
        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *Core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int  warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            WarpSystem::Core *getCore();
        private:
            int _length;
            int _width;
            int _shield;
            int _photonTorpedo;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *Core;
            Destination _location;
            Destination _home = VULCAN;
            WarpSystem::QuantumReactor *quantumReactor;
    };
};


#endif /* !FEDERATION_HPP_ */
