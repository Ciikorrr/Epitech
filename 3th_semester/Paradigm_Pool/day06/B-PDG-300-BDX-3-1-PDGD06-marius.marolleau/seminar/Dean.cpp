/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Dean
*/

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Dean.hpp"
#include "Assistant.hpp"
#include "Student.hpp"
using namespace std;

Dean::Dean(string name)
{
    this->name = name;
    cout << "Dean " << this->name << ": I'm Dean " << this->name << "! How do you do, fellow kids?" << endl;
    this->isWorking = false;
}

Dean::~Dean()
{
    this->name = "";
    cout << "Dean " << this->name << ": Time to go home." << endl;
}

bool Dean::getWork()
{
    return this->isWorking;
}

void Dean::teachStudent(Student *student, string lesson)
{
    string drink[5] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    bool err = student->learn(lesson);
    int idx;
    if (!err) {
        cout << "Dean " << this->name << ": All work and no play makes " << student->getName() << " a dull student." << endl;
        ofstream file(student->getName() + ".drink");
        cout << student->getName() + ".drink" <<endl;
        idx = rand() % 5;
        cout << drink[idx] << endl;
        file << drink[idx];
        file.close();
    }

}

void Dean::timeCheck()
{
    if (this->getWork() == false) {
        this->isWorking = true;
        cout << "Dean " << this->getName() << ": Where is everyone?" << endl;
    } else {
        this->isWorking = false;
        cout << "Dean " << this->getName() << ": Don't forget to close the windows when you leave." << endl;
    }
}

string Dean::getName()
{
    return this->name;
}