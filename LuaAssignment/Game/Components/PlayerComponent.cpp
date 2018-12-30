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

    CardTemplate* t = new CardTemplate("LOL","DESC",Engine::Game::GetResourceManager()->GetTexture("CardArtTest"),10,20, nullptr);
    m_deck->GetDeckComponent()->AddCardTemplate(t);

    DrawCard();

}

void PlayerComponent::Update(float timeStep)
{
    Component::Update(timeStep);
}


void PlayerComponent::AddCardToHand(Card *card)
{
    card->GetComponent<CardComponent>()->SetPlayer(this);
    m_hand->GetHandComponent()->AddCard(card);
}

void PlayerComponent::DrawCard()
{
    AddCardToHand(m_deck->GetDeckComponent()->DrawCard());
}



