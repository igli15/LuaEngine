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
#include "Enemy.h"

void MainLevel::BuildScene()
{
    Player* p = Instantiate<Player>();
    PlayerComponent* playerComponent = p->GetComponent<PlayerComponent>();
    Enemy* enemy = Instantiate<Enemy>();
    EnemyComponent* enemyComponent = enemy->GetComponent<EnemyComponent>();


    enemyComponent->SetPlayerComponent(playerComponent);
    playerComponent->SetEnemyComponent(enemyComponent);

    PlayerInfo* info = Instantiate<PlayerInfo>();
    info->SetPlayerComponent(playerComponent);



}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

