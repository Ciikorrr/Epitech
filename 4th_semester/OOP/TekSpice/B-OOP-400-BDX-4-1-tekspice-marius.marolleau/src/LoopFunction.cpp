/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-marius.marolleau
** File description:
** LoopFunction
*/

#include <csignal>
#include "Circuit/Circuit.hpp"

void display(Circuit &circuit);
void simulate(Circuit &circuit);

volatile sig_atomic_t signal_received = 0;

void signalHandler(int signum) {
    (void)signum;
    signal_received = 1;
}

void loop(Circuit &circuit)
{
    std::signal(SIGINT, signalHandler);

    while (!signal_received) {
        simulate(circuit);
        display(circuit);
    }
}