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
#include "PlayerInfo.h"

void MainLevel::BuildScene()
{
    Player* p = Instantiate<Player>();

    PlayerInfo* info = Instantiate<PlayerInfo>();
    info->SetPlayerComponent(p->GetComponent<PlayerComponent>());

}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

