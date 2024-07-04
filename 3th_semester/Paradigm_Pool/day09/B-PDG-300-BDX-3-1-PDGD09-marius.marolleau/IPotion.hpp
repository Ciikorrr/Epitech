/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-marius.marolleau
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

class IPotion {
    public:
        virtual ~IPotion(){};
        virtual int getHeal() const = 0;
        virtual int getPower() const = 0;
    protected:
        
    private:
};

#endif /* !IPOTION_HPP_ */
