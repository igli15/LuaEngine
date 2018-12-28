//
// Created by Igli milaqi on 25/12/2018.
//

#include "Hand.h"
#include "../Engine/Game.h"
#include "HandSlot.h"
#include "Card.h"
#include "Components/CardComponent.h"

Hand::Hand()
{
    m_startX = 100;
    m_cardWidth = 400;
    m_cardHeight = 570;
    m_slotNumber = 5;
}

void Hand::Build()
{
    Entity::Build();

   m_handComponent = AddComponent<HandComponent>();
   m_handComponent->AddSlots(m_slotNumber,m_startX,m_cardWidth,m_cardHeight);
}


HandComponent *Hand::GetHandComponent()
{
    return m_handComponent;
}
