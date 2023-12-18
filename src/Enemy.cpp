#include "Enemy.hpp"

Enemy::Enemy(std::string& name, int gold, unsigned int attackBonus, unsigned int dodgeBonus, unsigned int hitPoints)
    : Creature(name, hitPoints * 10U),
      m_gold(gold) {
    m_attackSkill = attackBonus * 10U;
    m_dodgeSkill = dodgeBonus * 10U;
}

Enemy::~Enemy() {

}

unsigned int Enemy::GoldWorth() const {
    return m_gold;
}
