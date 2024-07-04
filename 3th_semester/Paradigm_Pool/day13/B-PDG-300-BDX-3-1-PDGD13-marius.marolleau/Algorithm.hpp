/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-marius.marolleau
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_
#include <algorithm>
template<typename T>

void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>

const T& min(const T& a,const  T& b) {
    if (a < b)
        return a;
    return b;
}

template<typename T>

const T& max(const T& a, const T& b) {
    if (a > b)
        return a;
    return b;
}

template<typename T>

const T& clamp(const T& value, const T& min, const T& max) {
    return std::clamp(value, min, max);
}

class Algorithm {
    public:
        Algorithm();
        ~Algorithm();

    protected:
    private:
};

#endif /* !ALGORITHM_HPP_ */
