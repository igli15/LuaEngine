//
// Created by Igli milaqi on 19/12/2018.
//

#include <iostream>
#include "MainLevel.h"


#include "../Engine/Text.h"
#include "../Engine/Game.h"
#include "../Engine/SpriteRenderer.h"
#include "../Engine/IVector.h";

void MainLevel::BuildScene()
{
    std::cout<<"Welcome to MainLevel"<<std::endl;

   Engine::Text* t = Instantiate<Engine::Text>();


   Engine::Entity* entity = Instantiate<Engine::Entity>();
   Engine::SpriteRenderer* sp =  entity->AddComponent<Engine::SpriteRenderer>();
   sp->ApplySprite("../Assets/CardTemplate.png");
   entity->Start();

   entity->SetLocalPosition(Engine::Game::Instance()->Width() / 2, Engine::Game::Instance()->Height() / 2);
   entity->setOrigin(entity->Width()/2,entity->Height()/2);

   entity->AddChild(t);

   t->Start();
   t->SetLocalPosition(45,95);

}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

