//
// Created by Igli milaqi on 10/10/2018.
//

#include "SceneManager.h"
#include <iostream>
#include <algorithm>


Engine::SceneManager::SceneManager()
{

}


Engine::Scene* Engine::SceneManager::GetScene(std::string sceneName)
{
    if(sceneMap.find(sceneName) == sceneMap.end())   //if it's not in the Dictionary
    {
        std::cout<<"Scene with that name is not there";
        return nullptr;
    }
    else
    {
        return sceneMap.at(sceneName);
    }

}

Engine::Scene *Engine::SceneManager::GetCurrentScene()
{
    return m_currentScene;
}


void Engine::SceneManager::DestroyScene(Engine::Scene *scene)
{
   // m_sceneToBeDeleted = m_currentScene;
   m_DestroyedScenesVector.push_back(scene);
}

void Engine::SceneManager::ClearDestroyedScene()
{
    /*if(m_sceneToBeDeleted != nullptr)
    {
        delete m_sceneToBeDeleted;
        m_sceneToBeDeleted = nullptr;
    }*/

    if(m_DestroyedScenesVector.size() != 0) {
        for (int i = 0; i < m_DestroyedScenesVector.size(); ++i) {
            delete m_DestroyedScenesVector[i];
            m_DestroyedScenesVector.erase(std::find(m_DestroyedScenesVector.begin(), m_DestroyedScenesVector.end(),
                                                    m_DestroyedScenesVector[i]));
        }
    }
}




