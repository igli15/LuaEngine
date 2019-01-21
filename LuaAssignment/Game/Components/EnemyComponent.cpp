//
// Created by Igli milaqi on 20/01/2019.
//

#include "EnemyComponent.h"

#include "PlayerComponent.h"

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
