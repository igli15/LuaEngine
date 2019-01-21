//
// Created by Igli milaqi on 20/01/2019.
//

#include <iostream>
#include "EnemyComponent.h"

#include "PlayerComponent.h"
#include "../../Engine/Utils.h"
#include "../Hand.h"
#include "HandComponent.h"

void EnemyComponent::Start()
{
    Component::Start();
    m_health = 30;


}

void EnemyComponent::Update(float timeStep)
{
    Component::Update(timeStep);
}

void EnemyComponent::DealDamage(int damage)
{
    m_health -= damage;
}

int EnemyComponent::GetHealth()
{
    return m_health;
}

void EnemyComponent::SetPlayerComponent(PlayerComponent* p)
{
    m_playerComponent = p;
}

void EnemyComponent::OnTurnStart()
{
    m_IsTurn = true;
    DiscardPlayerCard();

    EndTurn();

}

void EnemyComponent::EndTurn()
{
    if(m_IsTurn)
    {
        m_IsTurn = false;
        m_playerComponent->OnTurnStart();
    }
}

void EnemyComponent::FreezePlayer()
{
    m_playerComponent->Freeze(Engine::Utils::RandomRange(1,2));
}

void EnemyComponent::DamagePlayer()
{
    m_playerComponent->DealDamage(Engine::Utils::RandomRange(1,5));
}

void EnemyComponent::DiscardPlayerCard()
{
    m_playerComponent->GetHand()->GetHandComponent()->DiscardRandomCard();
    m_playerComponent->GetHand()->GetHandComponent()->DiscardRandomCard();
}
