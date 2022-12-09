//
// Created by ahmad.fadool on 12/6/22.
//

#include "Card.h"
#include "./utilities.h"


Card::Card(CardType type, const CardStats &stats):
    m_effect(type),
    m_stats(stats)
{}

void Card::applyEncounter(Player &player) const
{
    if(this->m_effect==CardType::Treasure)
    {
        player.addCoins(this->m_stats.loot);
        return;
    }
    if(this->m_effect==CardType::Buff)
    {
        if(player.pay(this->m_stats.cost))
        {
            player.buff(this->m_stats.buff);
            return;
        }
//        else
//        {
//            //print no enough coins
//        }
    }
    if(this->m_effect==CardType::Heal)
    {
        if(player.pay(this->m_stats.cost))
        {
            player.heal(this->m_stats.heal);
            return;
        }
//        else
//        {
//            // print not enough coins
//        }


    }
    if(this->m_effect==CardType::Battle)
    {
        if(player.getAttackStrength()>=this->m_stats.force)
        {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
            printBattleResult(player.getAttackStrength()>=this->m_stats.force);
        }
        else
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(player.getAttackStrength()>=this->m_stats.force);
        }

    }

}
void Card::printInfo() const
{   // Battle card
    if(this->m_effect==CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
        return;
    }
    //Heal card
    if(this->m_effect==CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
        return;
    }
    //Buff card
    if(this->m_effect==CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
        return;
    }
    //Treasure card
    if(this->m_effect==CardType::Treasure)
    {
        printTreasureCardInfo(this->m_stats);
        return;
    }

    return;

}






















