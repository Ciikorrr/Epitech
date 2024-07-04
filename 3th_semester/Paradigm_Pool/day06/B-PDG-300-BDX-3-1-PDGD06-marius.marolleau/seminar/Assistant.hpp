/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Assistant
*/
#include "Student.hpp"
#ifndef ASSISTANT_HPP_
#define ASSISTANT_HPP_
using namespace std;

class Assistant {
    public:
        Assistant(int number);
        ~Assistant();
        void giveDrink(Student *student, string to_drink);
        string readDrink(string name);
        void helpStudent(Student *student);
        void timeCheck();
        int getId();
        bool isWorking();
    protected:
    private:
        int number;
        bool work;
};

#endif /* !ASSISTANT_HPP_ */