//
// Created by Omer Bahat on 30/11/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player
{
    private:
        char* name;
        int level;
        int force;
        int maxHP;
        int HP;
        int coins;
    public:
        Player(char* name, int maxHP=100, int force=5);
        Player(Player toCopy);
        ~Player();
        Player operator = (Player const &toImplement);
        void printInfo();
        void levelUp();
        int getLevel();
        void buff(int buffBy);
        void heal(int healBy);
        void damage(int damageBy);
        bool isKnockedOut();
        void addCoins(int toAdd);
        bool pay(int price);
        int getAttackStrength();

};
Player

#endif //EX2_PLAYER_H
