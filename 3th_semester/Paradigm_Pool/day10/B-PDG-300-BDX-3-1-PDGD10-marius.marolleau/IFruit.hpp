/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-marius.marolleau
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_
#include <string>

class IFruit {
    public:
        virtual ~IFruit() = default;
        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;
    protected:
    private:
};

std::ostream &operator<<(std::ostream &s, IFruit const &f1);
#endif /* !IFRUIT_HPP_ */
