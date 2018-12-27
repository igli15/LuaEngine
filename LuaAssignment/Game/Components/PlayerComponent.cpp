//
// Created by Igli milaqi on 27/12/2018.
//

#include "PlayerComponent.h"
#include "../Hand.h"
#include "CardComponent.h"

void PlayerComponent::Start()
{
    Component::Start();

    m_hand = new Hand(100,400,570);
}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);
}



void PlayerComponent::AddCardToHand(Card *card)
{
    card->GetComponent<CardComponent>()->SetPlayer(this);
    m_hand->AddCard(card);
}


