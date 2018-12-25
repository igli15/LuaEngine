//
// Created by Igli milaqi on 11/10/2018.
//

#include "SpriteRenderer.h"
#include "Entity.h"
#include "Scene.h"
#include "iostream"

void Engine::SpriteRenderer::RenderSprite(sf::RenderWindow &window)
{
    if(m_sprite != nullptr)
    {
        sf::RenderStates spriteRenderStates(m_sprite->getTransform());

        spriteRenderStates.transform *= m_parent->getTransform();

        if(m_parent->GetParentEntity() != nullptr)
        {
            spriteRenderStates.transform *= m_parent->GetParentEntity()->getTransform();
        }


        window.draw(*m_sprite,spriteRenderStates);
    }

}

sf::Sprite *Engine::SpriteRenderer::ApplySprite(const std::string& filename)
{
    if(m_sprite == nullptr)
    {
        CreateSprite(filename);
        m_parent->ApplySprite(m_sprite);
        m_parent->SetWidth(m_sprite->getGlobalBounds().width);
        m_parent->SetHeight(m_sprite->getGlobalBounds().height);
        return m_sprite;
    }
    else
    {
        delete m_sprite;
        m_sprite = nullptr;
        delete m_texture;
        m_texture = nullptr;
        CreateSprite(filename);
        m_parent->ApplySprite(m_sprite);
        m_parent->SetWidth(m_sprite->getGlobalBounds().width);
        m_parent->SetHeight(m_sprite->getGlobalBounds().height);
        return m_sprite;
    }
}

void Engine::SpriteRenderer::CreateSprite(const std::string& filename)
{
    m_texture = new sf::Texture();
    m_texture->loadFromFile(filename);
    m_sprite = new sf::Sprite();
    m_sprite->setTexture(*m_texture);
    //m_sprite->setOrigin(m_sprite->getLocalBounds().width/2,m_sprite->getLocalBounds().height/2);
}

sf::Sprite *Engine::SpriteRenderer::GetSprite()
{
    return m_sprite;
}


void Engine::SpriteRenderer::Start()
{
    Component::Start();
    m_parent->parentScene->m_spriteRenderVector.push_back(this);
}

Engine::SpriteRenderer::~SpriteRenderer()
{
    auto iterator = std::find(m_parent->parentScene->m_spriteRenderVector.begin(),
                              m_parent->parentScene->m_spriteRenderVector.end(),this);

    if(iterator != m_parent->parentScene->m_spriteRenderVector.end()) {

        //std::cout<<"REmoved"<<std::endl;
        m_parent->parentScene->m_spriteRenderVector.erase(iterator);
    }

    delete m_texture;
    m_texture = nullptr;
    m_sprite = nullptr;
}

Engine::SpriteRenderer::SpriteRenderer()
{
}




