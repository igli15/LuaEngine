//
// Created by Igli milaqi on 10/10/2018.
//

#ifndef SMFLPROJECT_SCENEMANAGER_H
#define SMFLPROJECT_SCENEMANAGER_H

#include <map>
#include <string>
#include <iostream>
#include "Scene.h"

namespace Engine {

    class SceneManager {

    private:
        Scene* m_currentScene = nullptr;
        void DestroyScene(Scene* scene);
        Scene* m_sceneToBeDeleted = nullptr;
        std::vector<Scene*> m_DestroyedScenesVector;

    public:
        SceneManager();
        std::map<std::string, Engine::Scene *> sceneMap;

        void ClearDestroyedScene();

        template <typename  T>
        T* CreateScene(std::string sceneName)
        {
            if(m_currentScene != nullptr) DestroyScene(m_currentScene);
            T* scene = new T(sceneName);
            m_currentScene = scene;
            m_currentScene->BuildScene();
            m_currentScene->StartScene();
           // std::cout<<"Created Scene"<<std::endl;

            return scene;
        }

        Scene* GetScene(std::string name);
        Scene* GetCurrentScene();

    };


}

#endif //SMFLPROJECT_SCENEMANAGER_H
