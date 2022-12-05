//
// Created by Omer Bahat on 30/11/2022.
//
#include "Player.h"

#include <utility>

Player::Player(std::string name, int maxHP, int force):
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
Player Player::operator=(const Player &toImplement) {
    if(this==&toImplement)
    {
        return *this;
    }
    else
    {
        m_name=toImplement.m_name;
        m_maxHP=toImplement.m_maxHP;
        m_force=toImplement.m_force;
        m_HP=toImplement.m_maxHP;
        m_coins=toImplement.m_coins;
        m_level=toImplement.m_level;
    }
}

void Player::printInfo()
{
    char * nameInChar = new char[m_name.length()+1];
    strcpy(nameInChar, m_name.c_str());
    printPlayerInfo(nameInChar, m_level, m_force,m_HP,m_coins);
    delete[] nameInChar;
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

int Player::getLevel() {
    return m_level;
}

void Player::buff(int buffBy) {
    if(buffBy<=NULL)
    {

    }
    else
    {
        m_force+=buffBy;
    }
}

void Player::heal(int healBy) {
    if(healBy<=NULL)
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
    if(damageBy<=NULL)
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

bool Player::isKnockedOut() {
    assert(m_HP>=0);
    return m_HP==0;
}

void Player::addCoins(int toAdd) {
    if(toAdd<=0)
    {

    }
    else
    {
        m_coins+=toAdd;
    }
}

bool Player::pay(int price) {
    if(price<=0)
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





