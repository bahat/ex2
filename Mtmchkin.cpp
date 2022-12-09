//
// Created by Omer Bahat on 05/12/2022.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
        m_player(playerName),
        m_numOfCards(numOfCards),
        m_currentCardIndex(0)
{
    m_cardsArray=cardsArray;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

void Mtmchkin::playNextCard()
{
    if(!isOver())
    {
        if(m_currentCardIndex==m_numOfCards)
        {
            m_currentCardIndex=0;
        }
        getCurrentCard().printInfo();
        getCurrentCard().applyEncounter(m_player);
        m_player.printInfo();
        m_currentCardIndex++;
    }
}

Card Mtmchkin::getCurrentCard() {
    return m_cardsArray[m_currentCardIndex];
}

bool Mtmchkin::isOver() const
{
    if(getGameStatus()==GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const {
    if(m_player.getLevel()==Player::getMaxLevel())
    {
        //player won
        return GameStatus::Win;
    }
    if(m_player.isKnockedOut())
    {
        //player lost
        return GameStatus::Loss;
    }
    else
    {
        return GameStatus::MidGame;
    }
}

