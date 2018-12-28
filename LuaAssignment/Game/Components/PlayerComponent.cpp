//
// Created by Igli milaqi on 27/12/2018.
//

#include "PlayerComponent.h"
#include "../Hand.h"
#include "../Card.h"
#include "CardComponent.h"
#include "../../Engine/Scene.h"

void PlayerComponent::Start()
{
    Component::Start();

    m_hand = m_parent->parentScene->Instantiate<Hand>();
}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);
}


void PlayerComponent::AddCardToHand(Card *card)
{
    card->GetComponent<CardComponent>()->SetPlayer(this);
    m_hand->GetHandComponent()->AddCard(card);
}


