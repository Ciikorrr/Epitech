/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** WarSystem
*/

#include "WarpSystem.hpp"

WarpSystem::Core::Core(QuantumReactor *content)
{
    this->_coreReactor = content;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}

WarpSystem::QuantumReactor::QuantumReactor()
{
}
