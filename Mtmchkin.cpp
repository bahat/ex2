//
// Created by Omer Bahat on 05/12/2022.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
        m_player(playerName),
        m_numOfCards(numOfCards),
        m_cardsArray(cardsArray),
        m_currentCardIndex(0)
{
    Card* tempDeck = new Card[numOfCards];
    for(int i=0;i<numOfCards;i++)
    {
        tempDeck[i] = cardsArray[i];
    }
    m_cardsArray = tempDeck;
}

Mtmchkin::~Mtmchkin()
{
    delete []m_cardsArray;
}

void Mtmchkin::playNextCard()
{
    if(!isOver())
    {
        if(m_currentCardIndex>=m_numOfCards)
        {
            m_currentCardIndex=0;
        }
        Card currentCard = m_cardsArray[m_currentCardIndex];
        currentCard.Card::printInfo();
        currentCard.applyEncounter(m_player);
        m_player.printInfo();
        m_currentCardIndex++;
    }
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

