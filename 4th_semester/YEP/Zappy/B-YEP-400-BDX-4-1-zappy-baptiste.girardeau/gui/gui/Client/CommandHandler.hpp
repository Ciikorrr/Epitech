/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Commands
*/

#pragma once

#include <sstream>

#include "gui/Client/Event.hpp"
#include "gui/Client/State.hpp"

namespace zizi::client {

class CommandHandler final {
   public:
    CommandHandler(State &state, EventQueue<Event> &events) : _state(&state), _events(&events) {}

    void handleCommand(std::string &name, std::istringstream &input);

   private:
    State *_state;
    EventQueue<Event> *_events;

    void msz(std::istringstream &input);
    void bct(std::istringstream &input);
    void tna(std::istringstream &input);
    void sgt(std::istringstream &input);
    void enw(std::istringstream &input);
    void pnw(std::istringstream &input);
    void pdi(std::istringstream &input);
    void ppo(std::istringstream &input);
    void plv(std::istringstream &input);
    void pin(std::istringstream &input);
    void pex(std::istringstream &input);
    void pbc(std::istringstream &input);
    void pic(std::istringstream &input);
    void pie(std::istringstream &input);
    void pfk(std::istringstream &input);
    void pdr(std::istringstream &input);
    void pgt(std::istringstream &input);
    void eht(std::istringstream &input);
    void ebo(std::istringstream &input);
    void edi(std::istringstream &input);
    void seg(std::istringstream &input);
    void smg(std::istringstream &input);
};

}  // namespace zizi::client
