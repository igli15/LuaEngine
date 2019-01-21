//
// Created by Igli milaqi on 29/12/2018.
//

#include "HandComponent.h"
#include "../Card.h"
#include "../HandSlot.h"
#include "../../Engine/Game.h"
#include "../../Engine/Utils.h"
#include "../../Engine/Scene.h"

HandComponent* HandComponent::handInstance;

void HandComponent::Start()
{
    Component::Start();

    SetHandInstance(this);
}

void HandComponent::AddSlots(float slotNumber, float startXPos, float cardWidth, float cardHeight)
{
    for (unsigned int i = 0; i < slotNumber ; i++)
    {
        HandSlot* slot = new HandSlot(i,Engine::IVector((startXPos + cardWidth) * (i+1),Engine::Game::Instance()->Height() -  cardHeight - 50));
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
    m_currentCardNumber += 1;
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

int HandComponent::GetCurrentCardNumber()
{
    return m_currentCardNumber;
}

unsigned int HandComponent::GetMaxCardCapacity()
{
    return m_maxCardCapacity;
}

void HandComponent::DecrementCardNumber()
{
    m_currentCardNumber -=1;
}

void HandComponent::DiscardRandomCard()
{
    if(m_currentCardNumber == 0) {
        return;
    }

    int index = Engine::Utils::RandomRange(0,m_currentCardNumber - 1);

    std::vector<HandSlot*> v;

    for (int i = 0; i < m_cardSlots.size(); ++i)
    {
        if(!m_cardSlots[i]->IsEmpty())
        {
            v.push_back(m_cardSlots[i]);
        }
    }

    if(!v.empty()) {
        m_parent->parentScene->DestroyEntity(v[index]->currentCard);
        v[index]->EmptySlot();
        DecrementCardNumber();
    }

}

void HandComponent::SetHandInstance(HandComponent *handComponent)
{
    handInstance = handComponent;
}

int HandComponent::luaDiscardRandomCard(lua_State *lua_state)
{
    handInstance->DiscardRandomCard();
    std::cout<<"DISCARD CARD"<<std::endl;
    return 0;
}


