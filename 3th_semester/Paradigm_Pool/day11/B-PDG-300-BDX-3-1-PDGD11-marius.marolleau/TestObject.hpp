/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-marius.marolleau
** File description:
** TestObject
*/

#ifndef TESTOBJECT_HPP_
#define TESTOBJECT_HPP_
#include <string>
#include "IObject.hpp"
#include <iostream>

class TestObject : public IObject {
    public:
        TestObject(std::string name)
        {
            _name = name;
            std::cout << name << " is alive" <<std::endl;
        }
        ~TestObject()
        {
            std::cout << _name << " is dead" <<std::endl;
        }
        void touch()
        {
            std::cout << _name << " is touched" << std::endl;
        }
    protected:
    private:
        std::string _name;
};

#endif /* !TESTOBJECT_HPP_ */
