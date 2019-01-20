//
// Created by Igli milaqi on 27/12/2018.
//

#include "PlayerComponent.h"
#include "../Hand.h"
#include "../Deck.h"
#include "../Card.h"
#include "CardComponent.h"
#include "DeckComponent.h"
#include "../../Engine/Scene.h"
#include "../../Engine/Game.h"

void PlayerComponent::Start()
{
    Component::Start();

    m_hand = m_parent->parentScene->Instantiate<Hand>();
    m_deck = m_parent->parentScene->Instantiate<Deck>();
    m_deck->GetDeckComponent()->SetPlayer(this);

    for (int i = 0; i < 20; ++i) {
        CardTemplate *t = new CardTemplate("LOL", "DESC", Engine::Game::GetResourceManager()->GetTexture("CardArtTest"),
                                           10, 20, nullptr);
        m_deck->GetDeckComponent()->AddCardTemplate(t);
    }

    for (int j = 0; j < 5 ; ++j) {

        DrawCard();
    }

}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        DrawCard();
    }
}


void PlayerComponent::AddCardToHand(Card *card)
{
    card->GetComponent<CardComponent>()->SetPlayer(this);
    m_hand->GetHandComponent()->AddCard(card);
}

void PlayerComponent::DrawCard()
{
    Card* c = m_deck->GetDeckComponent()->DrawCard();

    if(c != nullptr)
    AddCardToHand(c);
}

Hand *PlayerComponent::GetHand()
{
    return m_hand;
}

Deck *PlayerComponent::GetDeck()
{
    return  m_deck;
}



