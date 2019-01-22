//
// Created by Igli milaqi on 24/12/2018.
//

#include "Card.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Scene.h"
#include "../Engine/Game.h"
#include "../Engine/Entity.h"
#include "Components/CardComponent.h"
#include "MainGame.h"

void Card::Build()
{
    Engine::Entity::Build();

    m_spriteRenderer = AddComponent<Engine::SpriteRenderer>();
   // m_spriteRenderer->ApplySprite("../Assets/CardTemplate.png");

   m_spriteRenderer->ApplyTexture(Engine::Game::GetResourceManager()->GetTexture("CardBackground"));

    setOrigin(Width()/2,Height()/2);

    m_cardName = parentScene->Instantiate<Engine::Text>();
    m_cardDescription = parentScene->Instantiate<Engine::Text>();
    m_cardCost = parentScene->Instantiate<Engine::Text>();

    m_cardName->GetTextComponent()->SetColor(sf::Color::Black);
    m_cardDescription->GetTextComponent()->SetColor(sf::Color::Black);
    m_cardCost->GetTextComponent()->SetColor(sf::Color::White);

    AddChild(m_cardName);
    AddChild(m_cardDescription);
    AddChild(m_cardCost);

    m_cardName->SetLocalPosition(60,95);
    m_cardDescription->SetLocalPosition(30,135);
    m_cardCost->SetLocalPosition(20,20);

    m_cardName->SetText("Card Name");
    m_cardDescription->SetText("Card Description");
    m_cardCost->SetText("0");

    m_cardComponent = AddComponent<CardComponent>();
}

void Card::Start()
{
    Engine::Entity::Start();
    m_cardImage = parentScene->Instantiate<Engine::Sprite>();

   AddChild(m_cardImage);

}


void Card::SetCardName(const std::string &name)
{
    m_cardName->SetText(name);
}

void Card::SetCardDescription(const std::string &description)
{
    m_cardDescription->SetText(description);
}

void Card::SetCardImage(const std::string &path)
{
    m_cardImage->GetSpriteRenderer()->ApplySprite(path);
}

void Card::ApplyTemplate(const CardTemplate& cardTemplate)
{
    m_cardName->SetText(cardTemplate.Name());
    m_cardDescription->SetText(cardTemplate.Description());
    m_cardImage->GetSpriteRenderer()->ApplyTexture(cardTemplate.Image());
    m_cardCost->SetText(std::to_string(cardTemplate.Cost()));

    m_cardComponent->SetCost(cardTemplate.Cost());
    m_cardComponent->SetDamage(cardTemplate.Damage());
    m_cardComponent->SetAbility(cardTemplate.Ability());
}

void Card::SetCardCostText(const std::string &newCost)
{
    m_cardCost->SetText(newCost);
}



