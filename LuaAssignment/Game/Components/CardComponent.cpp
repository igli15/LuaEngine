//
// Created by Igli milaqi on 27/12/2018.
//

#include <iostream>
#include "CardComponent.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Game.h"

void CardComponent::Start()
{
    Component::Start();
    m_spriteRenderer = m_parent->GetComponent<Engine::SpriteRenderer>();
}

void CardComponent::Update(float timeStep)
{
    Component::Update(timeStep);

    float width = m_parent->Width();
    float height = m_parent->Height();

    auto mousePos = sf::Mouse::getPosition(*(Engine::Game::Instance()->GetWindow()));

    if(mousePos.x > m_parent->GetWorldPosition().x - width/2 && mousePos.x < m_parent->GetWorldPosition().x + width/2
        && mousePos.y > m_parent->GetWorldPosition().y - height/2 && mousePos.y < m_parent->GetWorldPosition().y + height/2)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_selected = true;
            m_parent->SetWorldPosition(mousePos.x,mousePos.y);
        }
    }

    if(m_selected && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_parent->SetWorldPosition(m_slot->pos->x,m_slot->pos->y);
        m_selected = false;
    }
}

void CardComponent::SetHandSlot(HandSlot* slot)
{
    m_slot = slot;
}
