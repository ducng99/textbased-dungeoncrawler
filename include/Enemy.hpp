#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include "Creature.hpp"

class Enemy : public Creature {
    private:
        unsigned int m_gold;

    public:
        Enemy(std::string& name, int gold, unsigned int attackBonus, unsigned int dodgeBonus, unsigned int hitPoints);
        ~Enemy();

        unsigned int GoldWorth() const;
};

#endif // _ENEMY_HPP_
