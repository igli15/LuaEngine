//
// Created by Igli milaqi on 24/12/2018.
//

#include "Sprite.h"

void Engine::Sprite::Build()
{
    Entity::Build();

    m_spriteRenderer = AddComponent<SpriteRenderer>();
}

Engine::SpriteRenderer *Engine::Sprite::GetSpriteRenderer()
{
    return m_spriteRenderer;
}

