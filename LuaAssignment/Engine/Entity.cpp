
#include "Entity.h"
#include <iostream>
#include "IVector.h"
#include "math.h"
#include <algorithm>
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

void Engine::Entity::SetLocalPosition(float x, float y)
{
    setPosition(x, y);
}

void Engine::Entity::SetLocalPosition(const sf::Vector2f &vec)
{
    setPosition(vec);
}

sf::Vector2f Engine::Entity::GetLocalPosition()
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
    m_parentEntity = nullptr;
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

void Engine::Entity::ScaleEntityLocal(const float &scaleX, const float &scaleY)
{
    setScale(scaleX,scaleY);

    Collider* collider = GetComponent<Collider>();
    if(collider != nullptr)
    {
        collider->SetWidth(m_width * scaleX);
    }
}

void Engine::Entity::AddChild(Engine::Entity *child)
{
    if(std::find(m_childerens.begin(),m_childerens.end(),child) != m_childerens.end())
    {
        return;
    }

    child->SetParent(this);
    m_childerens.push_back(child);
}

void Engine::Entity::SetParent(Engine::Entity* parent)
{
    m_parentEntity = parent;
    m_topParentNode = GetParentRecursively();

    for (int i = 0; i < GetChildCount() ; ++i)
    {
        GetChildAt(i)->SetTopParentNode(m_topParentNode);
    }

}

void Engine::Entity::SetTopParentNode(Engine::Entity *topParentNode)
{
    m_topParentNode = topParentNode;
}

Engine::Entity *Engine::Entity::GetParentRecursively()
{
    Entity* parent = m_parentEntity;

    while(parent != nullptr)
    {
        if(m_parentEntity->m_parentEntity == nullptr)
            return  parent;

        parent = m_parentEntity->m_parentEntity;
    }

    return parent;

}

Engine::Entity *Engine::Entity::GetParentEntity()
{
    return m_parentEntity;
}

void Engine::Entity::SetWorldPosition(float x, float y)
{
    sf::Vector2f v(x,y);

   // Entity* parent = GetParentRecursively();
    if(m_topParentNode != nullptr)
    {
        v = m_topParentNode->getTransform().getInverse().transformPoint(v);
        setPosition(v);
    }
    else
    {
        setPosition(v);
    }
}

void Engine::Entity::SetWorldPosition(sf::Vector2f vec)
{
   // Entity* parent = GetParentRecursively();
    if(m_topParentNode != nullptr)
    {
        vec = m_topParentNode->getTransform().getInverse().transformPoint(vec);

        setPosition(vec);
    }
    else
    {
        setPosition(vec);
    }
}

sf::Vector2f Engine::Entity::GetWorldPosition()
{
   // Entity* parent = GetParentRecursively();

    sf::Vector2f currentPos= getPosition();

    if(m_topParentNode != nullptr)
    {
        currentPos = m_topParentNode->getTransform().transformPoint(currentPos);
        return currentPos;
    }
    else
    {
        return GetLocalPosition();
    }
}

Engine::Entity* Engine::Entity::GetChildAt(const int& index)
{
    return m_childerens.at(index);
}

int Engine::Entity::GetChildCount()
{
    return m_childerens.size();
}



