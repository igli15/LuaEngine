//
// Created by Igli milaqi on 29/12/2018.
//

#include <random>
#include <iostream>
#include "DeckComponent.h"
#include "../Card.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "CardComponent.h"
#include "PlayerComponent.h"
#include "HandComponent.h"
#include "../Hand.h"

void DeckComponent::Start()
{
    Component::Start();

}

void DeckComponent::AddCardTemplate(CardTemplate *cardTemplate)
{
    m_cardTemplates.push_back(cardTemplate);
}

Card* DeckComponent::DrawCard()
{
    if(m_cardTemplates.empty())
    {
        std::cout<<"no cards left in the deck"<<std::endl;
        m_playerComponent->DealDamage(2);
        return  nullptr;
    }

    CardTemplate* cardTemplate = m_cardTemplates[m_cardTemplates.size() - 1];
    m_cardTemplates.erase(m_cardTemplates.end() - 1 );

    if(m_playerComponent->GetHand()->GetHandComponent()->GetCurrentCardNumber() >= m_playerComponent->GetHand()->GetHandComponent()->GetMaxCardCapacity())
    {
        std::cout<<"mill card here"<<std::endl;
        return nullptr;
    }

    Card* card = m_parent->parentScene->Instantiate<Card>();
    card->ApplyTemplate(*cardTemplate);
    return card;
}

void DeckComponent::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    std::shuffle(m_cardTemplates.begin(),m_cardTemplates.end(),rng);
}

void DeckComponent::SetPlayer(PlayerComponent *p)
{
    m_playerComponent = p;
}

int DeckComponent::GetNumberOfCardsInDeck()
{
    if(this != nullptr)
    return m_cardTemplates.size();
}

