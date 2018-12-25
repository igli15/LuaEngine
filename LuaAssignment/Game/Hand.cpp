//
// Created by Igli milaqi on 25/12/2018.
//

#include "Hand.h"
#include "../Engine/Game.h"

bool Hand::HandSlot::IsEmpty()
{
    return currentCard == nullptr;
}

Hand::HandSlot::HandSlot(const unsigned int & pIndex,const Engine::IVector& pPos)
{
    pos = new Engine::IVector(0,0);
    index = pIndex;
    pos->x = pPos.x;
    pos->y = pPos.y;
}

Hand::HandSlot::~HandSlot()
{
    delete(pos);
    pos = nullptr;
    currentCard = nullptr;
}


Hand::Hand(float startX, float cardWidth, float cardHeight)
{
    for (unsigned int i = 0; i < m_slotNumber ; ++i)
    {
        HandSlot* slot = new HandSlot(i,Engine::IVector(startX + cardWidth * (i+1),Engine::Game::Instance()->Height() -  cardHeight - 50));
        m_cardSlots.push_back(slot);
    }
}

Hand::~Hand()
{
    for (unsigned int i = 0; i < m_slotNumber ; ++i)
    {
        delete(m_cardSlots[i]);
        m_cardSlots[i] = nullptr;
    }
}

Hand::HandSlot *Hand::FindEmptySlot()
{
    for (unsigned int i = 0; i < m_slotNumber ; ++i)
    {
        if(m_cardSlots[i]->IsEmpty()) return  m_cardSlots[i];
    }
}

void Hand::AddCard(Card *card)
{
    HandSlot* freeSlot = FindEmptySlot();
    freeSlot->currentCard = card;
    card->SetWorldPosition(freeSlot->pos->x,freeSlot->pos->y);
}
