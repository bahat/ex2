//
// Created by Omer Bahat on 30/11/2022.
//
#include "Player.h"

#include <utility>

Player::Player(const std::string name, int maxHP, int force):
    m_name(name),
    m_maxHP(maxHP),
    m_force(force),
    m_HP(maxHP),
    m_coins(Player::DEFAULT_COINS),
    m_level(Player::DEFAULT_LEVEL)
{
    if(maxHP<=0)
    {
        m_maxHP=Player::DEFAULT_MAX_HP;
        m_HP = Player::DEFAULT_MAX_HP;
    }
    if(force<0)
    {
        m_force = Player::DEFAULT_FORCE;
    }


}
Player::Player(const Player &toCopy)=default;
Player::~Player()=default;
Player& Player::operator=(const Player &toImplement) = default;


void Player::printInfo()
{
    printPlayerInfo(m_name.std::string::c_str(), m_level, m_force,m_HP,m_coins);
}


void Player::levelUp()
{
    if(m_level>=Player::MAX_LEVEL)
    {

    }
    else
    {
        m_level+=1;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int buffBy) {
    if(buffBy<=ZERO)
    {

    }
    else
    {
        m_force+=buffBy;
    }
}

void Player::heal(int healBy) {
    if(healBy<=ZERO)
    {

    }
    else
    {
        m_HP+=healBy;
        if(m_HP>m_maxHP)
        {
            m_HP=m_maxHP;
        }
    }
}

void Player::damage(int damageBy) {
    if(damageBy<=ZERO)
    {

    }
    else
    {
        if(damageBy>=m_HP)
        {
            m_HP=0;
        }
        else
        {
            m_HP-=damageBy;
        }
    }
}

bool Player::isKnockedOut() const {
    return m_HP==ZERO;
}

void Player::addCoins(int toAdd) {
    if(toAdd<=ZERO)
    {

    }
    else
    {
        m_coins+=toAdd;
    }
}

bool Player::pay(int price) {
    if(price<=ZERO)
    {
        return true;
    }
    else
    {
        if(price>m_coins)
        {
            return false;
        }
        else
        {
            m_coins-=price;
            return true;
        }
    }
}

int Player::getAttackStrength() {
    return m_level+m_force;
}


int Player::getMaxLevel() {
    return MAX_LEVEL;
}



