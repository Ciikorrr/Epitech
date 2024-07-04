/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-marius.marolleau
** File description:
** WarSystem
*/

#ifndef WARSYSTEM_HPP_
#define WARSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);
        private:
            bool _stability = true;
    };
    class Core {
        public:
            Core(QuantumReactor *QuantumReactor);
            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
};

#endif /* !WARSYSTEM_HPP_ */
