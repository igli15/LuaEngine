//
// Created by Igli milaqi on 04/10/2018.
//

#include "Component.h"
#include "Entity.h"
#include "Collider.h"
#include <iostream>
Engine::Entity * Engine::Component::Parent() const
{
    return m_parent;
}

Engine::Component::~Component()
{
    m_parent = nullptr;   //just destroy the pointer.. The parent should remain as it is.
}

void Engine::Component::Update(float timeStep)
{

}

void Engine::Component::Start()
{

}

void Engine::Component::SetParent(Engine::Entity* entity)
{
    m_parent = entity;
}

void Engine::Component::OnCollisionEnter(const Collider& other) const
{

}



