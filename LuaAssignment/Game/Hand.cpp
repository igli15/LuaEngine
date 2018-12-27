//
// Created by Igli milaqi on 25/12/2018.
//

#include "Hand.h"
#include "../Engine/Game.h"
#include "HandSlot.h"
#include "Card.h"
#include "Components/CardComponent.h"

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

HandSlot* Hand::FindEmptySlot()
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
    card->GetComponent<CardComponent>()->SetHandSlot(freeSlot);
    card->SetWorldPosition(freeSlot->pos->x,freeSlot->pos->y);
}
