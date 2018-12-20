
#include "Entity.h"
#include <iostream>
#include "IVector.h"
#include "math.h"
#include "Collider.h"

std::map<std::string,Engine::Entity*> Engine::Entity::TagDictionary;

unsigned int Engine::Entity::m_idIncrement = 0;
Engine::Entity::Entity()
{
    m_id += m_idIncrement;
    m_idIncrement+=1;

    m_isDead = false;
}


void Engine::Entity::SetTag(const std::string& tag)
{
    m_tag = tag;

    TagDictionary.insert({tag,this});
}


void Engine::Entity::Move(float x, float y)
{
    move(x,y);

}

void Engine::Entity::Move(const sf::Vector2f& vec)
{
    move(vec);
}

void Engine::Entity::SetPosition(float x, float y)
{
    setPosition(x,y);

    /*if(m_sprite!= nullptr)
    {
        m_sprite->setPosition(x, y);
    }*/
}

void Engine::Entity::SetPosition(const sf::Vector2f& vec)
{
    setPosition(vec);

}

sf::Vector2f Engine::Entity::GetPosition()
{
    return getPosition();
}

void Engine::Entity::SetRotation(float angle)
{
    setRotation(angle);

    /*if(m_sprite != nullptr)
    m_sprite->setRotation(angle);*/
}

void Engine::Entity::Rotate(float angle)
{
    rotate(angle);

}


Engine::Entity *Engine::Entity::FindEntityWithTag(const std::string &tag)
{
  if(TagDictionary.find(tag) == TagDictionary.end())   //if it's not in the Dictionary
  {
      std::cout<<"Entity with that tag does not exist!!"<<std::endl;
      return nullptr;
  }
  else
  {
      return TagDictionary.at(tag);
  }

}

//Use Build Only To Attach Components.
void Engine::Entity::Build()
{

}


void Engine::Entity::Update(float timeStep)
{
    UpdateAllAttachedComponents(timeStep);
}

void Engine::Entity::Start()
{
    StartAllAttachedComponents();
}

void Engine::Entity::UpdateAllAttachedComponents(float timeStep)
{
    //for (auto i : m_attachedComponents)
    for (int i = 0; i < m_attachedComponents.size() ; ++i) {

        m_attachedComponents[i]->Update(timeStep);
    }

}


void Engine::Entity::StartAllAttachedComponents()
{
    for (int i = 0  ; i < m_attachedComponents.size() ; i++)
    {
        m_attachedComponents[i]->Start();
    }
}


std::string Engine::Entity::Tag()
{
    return m_tag;
}


Engine::Entity::~Entity()
{

    for (int i = 0; i < m_attachedComponents.size() ; ++i)
    {
        delete m_attachedComponents[i];
        m_attachedComponents[i] = nullptr;
    }

    delete m_sprite;
    m_sprite = nullptr;
    parentScene = nullptr;
}


Engine::IVector Engine::Entity::Forward()
{
    return IVector(cosf(IVector::Deg2Rad(m_sprite->getRotation())),sinf(IVector::Deg2Rad(m_sprite->getRotation()))).Normalize();
}

void Engine::Entity::ApplySprite(sf::Sprite* sprite)
{
    m_sprite = sprite;
}

float Engine::Entity::Width()
{
    return  m_width;
}

float Engine::Entity::Height()
{
    return m_height;
}

void Engine::Entity::SetWidth(float width)
{
    m_width = width;
}

void Engine::Entity::SetHeight(float height)
{
    m_height = height;
}

void Engine::Entity::UpdateAllOnCollisionEnters(const Collider& other)
{
    for (int i = 0; i < m_attachedComponents.size() ; i++)
    {
        m_attachedComponents[i]->OnCollisionEnter(other);
    }

}

void Engine::Entity::MarkEntityForDeletion()
{
    m_isDead = true;
}

bool Engine::Entity::IsDead()
{
    return m_isDead;
}

bool Engine::Entity::operator==(const Engine::Entity &other) const
{
    return m_id == other.ID();
}

unsigned int Engine::Entity::ID() const
{
    return m_id;
}

void Engine::Entity::ScaleEntity(const float &scaleX, const float &scaleY)
{
    setScale(scaleX,scaleY);

    Collider* collider = GetComponent<Collider>();
    if(collider != nullptr)
    {
        collider->SetWidth(m_width * scaleX);
    }
}



