/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Student
*/
#include "Student.hpp"

using namespace std;

Student::Student(string name)
{
    this->name =  name;
    this->energy = 100;
    cout << "Student " << this->name << ": I'm ready to learn C++." << endl;

}

string Student::getName()
{
    return this->name;
}

bool Student::learn(string to_say)
{
    if ((this->energy - 42) <= 0) {
        for (int i = 0; to_say[i] != '\0'; i++) {
            if (to_say[i] == 'C') {
                int index = to_say.find("C++", i);
                to_say.replace(index, 3, "shit");
            }
        }
        cout << "Student " << this->name << ": " << to_say << endl;
        return false;
    }
    cout << "Student " << this->name << ": " << to_say << endl;    
    this->energy -= 42;
    return true;
}

Student::~Student()
{
    cout << "Student " << this->name << ": Wow, much learning today, very smart, such C++." << endl;
    this->name = "";
    this->energy = 0;
}

void Student::drink(string boisson)
{
    if (boisson == "Red Bull") {
        if (this->energy + 32 >= 100) {
            this->energy = 100;
        } else {
            this->energy += 32;
        }
        cout << "Student " << this->name << ": Red Bull gives you wings!" << endl;
    } else if (boisson == "Monster") {
        if (this->energy + 64 >= 100) {
            this->energy = 100;
        } else {
            this->energy += 64;
            
        }
        cout << "Student " << this->name << ": Unleash The Beast!" << endl;
    } else {
        if (this->energy < 100)
            this->energy += 1;
        cout << "Student " << this->name << ": ah, yes... enslaved moisture." << endl;
    }
}
