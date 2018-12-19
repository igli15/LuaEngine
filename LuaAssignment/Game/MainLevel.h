//
// Created by Igli milaqi on 19/12/2018.
//

#ifndef LUAASSIGNMENT_MAINLEVEL_H
#define LUAASSIGNMENT_MAINLEVEL_H


#include "../Engine/Scene.h"

class MainLevel : public Engine::Scene {

public:
    MainLevel();
    ~MainLevel() override;
    void BuildScene() override;


};


#endif //LUAASSIGNMENT_MAINLEVEL_H
