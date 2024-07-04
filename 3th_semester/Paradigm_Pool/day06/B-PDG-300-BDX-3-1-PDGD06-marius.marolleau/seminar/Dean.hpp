/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Dean
*/
#include <sstream>
#include <string>
#include "Student.hpp"
#ifndef DEAN_HPP_
#define DEAN_HPP_
using namespace std;

class Dean {
    public:
        Dean(string name);
        ~Dean();
        string getName();
        void teachStudent(Student *student, string lesson);
        bool getWork();
        void timeCheck();
    protected:
    private:
        bool isWorking;
        string name;
};

#endif /* !DEAN_HPP_ */
