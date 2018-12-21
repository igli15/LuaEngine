//
// Created by Igli milaqi on 14/10/2018.
//

#include "Collider.h"
#include "Game.h"
#include "Entity.h"
#include "Rigidbody.h"
#include <iostream>

Engine::Collider::Collider()
{
    Game::GetPhysics()->colliderVector.push_back(this);
}

void Engine::Collider::Start()
{
    Component::Start();

    m_rb = m_parent->GetComponent<Rigidbody>();
    m_width = m_parent->Width();
    m_height = m_parent->Height();

    m_x = m_parent->GetLocalPosition().x;
    m_y = m_parent->GetLocalPosition().y;
}


void Engine::Collider::Update(float timeStep)
{
    Component::Update(timeStep);


    CheckForAllCollisions();
    m_x = m_parent->GetLocalPosition().x;
    m_y = m_parent->GetLocalPosition().y;

}


void Engine::Collider::CheckForAllCollisions()
{
    if(!Game::GetPhysics()->colliderVector.empty())
    {
        for (int i = Game::GetPhysics()->colliderVector.size() -1 ; i >= 0; --i)
        {
            if(Game::GetPhysics()->colliderVector[i] != this) //If they are not pointing at same address
            {
                if(Game::GetPhysics()->CircleCircleCollision(*this,*Game::GetPhysics()->colliderVector[i]))
                {
                    m_parent->UpdateAllOnCollisionEnters(*Game::GetPhysics()->colliderVector[i]);
                }
            }
        }
    }
}


float Engine::Collider::Width() const {
    return m_width;
}

float Engine::Collider::Height()
{
    return m_height;
}

bool Engine::Collider::IsTrigger()
{
    return  m_isTrigger;
}

float Engine::Collider::X() const {
    return  m_x;
}

float Engine::Collider::Y() const {
    return m_y;
}

void Engine::Collider::SetWidth(float width)
{
    m_width = width;
}

void Engine::Collider::SetHeight(float height)
{
    m_height = height;
}

void Engine::Collider::SetIsTrigger(bool isTrigger)
{
    m_isTrigger = isTrigger;
}

Engine::Collider::~Collider()
{
    for (int i = 0; i < Game::GetPhysics()->colliderVector.size(); ++i)
    {

        if(Game::GetPhysics()->colliderVector[i]->Parent() == this->Parent())
        {
           // std::cout<< "deleting: "<< Game::GetPhysics()->colliderVector[i]->Parent()->Tag() <<std::endl;

            Game::GetPhysics()->colliderVector.erase(Game::GetPhysics()->colliderVector.begin() + i);
        }
    }
    m_rb = nullptr;
}



