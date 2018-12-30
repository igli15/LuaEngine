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

//There is supposed to be only one MainGame Class.
//Use this class to create scenes via SceneManager Class.;
//This class serves just as a place to create your scene.
//Use Game::Instance to get properties of Game Class like width,height.

MainGame::MainGame() : Game(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height,"Engine")
{

}

void MainGame::LoadResources(Engine::ResourceManager &resourceManager)
{
    Game::LoadResources(resourceManager);

    resourceManager.LoadTexture("../Assets/CardTemplate.png","CardBackground");
}

void MainGame::Build()
{
    Game::Build();   //Used to build the game

    lua_State* lua = luaL_newstate();
    luaL_openlibs(lua);
    luaL_loadfile(lua,"../LuaScripts/HelloWorld.lua");
    lua_call(lua,0,0);
    lua_close(lua);

    std::cout<<"Hello World "<<std::endl;
    std::cout<<Game::Instance()->Width()<<std::endl;
    std::cout<<Game::Instance()->Height()<<std::endl;

    Game::GetSceneManager()->CreateScene<MainLevel>("MainLevel");

    TestEvent* t = new TestEvent();

    Game::GetEventQueue()->RegisterEvent<TestEvent>( []() -> void {std::cout<<"WORKED";});

    Game::GetEventQueue()->QueueEventType<TestEvent>();
}



