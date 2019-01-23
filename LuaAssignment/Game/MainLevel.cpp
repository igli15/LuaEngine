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
#include "CardTemplate.h"


static const struct luaL_Reg cardLib[]
        {
                {"newCard",CardTemplate::NewCardTemplate},
                {NULL,NULL}
        };

void MainLevel::BuildScene()
{
    Player* p = Instantiate<Player>();
    p->SetTag("Player");

    PlayerComponent* playerComponent = p->GetComponent<PlayerComponent>();
    Enemy* enemy = Instantiate<Enemy>();
    EnemyComponent* enemyComponent = enemy->GetComponent<EnemyComponent>();

    enemyComponent->SetPlayerComponent(playerComponent);
    playerComponent->SetEnemyComponent(enemyComponent);

    PlayerInfo* info = Instantiate<PlayerInfo>();
    info->SetPlayerComponent(playerComponent);

    Engine::LuaProgram* m_luaProgram = new Engine::LuaProgram("../LuaScripts/CardTest.lua");
    m_luaProgram->SetNewLibrary("cardTemplate",cardLib);
    m_luaProgram->CallCurrentProgram();

    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","discardCard",HandComponent::luaDiscardRandomCard);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","drawCard",PlayerComponent::luaDrawCard);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","freezeOpponent",PlayerComponent::luaFreezeOpponent);
    m_luaProgram->PushToTable<std::string, int(*)(lua_State *) > ("callbacks", "decreaseCostOfACard", HandComponent::luaDecreaseCostOfACard);

    m_luaProgram->GetGlobalFunction("InitCards",0,0);
    m_luaProgram->CallGlobalFunction("InitCards");

playerComponent->OnTurnStart();


}

MainLevel::~MainLevel()
{

}

MainLevel::MainLevel()
{

}

