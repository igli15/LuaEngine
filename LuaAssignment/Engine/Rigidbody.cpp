//
// Created by Igli milaqi on 09/10/2018.
//

#include <iostream>
#include "Rigidbody.h"
#include "Entity.h"



void Engine::Rigidbody::Start()
{
    Component::Start();

}

void Engine::Rigidbody::Update(float timeStep)
{
    Component::Update(timeStep);

    *m_velocity += (*m_acceeration) - m_friction * (*m_velocity);
    m_velocity->MaxLength(m_maxSpeed);
    m_parent->Move(*m_velocity * timeStep);
}

void Engine::Rigidbody::SetAcceleration(float x, float y)
{
    m_acceeration->x = x;
    m_acceeration->y = y;
}

void Engine::Rigidbody::SetMaxSpeed(float maxSpeed)
{
    m_maxSpeed = maxSpeed;
}

void Engine::Rigidbody::SetFriction(float friction)
{
    m_friction = friction;
}

void Engine::Rigidbody::SetVelocity(float x, float y)
{
    m_velocity->x = x;
    m_velocity->y = y;
}

Engine::IVector *Engine::Rigidbody::GetAcceleration()
{
    return m_acceeration;
}

Engine::IVector *Engine::Rigidbody::GetVelocity()
{
    return m_velocity;
}

Engine::Rigidbody::Rigidbody()
{
    m_acceeration = new IVector(0,0);
    m_velocity = new IVector(0,0);
}

