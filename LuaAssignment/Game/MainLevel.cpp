//
// Created by Igli milaqi on 19/12/2018.
//

#include <iostream>
#include "MainLevel.h"


#include "../Engine/Text.h"
#include "../Engine/Game.h"

void MainLevel::BuildScene()
{
    std::cout<<"Welcome to MainLevel"<<std::endl;

   Engine::Text* t = Instantiate<Engine::Text>();
   t->SetPosition(Engine::Game::Instance()->Width()/2, Engine::Game::Instance()->Height()/2);
   

}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

