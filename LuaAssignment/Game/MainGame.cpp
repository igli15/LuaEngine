//
// Created by Igli milaqi on 12/12/2018.
//

#include <iostream>
#include "../LuaSrc/lua.hpp"
#include "MainGame.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Scene.h"
#include "TestEvent.h"
#include "MainLevel.h"
#include "../Engine/LuaProgram.h"
#include "Components/HandComponent.h"

//There is supposed to be only one MainGame Class.
//Use this class to create scenes via SceneManager Class.;
//This class serves just as a place to create your scene.
//Use Game::Instance to get properties of Game Class like width,height.


MainGame::MainGame() : Game(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height,"Engine")
{

}

//Load All The Required Resources Once Here
void MainGame::LoadResources(Engine::ResourceManager &resourceManager)
{
    Game::LoadResources(resourceManager);

    resourceManager.LoadTexture("../Assets/CardArtTest.png","CardArtTest");
    resourceManager.LoadTexture("../Assets/CardTemplate.png","CardBackground");
    resourceManager.LoadTexture("../Assets/EnemyBorder.png","EnemyBorder");
    resourceManager.LoadTexture("../Assets/EnemyArt.png","EnemyArt");
    resourceManager.LoadFont("../Assets/NormalFont.ttf","TitleFont");
}

void MainGame::Build()
{
    Game::Build();   //Used to build the game

    //Engine::LuaProgram* luaProgram = new Engine::LuaProgram("../LuaScripts/CardTest.lua");

   // luaProgram->CallCurrentProgram();
   //luaProgram->PushToTable<std::string, int(*)(lua_State*)>("callbacks","discardCard",HandComponent::luaDiscardRandomCard);
    //std::cout<<luaProgram->GetValueFromTable<std::string,std::string>("test","te")<<std::endl;
   // luaProgram->PushToTable<std::string,int>("test","t",20);


    /* luaProgram->GetGlobalFunction("concat",2,1);
    luaProgram->PushFunctionArgument<std::string>("te");
    luaProgram->PushFunctionArgument<std::string>("st");
    luaProgram->CallGlobalFunction("concat");
    std::cout<<luaProgram->PopFunctionReturn<std::string>()<<std::endl; */

    /*luaProgram->GetGlobalFunction("ability",0,0);
    luaProgram->CallGlobalFunction("ability");*/

    //std::cout<<luaProgram->GetGlobalBoolean("t")<<std::endl;

    std::cout<< "Hello World "<< std::endl;
    std::cout<<Game::Instance()->Width()<<std::endl;
    std::cout<<Game::Instance()->Height()<<std::endl;

    Game::GetSceneManager()->CreateScene<MainLevel>("MainLevel");

    TestEvent* t = new TestEvent();

    Game::GetEventQueue()->RegisterEvent<TestEvent>( []() -> void {std::cout<<"WORKED";});

    Game::GetEventQueue()->QueueEventType<TestEvent>();
}



