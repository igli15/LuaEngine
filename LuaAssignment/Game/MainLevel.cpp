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
   t->SetLocalPosition(Engine::Game::Instance()->Width() / 2, Engine::Game::Instance()->Height() / 2);

   Engine::Entity* entity = Instantiate<Engine::Entity>();
   Engine::SpriteRenderer* sp =  entity->AddComponent<Engine::SpriteRenderer>();
   sp->ApplySprite("../Assets/asteroids.png");
   entity->Start();
   entity->setOrigin(entity->Width()/2,entity->Height()/2);
   entity->SetLocalPosition(Engine::Game::Instance()->Width() / 2, Engine::Game::Instance()->Height() / 2);


   Engine::Entity* entity2 = Instantiate<Engine::Entity>();
   Engine::SpriteRenderer* sp2 =  entity2->AddComponent<Engine::SpriteRenderer>();
   sp2->ApplySprite("../Assets/asteroids.png");
   entity2->Start();

   entity->AddChild(entity2);

   entity2->SetWorldPosition(60, 30);
   std::cout<<entity2->GetWorldPosition().x<<std::endl;
   std::cout<<entity2->GetLocalPosition().x<<std::endl;

}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

