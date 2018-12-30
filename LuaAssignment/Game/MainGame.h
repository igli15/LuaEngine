//
// Created by Igli milaqi on 12/12/2018.
//

#ifndef SMFLPROJECT_MAINGAME_H
#define SMFLPROJECT_MAINGAME_H

#include "../Engine/Game.h"

class MainGame : public Engine::Game {

public:

    MainGame();
    void LoadResources(Engine::ResourceManager& resourceManager) override;
    void Build() override;
};


#endif //SMFLPROJECT_MAINGAME_H
