//
// Created by Omer Bahat on 30/11/2022.
//
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include <string>
#include "utilities.h"
class Player
{
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LEVEL = 1;
    static const int DEFAULT_COINS = 0;
    static const int MAX_LEVEL = 10;

    private:
        std::string m_name;
        int m_maxHP;
        int m_force;
        int m_level;
        int m_HP;
        int m_coins;
    public:
        
        /// @brief Constructor recieves name, maximal HP and force, other as default
        /// @param name - Player name to be initialized
        /// @param maxHP - Maximal HP of player
        /// @param force - Starting force of player (can be buffed later)
        Player(std::string name, int maxHP=DEFAULT_MAX_HP, int force=DEFAULT_FORCE);
        /// @brief Constructor which initializes new Player object with values copied from an existing Player
        /// @param toCopy - Player object to copy values from
        Player(Player const &toCopy);
        /// @brief Deconstructor of Player
        ~Player();
        /// @brief Operator overloading of equals sign- copies values from paramater to an existing Player
        /// @param toImplement - Player to copy values from 
        /// @return Player object with values copied from parameter Player
        Player operator = (Player const &toImplement);
        /// @brief Prints Player info according to format specified in utilities.h
        void printInfo();
        /// @brief Increases level by 1, if level is maximal, does nothing
        void levelUp();
        /// @brief Gets current level of Player
        /// @return Returns Player's current level
        int getLevel();
        /// @brief Increments force
        /// @param buffBy- Determines by how much player force shall be increased
        void buff(int buffBy);
        /// @brief Increases HP (until reaching maximal HP)
        /// @param healBy- Determines by how much player hp will be increased
        void heal(int healBy);
        /// @brief Decreases HP until reaches 0
        /// @param damageBy - Determines by how much player hp will be decreased
        void damage(int damageBy);
        /// @brief Checks if HP is 0 <=> player is knocked out
        /// @return true if knocked out, false else
        bool isKnockedOut();
        /// @brief Adds coins to player
        /// @param toAdd Determines how many coins should be added do player
        void addCoins(int toAdd);
        /// @brief Reduces coins from player in order to pay. If coins aren't sufficient payment fails.
        /// @param price - Value of current payment
        /// @return true if transaction uas successful, false else
        bool pay(int price);
        /// @brief Gets current player strength
        /// @return strength of player which is defined as level+force
        int getAttackStrength();

};


#endif //EX2_PLAYER_H