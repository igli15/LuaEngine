//
// Created by Igli milaqi on 20/01/2019.
//

#include "Enemy.h"
#include "../Engine/Game.h"
#include "../Engine/Scene.h"

void Enemy::Build()
{
    m_healthText = parentScene->Instantiate<Engine::Text>();
    m_enemyInfo = parentScene->Instantiate<Engine::Text>();

    AddChild(m_healthText);
    AddChild(m_enemyInfo);

    m_healthText->SetLocalPosition(150,20);

    m_enemyInfo->SetLocalPosition(150,60);

    m_enemyComponent = AddComponent<EnemyComponent>();

    m_healthText->GetTextComponent()->SetCharacterSize(48);
    m_enemyInfo->GetTextComponent()->SetCharacterSize(48);

    m_spriteRenderer = AddComponent<Engine::SpriteRenderer>();
    m_spriteRenderer->ApplyTexture(Engine::Game::GetResourceManager()->GetTexture("EnemyBorder"));

    Entity::Build();
}

void Enemy::Start()
{
    Entity::Start();

    m_enemyArtSprite = parentScene->Instantiate<Engine::Sprite>();
    m_enemyArtSprite->GetSpriteRenderer()->ApplyTexture(Engine::Game::GetResourceManager()->GetTexture("EnemyArt"));

    AddChild(m_enemyArtSprite);

    SetWorldPosition(Engine::Game::Instance()->Width()/2 - 300 ,200);
}

void Enemy::Update(float timeStep)
{
    Entity::Update(timeStep);

    m_healthText->SetText("Health: " + std::to_string(m_enemyComponent->GetHealth()));

    if(m_enemyComponent->IsFrozen())
    {
        m_enemyInfo->SetText("Frozen");
    } else{
        m_enemyInfo->SetText("");
    }

}
