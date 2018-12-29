//
// Created by Igli milaqi on 29/12/2018.
//

#include "Deck.h"

void Deck::Build()
{
    Entity::Build();
    m_deckComponent = AddComponent<DeckComponent>();
}

DeckComponent *Deck::GetDeckComponent() const
{
    return m_deckComponent;
}

