//
// Created by Igli milaqi on 20/01/2019.
//

#include "PlayerInfo.h"
#include "../Engine/Game.h"
#include "../Engine/Text.h"
#include "../Engine/Scene.h"
#include "Hand.h"
#include "Deck.h"

void PlayerInfo::Build()
{
    Entity::Build();

    float gameWidth = Engine::Game::Instance()->Width();
    float gameHeight =  Engine::Game::Instance()->Height();
    SetWorldPosition(gameWidth - 500, gameHeight - 800);

    deckInfoText = AddComponent<Engine::TextComponent>();

}

void PlayerInfo::Start()
{
    Entity::Start();

    deckInfoText->SetCharacterSize(48);
}

void PlayerInfo::Update(float timeStep)
{
    Entity::Update(timeStep);

    int cardNumberOnHand = m_playerComponent->GetHand()->GetHandComponent()->GetCurrentCardNumber();
    int cardsOnDeck = m_playerComponent->GetDeck()->GetDeckComponent()->GetNumberOfCardsInDeck();
    deckInfoText->SetText("CardNumber: " + std::to_string(cardNumberOnHand) +
    "\nPlayerHealth: " + std::to_string(m_playerComponent->GetHealth()) + "\nCardsInDeck: " + std::to_string(cardsOnDeck)
    + "\nMana: " + std::to_string(m_playerComponent->GetCurrentManaCount()) + "/" + std::to_string(m_playerComponent->GetMaxManaCount()));
}

void PlayerInfo::SetPlayerComponent(PlayerComponent *p)
{
    m_playerComponent = p;
}
