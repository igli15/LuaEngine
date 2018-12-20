//
// Created by Igli milaqi on 06/10/2018.
//

#include "Scene.h"
#include "SceneManager.h"
#include "algorithm"
#include "SpriteRenderer.h"
#include <iostream>

Engine::Scene::Scene()
{

}

std::string Engine::Scene::GetName()
{
    return m_name;
}



void Engine::Scene::RenderAllEntities(sf::RenderWindow& window)
{

    if( m_spriteRenderVector.size() == 0) return;

    for (int i = m_spriteRenderVector.size() -1 ; i >= 0; i--)
    {
        m_spriteRenderVector[i]->RenderSprite(window);
    }
}

void Engine::Scene::BuildScene()
{
    for(int i = m_entities.size() - 1; i >= 0; i-- )
    {
        m_entities[i]->Build();
    }
}

void Engine::Scene::UpdateScene(float timeStep)
{
        for(int i = m_entities.size() - 1; i >= 0; i-- )
        {
            m_entities[i]->Update(timeStep);
        }
}

void Engine::Scene::DestroyEntity(Engine::Entity *objToDestroy)
{
    objToDestroy->MarkEntityForDeletion();

}

void Engine::Scene::DestroyAllEntities()
{
  //  for (auto entity : *m_entities)
    for (int i = 0; i <m_entities.size() ; ++i)
    {
        DestroyEntity(m_entities[i]);
    }

    ClearDeadEntities();

}

Engine::Scene::~Scene()
{
    DestroyAllEntities();
}

void Engine::Scene::ClearDeadEntities()
{
    if(m_entities.size() > 0) {

        for (int i = m_entities.size() - 1; i >= 0; --i) {
            if (m_entities[i]->IsDead())
            {
                Entity* entity = m_entities[i];
                m_entities.erase(std::find(m_entities.begin(), m_entities.end(), entity));
                delete entity;
            }
        }
    }
}

void Engine::Scene::RenderAllText(sf::RenderWindow& window)
{
    for (int i = m_textRenderVector.size() -1 ; i >= 0; i--)
    {
        m_textRenderVector[i]->DrawText(window);
    }
}

void Engine::Scene::SetName(const std::string &name)
{
    m_name = name;
}



