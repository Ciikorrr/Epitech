/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-marius.marolleau
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <string>


class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy();
        Toy(ToyType type, std::string name, std::string filename);
        ~Toy();
        Toy(const Toy &);
        Toy &operator=(const Toy &t);
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string name);
        bool setAscii(std::string filename);
    protected:
    private:
        ToyType _type;
        std::string _name;
        std::string _picture;
};

#endif /* !TOY_HPP_ */
