//
// Created by Igli milaqi on 20/10/2018.
//

#include "Text.h"
#include "TextComponent.h"
#include <SFML/Graphics.hpp>

Engine::Text::Text()
{
}

void Engine::Text::Build()
{
    m_textComponent =  AddComponent<TextComponent>();
    Entity::Build();
}

void Engine::Text::ScaleEntity(const float &scaleX, const float &scaleY)
{
    Entity::ScaleEntity(scaleX, scaleY);
    m_textComponent->GetText()->setScale(scaleX,scaleY);

}

void Engine::Text::SetPosition(float x, float y)
{
    Entity::SetPosition(x, y);
    m_textComponent->GetText()->setPosition(x,y);
}

