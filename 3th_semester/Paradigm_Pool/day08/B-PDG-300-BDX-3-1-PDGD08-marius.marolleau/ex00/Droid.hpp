/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-marius.marolleau
** File description:
** Droid
*/
#include <string>
#include <iostream>
#ifndef DROID_HPP_
#define DROID_HPP_

class Droid {
    public:
        Droid(std::string Id = "");
        Droid(const Droid &copy);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setId(std::string);
        size_t getAttack() const;
        size_t getToughness() const;
        size_t getEnergy() const;
        std::string getId() const;
        std::string getStatus() const;
        bool operator==(const Droid &d2) const;
        bool operator!=(const Droid &d2) const;
        Droid &operator=(const Droid &d2);
        size_t &operator<<(size_t &battery);
        ~Droid();

    private:
        size_t _Energy;
        const size_t _Attack;
        const size_t _Toughness;
        std::string _Id;
        std::string *_Status;
};

#endif /* !DROID_HPP_ */
