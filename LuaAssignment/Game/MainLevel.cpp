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
#include "Hand.h"

void MainLevel::BuildScene()
{
    std::cout<<"Welcome to MainLevel"<<std::endl;

    Hand* hand = new Hand(100,400,570);

   Card* card = Instantiate<Card>();
   //card->SetLocalPosition(Engine::Game::Instance()->Width() / 2,Engine::Game::Instance()->Height() / 2);

    Card* card2 = Instantiate<Card>();
    //card2->SetLocalPosition(Engine::Game::Instance()->Width() / 2,Engine::Game::Instance()->Height() / 2);

   hand->AddCard(card);
   hand->AddCard(card2);
}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

