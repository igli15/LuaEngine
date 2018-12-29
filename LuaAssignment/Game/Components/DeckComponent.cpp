//
// Created by Igli milaqi on 29/12/2018.
//

#include <random>
#include "DeckComponent.h"
#include "../Card.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "CardComponent.h"

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
    CardTemplate* cardTemplate = m_cardTemplates[m_cardTemplates.size() - 1];
    m_cardTemplates.erase(m_cardTemplates.end() - 1 );

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

