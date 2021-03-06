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
        if(m_parent->GetWorldPosition().y <= 600)
        {
            if(m_cost <= m_playerComponent->GetCurrentManaCount())
             m_playerComponent->PlayCard(this);
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

HandSlot *CardComponent::GetSlot()
{
    return m_slot;
}

std::function<void()> CardComponent::GetAbility()
{
    return m_ability;
}

int CardComponent::GetCost()
{
    return m_cost;
}

int CardComponent::GetDamage() {
    return m_damage;
}

void CardComponent::DecreaseCost(int amount)
{
    m_cost -= amount;

    if(m_cost<= 0) m_cost = 0 ;
}

void CardComponent::IncreaseDamage(int amount)
{
    m_damage += amount;
}

bool CardComponent::isSelected()
{
    return m_selected;
}

void CardComponent::OnCostChanged()
{
    static_cast<Card*>(m_parent)->SetCardCostText(std::to_string(m_cost));
}

