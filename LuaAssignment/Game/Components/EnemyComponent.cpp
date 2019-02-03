//
// Created by Igli milaqi on 20/01/2019.
//

#include <iostream>
#include "EnemyComponent.h"

#include "PlayerComponent.h"
#include "../../Engine/Utils.h"
#include "../../Engine/Scene.h"
#include "../../Engine/Game.h"
#include "../Hand.h"
#include "HandComponent.h"
#include "../../Engine/LuaProgram.h"
#include "../Enemy.h"
#include <functional>



void EnemyComponent::Start()
{
    Component::Start();

    Engine::LuaProgram* lua = new Engine::LuaProgram("../LuaScripts/Enemy.lua");
    lua->CallCurrentProgram();

    m_health = lua->GetValueFromTable<std::string,int>("enemy","health");


    std::function<void()> freezePlayer = std::bind(&EnemyComponent::FreezePlayer,this);
    std::function<void()> damagePlayer = std::bind(&EnemyComponent::DamagePlayer,this);
    std::function<void()> discardCard = std::bind(&EnemyComponent::DiscardPlayerCard,this);

    m_abilities["freeze"] = freezePlayer;
    m_abilities["damage"] = damagePlayer;
    m_abilities["discard"] = discardCard;

}

void EnemyComponent::Update(float timeStep)
{
    Component::Update(timeStep);

    if(m_health <=0)
    {
        Engine::Text* t = m_parent->parentScene->Instantiate<Engine::Text>();
        t->SetText("You Win");
        t->GetTextComponent()->SetCharacterSize(200);
        t->SetWorldPosition(Engine::Game::Instance()->Width()/2 - 500,Engine::Game::Instance()->Height()/2 - 200);
        m_parent->parentScene->DestroyEntity(m_parent);
    }
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

    if(!m_isFrozen)
    {
        int randomIndex = Engine::Utils::RandomRange(0, m_abilities.size() - 1);
        std::cout<<randomIndex<<std::endl;
        if(randomIndex == 0 )
        {
            m_abilities["freeze"]();
            dynamic_cast<Enemy*>(m_parent)->SetAbilityText("Freeze");
        }
        else if (randomIndex == 1)
        {
            m_abilities["damage"]();
            dynamic_cast<Enemy*>(m_parent)->SetAbilityText("Damage");
        }
        else if (randomIndex == 2)
        {
            m_abilities["discard"]();
            dynamic_cast<Enemy*>(m_parent)->SetAbilityText("Discard Card");
        }

    }

   EndTurn();

}

void EnemyComponent::EndTurn()
{
    if(m_IsTurn)
    {
        if(m_isFrozen) m_isFrozen = false;

        m_IsTurn = false;
        m_playerComponent->OnTurnStart();
    }
}

void EnemyComponent::DamagePlayer()
{
    m_playerComponent->DealDamage(Engine::Utils::RandomRange(1,5));
}

void EnemyComponent::FreezePlayer()
{
    m_playerComponent->Freeze(Engine::Utils::RandomRange(1,2));
}

void EnemyComponent::DiscardPlayerCard()
{
    m_playerComponent->GetHand()->GetHandComponent()->DiscardRandomCard();
    m_playerComponent->GetHand()->GetHandComponent()->DiscardRandomCard();
}

void EnemyComponent::Freeze()
{
    m_isFrozen = true;
}

bool EnemyComponent::IsFrozen()
{
    return m_isFrozen;
}

EnemyComponent::~EnemyComponent()
{
    m_playerComponent->ClearEnemy();
    m_playerComponent = nullptr;
}


