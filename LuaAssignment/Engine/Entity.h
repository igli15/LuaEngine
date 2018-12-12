//
// Created by Igli milaqi on 05/10/2018.
//

#ifndef SMFLPROJECT_ENTITY_H
#define SMFLPROJECT_ENTITY_H


#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Component.h"
#include "Collider.h"



namespace Engine {

    class IVector;
    class Scene;

class Entity : public sf::Transformable{

    private:
        static unsigned int m_idIncrement;

        std::string m_tag;
        std::vector<Engine::Component*> m_attachedComponents;

        unsigned int m_id;

        float m_width;
        float m_height;

        bool m_isDead = false;

        void UpdateAllAttachedComponents(float timeStep);
        void StartAllAttachedComponents();

protected:
    sf::Sprite* m_sprite = nullptr;

public:

        bool operator==(const Entity& other)const;

        unsigned int ID() const;

        static std::map<std::string, Entity*> TagDictionary;

        Entity();

        static Entity* FindEntityWithTag(const std::string& tag);

        virtual void Update(float timeStep);

        virtual void Start();

        virtual void Build();

        void UpdateAllOnCollisionEnters(const Collider& other);


        Scene* parentScene;

        Engine::IVector Forward();

        std::string Tag();

        template<typename T>
        T* AddComponent()     //Adds a component to this gameobject and also returns the added component
        {
            T* comp = new T();

            //fast way to get the last element without iterating through it.
           m_attachedComponents.push_back(comp);
           m_attachedComponents.at(m_attachedComponents.size() - 1)->SetParent(this); //Get the end

           return comp;
        }

    template<typename T>
    T* GetComponent()     //Gets a component from the list of attached components
    {
        //for(auto component : m_attachedComponents)
        for (int i = 0; i < m_attachedComponents.size() ; ++i)
        {
            if(typeid(T) == typeid(*m_attachedComponents[i]))
            {
                return (T*)m_attachedComponents[i];
            }
        }

        return nullptr;
    }


        void SetTag(const std::string& tag);

        virtual void Move(float x, float y);

        virtual void Move(const sf::Vector2f& vec);

        virtual void SetPosition(float x, float y);

        virtual void SetPosition(const sf::Vector2f& vec);

        virtual void Rotate(float angle);

        virtual void SetRotation(float angle);

        sf::Vector2f GetPosition();

        void ApplySprite(sf::Sprite* sprite);

        float Width();

        float Height();

        void SetWidth(float width);
        void SetHeight(float height);

        virtual void ScaleEntity(const float& scaleX,const float & scaleY);

        void MarkEntityForDeletion();

        bool IsDead();

        virtual ~Entity();


    };
}


#endif //SMFLPROJECT_ENTITY_H
