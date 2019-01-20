//
// Created by Igli milaqi on 27/12/2018.
//

#include <iostream>
#include "CardComponent.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Game.h"
#include "../../Engine/Scene.h"
#include "../Hand.h"

void CardComponent::Start()
{
    Component::Start();
}

void CardComponent::Update(float timeStep)
{
    Component::Update(timeStep);

    float width = m_parent->Width();
    float height = m_parent->Height();

    auto mousePos = sf::Mouse::getPosition(*(Engine::Game::Instance()->GetWindow()));

    if(!m_playerComponent->isHoldingCard && mousePos.x > m_parent->GetWorldPosition().x - width/2 && mousePos.x < m_parent->GetWorldPosition().x + width/2
        && mousePos.y > m_parent->GetWorldPosition().y - height/2 && mousePos.y < m_parent->GetWorldPosition().y + height/2)
    {
        m_hovered = true;
        m_parent->SetWorldPosition(m_slot->pos->x,m_slot->pos->y - 80);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_selected = true;
        }
    }
    else if(m_hovered)
    {
        m_hovered = false;
        m_parent->SetWorldPosition(m_slot->pos->x,m_slot->pos->y);
    }

    if(m_selected)
    {
        m_playerComponent->isHoldingCard = true;
        m_parent->SetWorldPosition(mousePos.x,mousePos.y);
    }

    if(m_selected && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(m_parent->GetWorldPosition().y <= 400)
        {
           PlayCard();
        }

        m_parent->SetWorldPosition(m_slot->pos->x,m_slot->pos->y);
        m_selected = false;
        m_playerComponent->isHoldingCard = false;
    }
}

void CardComponent::SetHandSlot(HandSlot* slot)
{
    m_slot = slot;
}

void CardComponent::SetPlayer(PlayerComponent *playerComponent)
{
    m_playerComponent = playerComponent;
}

void CardComponent::SetDamage(int damage)
{
    m_damage = damage;
}

void CardComponent::SetCost(int cost)
{
    m_cost = cost;
}

void CardComponent::SetAbility(std::function<void()> ability)
{
    m_ability = ability;
}

void CardComponent::PlayCard()
{
    if(m_ability != nullptr)
        m_ability();

    m_playerComponent->GetHand()->GetHandComponent()->DecrementCardNumber();
    m_slot->EmptySlot();
    m_parent->parentScene->DestroyEntity(m_parent);

}

