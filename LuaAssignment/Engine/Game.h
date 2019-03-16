//
// Created by Igli milaqi on 08/10/2018.
//

#ifndef SMFLPROJECT_GAME_H
#define SMFLPROJECT_GAME_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Physics.h"
#include "EventQueue.h"
#include "ResourceManager.h"


namespace Engine {

    class Entity;
    class Scene;
    class SceneManager;


    class Game {
    public:
        virtual ~Game();
        virtual void LoadResources(ResourceManager& manager) = 0;
        virtual void Build() = 0;
        void Gameloop();
        Game(unsigned int  width,unsigned int height,std::string gameTitle);
        sf::RenderWindow* GetWindow();

        static Game* Instance();
        static SceneManager* GetSceneManager();
        static Physics* GetPhysics();
        static EventQueue* GetEventQueue();
        static Engine::ResourceManager* GetResourceManager();

        unsigned int Width();
        unsigned int Height();

    private:
        static Game* instance;
        static Engine::ResourceManager* m_resourceManager;
        static SceneManager* m_sceneManager;
        static Physics* m_physics;
        static EventQueue* m_eventQueue;

    protected:
        sf::RenderWindow* m_window;
        unsigned int m_width;
        unsigned int m_height;
        unsigned int m_screenBits;
        std::string m_title;
    };
}


#endif //SMFLPROJECT_GAME_H
