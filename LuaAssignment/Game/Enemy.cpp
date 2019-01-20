//
// Created by Igli milaqi on 20/01/2019.
//

#include "Enemy.h"
#include "../Engine/Game.h"
#include "../Engine/Scene.h"

void Enemy::Build()
{
    m_enemyComponent = AddComponent<EnemyComponent>();

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
