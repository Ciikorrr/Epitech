/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Student
*/
#include <sstream>
#include <iostream>

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

using namespace std;

class Student {
    public:
        Student(string name);
        ~Student();
        bool learn(string to_say);
        void drink(string boisson);
        string getName();
    private:
        string name;
        int32_t energy;
};

#endif /* !STUDENT_HPP_ */
