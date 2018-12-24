//
// Created by Igli milaqi on 06/10/2018.
//

#ifndef SMFLPROJECT_SCENE_H
#define SMFLPROJECT_SCENE_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "Entity.h"
#include "TextComponent.h"

namespace Engine {

    class SpriteRenderer;

    class Scene {

    private:
        std::string m_name;

    public:
        virtual ~Scene();
        void DestroyEntity(Engine::Entity* objToDestroy);
        std::vector<Engine::Entity*> m_entities;
        std::vector<Engine::SpriteRenderer*> m_spriteRenderVector;
        std::vector<Engine::TextComponent*> m_textRenderVector;
        std::vector<Engine::Entity*> m_EntityGarbage;
        Scene();
        std::string GetName();
        void RenderAllEntities(sf::RenderWindow& window);
        void RenderAllText(sf::RenderWindow& window);
        virtual void UpdateScene(float timeStep);
        virtual void BuildScene() = 0;
        void DestroyAllEntities();
        void ClearDeadEntities();
        void SetName(const std::string& name);

        /*!
         * Used to Instantiate an GameObject In the Current Scene.
         * @tparam T Type of GameObject
         * @return Pointer to the created GameObject
         */
        template <typename T>
        T* Instantiate()
        {
            T* entityToCreate = new T;
            m_entities.push_back(entityToCreate);
            Entity* entity = m_entities.at(m_entities.size() - 1);
            entity->parentScene = this;
            entity->Build();
            entity->Start();
            return entityToCreate;
        }

    };
}


#endif //SMFLPROJECT_SCENE_H
