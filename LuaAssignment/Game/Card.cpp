//
// Created by Igli milaqi on 24/12/2018.
//

#include "Card.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Scene.h"
#include "../Engine/Entity.h"
#include "Components/CardComponent.h"

void Card::Build()
{
    Engine::Entity::Build();

    m_spriteRenderer = AddComponent<Engine::SpriteRenderer>();
    m_spriteRenderer->ApplySprite("../Assets/CardTemplate.png");

    setOrigin(Width()/2,Height()/2);

    m_cardName = parentScene->Instantiate<Engine::Text>();
    m_cardDescription = parentScene->Instantiate<Engine::Text>();

    AddChild(m_cardName);
    AddChild(m_cardDescription);
   // AddChild(m_cardImage);

    m_cardName->SetLocalPosition(45,95);
    m_cardDescription->SetLocalPosition(30,135);

    m_cardName->SetText("Card Name");
    m_cardDescription->SetText("Card Description");

    m_cardComponent = AddComponent<CardComponent>();
}

void Card::Start()
{
    Engine::Entity::Start();
    m_cardImage = parentScene->Instantiate<Engine::Sprite>();

    AddChild(m_cardImage);

}

Card::~Card()
{
    delete(m_cardDescription);
    m_cardDescription = nullptr;
    delete(m_cardImage);
    m_cardImage = nullptr;
    delete(m_cardName);
    m_cardName = nullptr;
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
    m_cardImage->GetSpriteRenderer()->ApplySprite(cardTemplate.ImagePath());

    m_cardComponent->SetCost(cardTemplate.Cost());
    m_cardComponent->SetDamage(cardTemplate.Damage());
    m_cardComponent->SetAbility(cardTemplate.Ability());
}



