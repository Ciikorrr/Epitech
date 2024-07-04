/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-marius.marolleau
** File description:
** Seminar
*/

#ifndef SEMINAR_HPP_
#define SEMINAR_HPP_
#include "Assistant.hpp"
#include "Student.hpp"
#include "Dean.hpp"

class Seminar {
    public:
        Seminar();
        ~Seminar();
        void addDean(Dean *dean);
        void addAssistant(Assistant *assistant);
        void addStudent(Student *student);

    protected:
    private:
};

#endif /* !SEMINAR_HPP_ */
