//
// Created by Igli milaqi on 12/12/2018.
//

#include <iostream>
#include "../LuaSrc/lua.hpp"
#include "MainGame.h"
#include "TestEvent.h"

//There is supposed to be only one MainGame Class.
//Use this class to create scenes via SceneManager Class.;
//This class serves just as a place to create your scene.
//Use Game::Instance to get properties of Game Class like width,height.

MainGame::MainGame() : Game(1920, 1080,"Engine")
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

    TestEvent* t = new TestEvent();

    Game::GetEventQueue()->RegisterEvent<TestEvent>( []() -> void {std::cout<<"WORKED";});

    Game::GetEventQueue()->QueueEventType<TestEvent>();

}

void MainGame::TestFunction()
{
    std::cout<<"HELLO";
}

