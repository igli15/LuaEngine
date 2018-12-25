//
// Created by Igli milaqi on 08/10/2018.
//

#ifndef SMFLPROJECT_GAME_H
#define SMFLPROJECT_GAME_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Physics.h"
#include "EventQueue.h"


namespace Engine {

    class Entity;
    class Scene;
    class SceneManager;


    class Game {
    public:
        virtual ~Game();
        void Build();
        void Gameloop();
        Game(unsigned int  width,unsigned int height,std::string gameTitle);

        static Game* Instance();
        static SceneManager* GetSceneManager();
        static Physics* GetPhysics();
        static EventQueue* GetEventQueue();

        unsigned int Width();
        unsigned int Height();

    private:
        static Game* instance;

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
