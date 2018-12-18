//
// Created by Igli milaqi on 08/10/2018.
//

#include "Game.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "SceneManager.h"

#include "EventQueue.h"



Engine::SceneManager* Engine::Game::m_sceneManager;

Engine::Game* Engine::Game::instance;

Engine::Physics* Engine::Game::m_physics;

Engine::EventQueue* Engine::Game::m_eventQueue;

Engine::Game::Game(unsigned int width, unsigned int height,std::string gameTitle)
{
    instance = this;
    m_width = width;
    m_height = height;
    m_title = gameTitle;
}


void Engine::Game::Build()
{
    m_screenBits = sf::VideoMode::getDesktopMode().bitsPerPixel;
    m_physics = GetPhysics();
    m_sceneManager = GetSceneManager();
    m_eventQueue = GetEventQueue();
    m_window = new sf::RenderWindow(sf::VideoMode(m_width,m_height,m_screenBits),m_title);
   // (m_sceneManager->CreateScene<MainMenu>("MainMenu"));
}

void Engine::Game::Gameloop()
{
    sf::Clock clock;

    const float FPS = 60.0f;
    m_window->setFramerateLimit(FPS);
    const float ticksPerMilliseconds = 1000.0f/FPS;
    float lag = 0.0f;

    while(m_window->isOpen())
    {
        sf::Event event;
        float elapsed = clock.getElapsedTime().asMilliseconds();
        lag += elapsed;
        bool physicsIsUpdated = false;
        while(lag >= ticksPerMilliseconds) {

            physicsIsUpdated = true;

            m_sceneManager->ClearDestroyedScene();

            m_eventQueue->HandleEvents();
            if(m_sceneManager->GetCurrentScene() != nullptr)
            {

                m_sceneManager->GetCurrentScene()->ClearDeadEntities();
                m_sceneManager->GetCurrentScene()->UpdateScene(ticksPerMilliseconds); //Update the current scene
            }

            clock.restart();
            lag -= ticksPerMilliseconds;
        }

        if(physicsIsUpdated) {

            m_window->clear(sf::Color::Black);
            if(m_sceneManager->GetCurrentScene() != nullptr)
            {
                m_sceneManager->GetCurrentScene()->RenderAllEntities(*m_window);
                m_sceneManager->GetCurrentScene()->RenderAllText(*m_window);
            }
            m_window->display();

        }

        while(m_window->pollEvent(event)) {

            if(event.type == sf::Event::Closed){

                return;

            }

        }

    }
}

Engine::Game::~Game()
{
    instance = nullptr;
}


Engine::Game *Engine::Game::Instance()
{
   // if(instance == nullptr) return  new Game(m_width,m_height,m_title);
    return instance;
}

Engine::SceneManager* Engine::Game::GetSceneManager()
{
    if(m_sceneManager == nullptr) return new SceneManager();
    return m_sceneManager;
}

Engine::Physics* Engine::Game::GetPhysics()
{
    if(m_physics == nullptr) return new Physics();
    return m_physics;
}

unsigned int Engine::Game::Width()
{
    return m_width;
}

unsigned int Engine::Game::Height()
{
    return m_height;
}

Engine::EventQueue *Engine::Game::GetEventQueue()
{
    if(m_eventQueue == nullptr) return new EventQueue();
    return m_eventQueue;
}


