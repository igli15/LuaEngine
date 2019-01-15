//
// Created by Igli milaqi on 15/01/2019.
//

#include "LuaProgram.h"
#include <string>

Engine::LuaProgram::LuaProgram(const std::string &filename)
{

    m_currentLuaState = GenerateProgram(filename);
}

lua_State *Engine::LuaProgram::GenerateProgram(const std::string &filename)
{
    lua_State* luaState = luaL_newstate();
    luaL_openlibs(luaState);
    luaL_loadfile(luaState,filename.c_str());  // convert the filename string to C style string

    if(lua_pcall(luaState,0,0,0) == 0)         //only if its zero it is called correctly
    {
        return luaState;
    }else
        {
        std::string error = lua_tostring(luaState,-1);   //get the error from the top of the stack
        std::cout<<error<<std::endl;
        throw error;
        return nullptr;
    }
}

double Engine::LuaProgram::GetGlobalDouble(std::string varName)
{
    lua_getglobal(m_currentLuaState,varName.c_str());

    if(lua_isnumber(m_currentLuaState,-1))
    {
        return lua_tonumber(m_currentLuaState,-1);
    }
    else {
        std::cout<<"The global is not of type Double"<<std::endl;
        throw;
    }
}
