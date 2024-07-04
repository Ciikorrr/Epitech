/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Assistant
*/
#include <fstream>
#include "Assistant.hpp"
#include <string.h>
using namespace std;

Assistant::Assistant(int number)
{
    this->number = number;
    this->work = false;
    cout << "Assistant " << this->number << ": 'morning everyone *sip coffee*" << endl;
}

Assistant::~Assistant()
{
    cout << "Assistant " << this->number << ": see you tomorrow at 9.00 *sip coffee*" << endl;
    this->number = 0;
}

void Assistant::giveDrink(Student *student, string to_drink)
{
    cout << "Assistant " << this->number << ": drink this, " << student->getName() << " *sip coffee*" << endl;
    student->drink(to_drink);
    ofstream file(student->getName() + ".drink");
    file << to_drink;
    file.close();
}

string Assistant::readDrink(string name)
{
    ifstream file(name + ".drink");
    string drink;
    const char *filepath = strcat((char *)name.c_str(), ".drink");
    if (!file.is_open())
        return "";
    getline(file, drink);
    cout << "Assistant " << this->number << ": " << name << " needs a " << drink << " *sip coffee*" << endl;
    remove(filepath);
    return drink;
}

void Assistant::helpStudent(Student *student)
{
    string res = readDrink(student->getName());
    if (res == "") {
        cout << "Assistant " << this->number << ": " << student->getName() << " seems fine *sip coffee" << endl;
        return;
    }
    return this->giveDrink(student, res);
    
}

int Assistant::getId()
{
    return this->number;
}

bool Assistant::isWorking()
{
    return this->work;
}

void Assistant::timeCheck()
{
    if (!this->work) {
        this->work = true;
        cout << "Assistant " << this->number << ": Time to teach some serious business *sip coffee*" << endl;
    } else {
        this->work = false;
        cout << "Asssistant " << this->number << " :Enough teaching for today *sip coffee*" << endl;
    }
}
