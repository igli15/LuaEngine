//
// Created by Igli milaqi on 19/12/2018.
//

#include <iostream>
#include "MainLevel.h"


#include "../Engine/Text.h"
#include "../Engine/Game.h"
#include "../Engine/SpriteRenderer.h"
#include "../Engine/IVector.h";
#include "Card.h"

void MainLevel::BuildScene()
{
    std::cout<<"Welcome to MainLevel"<<std::endl;

   Card* card = Instantiate<Card>();
   card->SetLocalPosition(Engine::Game::Instance()->Width() / 2,Engine::Game::Instance()->Height() / 2);

}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

