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
#include "Player.h"

void MainLevel::BuildScene()
{
    Player* p = Instantiate<Player>();
    Card* card = Instantiate<Card>();

    Card* card2 = Instantiate<Card>();

    p->GetComponent<PlayerComponent>()->GetHand()->AddCard(card);
    p->GetComponent<PlayerComponent>()->GetHand()->AddCard(card2);
}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

