//
// Created by Igli milaqi on 29/12/2018.
//

#include "HandComponent.h"
#include "../Card.h"
#include "../HandSlot.h"
#include "../../Engine/Game.h"


void HandComponent::Start()
{
    Component::Start();
}

void HandComponent::AddSlots(float slotNumber, float startXPos, float cardWidth, float cardHeight)
{
    for (unsigned int i = 0; i < slotNumber ; ++i)
    {
        HandSlot* slot = new HandSlot(i,Engine::IVector(startXPos + cardWidth * (i+1),Engine::Game::Instance()->Height() -  cardHeight - 50));
        m_cardSlots.push_back(slot);
    }
}

HandComponent::~HandComponent()
{
    for (unsigned int i = 0; i < m_cardSlots.size() ; ++i)
    {
        delete(m_cardSlots[i]);
        m_cardSlots[i] = nullptr;
    }
}

void HandComponent::AddCard(Card *card)
{
    HandSlot* freeSlot = FindEmptySlot();
    freeSlot->currentCard = card;
    card->GetComponent<CardComponent>()->SetHandSlot(freeSlot);
    card->SetWorldPosition(freeSlot->pos->x,freeSlot->pos->y);
}

HandSlot *HandComponent::FindEmptySlot()
{
    for (unsigned int i = 0; i < m_cardSlots.size() ; ++i)
    {
        if(m_cardSlots[i]->IsEmpty()) return  m_cardSlots[i];
    }
}


