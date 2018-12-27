//
// Created by Igli milaqi on 27/12/2018.
//

#include "PlayerComponent.h"
#include "../Hand.h"

void PlayerComponent::Start()
{
    Component::Start();

    m_hand = new Hand(100,400,570);
}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);
}


Hand *PlayerComponent::GetHand()
{
    return m_hand;
}


